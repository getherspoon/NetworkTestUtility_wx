/* 
 * File:   NetworkDlgUDPTab.h
 * Author: jarmentrout
 *
 * Created on February 28, 2013, 2:40 PM
 */

#ifndef NETWORKDLGUDPTAB_H
#define	NETWORKDLGUDPTAB_H

#include "NetworkTestUtility_wxGUI.h"
#include "NetworkTabDialog.h"

#include <memory>
#include <string>

#include <boost/system/error_code.hpp>
#include <boost/thread.hpp>

#include <wx/string.h>

class CAsyncUDPComms;
class CSyncUDPComms;

class CNetworkPane_UDP : public CNetworkDlgUDPTab_wxGUI
{
public:
    CNetworkPane_UDP( wxWindow* parent );
    virtual ~CNetworkPane_UDP();
       
    virtual void OnToggle_Listen( wxCommandEvent& event );
    
    wxString	GetTabTitle();
    void	OnExit();

    bool    SendUserInput( const std::string& p_strToSend, boost::system::error_code& p_bstError );
protected:
    void ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError );

    void ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError );    

    void SyncListenThread();

private:
    
    static const wxString		m_s_strLISTEN_TEXT;
    static const wxString		m_s_strCLOSE_TEXT;
    
    std::auto_ptr<boost::thread>	m_bstListen;
    bool				m_bListen;

    std::auto_ptr<CAsyncUDPComms>	m_pAsyncComms;
    std::auto_ptr<CSyncUDPComms>	m_pSyncComms;
};

#endif	/* NETWORKDLGUDPTAB_H */

