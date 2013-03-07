#include "stdafx.h"
#include "NetworkPanel_Base.h"

#include "NetworkTabDialog.h"

void CNetworkPanel_Base::ErrorMessageBox( const std::string& p_strMessage )
{
    if( this->m_pParent )
    {
        this->m_pParent->ErrorMessageBox( p_strMessage );
    }
}
