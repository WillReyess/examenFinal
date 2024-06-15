#include "HacerAbonos.h"
#include "Abono.h"
#include "Fecha.h"

BEGIN_EVENT_TABLE(HacerAbonosDialog, wxDialog)
    EVT_BUTTON(300, HacerAbonosDialog::onClickPagar)
    EVT_BUTTON(301, HacerAbonosDialog::onClickVolver)
END_EVENT_TABLE()

HacerAbonosDialog::HacerAbonosDialog(wxDialog *dlg, const wxString &title, examenFinalFrame *frame)
    : wxDialog(dlg, -1, title),  examenFrame(frame)
{
    ///cajas de texto
    this->hacerPagos = new wxStaticText(this, 100, "HACER ABONO", wxPoint(40, 10), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    hacerPagos->SetFont(wxFont(wxFontInfo(20).Italic()));

    this->numCuenta = new wxStaticText(this, 101, "N° Cuenta", wxPoint(30, 60), wxDefaultSize);
    numCuenta->SetFont(wxFont(wxFontInfo(15).Bold()));

    this->monto = new wxStaticText(this, 102, "Monto", wxPoint(30,100), wxDefaultSize);
    monto->SetFont(wxFont(wxFontInfo(15).Bold()));

    this->fechaPago = new wxStaticText(this, 103, "Fecha de pago", wxPoint(30, 140), wxDefaultSize);
    fechaPago->SetFont(wxFont(wxFontInfo(15).Bold()));

    ////controles de texto
    this->ctrlNumcuenta = new wxTextCtrl(this, 200, "", wxPoint(210, 60), wxSize(115, 30));
    ctrlNumcuenta->SetFont(wxFont(wxFontInfo(12)));

    this->ctrlmonto = new wxTextCtrl(this, 201, "", wxPoint(210, 100), wxSize(115, 30));
    ctrlmonto->SetFont(wxFont(wxFontInfo(12)));

    this->fecha = new wxDatePickerCtrl(this, 102, wxDefaultDateTime, wxPoint(210, 140), wxSize(115,30), wxDP_DROPDOWN | wxDP_SHOWCENTURY);
    fecha->SetFont(wxFont(wxFontInfo(12)));

    ///botones
    this->btnPagar = new wxButton(this, 300, "Pagar", wxPoint(40, 180), wxSize(115,40));
    btnPagar->SetFont(wxFont(wxFontInfo(15).Italic()));

    this->btnVolver = new wxButton(this, 301, "Volver", wxPoint(225, 180), wxSize(115,40));
    btnVolver->SetFont(wxFont(wxFontInfo(15).Italic()));
}


HacerAbonosDialog::~HacerAbonosDialog()
{
}
void HacerAbonosDialog::onClickPagar(wxCommandEvent &event)
{
    /// se obtien el numero de cuenta y el monto
    wxString numCuenta = this->ctrlNumcuenta->GetValue();
    wxString monto = this->ctrlmonto->GetValue();


    /// Intentar convertir el numero de cuenta y el monto a entero y flotante respectivamente
    long numCuent;
    double mont;
    if (!numCuenta.ToLong(&numCuent) || !monto.ToDouble(&mont)) { // Si la conversión falla
        wxMessageBox("número de cuenta o monto no válidos (número entero)", "Error");
        ///Limpiar los controles de texto
        this->ctrlNumcuenta->Clear();
        this->ctrlmonto->Clear();
        return;
    }

    ///se obtiene la fecha
    wxDateTime fechaseleccionada = this->fecha->GetValue();

    ///se obtiene los valores de la fecha (dia, mes, anio) individual y se asigna a sus respectivas variables
    int dia = fechaseleccionada.GetDay();
    int mes = fechaseleccionada.GetMonth() + 1; ///se agrega un +1 por que al igual que nos arreglos los meses comienzan desde 0
    int anio = fechaseleccionada.GetYear();

    ///se asignan los valores a al objeto de la clase fecha
    Fecha *fecha = new Fecha(dia, mes, anio);

    ///se busca la cuenta en la lista de cuentas
    bool cuentaEncontrada = false;
    Cuenta *cuent = NULL;
    for (int i = 0; i < examenFrame->getcontadorCuentas(); ++i) {
        if (examenFrame->getlstCuenta()[i]->getNumeroCuenta() == numCuent) {
            cuent = examenFrame->getlstCuenta()[i];
            cuentaEncontrada = true;
            break;
        }
    }
    ///si la cuenta fue encontrada
    if(cuentaEncontrada){
        Abono *abono = new Abono(fecha, mont);
        cuent->agregarAbono(abono);

        // Mostrar un mensaje de éxito
        wxString mensaje = wxString::Format("Pago agregado con éxito");
        wxMessageBox(mensaje, "Éxito");
    }else{
        wxMessageBox("Error, Cuenta no encontrado");
    }
}
void HacerAbonosDialog::onClickVolver(wxCommandEvent &event)
{
    Destroy();
}
