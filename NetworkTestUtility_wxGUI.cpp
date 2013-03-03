///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "NetworkTestUtility_wxGUI.h"

///////////////////////////////////////////////////////////////////////////

CNetworkTestUtilityDlg_wxGUI::CNetworkTestUtilityDlg_wxGUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonExit = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_buttonExit, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonExit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkTestUtilityDlg_wxGUI::OnButtonClick_Exit ), NULL, this );
}

CNetworkTestUtilityDlg_wxGUI::~CNetworkTestUtilityDlg_wxGUI()
{
	// Disconnect Events
	m_buttonExit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkTestUtilityDlg_wxGUI::OnButtonClick_Exit ), NULL, this );
	
}

CNetworkDlgMulticastTab_wxGUI::CNetworkDlgMulticastTab_wxGUI( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : CNetworkTabDialog( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_listBoxRecv = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	gbSizer2->Add( m_listBoxRecv, wxGBPosition( 1, 0 ), wxGBSpan( 1, 8 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextRecv = new wxStaticText( this, wxID_ANY, wxT("Received Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRecv->Wrap( -1 );
	gbSizer2->Add( m_staticTextRecv, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonClearRecv = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonClearRecv, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextSent = new wxStaticText( this, wxID_ANY, wxT("Sent Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSent->Wrap( -1 );
	gbSizer2->Add( m_staticTextSent, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonClearSent = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonClearSent, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_listBoxSend = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0|wxHSCROLL|wxVSCROLL ); 
	gbSizer2->Add( m_listBoxSend, wxGBPosition( 3, 0 ), wxGBSpan( 1, 8 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextSend = new wxStaticText( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSend->Wrap( -1 );
	gbSizer2->Add( m_staticTextSend, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer2->Add( m_staticline2, wxGBPosition( 4, 0 ), wxGBSpan( 1, 10 ), wxEXPAND | wxALL, 5 );
	
	m_textCtrlSend0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSend0, wxGBPosition( 6, 0 ), wxGBSpan( 2, 7 ), wxALL|wxEXPAND, 5 );
	
	m_buttonSend0 = new wxButton( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonSend0, wxGBPosition( 6, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxSendAsHex0 = new wxCheckBox( this, wxID_ANY, wxT("Send as Hex"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxSendAsHex0, wxGBPosition( 7, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_textCtrlSend1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSend1, wxGBPosition( 8, 0 ), wxGBSpan( 2, 7 ), wxALL|wxEXPAND, 5 );
	
	m_buttonSend1 = new wxButton( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonSend1, wxGBPosition( 8, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxSendAsHex1 = new wxCheckBox( this, wxID_ANY, wxT("Send As Hex"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxSendAsHex1, wxGBPosition( 9, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextMulticast = new wxStaticText( this, wxID_ANY, wxT("Multicast Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextMulticast->Wrap( -1 );
	gbSizer2->Add( m_staticTextMulticast, wxGBPosition( 11, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer2->Add( m_staticline1, wxGBPosition( 10, 0 ), wxGBSpan( 1, 10 ), wxEXPAND | wxALL, 5 );
	
	m_textCtrlMCGroupSend = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlMCGroupSend, wxGBPosition( 13, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );
	
	m_textCtrlMCGroupRecv = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlMCGroupRecv, wxGBPosition( 15, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextMCGroupSend = new wxStaticText( this, wxID_ANY, wxT("Multicast Group (Send)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextMCGroupSend->Wrap( -1 );
	gbSizer2->Add( m_staticTextMCGroupSend, wxGBPosition( 12, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextMCGroupRecv = new wxStaticText( this, wxID_ANY, wxT("Multicast Group (Recv)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextMCGroupRecv->Wrap( -1 );
	gbSizer2->Add( m_staticTextMCGroupRecv, wxGBPosition( 14, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_textCtrlPortSend = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlPortSend, wxGBPosition( 13, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_textCtrlPortRecv = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlPortRecv, wxGBPosition( 15, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextPortSend = new wxStaticText( this, wxID_ANY, wxT("Port (Send)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPortSend->Wrap( -1 );
	gbSizer2->Add( m_staticTextPortSend, wxGBPosition( 12, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextPortRecv = new wxStaticText( this, wxID_ANY, wxT("Port (Recv)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPortRecv->Wrap( -1 );
	gbSizer2->Add( m_staticTextPortRecv, wxGBPosition( 14, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_toggleBtnJoin = new wxToggleButton( this, wxID_ANY, wxT("Join"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_toggleBtnJoin, wxGBPosition( 15, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxUseSendForBoth = new wxCheckBox( this, wxID_ANY, wxT("Use Send for Both"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxUseSendForBoth, wxGBPosition( 13, 3 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_checkBoxEnableLoopback = new wxCheckBox( this, wxID_ANY, wxT("Enable Loopback"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxEnableLoopback, wxGBPosition( 14, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxAsync = new wxCheckBox( this, wxID_ANY, wxT("Asynchronous"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxAsync, wxGBPosition( 15, 3 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer2->Add( gbSizer2, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	m_buttonClearRecv->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_ClearRecvData ), NULL, this );
	m_buttonClearSent->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_ClearSentData ), NULL, this );
	m_buttonSend0->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_Send0 ), NULL, this );
	m_checkBoxSendAsHex0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_SendAsHex0 ), NULL, this );
	m_buttonSend1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_Send1 ), NULL, this );
	m_checkBoxSendAsHex1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_SendAsHex1 ), NULL, this );
	m_toggleBtnJoin->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_Join ), NULL, this );
	m_checkBoxUseSendForBoth->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_UseSendForBoth ), NULL, this );
	m_checkBoxEnableLoopback->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_EnableLoopBack ), NULL, this );
	m_checkBoxAsync->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_Asynchronous ), NULL, this );
}

CNetworkDlgMulticastTab_wxGUI::~CNetworkDlgMulticastTab_wxGUI()
{
	// Disconnect Events
	m_buttonClearRecv->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_ClearRecvData ), NULL, this );
	m_buttonClearSent->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_ClearSentData ), NULL, this );
	m_buttonSend0->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_Send0 ), NULL, this );
	m_checkBoxSendAsHex0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_SendAsHex0 ), NULL, this );
	m_buttonSend1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_Send1 ), NULL, this );
	m_checkBoxSendAsHex1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_SendAsHex1 ), NULL, this );
	m_toggleBtnJoin->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnButtonClick_Join ), NULL, this );
	m_checkBoxUseSendForBoth->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_UseSendForBoth ), NULL, this );
	m_checkBoxEnableLoopback->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_EnableLoopBack ), NULL, this );
	m_checkBoxAsync->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CNetworkDlgMulticastTab_wxGUI::OnCheckBox_Asynchronous ), NULL, this );
	
}

CNetworkDlgUDPTab_wxGUI::CNetworkDlgUDPTab_wxGUI( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : CNetworkTabDialog( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_listBoxRecv = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	gbSizer2->Add( m_listBoxRecv, wxGBPosition( 1, 0 ), wxGBSpan( 1, 8 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextRecv = new wxStaticText( this, wxID_ANY, wxT("Received Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRecv->Wrap( -1 );
	gbSizer2->Add( m_staticTextRecv, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonClearRecv = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonClearRecv, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextSent = new wxStaticText( this, wxID_ANY, wxT("Sent Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSent->Wrap( -1 );
	gbSizer2->Add( m_staticTextSent, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonClearSent = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonClearSent, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_listBoxSend = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0|wxHSCROLL|wxVSCROLL ); 
	gbSizer2->Add( m_listBoxSend, wxGBPosition( 3, 0 ), wxGBSpan( 1, 8 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextSend = new wxStaticText( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSend->Wrap( -1 );
	gbSizer2->Add( m_staticTextSend, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer2->Add( m_staticline2, wxGBPosition( 4, 0 ), wxGBSpan( 1, 10 ), wxEXPAND | wxALL, 5 );
	
	m_textCtrlSend0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSend0, wxGBPosition( 6, 0 ), wxGBSpan( 2, 7 ), wxALL|wxEXPAND, 5 );
	
	m_buttonSend0 = new wxButton( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonSend0, wxGBPosition( 6, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxSendAsHex0 = new wxCheckBox( this, wxID_ANY, wxT("Send as Hex"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxSendAsHex0, wxGBPosition( 7, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_textCtrlSend1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSend1, wxGBPosition( 8, 0 ), wxGBSpan( 2, 7 ), wxALL|wxEXPAND, 5 );
	
	m_buttonSend1 = new wxButton( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonSend1, wxGBPosition( 8, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxSendAsHex1 = new wxCheckBox( this, wxID_ANY, wxT("Send As Hex"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxSendAsHex1, wxGBPosition( 9, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextUDP = new wxStaticText( this, wxID_ANY, wxT("UDP Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUDP->Wrap( -1 );
	gbSizer2->Add( m_staticTextUDP, wxGBPosition( 11, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer2->Add( m_staticline1, wxGBPosition( 10, 0 ), wxGBSpan( 1, 10 ), wxEXPAND | wxALL, 5 );
	
	m_textCtrlSendToAddress = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSendToAddress, wxGBPosition( 13, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextSendToAddress = new wxStaticText( this, wxID_ANY, wxT("Send To Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSendToAddress->Wrap( -1 );
	gbSizer2->Add( m_staticTextSendToAddress, wxGBPosition( 12, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_textCtrlSendToPort = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSendToPort, wxGBPosition( 13, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextSendToPort = new wxStaticText( this, wxID_ANY, wxT("Send To Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSendToPort->Wrap( -1 );
	gbSizer2->Add( m_staticTextSendToPort, wxGBPosition( 12, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextLocalListenPort = new wxStaticText( this, wxID_ANY, wxT("Local Listening Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLocalListenPort->Wrap( -1 );
	gbSizer2->Add( m_staticTextLocalListenPort, wxGBPosition( 12, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_textCtrlLocalListeningPort = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlLocalListeningPort, wxGBPosition( 13, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_buttonStart = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonStart, wxGBPosition( 13, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxAsync = new wxCheckBox( this, wxID_ANY, wxT("Asynchronous"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxAsync, wxGBPosition( 13, 5 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer2->Add( gbSizer2, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
}

CNetworkDlgUDPTab_wxGUI::~CNetworkDlgUDPTab_wxGUI()
{
}

CNetworkDlgTCPClientTab_wxGUI::CNetworkDlgTCPClientTab_wxGUI( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : CNetworkTabDialog( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_listBoxRecv = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	gbSizer2->Add( m_listBoxRecv, wxGBPosition( 1, 0 ), wxGBSpan( 1, 8 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextRecv = new wxStaticText( this, wxID_ANY, wxT("Received Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRecv->Wrap( -1 );
	gbSizer2->Add( m_staticTextRecv, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonClearRecv = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonClearRecv, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextSent = new wxStaticText( this, wxID_ANY, wxT("Sent Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSent->Wrap( -1 );
	gbSizer2->Add( m_staticTextSent, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonClearSent = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonClearSent, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_listBoxSend = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0|wxHSCROLL|wxVSCROLL ); 
	gbSizer2->Add( m_listBoxSend, wxGBPosition( 3, 0 ), wxGBSpan( 1, 8 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextSend = new wxStaticText( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSend->Wrap( -1 );
	gbSizer2->Add( m_staticTextSend, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer2->Add( m_staticline2, wxGBPosition( 4, 0 ), wxGBSpan( 1, 10 ), wxEXPAND | wxALL, 5 );
	
	m_textCtrlSend0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSend0, wxGBPosition( 6, 0 ), wxGBSpan( 2, 7 ), wxALL|wxEXPAND, 5 );
	
	m_buttonSend0 = new wxButton( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonSend0, wxGBPosition( 6, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxSendAsHex0 = new wxCheckBox( this, wxID_ANY, wxT("Send as Hex"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxSendAsHex0, wxGBPosition( 7, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_textCtrlSend1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSend1, wxGBPosition( 8, 0 ), wxGBSpan( 2, 7 ), wxALL|wxEXPAND, 5 );
	
	m_buttonSend1 = new wxButton( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonSend1, wxGBPosition( 8, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxSendAsHex1 = new wxCheckBox( this, wxID_ANY, wxT("Send As Hex"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxSendAsHex1, wxGBPosition( 9, 7 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextTCP = new wxStaticText( this, wxID_ANY, wxT("TCP Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTCP->Wrap( -1 );
	gbSizer2->Add( m_staticTextTCP, wxGBPosition( 11, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer2->Add( m_staticline1, wxGBPosition( 10, 0 ), wxGBSpan( 1, 10 ), wxEXPAND | wxALL, 5 );
	
	m_textCtrlSendToAddress = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSendToAddress, wxGBPosition( 13, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );
	
	m_staticTextServerAddress = new wxStaticText( this, wxID_ANY, wxT("TCP Server Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextServerAddress->Wrap( -1 );
	gbSizer2->Add( m_staticTextServerAddress, wxGBPosition( 12, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_textCtrlSendToPort = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_textCtrlSendToPort, wxGBPosition( 13, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticTextServerPort = new wxStaticText( this, wxID_ANY, wxT("Server Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextServerPort->Wrap( -1 );
	gbSizer2->Add( m_staticTextServerPort, wxGBPosition( 12, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_buttonStart = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_buttonStart, wxGBPosition( 13, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_checkBoxAsync = new wxCheckBox( this, wxID_ANY, wxT("Asynchronous"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_checkBoxAsync, wxGBPosition( 13, 4 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer2->Add( gbSizer2, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
}

CNetworkDlgTCPClientTab_wxGUI::~CNetworkDlgTCPClientTab_wxGUI()
{
}
