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

class CNetworkDlgMulticastTab : public CNetworkDlgMulticastTab_wxGUI
{
public:
    CNetworkDlgMulticastTab( wxWindow* parent );
    virtual ~CNetworkDlgMulticastTab();
    
    wxString GetTabTitle()      { return "Multicast";   }
private:

};

#endif	/* NETWORKDLGMULTICASTTAB_H */

