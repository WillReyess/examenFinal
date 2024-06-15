/***************************************************************
 * Name:      examenFinalApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2024-06-02
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "examenFinalApp.h"
#include "examenFinalMain.h"

IMPLEMENT_APP(examenFinalApp);

bool examenFinalApp::OnInit()
{
    examenFinalFrame* frame = new examenFinalFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
