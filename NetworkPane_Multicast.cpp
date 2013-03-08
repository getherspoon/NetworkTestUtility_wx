/* 
 * File:   NetworkDlgMulticastTab.cpp
 * Author: jarmentrout
 * 
 * Created on February 28, 2013, 2:40 PM
 */

#include "stdafx.h"
#include "NetworkPane_Multicast.h"

#include "AsyncMulticastComms.h"
#include "AsyncMulticastReceiver.h"
#include "AsyncMulticastSender.h"

#include "NetworkTabDialog.h"

#include "SyncMulticastComms.h"
#include "SyncMulticastReceiver.h"
#include "SyncMulticastSender.h"
#include "NetworkTabDialog.h"

#include <sstream>

#include <boost/lexical_cast.hpp>

const wxString		CNetworkPane_Multicast::m_s_strJOIN_TEXT	= "Join";
const wxString		CNetworkPane_Multicast::m_s_strUNJOIN_TEXT	= "Unjoin";

CNetworkPane_Multicast::CNetworkPane_Multicast( wxWindow* parent ) 
:
CNetworkDlgMulticastTab_wxGUI( parent ),
m_bListen( false )
{
    this->m_textCtrlMCGroupSend->SetValue( wxString( CommsUtilities::Multicast::s_strMULTICAST_GROUP_RCU_RDRCP_LEGACY_RDR.c_str(), wxConvUTF8 ) );
    std::string strPort = boost::lexical_cast<std::string>( CommsUtilities::Multicast::s_usMULTICAST_PORT_RCU_RDRCP_LEGACY_RDR );
    this->m_textCtrlPortSend->SetValue( wxString( strPort.c_str(), wxConvUTF8 ) );	
        
    this->m_checkBoxUseSendForBoth->SetValue( true );
    wxCommandEvent ce;
    this->OnCheckBox_UseSendForBoth( ce );
    
    if( this->m_pParent )
    {
        this->m_pParent->UpdateSendEnable( this->m_toggleBtnJoin->GetValue() );
    }
}

CNetworkPane_Multicast::~CNetworkPane_Multicast() 
{
}

