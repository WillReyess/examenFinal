#ifndef MOSTRARCLIENTES_H
#define MOSTRARCLIENTES_H

#include <wx/wx.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/listctrl.h>
#include "Cliente.h"

class MostrarClientesDialog: public wxDialog
{
    public:
        MostrarClientesDialog(wxWindow *dlg, const wxString &title, Cliente **lstCliente, int contador);
        ~MostrarClientesDialog();
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
    protected:

    private:
        wxButton* BtnQuit;
        wxListCtrl* listaClientes;
        wxStaticText* infoCliente;
        DECLARE_EVENT_TABLE()
};
#endif // MOSTRARCLIENTES_H
