/* 
 * File:   NetworkDlgMulticastTab.cpp
 * Author: jarmentrout
 * 
 * Created on February 28, 2013, 2:40 PM
 */

#include "stdafx.h"
#include "NetworkDlgMulticastTab.h"

#include "AsyncMulticastComms.h"
#include "AsyncMulticastReceiver.h"
#include "AsyncMulticastSender.h"

#include "NetworkDlgMulticastTab.h"

#include "SyncMulticastComms.h"
#include "SyncMulticastReceiver.h"
#include "SyncMulticastSender.h"

#include <sstream>

#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>

#include <wx/msgdlg.h>

const wxString		CNetworkDlgMulticastTab::m_s_strJOIN_TEXT	= "Join";
const wxString		CNetworkDlgMulticastTab::m_s_strUNJOIN_TEXT	= "Unjoin";

const CNetworkDlgMulticastTab::HexMapType	CNetworkDlgMulticastTab::m_s_mapHEX_CHARS = boost::assign::map_list_of
( '0', 0 )( '1', 1 )( '2', 2 )( '3', 3 )( '4', 4 )( '5', 5 )( '6', 6 )( '7', 7 )( '8', 8 )( '9', 9 )
( 'A', 10 )( 'B', 11 )( 'C', 12 )( 'D', 13 )( 'E', 14 )( 'F', 15 )
( 'a', 10 )( 'b', 11 )( 'c', 12 )( 'd', 13 )( 'e', 14 )( 'f', 15 );

const std::set<char> CNetworkDlgMulticastTab::m_s_setALLOWED_HEX_DELIMETERS = boost::assign::list_of
( ' ' )( ':' )( '-' );