// CNetworkDlgMulticastTab message handlers
void CNetworkPane_Multicast::OnButtonClick_Join( wxCommandEvent& event )
{		
    if( this->m_toggleBtnJoin->GetValue() )
    {
        this->m_checkBoxAsync->Enable( false );
        this->m_checkBoxEnableLoopback->Enable( false );
        this->m_checkBoxUseSendForBoth->Enable( false );
        this->m_textCtrlPortRecv->Enable( false );
        this->m_textCtrlPortSend->Enable( false );
        this->m_textCtrlMCGroupRecv->Enable( false );
        this->m_textCtrlMCGroupSend->Enable( false );

        std::string strIPRecv( this->m_textCtrlMCGroupRecv->GetValue().mb_str() );
        std::string strPortRecv( this->m_textCtrlPortRecv->GetValue().mb_str() );
        
        std::string strIPSend( this->m_textCtrlMCGroupSend->GetValue().mb_str() );                
        std::string strPortSend( this->m_textCtrlPortSend->GetValue().mb_str() );        

        unsigned short int usPortSend, usPortRecv;		

        boost::system::error_code	bstError;    

        bool bRecv = false;		
        try
        {
                usPortRecv = boost::lexical_cast<unsigned short>( strPortRecv );
                bRecv = strIPRecv != "0.0.0.0";
        }
        catch( boost::bad_lexical_cast& )
        {}

        if( bRecv )
        {
            boost::system::error_code	bstError;    
            boost::asio::ip::address	bstAddress;
            bstAddress =	boost::asio::ip::address::from_string( strIPRecv, bstError );
            if( bstError )
            {
                    TRACE( "IP Conversion (RECV): Error %s\n", bstError.message().c_str() );
                    bRecv = false;
            }
        }

        bool bSend = false;
        try
        {
            usPortSend = boost::lexical_cast<unsigned short>( strPortSend );
            bSend = strIPSend != "0.0.0.0";
        }
        catch( boost::bad_lexical_cast& )
        {}

        if( bSend )
        {			
            boost::asio::ip::address	bstAddress;
            bstAddress =	boost::asio::ip::address::from_string( strIPSend, bstError );
            if( bstError )
            {
                    TRACE( "IP Conversion: Error(SEND) %s\n", bstError.message().c_str() );
                    bSend = false;
            }
        }

//        this->m_buttonSend0->Enable( bSend );
//        this->m_buttonSend1->Enable( bSend );        

        if( this->m_checkBoxAsync->GetValue() )
        {
            if( bSend && bRecv )
            {
                this->m_pAsyncComms.reset( new CAsyncMulticastComms(	std::string( strIPRecv ),
                                                                        usPortRecv,
                                                                        std::string( strIPSend ),
                                                                        usPortSend,
                                                                        boost::bind( &CNetworkPane_Multicast::ProcessRecvMessage, this, _1, _2, _3, _4 ),
                                                                        boost::bind( &CNetworkPane_Multicast::ProcessSendMessage, this, _1, _2 ),
                                                                        ( this->m_checkBoxEnableLoopback->GetValue() ) ) );
            }
            else if( bSend && !bRecv )
            {
                this->m_pAsyncComms.reset( new CAsyncMulticastComms(	std::string( strIPSend ),
                                                                        usPortSend,
                                                                        boost::bind( &CNetworkPane_Multicast::ProcessSendMessage, this, _1, _2 ) ) );
            }
            else if( !bSend && bRecv )
            {
                this->m_pAsyncComms.reset( new CAsyncMulticastComms(	std::string( strIPRecv ),
                                                                        usPortRecv,
                                                                        boost::bind( &CNetworkPane_Multicast::ProcessRecvMessage, this, _1, _2, _3, _4 ),
                                                                        ( this->m_checkBoxEnableLoopback->GetValue() ) ) );
            }
            else
            {
                this->ErrorMessageBox( std::string( "ERROR: Cannot Send or Recv in this Configuration" ) );
            }
            if( this->m_pAsyncComms.get() )
            {
                if( !this->m_pAsyncComms->InitializeComms( bstError ) ) 
                {
                    this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ) );
                }
            }
        }
        else
        {
            if( bSend && bRecv )
            {
                this->m_pSyncComms.reset( new CSyncMulticastComms(	std::string( strIPRecv ), 
                                                                        usPortRecv,
                                                                        std::string( strIPSend ), 
                                                                        usPortSend,
                                                                        ( this->m_checkBoxEnableLoopback->GetValue() ) ) );
            }
            else if( bSend && !bRecv )
            {
                    this->m_pSyncComms.reset( new CSyncMulticastComms(	std::string( strIPSend ), 
                                                                        usPortSend ) );
            }
            else if( bSend && bRecv )
            {
                    this->m_pSyncComms.reset( new CSyncMulticastComms(	std::string( strIPRecv ), 
                                                                        usPortRecv,																	
                                                                        ( this->m_checkBoxEnableLoopback->GetValue() ) ) );
            }
            else
            {                    
                    this->ErrorMessageBox( std::string( "ERROR: Cannot Send or Recv in this Configuration" ) );
            }
            if( this->m_pSyncComms.get() )
            {
                if( !this->m_pSyncComms->InitializeComms( bstError ) ) 
                {                        
                    this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ) );                   
                }
                else
                {
                    this->m_bstListen.reset( new boost::thread( &CNetworkPane_Multicast::SyncListenThread, this ) );
                }
            }
        }		
    }
    else
    {
        this->m_checkBoxAsync->Enable( true );
        this->m_checkBoxEnableLoopback->Enable( true );
        this->m_checkBoxUseSendForBoth->Enable( true );
        this->m_textCtrlPortSend->Enable( true );
        this->m_textCtrlMCGroupSend->Enable( true );
        wxCommandEvent ce;
        this->OnCheckBox_UseSendForBoth( ce );


        this->m_toggleBtnJoin->SetLabel( m_s_strJOIN_TEXT );

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
        this->m_pParent->UpdateSendEnable( this->m_toggleBtnJoin->GetValue() );
    }    
}

void CNetworkPane_Multicast::OnCheckBox_UseSendForBoth( wxCommandEvent& event )
{
    if( this->m_checkBoxUseSendForBoth->GetValue() )
    {
        wxString strIP  = this->m_textCtrlMCGroupSend->GetValue();
        wxString strPort= this->m_textCtrlPortSend->GetValue();
        
        this->m_textCtrlMCGroupRecv->SetValue( strIP );
        this->m_textCtrlPortRecv->SetValue( strPort );
        
        this->m_textCtrlMCGroupRecv->Enable( false );
        this->m_textCtrlPortRecv->Enable( false );
    }
    else
    {
        this->m_textCtrlMCGroupRecv->Enable( true );
        this->m_textCtrlPortRecv->Enable( true );
    }
}

bool CNetworkPane_Multicast::SendUserInput( const std::string& p_strToSend, boost::system::error_code& p_bstError )
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

void CNetworkPane_Multicast::ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError )
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

void CNetworkPane_Multicast::ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError )
{
    if( p_bstError )
    {
        this->ErrorMessageBox( std::string( "ERROR: " + p_bstError.message() ) );
    }
}

void CNetworkPane_Multicast::SyncListenThread()
{
    this->m_bListen = true;
    while( this->m_bListen )
    {
        try
        {
            std::string strIp, strMsg;
            unsigned short usPort;
            boost::system::error_code bstError;
            if( this->m_pSyncComms.get() && this->m_pSyncComms->Receive( strMsg, strIp, usPort, bstError, 5000 ) )
            {
                this->ProcessRecvMessage( strMsg, strIp, usPort, bstError );
            }
        }
        catch( boost::system::system_error& ex )
        {
            TRACE("Listen Thread Exception: %s\n", ex.what() );
        }
    }
}
