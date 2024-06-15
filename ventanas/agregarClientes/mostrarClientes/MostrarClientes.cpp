#include "MostrarClientes.h"
#include "AgregarClienteMain.h"

BEGIN_EVENT_TABLE(MostrarClientesDialog, wxDialog)
    EVT_CLOSE(MostrarClientesDialog::OnClose)
END_EVENT_TABLE()

MostrarClientesDialog::MostrarClientesDialog(wxWindow *dlg, const wxString &title, Cliente **lstCliente, int contador)
    : wxDialog(dlg, -1, title)
{
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    this->infoCliente = new wxStaticText(this, 100, "Lista de los clientes", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    infoCliente->SetFont(wxFont(wxFontInfo(15).Bold().Underlined()));

    this->listaClientes = new wxListCtrl(this, 1000, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    listaClientes->InsertColumn(0, "ID");
    listaClientes->InsertColumn(1, "Nombre");
    listaClientes->InsertColumn(2, "Apellido");
    listaClientes->SetColumnWidth(0, 80);
    listaClientes->SetColumnWidth(1, 145);
    listaClientes->SetColumnWidth(2, 145);

    // Iterar sobre la lista de clientes y agregarlos a la lista visual
    for (int i = 0; i < contador; ++i) {
        Cliente *cli = lstCliente[i];
        long index = listaClientes->GetItemCount();
        listaClientes->InsertItem(index, wxString::Format("%ld", cli->getIdCliente()));
        listaClientes->SetItem(index, 1, wxString(cli->getNombre()));
        listaClientes->SetItem(index, 2, wxString(cli->getApellido()));
    }

    mainSizer->Add(infoCliente, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(listaClientes, 0, wxEXPAND | wxALL, 10);
    SetSizer(mainSizer);
}




MostrarClientesDialog::~MostrarClientesDialog()
{
}


void MostrarClientesDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}
