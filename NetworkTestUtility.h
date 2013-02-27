/* 
 * File:   NetworkTestUtility.h
 * Author: jarmentrout
 *
 * Created on February 27, 2013, 3:46 PM
 */

#ifndef NETWORKTESTUTILITY_H
#define	NETWORKTESTUTILITY_H

#include <wx/wx.h>

class CNetworkTestUtility : public wxApp
{
public:
    CNetworkTestUtility();
    virtual ~CNetworkTestUtility();
    
    virtual bool OnInit();
    virtual int OnExit();
};

#endif	/* NETWORKTESTUTILITY_H */

