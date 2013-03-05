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
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/checkbox.h>
#include <wx/valtext.h>
#include <wx/tglbtn.h>
#include <wx/gbsizer.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class CNetworkTestUtilityDlg_wxGUI
///////////////////////////////////////////////////////////////////////////////
class CNetworkTestUtilityDlg_wxGUI : public wxDialog 
{
	private:
	
	protected:
		wxButton* m_buttonExit;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonClick_Exit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CNetworkTestUtilityDlg_wxGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 370,349 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CNetworkTestUtilityDlg_wxGUI();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CNetworkDlgMulticastTab_wxGUI
///////////////////////////////////////////////////////////////////////////////
class CNetworkDlgMulticastTab_wxGUI : public CNetworkTabDialog
{
	private:
	
	protected:
		wxStaticText* m_staticTextRecv;
		wxTextCtrl* m_textCtrlRecvData;
		wxButton* m_buttonClearRecv;
		wxStaticText* m_staticTextSent;
		wxButton* m_buttonClearSent;
		wxTextCtrl* m_textCtrlSentData;
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
		wxToggleButton* m_toggleBtnJoin;
		wxCheckBox* m_checkBoxUseSendForBoth;
		wxCheckBox* m_checkBoxEnableLoopback;
		wxCheckBox* m_checkBoxAsync;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonClick_ClearRecvData( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_ClearSentData( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnText_Send0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_Send0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_SendAsHex0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnText_Send1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_Send1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_SendAsHex1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_Join( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_UseSendForBoth( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_EnableLoopBack( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_Asynchronous( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CNetworkDlgMulticastTab_wxGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 651,635 ), long style = wxTAB_TRAVERSAL );
		~CNetworkDlgMulticastTab_wxGUI();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CNetworkDlgUDPTab_wxGUI
///////////////////////////////////////////////////////////////////////////////
class CNetworkDlgUDPTab_wxGUI : public CNetworkTabDialog
{
	private:
	
	protected:
		wxStaticText* m_staticTextRecv;
		wxButton* m_buttonClearRecv;
		wxStaticText* m_staticTextSent;
		wxButton* m_buttonClearSent;
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
		wxCheckBox* m_checkBoxAsync;
		wxToggleButton* m_toggleBtnListen;
		wxTextCtrl* m_textCtrlRecvData;
		wxTextCtrl* m_textCtrlSentData;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonClick_ClearRecvData( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_ClearSentData( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnText_Send0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_Send0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnText_Send1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_Send1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToggle_Listen( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CNetworkDlgUDPTab_wxGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 694,583 ), long style = wxTAB_TRAVERSAL );
		~CNetworkDlgUDPTab_wxGUI();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CNetworkDlgTCPClientTab_wxGUI
///////////////////////////////////////////////////////////////////////////////
class CNetworkDlgTCPClientTab_wxGUI : public CNetworkTabDialog
{
	private:
	
	protected:
		wxStaticText* m_staticTextRecv;
		wxButton* m_buttonClearRecv;
		wxStaticText* m_staticTextSent;
		wxButton* m_buttonClearSent;
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
		wxCheckBox* m_checkBoxAsync;
		wxToggleButton* m_toggleBtnListen;
		wxTextCtrl* m_textCtrlRecvData;
		wxTextCtrl* m_textCtrlSentData;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonClick_ClearRecvData( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_ClearSentData( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnText_Send0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_Send0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnText_Send1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_Send1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToggle_Listen( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CNetworkDlgTCPClientTab_wxGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 694,588 ), long style = wxTAB_TRAVERSAL );
		~CNetworkDlgTCPClientTab_wxGUI();
	
};

#endif //__NetworkTestUtility_wxGUI__
