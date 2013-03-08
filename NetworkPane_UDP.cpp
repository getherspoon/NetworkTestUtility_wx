/* 
 * File:   NetworkDlgUDPTab.cpp
 * Author: jarmentrout
 * 
 * Created on February 28, 2013, 2:40 PM
 */

#include "stdafx.h"
#include "NetworkPane_UDP.h"

#include "AsyncUDPComms.h"
#include "AsyncUDPCommsImpl.h"
#include "AsyncUDPReceiver.h"
#include "AsyncUDPSender.h"

#include "NetworkTestUtility.h"

#include "SyncUDPComms.h"
#include "SyncUDPCommsImpl.h"
#include "SyncUDPReceiver.h"
#include "SyncUDPSender.h"

#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>

const wxString		CNetworkPane_UDP::m_s_strLISTEN_TEXT	= "Start";
const wxString		CNetworkPane_UDP::m_s_strCLOSE_TEXT	= "Close";

CNetworkPane_UDP::CNetworkPane_UDP( wxWindow* parent )
:
CNetworkDlgUDPTab_wxGUI( parent ),
m_bListen( false )
{
    if( this->m_pParent )
    {
        this->m_pParent->UpdateSendEnable( this->m_toggleBtnListen->GetValue() );
    }

    this->m_textCtrlSendToAddress->WriteText( "192.168.2.16" );
    this->m_textCtrlSendToPort->WriteText( "1234" );
    this->m_textCtrlLocalListeningPort->WriteText( "1234" );
}


CNetworkPane_UDP::~CNetworkPane_UDP() 
{
}

void CNetworkPane_UDP::OnToggle_Listen( wxCommandEvent& event )
{
    if( this->m_toggleBtnListen->GetValue() )
    {
        this->m_checkBoxAsync->Enable( false );
        this->m_textCtrlSendToPort->Enable( false );
        this->m_textCtrlLocalListeningPort->Enable( false );
        this->m_textCtrlSendToAddress->Enable( false );

        wxString strIP = this->m_textCtrlSendToAddress->GetValue();

        wxString strPort = this->m_textCtrlSendToPort->GetValue();

        wxString strListenPort = this->m_textCtrlLocalListeningPort->GetValue();

        unsigned short usPort;
        unsigned short usListenPort;

        boost::system::error_code	bstError;    

        bool bListen = false;
        bool bSend = false;
        try
        {
                usListenPort = boost::lexical_cast<unsigned short>( strListenPort );
                bListen = true;
        }
        catch( boost::bad_lexical_cast& )
        {}

        try
        {
                usPort = boost::lexical_cast<unsigned short>( strPort );
                bSend = strIP != "0.0.0.0";
        }
        catch( boost::bad_lexical_cast& )
        {}

        if( bSend )
        {
                boost::asio::ip::address	bstAddress;
                bstAddress		=	boost::asio::ip::address::from_string( strIP, bstError );
                if( bstError )
                {
                        this->ErrorMessageBox( "Invalid IP" );
                        bSend = false;
                }
        }

//        this->m_buttonSend0->Enable( bSend );
//        this->m_buttonSend1->Enable( bSend );
        
        this->m_toggleBtnListen->SetLabel( m_s_strCLOSE_TEXT );

        if( this->m_checkBoxAsync->GetValue() )
        {
            if( bSend && bListen )
            {
                this->m_pAsyncComms.reset( new CAsyncUDPComms(	usListenPort, 
                                                                std::string( strIP ), 
                                                                usPort, 
                                                                boost::bind( &CNetworkPane_UDP::ProcessRecvMessage, this, _1, _2, _3, _4 ),
                                                                boost::bind( &CNetworkPane_UDP::ProcessSendMessage, this, _1, _2 ) ) );

            }
            else if( bSend && !bListen )
            {
                this->m_pAsyncComms.reset( new CAsyncUDPComms(	std::string( strIP ), 
                                                                usPort, 
                                                                boost::bind( &CNetworkPane_UDP::ProcessSendMessage, this, _1, _2 ) ) );

                if( !this->m_pAsyncComms->InitializeComms( bstError ) ) 
                {
                        this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ).c_str() );
                }
            }
            else if( !bSend && bListen )
            {
                this->m_pAsyncComms.reset( new CAsyncUDPComms(	usListenPort, 
                                                                boost::bind( &CNetworkPane_UDP::ProcessRecvMessage, this, _1, _2, _3, _4 ) ) );

                if( !this->m_pAsyncComms->InitializeComms( bstError ) ) 
                {
                        this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ).c_str() );
                }
            }
            else
            {
                this->ErrorMessageBox( "ERROR: Cannot Send or Recv in this Configuration" );
            }
            if( this->m_pAsyncComms.get() )
            {
                if( !this->m_pAsyncComms->InitializeComms( bstError ) ) 
                {
                    this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ).c_str() );
                }
            }				
        }
        else
        {
            if( bSend && bListen )
            {
                this->m_pSyncComms.reset( new CSyncUDPComms(	usListenPort, 
                                                                std::string( strIP ), 
                                                                usPort ) );
            }
            else if( bSend && !bListen )
            {
                this->m_pSyncComms.reset( new CSyncUDPComms(	std::string( strIP ), 
                                                                usPort ) );
            }
            else if( !bSend && bListen )
            {
                this->m_pSyncComms.reset( new CSyncUDPComms(	usListenPort ) );
            }
            else
            {
                this->ErrorMessageBox( "ERROR: Cannot Send or Recv in this Configuration" );
            }
            if( this->m_pSyncComms.get() )
            {
                if( !this->m_pSyncComms->InitializeComms( bstError ) ) 
                {
                    this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ).c_str() );
                }
                else
                {
                    this->m_bstListen.reset( new boost::thread( &CNetworkPane_UDP::SyncListenThread, this ) );
                }
            }
        }			
    }
    else
    {
        this->m_checkBoxAsync->Enable( true );
        this->m_textCtrlSendToPort->Enable( true );
        this->m_textCtrlLocalListeningPort->Enable( true );
        this->m_textCtrlSendToAddress->Enable( true );

        this->m_toggleBtnListen->SetLabel( m_s_strLISTEN_TEXT );

        if( this->m_pSyncComms.get() )
        {
            boost::system::error_code	bstError; 
            this->m_pSyncComms->TerminateComms( bstError );			

            this->m_bListen = false;
            if( this->m_bstListen.get() && this->m_bstListen->joinable() )
            {
                    this->m_bstListen->join();
            }	
        }

        // Reset Comms
        this->m_pAsyncComms.reset();
        this->m_pSyncComms.reset();		
    }

    if( this->m_pParent )
    {
        this->m_pParent->UpdateSendEnable( this->m_toggleBtnListen->GetValue() );
    }
}

