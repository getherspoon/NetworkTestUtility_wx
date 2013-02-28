/* 
 * File:   main.cpp
 * Author: jarmentrout
 *
 * Created on February 27, 2013, 2:26 PM
 */

#include "NetworkTestUtility.h"
#include "NetworkTestUtilityDlg.h"

#ifdef __WXMAC__
#include <ApplicationServices/ApplicationServices.h>
#endif

IMPLEMENT_APP(CNetworkTestUtility)
/*
 * 
 */

CNetworkTestUtility::CNetworkTestUtility()
{

}

CNetworkTestUtility::~CNetworkTestUtility()
{
    
}

bool CNetworkTestUtility::OnInit()
{
     CNetworkTestUtilityDlg* pFrame = new CNetworkTestUtilityDlg( (wxWindow*) NULL );
      
     pFrame->Show();
     SetTopWindow( pFrame );
    
     return true;
}

int CNetworkTestUtility::OnExit()
{       
    return wxApp::OnExit();
}
