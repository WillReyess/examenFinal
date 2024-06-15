#ifndef AGREGARCUENTASMAIN_H
#define AGREGARCUENTASMAIN_H

#include <wx/wx.h>
#include <wx/button.h>
#include <wx/statline.h>
#include "../../examenFinalMain.h"
class agregarCuentaDialog: public wxDialog
{
    public:
        agregarCuentaDialog(wxWindow *dlg, const wxString& title, examenFinalFrame *frame);
        ~agregarCuentaDialog();
        void onAgregar(wxCommandEvent& event);
        void onHacerAbonos(wxCommandEvent& event);
        void onMostrarListaCuentas(wxCommandEvent& event);
        void onVolver(wxCommandEvent& event);
    protected:

    private:
        examenFinalFrame *examenFrame;
        ///botones
        wxButton* btnAgregarCuenta;
        wxButton* btnHacerAbonos;
        wxButton* btnMostrarListaCuentas ;
        wxButton* btnVolver;
        ///imagen de encabezado
        wxStaticBitmap* cuentaImagen;
        ///texto estatico
        wxStaticText *id;
        wxStaticText *idCuenta;
        ///caja de texto
        wxTextCtrl *ctrlId;
        wxTextCtrl *ctrlIdCuenta;
        DECLARE_EVENT_TABLE()
};
#endif // AGREGARCUENTASMAIN_H
