/* 
 * File:   NetworkTabDialog.cpp
 * Author: jarmentrout
 *
 * Created on March 4, 2013, 9:23 AM
 */

#include "NetworkTabDialog.h"

#include <wx/msgdlg.h>

void CNetworkTabDialog::ErrorMessageBox(const std::string& p_strMessage)
{    
    wxMessageDialog *wxMsgDlg = new wxMessageDialog( this,
                                                    wxT( p_strMessage ),
                                                    wxT("ERROR!"), wxOK | wxICON_ERROR );
    wxMsgDlg->ShowModal();
}