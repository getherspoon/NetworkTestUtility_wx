/* 
 * File:   NetworkDlgUDPTab.cpp
 * Author: jarmentrout
 * 
 * Created on February 28, 2013, 2:40 PM
 */

#include "stdafx.h"
#include "NetworkDlgUDPTab.h"

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

const wxString		CNetworkDlgUDPTab::m_s_strLISTEN_TEXT	= "Start";
const wxString		CNetworkDlgUDPTab::m_s_strCLOSE_TEXT	= "Close";


const CNetworkDlgUDPTab::HexMapType	CNetworkDlgUDPTab::m_s_mapHEX_CHARS = boost::assign::map_list_of
( '0', 0 )( '1', 1 )( '2', 2 )( '3', 3 )( '4', 4 )( '5', 5 )( '6', 6 )( '7', 7 )( '8', 8 )( '9', 9 )
( 'A', 10 )( 'B', 11 )( 'C', 12 )( 'D', 13 )( 'E', 14 )( 'F', 15 )
( 'a', 10 )( 'b', 11 )( 'c', 12 )( 'd', 13 )( 'e', 14 )( 'f', 15 );

const std::set<char> CNetworkDlgUDPTab::m_s_setALLOWED_HEX_DELIMETERS = boost::assign::list_of
( ' ' )( ':' )( '-' );

