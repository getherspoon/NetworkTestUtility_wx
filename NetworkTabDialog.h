/* 
 * File:   NetworkTabDialog.h
 * Author: jarmentrout
 *
 * Created on February 27, 2013, 4:17 PM
 */

#ifndef NETWORKTABDIALOG_H
#define	NETWORKTABDIALOG_H

#include "NetworkTestUtility_wxGUI.h"

#include <map>
#include <set>

#include <boost/shared_ptr.hpp>

#include <wx/window.h>

class CNetworkPanel_Base;

class CNetworkTabDialog : public CNetworkTabDialog_wxGUI
{
public:
    CNetworkTabDialog( wxWindow *parent );
    virtual ~CNetworkTabDialog() {}

    wxString	GetTabTitle();
    
    void SetNetworkPanel( boost::shared_ptr<CNetworkPanel_Base> p_pPanel );

    void ErrorMessageBox( const std::string& p_strMessage );
        
    void OnButtonClick_ClearRecvData( wxCommandEvent& event );
    void OnButtonClick_ClearSentData( wxCommandEvent& event );
    void OnButtonClick_Send0( wxCommandEvent& event );
    void OnButtonClick_Send1( wxCommandEvent& event );
    void OnText_Send0( wxCommandEvent& event );
    void OnText_Send1( wxCommandEvent& event );
    
    void AddRecvText( const wxString& p_strValue );
    
    void AddSentText( const wxString& p_strValue );
    
    void UpdateSendEnable( const bool p_bEnable );
    
    void SendUserInput( const int p_iInputNumber );

    bool EditBoxInvalid( int p_iIndex );

    bool IsValidHexString( const std::string& p_strHex );
    
    typedef	std::map<char,unsigned int>	HexMapType;

    static const int		m_s_iSendCount = 2;
    static const HexMapType	m_s_mapHEX_CHARS;
    static const std::set<char>	m_s_setALLOWED_HEX_DELIMETERS;
          
private:
    
    boost::shared_ptr<CNetworkPanel_Base>       m_pNetworkPanel;
       
    
};
#endif	/* NETWORKTABDIALOG_H */

