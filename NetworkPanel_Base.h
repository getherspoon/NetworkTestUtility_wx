/* 
 * File:   NetworkDlgBaseTab.h
 * Author: Josh
 *
 * Created on March 6, 2013, 9:51 AM
 */

#ifndef NETWORKDLGBASETAB_H
#define	NETWORKDLGBASETAB_H

#include <boost/system/error_code.hpp>
#include <boost/shared_ptr.hpp>

#include <string>

#include <wx/panel.h>
#include <wx/window.h>

class CNetworkTabDialog;

class CNetworkPanel_Base : public wxPanel
{
public:
    virtual wxString	GetTabTitle() = 0;
    
    virtual bool        SendUserInput( const std::string& p_strToSend, boost::system::error_code& p_bstError ) = 0;
    
protected:
    CNetworkPanel_Base( wxWindow *parent,
                        wxWindowID winid = wxID_ANY,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = wxTAB_TRAVERSAL | wxNO_BORDER,
                        const wxString& name = wxPanelNameStr )
    :
    wxPanel( parent, winid, pos, size, style, name )
    { 
        m_pParent = (CNetworkTabDialog*)parent; 
    }
    virtual ~CNetworkPanel_Base(){} 
    
    void ErrorMessageBox( const std::string& p_strMessage );
    
    CNetworkTabDialog* m_pParent;
};

#endif	/* NETWORKDLGBASETAB_H */