CNetworkDlgUDPTab::CNetworkDlgUDPTab( wxWindow* parent )
:
CNetworkDlgUDPTab_wxGUI( parent ),
m_bListen( false )
{
    wxString strTemp( this->m_textCtrlSend0->GetValue() );
    this->m_textCtrlSend0->Enable( this->m_toggleBtnListen->GetValue() );
    this->m_buttonSend0->Enable( this->m_toggleBtnListen->GetValue() && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex0->Enable( this->m_toggleBtnListen->GetValue() );
    
    strTemp = this->m_textCtrlSend1->GetValue();
    this->m_textCtrlSend1->Enable( this->m_toggleBtnListen->GetValue() );
    this->m_buttonSend1->Enable( this->m_toggleBtnListen->GetValue() && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex1->Enable( this->m_toggleBtnListen->GetValue() );

    this->m_textCtrlSendToAddress->WriteText( "192.168.2.16" );
    this->m_textCtrlSendToPort->WriteText( "1234" );
    this->m_textCtrlLocalListeningPort->WriteText( "1234" );
}


CNetworkDlgUDPTab::~CNetworkDlgUDPTab() 
{
}

void CNetworkDlgUDPTab::OnButtonClick_ClearRecvData( wxCommandEvent& event )
{   
    this->m_textCtrlRecvData->Clear();
}

void CNetworkDlgUDPTab::OnButtonClick_ClearSentData( wxCommandEvent& event )
{    
    this->m_textCtrlSentData->Clear();
}

void CNetworkDlgUDPTab::OnButtonClick_Send0( wxCommandEvent& event )
{
    this->SendUserInput( 0 );
}

void CNetworkDlgUDPTab::OnButtonClick_Send1( wxCommandEvent& event )
{
    this->SendUserInput( 0 );
}

void CNetworkDlgUDPTab::OnToggle_Listen( wxCommandEvent& event )
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

        this->m_buttonSend0->Enable( bSend );
        this->m_buttonSend1->Enable( bSend );
        
        this->m_toggleBtnListen->SetLabel( m_s_strCLOSE_TEXT );

        if( this->m_checkBoxAsync->GetValue() )
        {
            if( bSend && bListen )
            {
                this->m_pAsyncComms.reset( new CAsyncUDPComms(	usListenPort, 
                                                                std::string( strIP ), 
                                                                usPort, 
                                                                boost::bind( &CNetworkDlgUDPTab::ProcessRecvMessage, this, _1, _2, _3, _4 ),
                                                                boost::bind( &CNetworkDlgUDPTab::ProcessSendMessage, this, _1, _2 ) ) );

            }
            else if( bSend && !bListen )
            {
                this->m_pAsyncComms.reset( new CAsyncUDPComms(	std::string( strIP ), 
                                                                usPort, 
                                                                boost::bind( &CNetworkDlgUDPTab::ProcessSendMessage, this, _1, _2 ) ) );

                if( !this->m_pAsyncComms->InitializeComms( bstError ) ) 
                {
                        this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ).c_str() );
                }
            }
            else if( !bSend && bListen )
            {
                this->m_pAsyncComms.reset( new CAsyncUDPComms(	usListenPort, 
                                                                boost::bind( &CNetworkDlgUDPTab::ProcessRecvMessage, this, _1, _2, _3, _4 ) ) );

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
                    this->m_bstListen.reset( new boost::thread( &CNetworkDlgUDPTab::SyncListenThread, this ) );
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

    wxString strTemp( this->m_textCtrlSend0->GetValue() );
    this->m_textCtrlSend0->Enable( this->m_toggleBtnListen->GetValue() );
    this->m_buttonSend0->Enable( this->m_toggleBtnListen->GetValue() && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex0->Enable( this->m_toggleBtnListen->GetValue() );
    
    strTemp = this->m_textCtrlSend1->GetValue();
    this->m_textCtrlSend1->Enable( this->m_toggleBtnListen->GetValue() );
    this->m_buttonSend1->Enable( this->m_toggleBtnListen->GetValue() && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex1->Enable( this->m_toggleBtnListen->GetValue() ); 
}

void CNetworkDlgUDPTab::OnText_Send0( wxCommandEvent& event )
{
    if( this->m_checkBoxSendAsHex0->GetValue() &&
        this->EditBoxInvalid( 0 ) )
    {
        this->m_buttonSend0->Enable( false );
    }	
    else
    {
        wxString strTemp = this->m_textCtrlSend0->GetValue();            
        this->m_buttonSend0->Enable( !strTemp.IsEmpty() );
    }	
}

void CNetworkDlgUDPTab::OnText_Send1( wxCommandEvent& event )
{
    if( this->m_checkBoxSendAsHex1->GetValue() &&
        this->EditBoxInvalid( 1 ) )
    {
        this->m_buttonSend1->Enable( false );
    }	
    else
    {
        wxString strTemp = this->m_textCtrlSend1->GetValue();            
        this->m_buttonSend1->Enable( !strTemp.IsEmpty() );
    }	
}

wxString CNetworkDlgUDPTab::GetTabTitle()
{
	return "UDP";
}

void CNetworkDlgUDPTab::OnExit()
{
    if( this->m_toggleBtnListen->GetValue() )
    {
        this->m_toggleBtnListen->SetValue( false );
        wxCommandEvent ce;
        this->OnToggle_Listen( ce );
    }
}

void CNetworkDlgUDPTab::SendUserInput( const int p_iInputNumber )
{
    if( p_iInputNumber < this->m_s_iSendCount )
    {
        wxTextCtrl* wxSend =    p_iInputNumber == 0 ? this->m_textCtrlSend0 : 
                                p_iInputNumber == 1 ? this->m_textCtrlSend1 : NULL;
        wxCheckBox* wxCheck=    p_iInputNumber == 0 ? this->m_checkBoxSendAsHex0 : 
                                p_iInputNumber == 1 ? this->m_checkBoxSendAsHex1 : NULL;
        if( wxSend )
        {
            wxString strText = wxSend->GetValue();
            if( !strText.IsEmpty() )
            {
                if( this->m_pAsyncComms.get() || this->m_pSyncComms.get() )
                {				
                        std::string strSend( strText.mb_str() );

                        bool bSendAsHex = ( wxCheck->GetValue() );
                        if( bSendAsHex && this->IsValidHexString( strSend ) )
                        {
                            // The string must be an even number of characters, so we'll pre-pend a leading 0
                            // if it is not.
                            std::string strHex;				
                            if( strSend.length() % 2 != 0 )
                            {
                                strSend = "0" + strSend;
                            }
                            for( std::string::iterator itSend = strSend.begin(); itSend != strSend.end(); )
                            {
                                try
                                {
                                    // Find the first character
                                    HexMapType::const_iterator itBit1 = m_s_mapHEX_CHARS.find( *itSend++ );															
                                    HexMapType::const_iterator itBit2 = m_s_mapHEX_CHARS.end();
                                    if( itSend != strSend.end() )
                                    {
                                            itBit2 = m_s_mapHEX_CHARS.find( *itSend++ );
                                    }				
                                    unsigned int uValue1 = 0;
                                    unsigned int uValue2 = 0;
                                    if( itBit1 != m_s_mapHEX_CHARS.end() )
                                    {
                                            uValue1 = boost::lexical_cast<unsigned int>( itBit1->second );
                                    }
                                    if( itBit2 != m_s_mapHEX_CHARS.end() )
                                    {
                                            uValue2 = boost::lexical_cast<unsigned int>( itBit2->second );
                                    }
                                    strHex.push_back( ( uValue1 << 4 ) + uValue2 );														
                                }
                                catch( std::exception& ex )
                                {
                                        TRACE( "EXCEPTION: %s\n", ex.what() );
                                }
                            }
                            strSend = strHex;
                    }

                    // Send over the wire
                    if( this->m_pAsyncComms.get() )
                    {
                        this->m_pAsyncComms->Send( strSend );
                    }
                    else if( this->m_pSyncComms.get() )
                    {
                        boost::system::error_code	bstError;    
                        if( !this->m_pSyncComms->Send( strSend, bstError ) )
                        {
                            this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ) );
                        }
                    }
                    else
                    {
                        ASSERT( false );
                    }
                    
                    if( bSendAsHex )
                    {
                        std::stringstream ss;
                        for( unsigned int i = 0; i < strSend.length(); ++i )
                        {
                            try
                            {
                                unsigned int iSentByte = (unsigned int)strSend[i];
                                unsigned int iFirstNibble = (iSentByte & 0xF0) >> 4;
                                unsigned int iSecondNibble = (iSentByte & 0x0F);

                                bool bFound = false;
                                for( HexMapType::const_iterator it = this->m_s_mapHEX_CHARS.begin();
                                         !bFound && it != this->m_s_mapHEX_CHARS.end(); ++it )
                                {
                                    if( it->second == iFirstNibble )
                                    {
                                            ss << it->first;
                                            bFound = true;
                                    }
                                }

                                bFound = false;
                                for( HexMapType::const_iterator it = this->m_s_mapHEX_CHARS.begin();
                                         !bFound && it != this->m_s_mapHEX_CHARS.end(); ++it )
                                {
                                    if( it->second == iSecondNibble )
                                    {
                                            ss << it->first;
                                            bFound = true;
                                    }
                                }
                            }
                            catch( std::exception& ex )
                            {
                                TRACE( "EXCEPTION: %s\n", ex.what() );
                            }
                        }
                        strSend = "0x" + ss.str();
                    }
                                        
                    strSend.append( "\r\n" );
                    this->m_textCtrlSentData->AppendText( strSend.c_str() );
                }
            }
        }
    }
}

void CNetworkDlgUDPTab::ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError )
{
    if( !p_bstError )
    {        
        wxString strNew;
        strNew.Format( "%s: %s\r\n", p_strRecvFromAddress.c_str(), p_strMessage.c_str() );
        this->m_textCtrlRecvData->AppendText( strNew );
    }
    else
    {
        this->ErrorMessageBox( std::string( "ERROR: " + p_bstError.message() ) ); 
    }
}

