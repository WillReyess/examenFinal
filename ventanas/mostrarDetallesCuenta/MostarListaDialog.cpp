#include "MostarListaDialog.h"
#include "Cuenta.h"

BEGIN_EVENT_TABLE(MostarListaDialog, wxDialog)

END_EVENT_TABLE()

MostarListaDialog::MostarListaDialog(wxWindow *dlg, const wxString &title, Cuenta **lstCuenta, int contadorCuenta)
    : wxDialog(dlg, -1, title)
{
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    this->infoCuenta = new wxStaticText(this, 100, "Detalles de la cuenta", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    infoCuenta->SetFont(wxFont(wxFontInfo(15).Bold().Underlined()));

    this->listaCuenta = new wxListCtrl(this, 1000, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    ///se agregan las columnas
    listaCuenta->InsertColumn(0, "Id cliente");
    listaCuenta->InsertColumn(1, "N° cuenta");
    listaCuenta->InsertColumn(2, "Nombre");
    listaCuenta->InsertColumn(3, "Apellido");
    listaCuenta->InsertColumn(4, "abono");
    listaCuenta->InsertColumn(5, "fecha");

    ///se agregan las dimensiones de las columnas
    listaCuenta->SetColumnWidth(0, 70);
    listaCuenta->SetColumnWidth(1, 70);
    listaCuenta->SetColumnWidth(2, 90);
    listaCuenta->SetColumnWidth(3, 90);
    listaCuenta->SetColumnWidth(4, 70);
    listaCuenta->SetColumnWidth(5, 70);

    for(int i = 0; i < contadorCuenta; i++){
        Cuenta *cuent = lstCuenta[i];
        long index = listaCuenta->GetItemCount();
        listaCuenta->InsertItem(index, wxString::Format("%ld", cuent->getCliente()->getIdCliente()));
        listaCuenta->SetItem(index, 1, wxString::Format("%ld", cuent->getNumeroCuenta()));
        listaCuenta->SetItem(index, 2, wxString(cuent->getCliente()->getNombre()));
        listaCuenta->SetItem(index, 3, wxString(cuent->getCliente()->getApellido()));

        // se obtiene el arreglo de abonos
        Abono **abonos = cuent->getLstAbonos();

        // Recorrer cada abono y agregarlo a la lista
        for(int j = 0; j < cuent->getContadorAbonos(); j++){
            listaCuenta->SetItem(index, 4, wxString::Format("%.2f", abonos[j]->getMontoAbono()));
            listaCuenta->SetItem(index, 5, wxString(abonos[j]->getFechaAbono()->mostrarFecha()));
        }
    }

    ///se agregan el texto estatico y la lista de clientes al sizer principal
    mainSizer->Add(infoCuenta, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(listaCuenta, 0, wxEXPAND | wxALL, 10);
    SetSizer(mainSizer);
}


MostarListaDialog::~MostarListaDialog()
{
}

