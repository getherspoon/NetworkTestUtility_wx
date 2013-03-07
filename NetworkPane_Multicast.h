/* 
 * File:   NetworkDlgMulticastTab.h
 * Author: jarmentrout
 *
 * Created on February 28, 2013, 2:40 PM
 */

#ifndef NETWORKDLGMULTICASTTAB_H
#define	NETWORKDLGMULTICASTTAB_H

#include "NetworkTestUtility_wxGUI.h"

#include <memory>
#include <string>

#include <boost/system/error_code.hpp>
#include <boost/thread.hpp>

#include <wx/string.h>

class CAsyncMulticastComms;
class CSyncMulticastComms;

class CNetworkPane_Multicast : public CNetworkDlgMulticastTab_wxGUI
{
public:
    CNetworkPane_Multicast( wxWindow* parent );
    virtual ~CNetworkPane_Multicast();
    
    wxString GetTabTitle()                                              { return "Multicast";   }
    
    boost::shared_ptr<CAsyncMulticastComms>      GetAsyncComms() const  { return this->m_pAsyncComms;   }
    boost::shared_ptr<CSyncMulticastComms>       GetSyncComms() const   { return this->m_pSyncComms;    }
    
    void OnButtonClick_Join( wxCommandEvent& event );    
    
    void OnCheckBox_UseSendForBoth( wxCommandEvent& event );    
    
    bool    SendUserInput( const std::string& p_strToSend, boost::system::error_code& p_bstError );
protected:
    void ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError );

    void ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError );    

    void SyncListenThread();
    
private:    
    static const wxString	m_s_strJOIN_TEXT;
    static const wxString	m_s_strUNJOIN_TEXT;    
    
    std::auto_ptr<boost::thread>		m_bstListen;
    bool					m_bListen;

    boost::shared_ptr<CAsyncMulticastComms>	m_pAsyncComms;
    boost::shared_ptr<CSyncMulticastComms>	m_pSyncComms;
};

#endif	/* NETWORKDLGMULTICASTTAB_H */

