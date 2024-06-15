#include "AgregarClienteMain.h"
#include "MostrarClientes.h"
#include <string>
#include "Cliente.h"
using namespace std;

BEGIN_EVENT_TABLE(agregarClientesDialog, wxDialog)
    EVT_CLOSE(agregarClientesDialog::OnClose)
    EVT_BUTTON(3000, agregarClientesDialog::onGuardar)
    EVT_BUTTON(3100, agregarClientesDialog::onMostrarLista)
END_EVENT_TABLE()

agregarClientesDialog::agregarClientesDialog(wxWindow *dlg, const wxString &title, examenFinalFrame *frame)
    : wxDialog(dlg, -1, title), examenFrame(frame)
{
    wxBoxSizer *mainsizer = new wxBoxSizer(wxVERTICAL);

    this->clienteInfo = new wxStaticBitmap(this, 300, wxBitmap(wxImage("C:\\Users\\wilmer\\Documents\\examenFinal\\examenFinal\\imagenes\\cliente.bmp", wxBITMAP_TYPE_BMP).Rescale(225, 100)));

    ///se crean los textos estaticos
    this->id = new wxStaticText(this, 1000, "ID", wxPoint(50, 150), wxDefaultSize);
    id->SetFont(wxFont(wxFontInfo(15).Bold()));

    this->nombre = new wxStaticText(this, 1000, "Nombre", wxPoint(50, 190), wxDefaultSize);
    nombre->SetFont(wxFont(wxFontInfo(15).Bold()));

    this->apellido = new wxStaticText(this, 1000, "apellido", wxPoint(50, 230), wxDefaultSize);
    apellido->SetFont(wxFont(wxFontInfo(15).Bold()));

    ///se crean las cajas de texto
    this->ctrlId = new wxTextCtrl(this, 2000, "", wxPoint(215, 150), wxSize(115,30));
    this->ctrlNombre = new wxTextCtrl(this, 2000, "", wxPoint(215,190), wxSize(115, 30));
    this->ctrlApellido = new wxTextCtrl(this, 2000, "", wxPoint(215, 230), wxSize(115,30));

    ///se crean los botones
    this->btnGuardar = new wxButton(this, 3000, "Guardar", wxPoint(30, 280), wxSize(115,40));
    btnGuardar->SetFont(wxFont(wxFontInfo(15).Italic()));
    this->btnMostrarLista = new wxButton(this, 3100, "Lista de clientes", wxPoint(200, 280), wxSize(175,40));
    btnMostrarLista->SetFont(wxFont(wxFontInfo(15).Italic()));

    mainsizer->Add(clienteInfo, 0, wxEXPAND | wxALL, 10);

    SetSizer(mainsizer);
}


agregarClientesDialog::~agregarClientesDialog()
{
}


void agregarClientesDialog::onGuardar(wxCommandEvent& event)
{

    // Obtener el ID, nombre y apellido de las cajas de texto
    wxString id = this->ctrlId->GetValue();
    wxString nombre = this->ctrlNombre->GetValue();
    wxString apellido = this->ctrlApellido->GetValue();

    // Intentar convertir el ID a un entero
    long ID;
    if (!id.ToLong(&ID)) { // Si la conversión falla
        wxMessageBox("Por favor ingrese un ID válido (número entero)", "Error");
        // Limpiar las cajas de texto
        this->ctrlId->Clear();
        this->ctrlNombre->Clear();
        this->ctrlApellido->Clear();

        return;
    }

    // Convertir los datos a string
    string nombreStr = nombre.ToStdString();
    string apellidoStr = apellido.ToStdString();



    // Verificar si la lista de clientes aún no está llena
    if (examenFrame->getContadorCliente() < MAXIMO) {
        // Crear un nuevo objeto Cliente
        Cliente *cli = new Cliente(ID, nombreStr, apellidoStr);

        // Agregar el cliente a la lista
        examenFrame->getLstCliente()[examenFrame->getContadorCliente()] = cli;

        // Incrementar el contador de clientes
        examenFrame->actualizarContadorCliente(examenFrame->getContadorCliente() + 1);


        // Limpiar las cajas de texto
        this->ctrlId->Clear();
        this->ctrlNombre->Clear();
        this->ctrlApellido->Clear();

        // Mostrar un mensaje de éxito
        wxString mensaje = wxString::Format("Cliente agregado con éxito:\nID: %ld\nNombre: %s\nApellido: %s", ID, nombre, apellido);
        wxMessageBox(mensaje, "Éxito");

    } else {
        // La lista de clientes está llena
        wxMessageBox("La lista de clientes está llena", "Error");
    }
}

void agregarClientesDialog::onMostrarLista(wxCommandEvent &event)
{

    // se verifica si el contador esta vacio no hay clientes que mostrar
    if (examenFrame->getContadorCliente() == 0) {
        wxMessageBox("La lista de clientes está vacía", "Vacío");
        return;
    }
    //se pasan la lista de cliente y el contador para poder acceder
    MostrarClientesDialog *dlg = new MostrarClientesDialog(this, "Lista de clientes", examenFrame->getLstCliente(), examenFrame->getContadorCliente());
    dlg->ShowModal();
}
void agregarClientesDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}
