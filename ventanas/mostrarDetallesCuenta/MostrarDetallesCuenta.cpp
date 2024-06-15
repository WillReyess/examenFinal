#include "MostrarDetallesCuenta.h"
#include "MostarListaDialog.h"
BEGIN_EVENT_TABLE(MostrarDetallesCuentaDialog, wxDialog)
    EVT_BUTTON(301, MostrarDetallesCuentaDialog::onClickBuscar)
    EVT_BUTTON(302, MostrarDetallesCuentaDialog::onclickVolver)
END_EVENT_TABLE()

MostrarDetallesCuentaDialog::MostrarDetallesCuentaDialog(wxWindow *dlg, const wxString &title,  examenFinalFrame *frame)
    : wxDialog(dlg, -1, title), examenFrame(frame)
{
    ///texto estatico
    this->mostrarDetallesCuenta = new wxStaticText(this, 100, "BUSCAR CUENTA", wxPoint(100, 10), wxDefaultSize, wxALIGN_CENTRE);
    mostrarDetallesCuenta->SetFont(wxFont(wxFontInfo(15).Bold()));

    this->numCuenta = new wxStaticText(this, 101, "N° Cuenta", wxPoint(40, 70), wxDefaultSize);
    numCuenta->SetFont(wxFont(wxFontInfo(12).Bold()));

    ///controles de texto
    this->ctrlNumCuenta = new wxTextCtrl(this, 102, "", wxPoint(200, 70), wxDefaultSize);
    ctrlNumCuenta->SetFont(wxFont(wxFontInfo(12).Bold()));

    ///botones
    this->btnBuscar = new wxButton(this, 301, "Buscar", wxPoint(30, 120), wxSize(115,40));
    btnBuscar->SetFont(wxFont(wxFontInfo(15).Italic()));

    this->btnVolver = new wxButton(this, 302, "Volver", wxPoint(200, 120), wxSize(115,40));
    btnVolver->SetFont(wxFont(wxFontInfo(15).Italic()));

}


MostrarDetallesCuentaDialog::~MostrarDetallesCuentaDialog()
{
}

void MostrarDetallesCuentaDialog::onClickBuscar(wxCommandEvent &event)
{
    /// se obtie el numero de cuenta
    wxString numCuenta = this->ctrlNumCuenta->GetValue();

    /// Intentar convertir el numero de cuenta a entero
    long numCuent;
    if (!numCuenta.ToLong(&numCuent)) { // Si la conversión falla
        wxMessageBox("número de cuenta es inválido (número entero)", "Error");
        ///Limpiar los controles de texto
        this->ctrlNumCuenta->Clear();
        return;
    }

    ///se busca la cuenta en la lista de cuentas
    bool cuentaEncontrada = false;
    for (int i = 0; i < examenFrame->getcontadorCuentas(); ++i) {
        if (examenFrame->getlstCuenta()[i]->getNumeroCuenta() == numCuent) {
            cuentaEncontrada = true;
            break;
        }
    }
    ///si la cuenta fue encontrada
    if(cuentaEncontrada){
        MostarListaDialog *dlg = new MostarListaDialog(this, "detalles de la cuenta", examenFrame->getlstCuenta(), examenFrame->getcontadorCuentas());
        dlg->SetSize(500,400);
        dlg->ShowModal();
    }else{
        wxMessageBox("cuenta no encontrada", "Error");
    }

}
void MostrarDetallesCuentaDialog::onclickVolver(wxCommandEvent &event)
{
    Destroy();
}

