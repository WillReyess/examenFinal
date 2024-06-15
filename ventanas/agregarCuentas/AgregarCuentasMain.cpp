#include "AgregarCuentasMain.h"
#include "HacerAbonos.h"
#include "MostrarListaCuentas.h"

#define MAXIMO 5
#include "Cuenta.h"

BEGIN_EVENT_TABLE(agregarCuentaDialog, wxDialog)
    EVT_BUTTON(1000, agregarCuentaDialog::onAgregar)
    EVT_BUTTON(1001, agregarCuentaDialog::onHacerAbonos)
    EVT_BUTTON(1002, agregarCuentaDialog::onMostrarListaCuentas)
    EVT_BUTTON(1003, agregarCuentaDialog::onVolver)
END_EVENT_TABLE()

agregarCuentaDialog::agregarCuentaDialog(wxWindow *dlg, const wxString &title, examenFinalFrame *frame)
    : wxDialog(dlg, -1, title), examenFrame(frame)
{
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    this->cuentaImagen = new wxStaticBitmap(this, 300, wxBitmap(wxImage("C:\\Users\\wilmer\\Documents\\examenFinal\\examenFinal\\imagenes\\agregarCuenta.bmp", wxBITMAP_TYPE_BMP).Rescale(225, 100)));

    ///se agregan los textos estaticos
    this->id = new wxStaticText(this, 100, "ID Cliente", wxPoint(70, 125), wxDefaultSize);
    id->SetFont(wxFont(wxFontInfo(15).Bold()));

    this->idCuenta = new wxStaticText(this, 300, "n° Cuenta", wxPoint(70,175), wxDefaultSize);
    idCuenta->SetFont(wxFont(wxFontInfo(15).Bold()));

    ///se agregan los controles de texto
    this->ctrlId = new wxTextCtrl(this, 200, "", wxPoint(200, 125), wxDefaultSize);
    ctrlId->SetFont(wxFont(wxFontInfo(15)));

    this->ctrlIdCuenta = new wxTextCtrl(this, 400, "", wxPoint(200, 175), wxDefaultSize);
    ctrlIdCuenta ->SetFont(wxFont(wxFontInfo(15)));

    ///se agregan los botones
    this->btnAgregarCuenta = new wxButton(this, 1000, "Agregar Cuenta", wxPoint(20, 230), wxSize(175, 35));
    btnAgregarCuenta->SetFont(wxFont(wxFontInfo(15).Italic().Slant()));

    this->btnHacerAbonos = new wxButton(this, 1001, "Hacer Abonos", wxPoint(225, 230), wxSize(150, 35));
    btnHacerAbonos->SetFont(wxFont(wxFontInfo(15).Italic().Slant()));

    this->btnMostrarListaCuentas = new wxButton(this, 1002, "lista de cuentas", wxPoint(20, 280), wxSize(175, 35));
    btnMostrarListaCuentas->SetFont(wxFont(wxFontInfo(15).Italic().Slant()));

    this->btnVolver = new wxButton(this, 1003, "Volver", wxPoint(225, 280), wxSize(150, 35));
    btnVolver->SetFont(wxFont(wxFontInfo(15).Italic().Slant()));

    SetClientSize(400, 300);

    mainSizer->Add(cuentaImagen, 0, wxEXPAND | wxALL, 10);

    SetSizer(mainSizer);
}


agregarCuentaDialog::~agregarCuentaDialog()
{
}
void agregarCuentaDialog::onHacerAbonos(wxCommandEvent &event)
{
    // se verifica si el contador esta vacio no hay clientes que mostrar
    if (examenFrame->getcontadorCuentas() == 0) {
        wxMessageBox("No hay cuentas para hacer pagos", "Error");
        return;
    }
    //se pasan la lista de cuentas y el contador para poder acceder desde el dialogo
    HacerAbonosDialog *dlg = new HacerAbonosDialog(this, "Hacer pagos", examenFrame);
    dlg->ShowModal();
}

void agregarCuentaDialog::onAgregar(wxCommandEvent &event)
{
    wxString id = this->ctrlId->GetValue();
    wxString numCuenta = this->ctrlIdCuenta->GetValue();

    // Intentar convertir el ID a un entero
    long ID;
    long numCuent;
    if (!id.ToLong(&ID) || !numCuenta.ToLong(&numCuent)) { // Si la conversión falla
        wxMessageBox("Error al agregar la cuenta al cliente (ID o numero de cuenta inválido)");
        // Limpiar las cajas de texto
        this->ctrlId->Clear();
        this->ctrlIdCuenta->Clear();
        return;
    }
    bool clienteEncontrado = false;
    Cliente *cli = NULL;
    for (int i = 0; i < examenFrame->getContadorCliente(); ++i) {
        if (examenFrame->getLstCliente()[i]->getIdCliente() == ID) {
            cli = examenFrame->getLstCliente()[i];
            clienteEncontrado = true;
            break;
        }
    }


    if (clienteEncontrado) {
        // El cliente fue encontrado y se verifica si la lista no esta llena
        // Verificar si la lista de clientes aún no está llena
        if (examenFrame->getcontadorCuentas() < MAXIMO) {
            // Crear un nuevo objeto Cliente
            Cuenta *cuent = new Cuenta(numCuent, cli);

            // Agregar el cliente a la lista
            examenFrame->getlstCuenta()[examenFrame->getcontadorCuentas()] = cuent;

            // Incrementar el contador de clientes
            examenFrame->actualizarContadorCuenta(examenFrame->getcontadorCuentas() + 1);

            ///se limpian los controles de texto
            this->ctrlId->Clear();
            this->ctrlIdCuenta->Clear();

            // Mostrar un mensaje de éxito
            wxString mensaje = wxString::Format("Cliente agregado con éxito");
            wxMessageBox(mensaje, "Éxito");

        } else {
            // La lista de clientes está llena
            wxMessageBox("La lista de clientes está llena", "Error");
        }
    } else {
        wxMessageBox("Error, Cliente no encontrado");
    }
}

void agregarCuentaDialog::onMostrarListaCuentas(wxCommandEvent &event)
{
    ///se verifica si el contador de cuenta esta vacio
    if(examenFrame->getcontadorCuentas() == 0){
        wxMessageBox("La lista de cuentas esta vacía", "Vacío");
        return;
    }
    MostrarCuentasDialog *dlg = new MostrarCuentasDialog(this, "Lista de cuentas", examenFrame->getlstCuenta(), examenFrame->getcontadorCuentas());
    dlg->ShowModal();

}
void agregarCuentaDialog::onVolver(wxCommandEvent &event)
{
    Destroy();
}
