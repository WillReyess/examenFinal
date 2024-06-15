#include "MostrarListaCuentas.h"

BEGIN_EVENT_TABLE(MostrarCuentasDialog, wxDialog)

END_EVENT_TABLE()

MostrarCuentasDialog::MostrarCuentasDialog(wxWindow *dlg, const wxString &title, Cuenta **lstCuenta, int contadorCuenta)
    : wxDialog(dlg, -1, title)
{
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    this->infoCuenta = new wxStaticText(this, 100, "Lista de cuentas", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    infoCuenta->SetFont(wxFont(wxFontInfo(15).Bold().Underlined()));

    this->listaCuenta = new wxListCtrl(this, 1000, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    ///se agregan las columnas
    listaCuenta->InsertColumn(0, "Id cliente");
    listaCuenta->InsertColumn(1, "N° cuenta");
    listaCuenta->InsertColumn(2, "Nombre");
    listaCuenta->InsertColumn(3, "Apellido");
    listaCuenta->InsertColumn(4, "Saldo");

    ///se agregan las dimensiones de las columnas
    listaCuenta->SetColumnWidth(0, 70);
    listaCuenta->SetColumnWidth(1, 70);
    listaCuenta->SetColumnWidth(2, 100);
    listaCuenta->SetColumnWidth(3, 100);
    listaCuenta->SetColumnWidth(4, 70);

    for(int i = 0; i < contadorCuenta; i++){
        Cuenta *cuent = lstCuenta[i];
        long index = listaCuenta->GetItemCount();
        listaCuenta->InsertItem(index, wxString::Format("%ld", cuent->getCliente()->getIdCliente()));
        listaCuenta->SetItem(index, 1, wxString::Format("%ld", cuent->getNumeroCuenta()));
        listaCuenta->SetItem(index, 2, wxString(cuent->getCliente()->getNombre()));
        listaCuenta->SetItem(index, 3, wxString(cuent->getCliente()->getApellido()));
        listaCuenta->SetItem(index, 4, wxString::Format("%.2f", cuent->getSaldo()));
    }

    ///se agregan el texto estatico y la lista de clientes al sizer principal
    mainSizer->Add(infoCuenta, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(listaCuenta, 0, wxEXPAND | wxALL, 10);
    SetSizer(mainSizer);
}


MostrarCuentasDialog::~MostrarCuentasDialog()
{
    //dtor
}
