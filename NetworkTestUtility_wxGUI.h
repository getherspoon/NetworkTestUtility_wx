///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NetworkTestUtility_wxGUI__
#define __NetworkTestUtility_wxGUI__

class CNetworkTabDialog;

#include "NetworkTabDialog.h"
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/gbsizer.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/valtext.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class CNetworkTestUtilitiyDlg
///////////////////////////////////////////////////////////////////////////////
class CNetworkTestUtilitiyDlg : public wxDialog 
{
	private:
	
	protected:
		wxButton* m_buttonExit;
	
	public:
		
		CNetworkTestUtilitiyDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 117,80 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CNetworkTestUtilitiyDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CNetworkDlgMulticastTab
///////////////////////////////////////////////////////////////////////////////
class CNetworkDlgMulticastTab : public CNetworkTabDialog
{
	private:
	
	protected:
		wxListBox* m_listBoxRecv;
		wxStaticText* m_staticTextRecv;
		wxButton* m_buttonClearRecv;
		wxStaticText* m_staticTextSent;
		wxButton* m_buttonClearSent;
		wxListBox* m_listBoxSend;
		wxStaticText* m_staticTextSend;
		wxStaticLine* m_staticline2;
		wxTextCtrl* m_textCtrlSend0;
		wxButton* m_buttonSend0;
		wxCheckBox* m_checkBoxSendAsHex0;
		wxTextCtrl* m_textCtrlSend1;
		wxButton* m_buttonSend1;
		wxCheckBox* m_checkBoxSendAsHex1;
		wxStaticText* m_staticTextMulticast;
		wxStaticLine* m_staticline1;
		wxTextCtrl* m_textCtrlMCGroupSend;
		wxTextCtrl* m_textCtrlMCGroupRecv;
		wxStaticText* m_staticTextMCGroupSend;
		wxStaticText* m_staticTextMCGroupRecv;
		wxTextCtrl* m_textCtrlPortSend;
		wxTextCtrl* m_textCtrlPortRecv;
		wxStaticText* m_staticTextPortSend;
		wxStaticText* m_staticTextPortRecv;
		wxButton* m_buttonJoin;
		wxCheckBox* m_checkBoxUseSendForBoth;
		wxCheckBox* m_checkBoxEnableLoopback;
		wxCheckBox* m_checkBoxAsync;
	
	public:
		
		CNetworkDlgMulticastTab( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 694,513 ), long style = wxTAB_TRAVERSAL );
		~CNetworkDlgMulticastTab();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CNetworkDlgUDPTab
///////////////////////////////////////////////////////////////////////////////
class CNetworkDlgUDPTab : public CNetworkTabDialog
{
	private:
	
	protected:
		wxListBox* m_listBoxRecv;
		wxStaticText* m_staticTextRecv;
		wxButton* m_buttonClearRecv;
		wxStaticText* m_staticTextSent;
		wxButton* m_buttonClearSent;
		wxListBox* m_listBoxSend;
		wxStaticText* m_staticTextSend;
		wxStaticLine* m_staticline2;
		wxTextCtrl* m_textCtrlSend0;
		wxButton* m_buttonSend0;
		wxCheckBox* m_checkBoxSendAsHex0;
		wxTextCtrl* m_textCtrlSend1;
		wxButton* m_buttonSend1;
		wxCheckBox* m_checkBoxSendAsHex1;
		wxStaticText* m_staticTextUDP;
		wxStaticLine* m_staticline1;
		wxTextCtrl* m_textCtrlSendToAddress;
		wxStaticText* m_staticTextSendToAddress;
		wxTextCtrl* m_textCtrlSendToPort;
		wxStaticText* m_staticTextSendToPort;
		wxStaticText* m_staticTextLocalListenPort;
		wxTextCtrl* m_textCtrlLocalListeningPort;
		wxButton* m_buttonStart;
		wxCheckBox* m_checkBoxAsync;
	
	public:
		
		CNetworkDlgUDPTab( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 694,467 ), long style = wxTAB_TRAVERSAL );
		~CNetworkDlgUDPTab();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CNetworkDlgTCPClientTab
///////////////////////////////////////////////////////////////////////////////
class CNetworkDlgTCPClientTab : public CNetworkTabDialog
{
	private:
	
	protected:
		wxListBox* m_listBoxRecv;
		wxStaticText* m_staticTextRecv;
		wxButton* m_buttonClearRecv;
		wxStaticText* m_staticTextSent;
		wxButton* m_buttonClearSent;
		wxListBox* m_listBoxSend;
		wxStaticText* m_staticTextSend;
		wxStaticLine* m_staticline2;
		wxTextCtrl* m_textCtrlSend0;
		wxButton* m_buttonSend0;
		wxCheckBox* m_checkBoxSendAsHex0;
		wxTextCtrl* m_textCtrlSend1;
		wxButton* m_buttonSend1;
		wxCheckBox* m_checkBoxSendAsHex1;
		wxStaticText* m_staticTextTCP;
		wxStaticLine* m_staticline1;
		wxTextCtrl* m_textCtrlSendToAddress;
		wxStaticText* m_staticTextServerAddress;
		wxTextCtrl* m_textCtrlSendToPort;
		wxStaticText* m_staticTextServerPort;
		wxButton* m_buttonStart;
		wxCheckBox* m_checkBoxAsync;
	
	public:
		
		CNetworkDlgTCPClientTab( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 694,467 ), long style = wxTAB_TRAVERSAL );
		~CNetworkDlgTCPClientTab();
	
};

#endif //__NetworkTestUtility_wxGUI__
