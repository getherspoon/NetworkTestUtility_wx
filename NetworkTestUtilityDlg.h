/* 
 * File:   NetworkTestUtilitiyDlg.h
 * Author: jarmentrout
 *
 * Created on February 28, 2013, 2:19 PM
 */

#ifndef NETWORKTESTUTILITIYDLG_H
#define	NETWORKTESTUTILITIYDLG_H

#include "NetworkTestUtility_wxGUI.h"

#include <map>
#include <memory>

#include <wx/app.h>
#include <wx/notebook.h>

class CNetworkTabDialog;

class CNetworkTestUtilityDlg : public CNetworkTestUtilityDlg_wxGUI
{
    protected:
        enum NetworkTabType
	{
		TAB_MULTICAST		= 0,
		TAB_UDP,
		TAB_TCPCLIENT,
		TAB_COUNT,
		TAB_DEFAULT		= 999
	};

	typedef		std::map< NetworkTabType, CNetworkTabDialog* >	NetworkTabMapType;
        
    public:
        CNetworkTestUtilityDlg(  wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 117,80 ), long style = wxDEFAULT_DIALOG_STYLE );
        virtual ~CNetworkTestUtilityDlg();
        
        void OnClose( wxCloseEvent& event )
        {
            wxCommandEvent ce;
            this->OnButtonClick_Exit( ce );
        }
        void OnButtonClick_Exit( wxCommandEvent& event ) 
        {
            wxTheApp->Exit();
        }
        
        long	m_lCurrentTab;
        
    private:
        std::auto_ptr<wxNotebook>       m_tabNetworkCtrl;
        // Tab dlgs
	NetworkTabMapType               m_mapNetworkTabs;
};

#endif	/* NETWORKTESTUTILITIYDLG_H */

