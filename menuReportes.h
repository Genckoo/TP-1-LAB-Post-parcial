#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED


void menuReportes(){
    Reportes obj;
    while (true)
    {
        system("cls");
        cout << "MENU EMPRESAS" << endl;
        cout << "------------------" << endl;
        cout << "1 - INFORMAR MUNICIPIO CON MAYOR CANTIDAD DE EMPRESAS" << endl;
        cout << "2 - GENERAR UN NUEVO ARCHIVO CON IMPORTES ANUALES MENOR AL INGRESADO " << endl;
        cout << "--------------------------------" << endl;
        cout << "0) SALIR" << endl;
        int op;
        cout << "INGRESAR OPCION: ";
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            obj.muniMayorEmpresas();
            break;
        case 2:
            system("cls");
            menosFacturacion();
            break;

        case 0:
            return ;
        default:
            system("cls");
            cout << "POR FAVOR INGRESE UNA OPCION VALIDA" << endl;
            break;
        }

        system("pause");
    }

}



#endif // MENUREPORTES_H_INCLUDED
