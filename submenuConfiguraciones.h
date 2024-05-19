#ifndef SUBMENUCONFIGURACIONES_H_INCLUDED
#define SUBMENUCONFIGURACIONES_H_INCLUDED

void copiadeseguridadArchivoEmpresas(){
 EmpresaArchivo archivo;
 if(archivo.CopiaSeguridad()){
    cout<<"COPIA DE SEGURIDAD COMPLETADA"<<endl;
 }else{cout<<"ERROR DURANTE LA COPIA DE SEGURIDAD"<<endl;}
}

void copiadeseguridadArchivoMunicipio(){
 ArchivoMunicipio archivo;
 if(archivo.CopiaSeguridad()){
    cout<<"COPIA DE SEGURIDAD COMPLETADA"<<endl;
 }else{cout<<"ERROR DURANTE LA COPIA DE SEGURIDAD"<<endl;}
}

void RestaurarArchivoEmpresas(){
cout<<"¿Estas seguro de Reenplazar los registros actuales con la copia de segurirad(1=SI,2=NO)?"<<endl;
int op;
EmpresaArchivo archivo;
cin>>op;
if(op==1){
    if(archivo.UsarCopiaSeguridad()){
        cout<<"Los registros han sido restaurados a la copia mas reciente"<<endl;
    }
}else{
return;
}
}

void RestaurarArchivoMunicipios(){
cout<<"¿Estas seguro de Reenplazar los registros actuales con la copia de segurirad(1=SI,2=NO)?"<<endl;
int op;
ArchivoMunicipio archivo;
cin>>op;
if(op==1){
    if(archivo.UsarCopiaSeguridad()){
        cout<<"Los registros han sido restaurados a la copia mas reciente"<<endl;
    }
}else{
return;
}
}

void EstablecerDatosDeInicio(){
   ArchivoMunicipio archimunicipio;
   EmpresaArchivo archiempresa;
   if(archiempresa.RestaurarDatosInicio()){
    cout<<"Datos de Inicio EMPRESAS restaurados"<<endl;
   }
   if(archimunicipio.RestaurarDatosInicio()){
    cout<<"Datos de Inicio MUNICIPIOS restaurados"<<endl;
   }
}


void menuconfiguracion()
{
    while (true)
    {
        system("cls");
        cout << "MENU CONFIGURACION" << endl;
        cout << "------------------" << endl;
        cout << "1) COPIA DE SEGURIDAD DEL ARCHIVO DE EMPRESAS" << endl;
        cout << "2) COPIA DE SEGURIDAD DEL ARCHIVO DE MUNICIPIOS" << endl;
        cout << "3) RESTAURAR EL ARCHIVO DE EMPRESAS" << endl;
        cout << "4) RESTAURAR EL ARCHIVO DE MUNICIPIOS" << endl;
        cout << "5) ESTABLECER DATOS DE INICIO" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl;
        int op;
        cout << "INGRESAR OPCION: ";
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            copiadeseguridadArchivoEmpresas();
            break;
        case 2:
            system("cls");
            copiadeseguridadArchivoMunicipio();
            break;
        case 3:
            RestaurarArchivoEmpresas();
            break;
        case 4:
            RestaurarArchivoMunicipios();
            break;
        case 5:
             EstablecerDatosDeInicio();
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

#endif // SUBMENUCONFIGURACIONES_H_INCLUDED
