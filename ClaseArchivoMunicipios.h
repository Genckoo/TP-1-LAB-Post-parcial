#ifndef CLASEARCHIVOMUNICIPIOS_H_INCLUDED
#define CLASEARCHIVOMUNICIPIOS_H_INCLUDED

class ArchivoMunicipio{
public:
     ArchivoMunicipio(const char *nombrearchivo="municipios.dat"){
     strcpy(_nombre,nombrearchivo);
    }
    int PosicionRegistro(int);
    bool GuardarMunicipio(Municipio);
    Municipio BuscarMunicipio(int);
    int CantRegistros();
    Municipio ListarMunicipio(int);
    bool ModificarArchivo(Municipio,int);
    bool VerifNumMunicipio(int);
    int CantRegistrosEliminados();
    bool CopiaSeguridad();
    bool UsarCopiaSeguridad();
    bool RestaurarDatosInicio();

private:
   char _nombre[30];


};
////////////////////////////////////////////////////////////////

bool ArchivoMunicipio::VerifNumMunicipio(int NumMunicipio){
Municipio municipio;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
    return false;
}
while(fread(&municipio,sizeof(Municipio),1,p)==1){
    if(municipio.getNumeroMunicipio()==NumMunicipio && municipio.getEstado()==true){
        fclose(p);
        return true;
    }
}
fclose(p);
return false;
}


bool ArchivoMunicipio::GuardarMunicipio(Municipio newMunicipio){
FILE *p;
p=fopen(_nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&newMunicipio,sizeof(Municipio),1,p);
fclose(p);
return true;
}


int ArchivoMunicipio::PosicionRegistro(int numMunicipio){
Municipio municipio;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
    return -1;
}
int pos=0;
while(fread(&municipio,sizeof(Municipio),1,p)==1){
    if(municipio.getNumeroMunicipio()==numMunicipio && municipio.getEstado()==true){
        fclose(p);
        return pos;
    }
    pos++;
}
fclose(p);
return -2;
}

//////////////////////////////////////////////////////////
int ArchivoMunicipio::CantRegistros(){
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(Municipio);
}


Municipio ArchivoMunicipio::BuscarMunicipio(int numMunicipio){
Municipio municipio;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
    municipio.setNumeroMunicipio(-1);
    return municipio;
}
while(fread(&municipio,sizeof(Municipio),1,p)==1){
    if(municipio.getNumeroMunicipio()==numMunicipio && municipio.getEstado()==true){
        fclose(p);
        return municipio;
    }
}
municipio.setNumeroMunicipio(-2);
fclose(p);
return municipio;
}

Municipio ArchivoMunicipio::ListarMunicipio(int posicion){
Municipio municipio;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return municipio;
}
fseek(p,sizeof(Municipio)*posicion,0);
fread(&municipio,sizeof(Municipio),1,p);
    fclose(p);
    return municipio;
}


bool ArchivoMunicipio::ModificarArchivo(Municipio MunicipioModificada,int posicion){
FILE *p;
p=fopen(_nombre,"rb+");
if(p==NULL){
    return false;
}
fseek(p,sizeof(Municipio)*posicion,0);
fwrite(&MunicipioModificada,sizeof(Municipio),1,p);
fclose(p);
return true;
}

int ArchivoMunicipio::CantRegistrosEliminados(){
Municipio municipio;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
    return -1;
}
int cant=0;
while(fread(&municipio,sizeof(Municipio),1,p)==1){
    if(municipio.getEstado()==false){
            cant++;
    }
}
fclose(p);
return cant;
}

bool ArchivoMunicipio::CopiaSeguridad(){
   FILE *pbak=fopen("municipios.bkp","wb");
   Municipio reg;
     if(pbak==NULL){
    return false;
}
    int cantReg = CantRegistros();
    for(int i=0;i<cantReg;i++){
    reg=ListarMunicipio(i);
    fwrite(&reg,sizeof reg,1,pbak);
}

    fclose(pbak);
    return true;
}

bool ArchivoMunicipio::UsarCopiaSeguridad(){
    FILE *p;
    Municipio reg;
    ArchivoMunicipio archivo("municipios.bkp");
    p=fopen("municipios.dat","wb");
    if(p==NULL){
    cout<<"No se pudo abrir"<<endl;
    return false;
}
    int cantReg = archivo.CantRegistros();
    for(int i=0;i<cantReg;i++){
    reg=archivo.ListarMunicipio(i);
    fwrite(&reg,sizeof reg,1,p);
}
    fclose(p);
    return true;
}

bool ArchivoMunicipio::RestaurarDatosInicio(){
    Municipio municipio;
    ArchivoMunicipio archivo("municipios.ini");
    FILE *p;
    p=fopen("municipios.dat","wb");
    if(p==NULL){
        return false;
    }
    int cant=archivo.CantRegistros();
    for(int i=0;i<cant;i++){
        municipio=archivo.ListarMunicipio(i);
        municipio.Mostrar();
        system("pause");
        fwrite(&municipio,sizeof(municipio),1,p);
    }
    fclose(p);
    return true;
}

#endif // CLASEARCHIVOMUNICIPIOS_H_INCLUDED
