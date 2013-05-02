/* 
 * File:   NetworkDlgTCPClientTab.cpp
 * Author: jarmentrout
 * 
 * Created on February 28, 2013, 2:40 PM
 */

#include "NetworkPane_TCPClient.h"

#include "AsyncTCPComms.h"
#include "SyncTCPComms.h"

#include <boost/lexical_cast.hpp>

const wxString	CNetworkPane_TCPClient::m_s_strLISTEN_TEXT	= "Start";
const wxString	CNetworkPane_TCPClient::m_s_strCLOSE_TEXT	= "Close";
const long      CNetworkPane_TCPClient::m_s_lSYNC_TIMEOUT_IN_MS = 1000;

CNetworkPane_TCPClient::CNetworkPane_TCPClient( wxWindow* parent ) 
:
CNetworkDlgTCPClientTab_wxGUI( parent ),
m_bListen( false )
{
}

CNetworkPane_TCPClient::~CNetworkPane_TCPClient() 
{
}

void CNetworkPane_TCPClient::OnToggle_Listen( wxCommandEvent& event )
{
    if( this->m_toggleBtnListen->GetValue() )
    {
            this->m_checkBoxAsync->Enable( false );
            this->m_textCtrlSendToAddress->Enable( false );
            this->m_textCtrlSendToPort->Enable( false );

            std::string strIP( this->m_textCtrlSendToAddress->GetValue().mb_str() );
            std::string strPort( this->m_textCtrlSendToPort->GetValue().mb_str() );
            
            unsigned short usPort;

            boost::system::error_code	bstError;    

            bool bListen = false;
            bool bSend = false;
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

            this->m_toggleBtnListen->SetLabel( m_s_strCLOSE_TEXT );

            if( this->m_checkBoxAsync->GetValue() )
            {

                    this->m_pAsyncComms.reset( new CAsyncTCPComms(std::string(strIP), 
                                                                    usPort, 
                                                                    boost::bind( &CNetworkPane_TCPClient::ProcessRecvMessage, this, _1, _2), 
                                                                    boost::bind( &CNetworkPane_TCPClient::ProcessSendMessage, this, _1, _2) ) );
            }
            else
            {
                    this->m_pSyncComms.reset( new CSyncTCPComms(std::string(strIP), usPort) );
                    if( this->m_pSyncComms.get() )
                    {
                            this->m_bstListen.reset( new boost::thread( &CNetworkPane_TCPClient::SyncListenThread, this ) );
                    }
            }			
    }
    else
    {
            this->m_checkBoxAsync->Enable( true );
            this->m_textCtrlSendToAddress->Enable( true );
            this->m_textCtrlSendToPort->Enable( true );

            this->m_toggleBtnListen->SetLabel( m_s_strLISTEN_TEXT );

            if( this->m_pSyncComms.get() )
            {
                    this->m_bListen = false;
                    if( this->m_bstListen.get() && this->m_bstListen->joinable() )
                    {
                            //Cancel any remaining IO on the socket. 
                            boost::system::error_code bstError;
                            this->m_pSyncComms->CancelIO(bstError);
                            this->m_bstListen->join();
                    }	
            }

            // Reset Comms
            this->m_pAsyncComms.reset();
            this->m_pSyncComms.reset();	
    }
}

bool CNetworkPane_TCPClient::SendUserInput( const std::string& p_strToSend, boost::system::error_code& p_bstError )
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


void CNetworkPane_TCPClient::ProcessRecvMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError )
{
	if( !p_bstError )
        {                    
            wxString strNew( p_strMessage.c_str(), wxConvUTF8 );
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

void CNetworkPane_TCPClient::ProcessSendMessage( boost::system::error_code &p_bstError, const std::size_t &p_st )
{
	if( p_bstError )
	{		
                this->ErrorMessageBox( std::string( "ERROR: " + p_bstError.message() ) ); 
	}
}

void CNetworkPane_TCPClient::SyncListenThread()
{
	this->m_bListen = true;
	while( this->m_bListen )
	{
		std::string strMsg;
		boost::system::error_code bstError;
		if( this->m_pSyncComms->Read( strMsg, bstError, m_s_lSYNC_TIMEOUT_IN_MS ) )
		{
			this->ProcessRecvMessage( strMsg, bstError );
		}
		boost::this_thread::sleep( boost::posix_time::milliseconds( 100 ) );
	}
}
