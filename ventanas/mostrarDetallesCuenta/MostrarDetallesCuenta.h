#ifndef MOSTRARDETALLESCUENTA_H
#define MOSTRARDETALLESCUENTA_H

#include <wx/wx.h>

#include <wx/button.h>
#include <wx/statline.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include "../../examenFinalMain.h"
class MostrarDetallesCuentaDialog: public wxDialog
{
    public:
        MostrarDetallesCuentaDialog(wxWindow *dlg, const wxString& title, examenFinalFrame *frame);
        ~MostrarDetallesCuentaDialog();
        void onClickBuscar(wxCommandEvent& event);
        void onclickVolver(wxCommandEvent& event);
    protected:

    private:
        examenFinalFrame *examenFrame;
        ///texto estatico
        wxStaticText *mostrarDetallesCuenta;
        wxStaticText *numCuenta;

        ///control de texto
        wxTextCtrl *ctrlNumCuenta;

        ///botones
        wxButton *btnBuscar;
        wxButton *btnVolver;

        DECLARE_EVENT_TABLE()
};

#endif // MOSTRARDETALLESCUENTA_H
