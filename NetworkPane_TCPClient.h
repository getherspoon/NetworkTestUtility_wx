/* 
 * File:   NetworkDlgTCPClientTab.h
 * Author: jarmentrout
 *
 * Created on February 28, 2013, 2:40 PM
 */

#ifndef NETWORKDLGTCPCLIENTTAB_H
#define	NETWORKDLGTCPCLIENTTAB_H

#include "NetworkTestUtility_wxGUI.h"

#include <memory>
#include <string>

#include <boost/system/error_code.hpp>
#include <boost/thread.hpp>

#include <wx/string.h>

class CAsyncTCPComms;
class CSyncTCPComms;

class CNetworkPane_TCPClient : public CNetworkDlgTCPClientTab_wxGUI
{
public:
        CNetworkPane_TCPClient( wxWindow* parent );    
        virtual ~CNetworkPane_TCPClient();

        wxString GetTabTitle()                        { return "TCP Client";   }
        
        boost::shared_ptr<CAsyncTCPComms>      GetAsyncComms() const  { return this->m_pAsyncComms;   }
        boost::shared_ptr<CSyncTCPComms>       GetSyncComms() const   { return this->m_pSyncComms;    }
        
        virtual void OnToggle_Listen( wxCommandEvent& event );
        
        bool    SendUserInput( const std::string& p_strToSend, boost::system::error_code& p_bstError );
        
protected:
        void ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError );

        void ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError );    

        void SyncListenThread();        
private:
        static const wxString	m_s_strLISTEN_TEXT;
	static const wxString	m_s_strCLOSE_TEXT;
        static const long	m_s_lSYNC_TIMEOUT_IN_MS;
    
        std::auto_ptr<boost::thread>				m_bstListen;
        bool							m_bListen;

        
        boost::shared_ptr<CAsyncTCPComms>			m_pAsyncComms;
        boost::shared_ptr<CSyncTCPComms>			m_pSyncComms;

};

#endif	/* NETWORKDLGTCPCLIENTTAB_H */

