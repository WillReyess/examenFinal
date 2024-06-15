#include "examenFinalMain.h"
#include "AgregarClienteMain.h"
#include "AgregarCuentasMain.h"
#include "MostrarDetallesCuenta.h"
#include "Cliente.h"

BEGIN_EVENT_TABLE(examenFinalFrame, wxFrame)
    EVT_BUTTON(1012, examenFinalFrame::onClickAgregarClientes)
    EVT_BUTTON(1013, examenFinalFrame::onClickAgregarCuentas)
    EVT_BUTTON(1014, examenFinalFrame::onClickMostrarDetallesCuenta)
    EVT_BUTTON(1015, examenFinalFrame::onclickSalir)
END_EVENT_TABLE()

examenFinalFrame::examenFinalFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
    /// Crear un sizer para la ventana principal
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    /// Crear un sizer para las imagenes categorizado por filas: fila 1 y 2
    wxBoxSizer *sizerFila1Img = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *sizerFila2Img = new wxBoxSizer(wxHORIZONTAL);

    /// Crear un sizer para los botones categorizado por filas: fila 1 y 2
    wxBoxSizer *sizerFila1Btn = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *sizerFila2Btn = new wxBoxSizer(wxHORIZONTAL);

    ///agregar la imagen al boton
    this->cliente = new wxStaticBitmap(this, 300, wxBitmap(wxImage("C:\\Users\\wilmer\\Documents\\examenFinal\\examenFinal\\imagenes\\Agregar_Ciente.bmp", wxBITMAP_TYPE_BMP).Rescale(225, 100)));
    this->cuenta = new wxStaticBitmap(this, 301, wxBitmap(wxImage("C:\\Users\\wilmer\\Documents\\examenFinal\\examenFinal\\imagenes\\agregarCuenta.bmp", wxBITMAP_TYPE_BMP).Rescale(255,100)));
    this->mostDetall = new wxStaticBitmap(this, 305, wxBitmap(wxImage("C:\\Users\\wilmer\\Documents\\examenFinal\\examenFinal\\imagenes\\mostrarDetalles.bmp", wxBITMAP_TYPE_BMP).Rescale(225,100)));
    this->Salir = new wxStaticBitmap(this, 306, wxBitmap(wxImage("C:\\Users\\wilmer\\Documents\\examenFinal\\examenFinal\\imagenes\\Salir.bmp", wxBITMAP_TYPE_BMP).Rescale(225,100)));

    ///crea los botones y se les asigna el tamaño de fuente
    this->GestionarClientes = new wxButton(this, 1012, "Gestionar Clientes");
    GestionarClientes->SetFont(wxFont(wxFontInfo(15).Italic()));

    this->GestionarCuentas = new wxButton(this, 1013, "Gestionar Cuentas");
    GestionarCuentas->SetFont(wxFont(wxFontInfo(15).Italic()));

    this->mostrarDetalleCuenta = new wxButton(this, 1014, "Mostrar detalles de la cuenta");
    mostrarDetalleCuenta->SetFont(wxFont(wxFontInfo(15).Italic()));

    this->salir = new wxButton(this, 1015, "Salir");
    salir->SetFont(wxFont(wxFontInfo(15).Italic()));

    ///se agregan las imagenes al sizerFila1Img para la primera fila de imagenes
    sizerFila1Img->Add(cliente, wxEXPAND | wxALL, 5);
    sizerFila1Img->AddSpacer(10); ///se agrega un espacio
    sizerFila1Img->Add(cuenta, wxEXPAND | wxALL, 5);


    ///se agregan las imagenes al sizerFila2Img para la segunda fila de imagenes
    sizerFila2Img->Add(mostDetall, wxEXPAND | wxALL, 5);
    sizerFila2Img->Add(Salir, wxEXPAND | wxALL, 5);

    ///se agregan los botones al sizer de la fila uno de botones
    sizerFila1Btn->Add(GestionarClientes, wxEXPAND | wxALL, 5);
    sizerFila1Btn->AddSpacer(10);
    sizerFila1Btn->Add(GestionarCuentas, wxEXPAND | wxALL, 5);


    ///se agregan los botones al sizer de la fila 2 de botones
    sizerFila2Btn->Add(mostrarDetalleCuenta, wxEXPAND | wxALL, 5);
    sizerFila2Btn->AddSpacer(10);
    sizerFila2Btn->Add(salir, wxEXPAND | wxALL, 5);

    /// Agregar el sizer de los botones al sizer principal
    mainSizer->Add(sizerFila1Img, 0, wxEXPAND | wxALL, 10);
    mainSizer->AddSpacer(1);
    mainSizer->Add(sizerFila1Btn, 0, wxEXPAND | wxALL, 10);
    mainSizer->AddSpacer(10);
    mainSizer->Add(sizerFila2Img, 0, wxEXPAND | wxALL, 10);
    mainSizer->AddSpacer(1);
    mainSizer->Add(sizerFila2Btn, 0, wxEXPAND | wxALL, 10);

    /// Establecer el sizer principal
    SetSizerAndFit(mainSizer);

}


examenFinalFrame::~examenFinalFrame()
{
}

void examenFinalFrame::onClickAgregarClientes(wxCommandEvent& event)
{
    agregarClientesDialog *dlg = new agregarClientesDialog(this, "Agregar Clientes", this);
    dlg->SetSize(400,400);
    dlg->ShowModal();

}
void examenFinalFrame::onClickAgregarCuentas(wxCommandEvent& event){
    agregarCuentaDialog *dlg = new agregarCuentaDialog(this, "Agregar Cuenta", this);
    dlg->SetSize(400,400);
    dlg->ShowModal();
}


void examenFinalFrame::onClickMostrarDetallesCuenta(wxCommandEvent& event){
    MostrarDetallesCuentaDialog *dlg =  new MostrarDetallesCuentaDialog(this, "Mostrar detalles de la cuente", this);
    dlg->ShowModal();
}
void examenFinalFrame::onclickSalir(wxCommandEvent &event)
{
    Destroy();
}
int examenFinalFrame::getContadorCliente(){
    return this->contadorCliente;
}
Cliente **examenFinalFrame::getLstCliente(){
    return this->lstCliente;
}
void examenFinalFrame::actualizarContadorCliente(int nuevoContador)
{
    this->contadorCliente = nuevoContador;
}
int examenFinalFrame::getcontadorCuentas()
{
    return this->contadorCuenta;
}
Cuenta **examenFinalFrame::getlstCuenta()
{
    return this->lstCuenta;
}
void examenFinalFrame::actualizarContadorCuenta(int nuevoContador)
{
    this->contadorCuenta = nuevoContador;
}