CNetworkDlgMulticastTab::CNetworkDlgMulticastTab( wxWindow* parent ) 
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

    wxString strTemp( this->m_textCtrlSend0->GetValue() );
    this->m_textCtrlSend0->Enable( this->m_toggleBtnJoin->GetValue() );
    this->m_buttonSend0->Enable( this->m_toggleBtnJoin->GetValue() && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex0->Enable( this->m_toggleBtnJoin->GetValue() );
    
    strTemp = this->m_textCtrlSend1->GetValue();
    this->m_textCtrlSend1->Enable( this->m_toggleBtnJoin->GetValue() );
    this->m_buttonSend1->Enable( this->m_toggleBtnJoin->GetValue() && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex1->Enable( this->m_toggleBtnJoin->GetValue() );           
}

CNetworkDlgMulticastTab::~CNetworkDlgMulticastTab() 
{
}

// CNetworkDlgMulticastTab message handlers
void CNetworkDlgMulticastTab::OnButtonClick_Join( wxCommandEvent& event )
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

        this->m_buttonSend0->Enable( bSend );
        this->m_buttonSend1->Enable( bSend );        

        if( this->m_checkBoxAsync->GetValue() )
        {
            if( bSend && bRecv )
            {
                this->m_pAsyncComms.reset( new CAsyncMulticastComms(	std::string( strIPRecv ),
                                                                            usPortRecv,
                                                                            std::string( strIPSend ),
                                                                            usPortSend,
                                                                            boost::bind( &CNetworkDlgMulticastTab::ProcessRecvMessage, this, _1, _2, _3, _4 ),
                                                                            boost::bind( &CNetworkDlgMulticastTab::ProcessSendMessage, this, _1, _2 ),
                                                                            ( this->m_checkBoxEnableLoopback->GetValue() ) ) );
            }
            else if( bSend && !bRecv )
            {
                this->m_pAsyncComms.reset( new CAsyncMulticastComms(	std::string( strIPSend ),
                                                                            usPortSend,
                                                                            boost::bind( &CNetworkDlgMulticastTab::ProcessSendMessage, this, _1, _2 ) ) );
            }
            else if( !bSend && bRecv )
            {
                this->m_pAsyncComms.reset( new CAsyncMulticastComms(	std::string( strIPRecv ),
                                                                            usPortRecv,
                                                                            boost::bind( &CNetworkDlgMulticastTab::ProcessRecvMessage, this, _1, _2, _3, _4 ),
                                                                            ( this->m_checkBoxEnableLoopback->GetValue() ) ) );
            }
            else
            {
                    std::string strError( "ERROR: Cannot Send or Recv in this Configuration" );
                    wxMessageDialog *wxMsgDlg = new wxMessageDialog( this,
                                                                    wxT( strError ),
                                                                    wxT("ERROR!"), wxOK | wxICON_ERROR );
                    wxMsgDlg->ShowModal();

            }
            if( this->m_pAsyncComms.get() )
            {
                    if( !this->m_pAsyncComms->InitializeComms( bstError ) ) 
                    {
                        std::string strError( "ERROR: " + bstError.message() );
                        wxMessageDialog *wxMsgDlg = new wxMessageDialog( this,
                                                                    wxT( strError ),
                                                                    wxT("ERROR!"), wxOK | wxICON_ERROR );
                        wxMsgDlg->ShowModal();                            
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
                    std::string strError( "ERROR: Cannot Send or Recv in this Configuration" );
                    wxMessageDialog *wxMsgDlg = new wxMessageDialog( this,
                                                                wxT( strError ),
                                                                wxT("ERROR!"), wxOK | wxICON_ERROR );
                    wxMsgDlg->ShowModal();
            }
            if( this->m_pSyncComms.get() )
            {
                if( !this->m_pSyncComms->InitializeComms( bstError ) ) 
                {                        
                    std::string strError( "ERROR: " + bstError.message() );
                    wxMessageDialog *wxMsgDlg = new wxMessageDialog( this,
                                                                wxT( strError ),
                                                                wxT("ERROR!"), wxOK | wxICON_ERROR );
                    wxMsgDlg->ShowModal();
                }
                else
                {
                    this->m_bstListen.reset( new boost::thread( &CNetworkDlgMulticastTab::SyncListenThread, this ) );
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

    wxString strTemp( this->m_textCtrlSend0->GetValue() );
    this->m_textCtrlSend0->Enable( this->m_toggleBtnJoin->GetValue() );
    this->m_buttonSend0->Enable( this->m_toggleBtnJoin->GetValue() && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex0->Enable( this->m_toggleBtnJoin->GetValue() );
    
    strTemp = this->m_textCtrlSend1->GetValue();
    this->m_textCtrlSend1->Enable( this->m_toggleBtnJoin->GetValue() );
    this->m_buttonSend1->Enable( this->m_toggleBtnJoin->GetValue() && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex1->Enable( this->m_toggleBtnJoin->GetValue() );    
}

void CNetworkDlgMulticastTab::OnButtonClick_Send0( wxCommandEvent& event )
{
    this->SendUserInput( 0 );
}

void CNetworkDlgMulticastTab::OnButtonClick_Send1( wxCommandEvent& event )
{
    this->SendUserInput( 1 );
}

void CNetworkDlgMulticastTab::OnButtonClick_ClearRecv( wxCommandEvent& event )
{
    this->m_textCtrlMCGroupRecv->Clear();
}

void CNetworkDlgMulticastTab::OnButtonClick_ClearSent( wxCommandEvent& event )
{
    this->m_textCtrlMCGroupSend->Clear();
}

void CNetworkDlgMulticastTab::OnCheckBox_UseSendForBoth( wxCommandEvent& event )
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

void CNetworkDlgMulticastTab::SendUserInput( const int p_iInputNumber )
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

                        bool bSendAsHex = ( wxCheck.GetValue() );
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
                            std::string strError( "ERROR: " + bstError.message() );
                            wxMessageDialog *wxMsgDlg = new wxMessageDialog( this,
                                                                        wxT( strError ),
                                                                        wxT("ERROR!"), wxOK | wxICON_ERROR );
                            wxMsgDlg->ShowModal();                         
                        }
                    }
                    else
                    {
                        ASSERT( false );
                    }

                    // Update the Sent edit box
                    CString strOld, strNew;
                    this->m_editSent.GetWindowTextA( strOld );

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

                    if( strOld.IsEmpty() )
                    {
                        strNew.Format( "%s", strSend.c_str() );
                    }
                    else
                    {
                        strNew.Format( "%s\r\n%s", strOld, strSend.c_str() );
                    }

                    this->m_editSent.SetWindowTextA( strNew );
                }
            }
        }
    }
}

void CNetworkDlgMulticastTab::ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError )
{
//	if( !p_bstError )
//	{
//		CString strText, strNew;
//		this->m_editReceived.GetWindowTextA( strText );
//		strNew.Format( "%s\r\n%s: %s", strText, p_strRecvFromAddress.c_str(), p_strMessage.c_str() );
//		this->m_editReceived.SetWindowTextA( strNew );
//	}
//	else
//	{
//		CString strMsg;
//		strMsg.Format( "ERROR Receiving: %s", p_bstError.message().c_str() );
//		::AfxMessageBox( strMsg );
//	}
}

void CNetworkDlgMulticastTab::ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError )
{
//	if( !p_bstError )
//	{		
//	}
//	else
//	{
//		CString strMsg;
//		strMsg.Format( "ERROR Sending: %s", p_bstError.message().c_str() );
//		::AfxMessageBox( strMsg );
//	}
}

void CNetworkDlgMulticastTab::SyncListenThread()
{
//	this->m_bListen = true;
//	while( this->m_bListen )
//	{
//		try
//		{
//			std::string strIp, strMsg;
//			unsigned short usPort;
//			boost::system::error_code bstError;
//			if( this->m_pSyncComms.get() && this->m_pSyncComms->Receive( strMsg, strIp, usPort, bstError, 5000 ) )
//			{
//				this->ProcessRecvMessage( strMsg, strIp, usPort, bstError );
//			}
//		}
//		catch( boost::system::system_error& ex )
//		{
//			TRACE("Listen Thread Exception: %s\n", ex.what() );
//		}
//	}
}
