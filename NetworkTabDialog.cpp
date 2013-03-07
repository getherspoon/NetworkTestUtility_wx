/* 
 * File:   NetworkTabDialog.cpp
 * Author: jarmentrout
 *
 * Created on March 4, 2013, 9:23 AM
 */

#include "stdafx.h"
#include "NetworkTabDialog.h"
#include "NetworkPanel_Base.h"

#include "NetworkPane_Multicast.h"

#include <sstream>

#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>

#include <wx/msgdlg.h>


const CNetworkTabDialog::HexMapType	CNetworkTabDialog::m_s_mapHEX_CHARS = boost::assign::map_list_of
( '0', 0 )( '1', 1 )( '2', 2 )( '3', 3 )( '4', 4 )( '5', 5 )( '6', 6 )( '7', 7 )( '8', 8 )( '9', 9 )
( 'A', 10 )( 'B', 11 )( 'C', 12 )( 'D', 13 )( 'E', 14 )( 'F', 15 )
( 'a', 10 )( 'b', 11 )( 'c', 12 )( 'd', 13 )( 'e', 14 )( 'f', 15 );

const std::set<char> CNetworkTabDialog::m_s_setALLOWED_HEX_DELIMETERS = boost::assign::list_of
( ' ' )( ':' )( '-' );

CNetworkTabDialog::CNetworkTabDialog(wxWindow* parent)
: 
CNetworkTabDialog_wxGUI( parent )
{    
}

void CNetworkTabDialog::SetNetworkPanel( boost::shared_ptr<CNetworkPanel_Base> p_pPanel )
{
    this->m_pNetworkPanel = p_pPanel;
    
    if( this->m_pNetworkPanel.get() )
    {
//        wxBoxSizer* wxBS = (wxBoxSizer*)this->GetSizer();
//        wxObject* userData = NULL;
//        wxBS->Insert( 1, (wxWindow*)this->m_pNetworkPanel.get(), 1, wxALL | wxALIGN_BOTTOM, 5, userData );      
//        this->GetSizer()->Show((wxWindow*)this->m_pNetworkPanel.get() );
//        this->GetSizer()->Layout();        
//        this->GetSizer()->Fit( this );        
        
        wxGridBagSizer* wxGBS = (wxGridBagSizer*)this->m_buttonSend0->GetContainingSizer();
        if( wxGBS )
        {
            wxGBS->Add( (wxPanel*)this->m_pNetworkPanel.get(), wxGBPosition( 11, 0 ), wxGBSpan( 5, 9 ), wxEXPAND | wxALL, 5 );
            wxGBS->Show( (wxPanel*)this->m_pNetworkPanel.get() );
            wxGBS->Layout();
            wxGBS->FitInside( this );
        }
    }
}

wxString CNetworkTabDialog::GetTabTitle()
{
    wxString strResult( "UNKNOWN" );
    if( this->m_pNetworkPanel.get() )
    {
        strResult = this->m_pNetworkPanel->GetTabTitle();
    }
    return strResult;
}

void CNetworkTabDialog::ErrorMessageBox(const std::string& p_strMessage)
{    
    wxMessageDialog *wxMsgDlg = new wxMessageDialog( this,
                                                    wxT( p_strMessage ),
                                                    wxT("ERROR!"), wxOK | wxICON_ERROR );
    wxMsgDlg->ShowModal();
}

void CNetworkTabDialog::AddRecvText( const wxString& p_strValue )
{
    this->m_textCtrlRecvData->AppendText( p_strValue );
}
    
void CNetworkTabDialog::AddSentText( const wxString& p_strValue )
{
    this->m_textCtrlSentData->AppendText( p_strValue );
}

