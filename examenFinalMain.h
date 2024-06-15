#ifndef EXAMENFINALMAIN_H
#define EXAMENFINALMAIN_H
#include "Cliente.h"
#include "Cuenta.h"
#include <wx/wx.h>

#include "examenFinalApp.h"

class examenFinalFrame: public wxFrame
{
    public:
        examenFinalFrame(wxFrame *frame, const wxString& title);
        ~examenFinalFrame();
        void onClickAgregarClientes(wxCommandEvent& event);
        void onClickAgregarCuentas(wxCommandEvent& event);
        void onClickMostrarDetallesCuenta(wxCommandEvent& event);
        void onclickSalir(wxCommandEvent& event);

        ///se agregan los getters del contador y la lista de clientes
        int getContadorCliente();
        Cliente **getLstCliente();
        void actualizarContadorCliente(int nuevoContador);

        ///se agregan los getter del ccontador y la lista de cuentas
        int getcontadorCuentas();
        Cuenta **getlstCuenta();
        void actualizarContadorCuenta(int nuevoContador);
    protected:


    private:
        ///se agrega el contador y la lista de clientes
        Cliente *lstCliente[5];
        int contadorCliente = 0;

        ///se agrega el contador y la lista de cuentas
        int contadorCuenta = 0;
        Cuenta *lstCuenta[5];

        wxStaticBox* caja1;

        //botones
        wxButton* GestionarClientes;
        wxButton* GestionarCuentas;
        wxButton* mostrarDetalleCuenta;
        wxButton* salir;

        ///crear las imagenes
        wxStaticBitmap *cliente;
        wxStaticBitmap *cuenta;
        wxStaticBitmap *mostDetall;
        wxStaticBitmap *Salir;

        DECLARE_EVENT_TABLE()
};


#endif // EXAMENFINALMAIN_H
