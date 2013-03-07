/* 
 * File:   NetworkTestUtilitiyDlg.cpp
 * Author: jarmentrout
 *
 * Created on February 28, 2013, 2:19 PM
 */

#include "NetworkTestUtilityDlg.h"

#include "NetworkTabDialog.h"
#include "NetworkPane_Multicast.h"
#include "NetworkPane_UDP.h"
#include "NetworkDlgTCPClientTab.h"

#include <memory>

CNetworkTestUtilityDlg::CNetworkTestUtilityDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style )
:
CNetworkTestUtilityDlg_wxGUI( parent, id, title, pos, size, style ),
m_lCurrentTab( 0 )
{
        this->m_tabNetworkCtrl.reset( new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT ) );
        
        this->m_mapNetworkTabs[ CNetworkTestUtilityDlg::TAB_MULTICAST ]	= new CNetworkTabDialog( this->m_tabNetworkCtrl.get() );        
        this->m_mapNetworkTabs[ CNetworkTestUtilityDlg::TAB_UDP ]	= new CNetworkTabDialog( this->m_tabNetworkCtrl.get() );
        //this->m_mapNetworkTabs[ CNetworkTestUtilityDlg::TAB_TCPCLIENT ]	= new CNetworkDlgTCPClientTab( this->m_tabNetworkCtrl.get() );
        
        boost::shared_ptr<CNetworkPane_Multicast> pMCPanel( new CNetworkPane_Multicast( this->m_mapNetworkTabs[ CNetworkTestUtilityDlg::TAB_MULTICAST ] ) );
        this->m_mapNetworkTabs[ CNetworkTestUtilityDlg::TAB_MULTICAST ]->SetNetworkPanel( pMCPanel );
        
        boost::shared_ptr<CNetworkPane_UDP> pUDPPanel( new CNetworkPane_UDP( this->m_mapNetworkTabs[ CNetworkTestUtilityDlg::TAB_UDP ] ) );
        this->m_mapNetworkTabs[ CNetworkTestUtilityDlg::TAB_UDP ]->SetNetworkPanel( pUDPPanel );
        
     
        // The enum type: NetworkTabType will define the order in which the tabs are created
        // and displayed
        for( int i = 0; i < (int)CNetworkTestUtilityDlg::TAB_COUNT; i++ )
        {
                CNetworkTestUtilityDlg::NetworkTabMapType::iterator it = this->m_mapNetworkTabs.find( (CNetworkTestUtilityDlg::NetworkTabType)i );
                if( ( it != this->m_mapNetworkTabs.end() ) &&
                    ( this->m_tabNetworkCtrl.get() ) )
                {
                        this->m_tabNetworkCtrl->AddPage( it->second, it->second->GetTabTitle() );
                }
        }
        wxObject* userData = NULL;
        ((wxBoxSizer*)this->GetSizer())->Insert( 0, (wxWindow*)m_tabNetworkCtrl.get(), 1, wxEXPAND | wxALL | wxALIGN_CENTER | wxALIGN_TOP, 5, userData );      
        this->GetSizer()->Show((wxWindow*)m_tabNetworkCtrl.get() );
        this->GetSizer()->Layout();        
        this->GetSizer()->Fit( this );
}

CNetworkTestUtilityDlg::~CNetworkTestUtilityDlg()
{

}