void CNetworkDlgUDPTab::ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError )
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

void CNetworkDlgUDPTab::SyncListenThread()
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

bool CNetworkDlgUDPTab::EditBoxInvalid( int p_iIndex )
{
    bool bResult = false;
    switch ( p_iIndex ) 
    { 
        case 0:
        {
            if( this->m_checkBoxSendAsHex0->GetValue() )
            {
                wxString strText = this->m_textCtrlSend0->GetValue();							
                bResult = !this->IsValidHexString( std::string( strText.mb_str() ) );
            }
            break;
        }
        case 1:
        {
            if( this->m_checkBoxSendAsHex1->GetValue() )
            {
                wxString strText = this->m_textCtrlSend1->GetValue();							
                bResult = !this->IsValidHexString( std::string( strText.mb_str() ) );
            }
            break;
        }		
        default:
        {
                break;
        }
    }		
    return bResult;
}

bool CNetworkDlgUDPTab::IsValidHexString( const std::string& p_strHex )
{
    bool bResult = !p_strHex.empty();
    for( unsigned int i = 0; i < p_strHex.length() && bResult; ++i )
    {
        HexMapType::const_iterator it = this->m_s_mapHEX_CHARS.find( p_strHex.at( i ) );
        if( it == this->m_s_mapHEX_CHARS.end() )
        {
                bResult = false;
        }
    }
    return bResult;
}
