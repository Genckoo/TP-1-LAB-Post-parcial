#ifndef CLASEMUNICIPIOS_H_INCLUDED
#define CLASEMUNICIPIOS_H_INCLUDED

class Municipio{
    public:
    Municipio(){
    _estado=false;
    }

    void setNumeroMunicipio(int numeroMunicipio){_numeroMunicipio=numeroMunicipio;}
    int getNumeroMunicipio(){return _numeroMunicipio;}

    void setNombre(const char *nombre){strcpy(_nombre,nombre);}
    const char *getNombre(){return _nombre;}

    int getSeccionPerteneciente(){return _seccionPerteneciente;}
    void setSeccionPerteneciente(int seccionPerteneciente){_seccionPerteneciente=seccionPerteneciente;}

    void setCantHabitantes(int cantHabitantes){_cantHabitantes=cantHabitantes;}
    int getCantHabitantes(){return _cantHabitantes;}

    void setEstado(bool estado){_estado=estado;}
    bool getEstado(){return _estado;}

    void Cargar();
    void Mostrar();


    private:
    int _numeroMunicipio;
    char _nombre[30];
    int _seccionPerteneciente;
    int _cantHabitantes;
    bool _estado;
};

void Municipio::Cargar(){
cout<<"Ingresar Nombre de municipio: "<<endl;
cargarCadena(_nombre,30);
cout<<"Ingresar Seccion perteneciente: "<<endl;
cin>>_seccionPerteneciente;
cout<<"Ingresar cantidad de habitantes: "<<endl;
cin>>_cantHabitantes;
_estado=true;
}

void Municipio::Mostrar(){
if(_estado==true){
cout<<"Numero de municipio: "<<_numeroMunicipio<<endl;
cout<<"Nombre de municipio: "<<_nombre<<endl;
cout<<"Seccion perteneciente: "<<_seccionPerteneciente<<endl;
cout<<"Cantidad de habitantes: "<<_cantHabitantes<<endl;
}

}


#endif // CLASEMUNICIPIOS_H_INCLUDED