wxString CNetworkPane_UDP::GetTabTitle()
{
	return "UDP";
}

void CNetworkPane_UDP::OnExit()
{
    if( this->m_toggleBtnListen->GetValue() )
    {
        this->m_toggleBtnListen->SetValue( false );
        wxCommandEvent ce;
        this->OnToggle_Listen( ce );
    }
}

bool CNetworkPane_UDP::SendUserInput( const std::string& p_strToSend, boost::system::error_code& p_bstError )
{
    bool bResult = false;
    if( this->m_pAsyncComms.get() || this->m_pSyncComms.get() )
    {				                        
        // Send over the wire
        if( this->m_pAsyncComms.get() )
        {
            this->m_pAsyncComms->Send( p_strToSend );
            bResult = true;
        }
        else if( this->m_pSyncComms.get() )
        {            
            if( this->m_pSyncComms->Send( p_strToSend, p_bstError ) )
            {
                bResult = true;
            }            
        }
        else
        {
            ASSERT( false );            
        }
    }
    return bResult;
}

void CNetworkPane_UDP::ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError )
{
    if( !p_bstError )
    {        
        wxString strNew( wxString( p_strRecvFromAddress.c_str(), wxConvUTF8 ) );
        strNew += ": ";
        strNew += wxString( p_strMessage.c_str(), wxConvUTF8 );
        strNew += "\r\n";        
        if( this->m_pParent )
        {
            this->m_pParent->AddRecvText( strNew );
        }
    }
    else
    {
        this->ErrorMessageBox( std::string( "ERROR: " + p_bstError.message() ) ); 
    }
}

void CNetworkPane_UDP::ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError )
{
	if( !p_bstError )
	{		
	}
	else
	{
            wxString strMsg;
            strMsg.Format( "ERROR Sending: %s", p_bstError.message().c_str() );
            this->ErrorMessageBox( std::string( strMsg.mb_str() ) );
	}
}

void CNetworkPane_UDP::SyncListenThread()
{
    this->m_bListen = true;
    while( this->m_bListen )
    {
        std::string strIp, strMsg;
        unsigned short usPort;
        boost::system::error_code bstError;
        if( this->m_pSyncComms->Receive( strMsg, strIp, usPort, bstError, 5000 ) )
        {
                this->ProcessRecvMessage( strMsg, strIp, usPort, bstError );
        }
        boost::this_thread::sleep( boost::posix_time::milliseconds( 100 ) );
    }
}
