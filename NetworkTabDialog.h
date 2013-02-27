/* 
 * File:   NetworkTabDialog.h
 * Author: jarmentrout
 *
 * Created on February 27, 2013, 4:17 PM
 */

#ifndef NETWORKTABDIALOG_H
#define	NETWORKTABDIALOG_H

#include <wx/panel.h>
#include <wx/geometry.h>
#include <wx/window.h>
#include <wx/string.h>

class CNetworkTabDialog : public wxPanel
{
    public:
        CNetworkTabDialog(      wxWindow *parent,
                                int x, int y, int width, int height,
                                long style = wxTAB_TRAVERSAL | wxNO_BORDER,
                                const wxString& name = wxPanelNameStr )
                : wxPanel( parent, x, y, width, height, style, name ) {}
                
        CNetworkTabDialog(      wxWindow *parent,
                                wxWindowID winid = wxID_ANY,
                                const wxPoint& pos = wxDefaultPosition,
                                const wxSize& size = wxDefaultSize,
                                long style = wxTAB_TRAVERSAL | wxNO_BORDER,
                                const wxString& name = wxPanelNameStr )
                : wxPanel( parent, winid, pos, size, style, name ) {}
        virtual ~CNetworkTabDialog() {}
};
#endif	/* NETWORKTABDIALOG_H */

