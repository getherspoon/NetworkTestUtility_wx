/* 
 * File:   NetworkDlgMulticastTab.h
 * Author: jarmentrout
 *
 * Created on February 28, 2013, 2:40 PM
 */

#ifndef NETWORKDLGMULTICASTTAB_H
#define	NETWORKDLGMULTICASTTAB_H

#include "NetworkTestUtility_wxGUI.h"
#include "NetworkTabDialog.h"

#include <map>
#include <memory>
#include <set>

#include <boost/system/error_code.hpp>
#include <boost/thread.hpp>

#include <wx/string.h>

class CAsyncMulticastComms;
class CSyncMulticastComms;


class CNetworkDlgMulticastTab : public CNetworkDlgMulticastTab_wxGUI
{
public:
    CNetworkDlgMulticastTab( wxWindow* parent );
    virtual ~CNetworkDlgMulticastTab();
    
    wxString GetTabTitle()      { return "Multicast";   }
    
    void OnButtonClick_ClearRecv( wxCommandEvent& event );
    void OnButtonClick_ClearSent( wxCommandEvent& event );
    void OnButtonClick_Send0( wxCommandEvent& event );
    void OnButtonClick_Send1( wxCommandEvent& event );
    void OnButtonClick_Join( wxCommandEvent& event );    
    
//    void OnCheckBox_SendAsHex0( wxCommandEvent& event );
//    void OnCheckBox_SendAsHex1( wxCommandEvent& event );
    void OnCheckBox_UseSendForBoth( wxCommandEvent& event );
//    void OnCheckBox_EnableLoopBack( wxCommandEvent& event );
//    void OnCheckBox_Asynchronous( wxCommandEvent& event );
    
protected:
    void ProcessRecvMessage( const std::string& p_strMessage, const std::string& p_strRecvFromAddress, const unsigned int p_usRecvFromPort, const boost::system::error_code& p_bstError );

    void ProcessSendMessage( const std::string& p_strMessage, const boost::system::error_code& p_bstError );

    void SendUserInput( const int p_iInputNumber );

    bool EditBoxInvalid( int p_iIndex );

    bool IsValidHexString( const std::string& p_strHex );

    void SyncListenThread();
    
private:
    typedef	std::map<char,unsigned int>	HexMapType;

    static const int		m_s_iSendCount = 2;
    static const wxString	m_s_strJOIN_TEXT;
    static const wxString	m_s_strUNJOIN_TEXT;
    static const HexMapType	m_s_mapHEX_CHARS;
    static const std::set<char>	m_s_setALLOWED_HEX_DELIMETERS;
    
    std::auto_ptr<boost::thread>		m_bstListen;
    bool					m_bListen;

    std::auto_ptr<CAsyncMulticastComms>		m_pAsyncComms;
    std::auto_ptr<CSyncMulticastComms>		m_pSyncComms;

};

#endif	/* NETWORKDLGMULTICASTTAB_H */

