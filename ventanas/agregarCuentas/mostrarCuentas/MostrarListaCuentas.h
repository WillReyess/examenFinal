#ifndef MOSTRARLISTACUENTAS_H
#define MOSTRARLISTACUENTAS_H

#include <wx/wx.h>

#include <wx/button.h>
#include <wx/statline.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include "Cuenta.h"
class MostrarCuentasDialog: public wxDialog
{
    public:
        MostrarCuentasDialog(wxWindow *dlg, const wxString& title, Cuenta **lstCuenta, int contadorCuenta);
        ~MostrarCuentasDialog();

    protected:

    private:
        wxListCtrl* listaCuenta;
        wxStaticText* infoCuenta;

        DECLARE_EVENT_TABLE()
};

#endif // MOSTRARLISTACUENTAS_H
