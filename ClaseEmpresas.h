#ifndef CLASEEMPRESAS_H_INCLUDED
#define CLASEEMPRESAS_H_INCLUDED

class Empresa{

private:
    int numEmp;
    char nombre[30];
    int cantEmpleados;
    int numeroMunicipio;
    int categoria;
    Fecha fecha;
    float facturacionAnual;
    bool estado;

    public:
    Empresa(){
    estado=false;
    }
    int getNumEmp(){return numEmp;}
    const char* getNombre(){return nombre;}
    int getCantidadEmpleados(){return cantEmpleados;}
    int getCategoria(){return categoria;}
    int getNumeroMunicipio(){return numeroMunicipio;}
    Fecha getFecha(){return fecha;}
    float getFacturacionAnual(){return facturacionAnual;}
    bool getEstado(){return estado;}
    void setNumEmp(int newEmp){numEmp=newEmp;}
    void setNombre(const char *nom){strcpy(nombre,nom);}
    void setCategoria(int c){categoria=c;}
    void setCantidadEmpleados(int can){cantEmpleados=can;}
    void setNumeroMunicipio(int n){numeroMunicipio=n;}
    void setFecha(Fecha f){fecha=f;}
    void setFacturacion(float fact){facturacionAnual=fact;}
    void setEstado(bool e){estado=e;}
    void Cargar();
    void Mostrar();

};

void Empresa::Cargar(){
cin.ignore();
cout << "Ingrese nombre: ";
cargarCadena(nombre,30);
cout<<"Cantidad de empleados: "<<endl;
cin>>cantEmpleados;
while(cantEmpleados<0){
    cout<<"La cantidad de Empleados no es valida, vuelva a intentarlo"<<endl;
    cout<<"Cantidad de empleados: "<<endl;
    cin>>cantEmpleados;
}
cout<<"Numero de municipio(1 a 135): "<<endl;
cin>>numeroMunicipio;
while(numeroMunicipio<=0||numeroMunicipio>135){
    cout<<"El numero de municipio no es valido, vuelva a intentarlo"<<endl;
    cout<<"Numero de municipio(1 a 135): "<<endl;
    cin>>numeroMunicipio;
}
cout<<"Categoria(1 a 80): "<<endl;
cin>>categoria;
while(categoria<=0||categoria>80){
    cout<<"El numero de Categoria no es valido, vuelva a intentarlo"<<endl;
    cout<<"Numero de Categoria(1 a 80): "<<endl;
    cin>>categoria;
}
cout<<"Fecha de creacion: "<<endl;
fecha.Cargar();
cout<<"Facturacion anual: "<<endl;
cin>>facturacionAnual;
estado=true;
}

void Empresa::Mostrar(){
 if(estado==true){
cout<<"Numero de empresa: "<< numEmp<<endl;
cout<<"Nombre de empresa: "<<nombre<<endl;
cout<<"Cantidad de empleados: "<<cantEmpleados<<endl;
cout<<"Numero de municipio: "<<numeroMunicipio<<endl;
cout<<"Categoria: "<<categoria<<endl;
cout<<"Fecha de creacion: ";
fecha.Mostrar();
cout<<endl;
cout<<"Facturacion anual: "<<facturacionAnual<<endl;
}
}

#endif // CLASEEMPRESAS_H_INCLUDED
