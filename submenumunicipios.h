#ifndef SUBMENUMUNICIPIOS_H_INCLUDED
#define SUBMENUMUNICIPIOS_H_INCLUDED
void agregarMunicipio(){
ArchivoMunicipio archivo;
Municipio municipio;
int numMuni;
numMuni=archivo.CantRegistros()+1;
do{
    bool SiExiste=archivo.VerifNumMunicipio(numMuni);
    if(SiExiste){
       cout<<"Ya existe un municipio con este numero, porfavor ingrese una opcion valida"<<endl;
       system("pause");
       system("cls");
       cout<<"Ingresar numero de municipio: "<<endl;
       cin>>numMuni;
    }
}while(archivo.VerifNumMunicipio(numMuni));
municipio.setNumeroMunicipio(numMuni);
municipio.Cargar();
if(archivo.GuardarMunicipio(municipio)){
 cout<<"Municipio agregada al archivo"<<endl;
}
else{
 cout<<"Error al agregar Municipio"<<endl;
}
}


void listarMunicipioPorNumero(){
int NumeroMunicipio;
Municipio municipio;
cout<<"Ingresar numero de municipio a Listar"<<endl;
cin>>NumeroMunicipio;
ArchivoMunicipio archivo;
municipio=archivo.BuscarMunicipio(NumeroMunicipio);
if(municipio.getNumeroMunicipio()>0){
    municipio.Mostrar();
}else cout<<"El Municipio no existe"<<endl;
}


void listarTodosLosMunicipios(){
ArchivoMunicipio archivo;
int cant=archivo.CantRegistros();
for(int i=0;i<cant;i++){
Municipio municipio=archivo.ListarMunicipio(i);
municipio.Mostrar();
cout<<"=================="<<endl;
}
}


void modificarCantHabitantes(){
ArchivoMunicipio archivo;
Municipio municipio;
int aux;
int numeroMunicipio;
cout<<"Numero de Municipio a modificar: "<<endl;
cin>>numeroMunicipio;
int pos=archivo.PosicionRegistro(numeroMunicipio);
municipio=archivo.BuscarMunicipio(numeroMunicipio);
if(municipio.getNumeroMunicipio()>0){
    cout<<"Ingresar nuevo valor para cantidad de habitantes: "<<endl;
    cin>>aux;
    municipio.setCantHabitantes(aux);
    if(archivo.ModificarArchivo(municipio,pos)){
    cout<<"Municipio Actualizado"<<endl;
    }
}else{
cout<<"ERROR AL MODIFICAR MUNICIPIO"<<endl;
}
}

void eliminarRegistroMunicipio(){
ArchivoMunicipio archivo;
Municipio municipio;
int numeroMunicipio;
cout<<"Numero de Municipio a Eliminar: "<<endl;
cin>>numeroMunicipio;
int pos=archivo.PosicionRegistro(numeroMunicipio);
municipio=archivo.BuscarMunicipio(numeroMunicipio);
if(municipio.getCantHabitantes()>0){
    municipio.setEstado(false);
    if(archivo.ModificarArchivo(municipio,pos)){
    cout<<"Municipio Dada de Baja :C"<<endl;
    }
}else{
cout<<"MUNICIPIO NO ENCONTRADO"<<endl;
}
}


void menumunicipios()
{
    while (true)
    {
        system("cls");
        cout << "MENU MUNICIPIO" << endl;
        cout << "------------------" << endl;
        cout << "1) AGREGAR MUNICIPIO" << endl;
        cout << "2) LISTAR MUNICIPIO POR NUMERO" << endl;
        cout << "3) LISTAR TODO" << endl;
        cout << "4) MODIFICAR CANTIDAD DE HABITANTES" << endl;
        cout << "5) ELIMINAR REGISTRO" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl;
        int op;
        cout << "INGRESAR OPCION: ";
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            agregarMunicipio();
            break;
        case 2:
            system("cls");
            listarMunicipioPorNumero();
            break;
        case 3:
            system("cls");
            listarTodosLosMunicipios();
            break;
        case 4:
            system("cls");
            modificarCantHabitantes();
            break;
        case 5:
            system("cls");
            eliminarRegistroMunicipio();
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

#endif // SUBMENUMUNICIPIOS_H_INCLUDED