void CNetworkTabDialog::UpdateSendEnable(const bool p_bEnable)
{   
    wxString strTemp( this->m_textCtrlSend0->GetValue() );
    this->m_textCtrlSend0->Enable( p_bEnable );
    this->m_buttonSend0->Enable( p_bEnable && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex0->Enable( p_bEnable );
    
    strTemp = this->m_textCtrlSend1->GetValue();
    this->m_textCtrlSend1->Enable( p_bEnable );
    this->m_buttonSend1->Enable( p_bEnable && !strTemp.IsEmpty() );
    this->m_checkBoxSendAsHex1->Enable( p_bEnable );           
}

void CNetworkTabDialog::OnButtonClick_Send0( wxCommandEvent& event )
{
    this->SendUserInput( 0 );
}

void CNetworkTabDialog::OnButtonClick_Send1( wxCommandEvent& event )
{
    this->SendUserInput( 1 );
}

void CNetworkTabDialog::OnButtonClick_ClearRecvData( wxCommandEvent& event )
{
    this->m_textCtrlRecvData->Clear();
}

void CNetworkTabDialog::OnButtonClick_ClearSentData( wxCommandEvent& event )
{
    this->m_textCtrlSentData->Clear();
}

void CNetworkTabDialog::OnText_Send0( wxCommandEvent& event )
{    
    if( this->m_checkBoxSendAsHex0->GetValue() &&
        this->EditBoxInvalid( 0 ) )
    {
        this->m_buttonSend0->Enable( false );
    }	
    else
    {
        wxString strTemp = this->m_textCtrlSend0->GetValue();            
        this->m_buttonSend0->Enable( !strTemp.IsEmpty() );
    }		    
}

void CNetworkTabDialog::OnText_Send1( wxCommandEvent& event )
{
    if( this->m_checkBoxSendAsHex1->GetValue() &&
        this->EditBoxInvalid( 1 ) )
    {
        this->m_buttonSend1->Enable( false );
    }	
    else
    {
        wxString strTemp = this->m_textCtrlSend1->GetValue();            
        this->m_buttonSend1->Enable( !strTemp.IsEmpty() );
    }	
}

void CNetworkTabDialog::SendUserInput( const int p_iInputNumber )
{
    if( p_iInputNumber < this->m_s_iSendCount )
    {
        wxTextCtrl* wxSend =    p_iInputNumber == 0 ? this->m_textCtrlSend0 : 
                                p_iInputNumber == 1 ? this->m_textCtrlSend1 : NULL;
        wxCheckBox* wxCheck=    p_iInputNumber == 0 ? this->m_checkBoxSendAsHex0 : 
                                p_iInputNumber == 1 ? this->m_checkBoxSendAsHex1 : NULL;
        if( wxSend )
        {
            wxString strText = wxSend->GetValue();
            if( !strText.IsEmpty() )
            {
                std::string strSend( strText.mb_str() );
                bool bSendAsHex = ( wxCheck->GetValue() );
                if( bSendAsHex && this->IsValidHexString( strSend ) )
                {
                    // The string must be an even number of characters, so we'll pre-pend a leading 0
                    // if it is not.
                    std::string strHex;				
                    if( strSend.length() % 2 != 0 )
                    {
                        strSend = "0" + strSend;
                    }
                    for( std::string::iterator itSend = strSend.begin(); itSend != strSend.end(); )
                    {
                        try
                        {
                            // Find the first character
                            HexMapType::const_iterator itBit1 = m_s_mapHEX_CHARS.find( *itSend++ );															
                            HexMapType::const_iterator itBit2 = m_s_mapHEX_CHARS.end();
                            if( itSend != strSend.end() )
                            {
                                    itBit2 = m_s_mapHEX_CHARS.find( *itSend++ );
                            }				
                            unsigned int uValue1 = 0;
                            unsigned int uValue2 = 0;
                            if( itBit1 != m_s_mapHEX_CHARS.end() )
                            {
                                    uValue1 = boost::lexical_cast<unsigned int>( itBit1->second );
                            }
                            if( itBit2 != m_s_mapHEX_CHARS.end() )
                            {
                                    uValue2 = boost::lexical_cast<unsigned int>( itBit2->second );
                            }
                            strHex.push_back( ( uValue1 << 4 ) + uValue2 );														
                        }
                        catch( std::exception& ex )
                        {
                                TRACE( "EXCEPTION: %s\n", ex.what() );
                        }
                    }
                    strSend = strHex;                    
                }
                if( this->m_pNetworkPanel.get() )
                {
                    boost::system::error_code bstError;
                    if( !this->m_pNetworkPanel->SendUserInput( strSend, bstError ) )
                    {
                        this->ErrorMessageBox( std::string( "ERROR: " + bstError.message() ) );
                    }
                    if( bSendAsHex )
                    {
                        std::stringstream ss;
                        for( unsigned int i = 0; i < strSend.length(); ++i )
                        {
                            try
                            {
                                unsigned int iSentByte = (unsigned int)strSend[i];
                                unsigned int iFirstNibble = (iSentByte & 0xF0) >> 4;
                                unsigned int iSecondNibble = (iSentByte & 0x0F);

                                bool bFound = false;
                                for( HexMapType::const_iterator it = this->m_s_mapHEX_CHARS.begin();
                                         !bFound && it != this->m_s_mapHEX_CHARS.end(); ++it )
                                {
                                    if( it->second == iFirstNibble )
                                    {
                                            ss << it->first;
                                            bFound = true;
                                    }
                                }

                                bFound = false;
                                for( HexMapType::const_iterator it = this->m_s_mapHEX_CHARS.begin();
                                         !bFound && it != this->m_s_mapHEX_CHARS.end(); ++it )
                                {
                                    if( it->second == iSecondNibble )
                                    {
                                            ss << it->first;
                                            bFound = true;
                                    }
                                }
                            }
                            catch( std::exception& ex )
                            {
                                TRACE( "EXCEPTION: %s\n", ex.what() );
                            }
                        }
                        strSend = "0x" + ss.str();
                    }
                                        
                    strSend.append( "\r\n" );
                    this->m_textCtrlSentData->AppendText( strSend.c_str() );
                }                                        
            }
        }
    }
}


bool CNetworkTabDialog::EditBoxInvalid( int p_iIndex )
{
    bool bResult = false;
    switch ( p_iIndex ) 
    { 
        case 0:
        {
            if( this->m_checkBoxSendAsHex0->GetValue() )
            {
                wxString strText = this->m_textCtrlSend0->GetValue();							
                bResult = !this->IsValidHexString( std::string( strText.mb_str() ) );
            }
            break;
        }
        case 1:
        {
            if( this->m_checkBoxSendAsHex1->GetValue() )
            {
                wxString strText = this->m_textCtrlSend1->GetValue();							
                bResult = !this->IsValidHexString( std::string( strText.mb_str() ) );
            }
            break;
        }		
        default:
        {
                break;
        }
    }		
    return bResult;
}

bool CNetworkTabDialog::IsValidHexString( const std::string& p_strHex )
{
    bool bResult = !p_strHex.empty();
    for( unsigned int i = 0; i < p_strHex.length() && bResult; ++i )
    {
        HexMapType::const_iterator it = this->m_s_mapHEX_CHARS.find( p_strHex.at( i ) );
        if( it == this->m_s_mapHEX_CHARS.end() )
        {
                bResult = false;
        }
    }
    return bResult;
}