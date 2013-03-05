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

#include <map>
#include <memory>
#include <set>
#include <string>

#include <boost/system/error_code.hpp>
#include <boost/thread.hpp>

#include <wx/string.h>

class CAsyncUDPComms;
class CSyncUDPComms;

class CNetworkDlgUDPTab : public CNetworkDlgUDPTab_wxGUI
{
public:
    CNetworkDlgUDPTab( wxWindow* parent );
    virtual ~CNetworkDlgUDPTab();
    
    virtual void OnButtonClick_ClearRecvData( wxCommandEvent& event );
    virtual void OnButtonClick_ClearSentData( wxCommandEvent& event );
    virtual void OnButtonClick_Send0( wxCommandEvent& event );
    virtual void OnButtonClick_Send1( wxCommandEvent& event );
    virtual void OnToggle_Listen( wxCommandEvent& event );
    
    void OnText_Send0( wxCommandEvent& event );
    void OnText_Send1( wxCommandEvent& event );
    
    wxString	GetTabTitle();
    void	OnExit();

protected:
    void ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError );

    void ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError );

    void SendUserInput( const int p_iInputNumber );

    bool EditBoxInvalid( int p_iIndex );

    bool IsValidHexString( const std::string& p_strHex );

    void SyncListenThread();

private:
    typedef	std::map<char,unsigned int>	HexMapType;

    static const int			m_s_iSendCount = 2;
    static const wxString		m_s_strLISTEN_TEXT;
    static const wxString		m_s_strCLOSE_TEXT;
    static const HexMapType		m_s_mapHEX_CHARS;
    static const std::set<char>         m_s_setALLOWED_HEX_DELIMETERS;
   
    std::auto_ptr<boost::thread>	m_bstListen;
    bool				m_bListen;

    std::auto_ptr<CAsyncUDPComms>	m_pAsyncComms;
    std::auto_ptr<CSyncUDPComms>	m_pSyncComms;

};

#endif	/* NETWORKDLGUDPTAB_H */

