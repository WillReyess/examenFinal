#ifndef HACERABONOS_H
#define HACERABONOS_H

#include <wx/wx.h>
#include "Cuenta.h"
#include "AgregarCuentasMain.h"

#include <wx/button.h>
#include <wx/statline.h>
#include <wx/datectrl.h>
class HacerAbonosDialog: public wxDialog
{
    public:
        HacerAbonosDialog(wxDialog *dlg, const wxString& title, examenFinalFrame *frame);
        ~HacerAbonosDialog();
        void onClickPagar(wxCommandEvent &event);
        void onClickVolver(wxCommandEvent &event);

    protected:

    private:
        examenFinalFrame *examenFrame;
        ///texto estatico
        wxStaticText *hacerPagos;
        wxStaticText *numCuenta;
        wxStaticText *monto;
        wxStaticText *fechaPago;

        ///control de texto
        wxTextCtrl *ctrlNumcuenta;
        wxTextCtrl *ctrlmonto;
        wxDatePickerCtrl *fecha;

        ///botones
        wxButton *btnPagar;
        wxButton *btnVolver;

        DECLARE_EVENT_TABLE()
};

#endif // HACERABONOS_H
