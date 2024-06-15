#ifndef MOSTARLISTADIALOG_H
#define MOSTARLISTADIALOG_H

#include <wx/wx.h>

#include <wx/button.h>
#include <wx/statline.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include "Cuenta.h"
class MostarListaDialog: public wxDialog
{
    public:
        MostarListaDialog(wxWindow *dlg, const wxString& title, Cuenta **lstCuenta, int contadorCuenta);
        ~MostarListaDialog();

    protected:

    private:
        wxListCtrl* listaCuenta;
        wxStaticText* infoCuenta;

        DECLARE_EVENT_TABLE()
};

#endif // MOSTARLISTADIALOG_H
