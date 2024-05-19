#include <cstring>
#include<string>
#include <iostream>
using namespace std;
#include "ClaseFecha.h"
#include "ClaseEmpresas.h"
#include "ClaseMunicipios.h"
#include "ClaseArchivoEmpresas.h"
#include "ClaseArchivoMunicipios.h"
#include "submenuempresas.h"
#include "submenumunicipios.h"
#include "submenuConfiguraciones.h"
#include "reportes.h"
#include "menuReportes.h"

int main()
{
    while(true)
    {
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"1.MENU EMPRESAS"<<endl;
        cout<<"2.MENU MUNUCIPIOS"<<endl;
        cout<<"3.REPORTES"<<endl;
        cout<<"4.CONFIGURACION"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"0.FIN DEL PROGRAMA"<<endl;
        int op;
        cout<<"INGRESAR OPCION: ";
        cin>>op;
        switch(op)
        {
        case 1:
            menuempresas();
            break;
        case 2:
            menumunicipios();
            break;
        case 3:
            menuReportes();
            break;
        case 4:
            menuconfiguracion();
            break;
        case 0:
            return 0;
            break;
        default:

            system("cls");
            cout<<"POR FAVOR INGRESE UNA OPCION VALIDA"<<endl;

            break;

        }
        system("pause");
    }

}
