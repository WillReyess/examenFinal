#ifndef AGREGARCLIENTEMAIN_
#define AGREGARCLIENTEMAIN_

#include <wx/wx.h>
#include "Cliente.h"
#include "../../examenFinalMain.h"
#define MAXIMO 10


class agregarClientesDialog: public wxDialog
{
    public:
        agregarClientesDialog(wxWindow *dlg, const wxString &title, examenFinalFrame *frame);
        ~agregarClientesDialog();
        void OnClose(wxCloseEvent& event);
        void onGuardar(wxCommandEvent& event);
        void onMostrarLista(wxCommandEvent& event);


    private:
        examenFinalFrame *examenFrame;
        ///se agrega la imagen
        wxStaticBitmap* clienteInfo;
        ///se agrega el texto estatico
        wxStaticText *id;
        wxStaticText *nombre;
        wxStaticText *apellido;

        ///se agregan las cajas de texto
        wxTextCtrl *ctrlId;
        wxTextCtrl *ctrlNombre;
        wxTextCtrl *ctrlApellido;

        ///se agregan los botones
        wxButton *btnMostrarLista;
        wxButton *btnGuardar;


        DECLARE_EVENT_TABLE()
};

#endif // AGREGARCLIENTEMAIN_
