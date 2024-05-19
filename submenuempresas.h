#ifndef SUBMENUEMPRESAS_H_INCLUDED
#define SUBMENUEMPRESAS_H_INCLUDED


void agregarempresa(){
EmpresaArchivo archivo;
Empresa empresa;
int numEmp;
cout<<"Ingresar numero de empresa: "<<endl;
cin>>numEmp;
do{
    int SiExiste=archivo.VerifNumEmpresa(numEmp);
    if(SiExiste==1){
       cout<<"Ya existe una empresa con este numero, porfavor ingrese una opcion valida"<<endl;
       system("pause");
       system("cls");
       cout<<"Ingresar numero de empresa: "<<endl;
       cin>>numEmp;
    }
    if(SiExiste==2){
        cout<<"Ya existe una empresa con este numero, pero fue dado de baja, ingrese un numero de empresa valido"<<endl;
        system("pause");
        system("cls");
        cout<<"Ingresar numero de empresa: "<<endl;
        cin>>numEmp;
        }
}while(archivo.VerifNumEmpresa(numEmp)==1||archivo.VerifNumEmpresa(numEmp)==2);
empresa.setNumEmp(numEmp);
empresa.Cargar();
if(archivo.GuardarEmpresa(empresa)){
 cout<<"Empresa agregada al archivo"<<endl;
}
else{
 cout<<"Error al agregar Empresa"<<endl;
}
}


void listarEmpresaPorNumero(){
int NumeroEmpresa;
Empresa empresa;
cout<<"Ingresar numero de empresa a Listar"<<endl;
cin>>NumeroEmpresa;
EmpresaArchivo archivo;
empresa=archivo.BuscarEmpresa(NumeroEmpresa);
if(empresa.getCategoria()>0){
   empresa.Mostrar();
}else cout<<"La empresa no existe"<<endl;
}


void listarTodasLasEmpresas(){
EmpresaArchivo archivo;
int cant=archivo.CantRegistros();
for(int i=0;i<cant;i++){
Empresa empresa=archivo.ListarEmpresa(i);
empresa.Mostrar();
cout<<"=================="<<endl;
}
}


void modificarFechaDeCreacion(){
EmpresaArchivo archivo;
Empresa empresa;
Fecha aux;
int numeroEmpresa;
cout<<"Numero de empresa a modificar: "<<endl;
cin>>numeroEmpresa;
int pos=archivo.PosicionRegistro(numeroEmpresa);
empresa=archivo.BuscarEmpresa(numeroEmpresa);
if(empresa.getCategoria()>0){
    cout<<"Ingresar nueva fecha: "<<endl;
    aux.Cargar();
    empresa.setFecha(aux);
    if(archivo.ModificarArchivo(empresa,pos)){
    cout<<"Fecha Actualizada"<<endl;
    }else{
cout<<"EMPRESA NO ENCONTRADA"<<endl;
}
}
}

void eliminarRegistroEmpresa(){
EmpresaArchivo archivo;
Empresa empresa;
int numeroEmpresa;
cout<<"Numero de empresa a Eliminar: "<<endl;
cin>>numeroEmpresa;
int pos=archivo.PosicionRegistro(numeroEmpresa);
empresa=archivo.BuscarEmpresa(numeroEmpresa);
if(empresa.getCategoria()>0){
    empresa.setEstado(false);
    if(archivo.ModificarArchivo(empresa,pos)){
    cout<<"Empresa Dada de Baja :C"<<endl;
    }
}else{
cout<<"EMPRESA NO ENCONTRADA"<<endl;
}
}

void menuempresas(){
    while (true)
    {
        system("cls");
        cout << "MENU EMPRESAS" << endl;
        cout << "------------------" << endl;
        cout << "1) AGREGAR EMPRESA" << endl;
        cout << "2) LISTAR EMPRESA POR NUMERO" << endl;
        cout << "3) LISTAR TODAS LAS EMPRESAS" << endl;
        cout << "4) MODIFICAR FECHA DE CREACION" << endl;
        cout << "5) ELIMINAR REGISTRO" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) SALIR" << endl;
        int op;
        cout << "INGRESAR OPCION: ";
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            agregarempresa();
            break;
        case 2:
            system("cls");
            listarEmpresaPorNumero();
            break;
        case 3:
            system("cls");
            listarTodasLasEmpresas();
            break;
        case 4:
            system("cls");
            modificarFechaDeCreacion();
            break;
        case 5:
            system("cls");
            eliminarRegistroEmpresa();
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

#endif // SUBMENUEMPRESAS_H_INCLUDED
