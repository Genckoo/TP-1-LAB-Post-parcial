#ifndef CLASEARCHIVOEMPRESAS_H_INCLUDED
#define CLASEARCHIVOEMPRESAS_H_INCLUDED

class EmpresaArchivo{
public:
    EmpresaArchivo(const char *nombrearchivo="empresas.dat"){
    strcpy(_nombre,nombrearchivo);
    }
    int PosicionRegistro(int);
    bool GuardarEmpresa(Empresa);
    Empresa BuscarEmpresa(int);
    int CantRegistros();
    Empresa ListarEmpresa(int);
    bool ModificarArchivo(Empresa,int);
    int VerifNumEmpresa(int);
    bool CopiaSeguridad();
    bool UsarCopiaSeguridad();
    bool RestaurarDatosInicio();

private:
    char _nombre[30];

};

int EmpresaArchivo::VerifNumEmpresa(int NumEmpresa){
Empresa empresa;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
    return -2;
}
while(fread(&empresa,sizeof(empresa),1,p)==1){
    if(empresa.getNumEmp()==NumEmpresa){
        fclose(p);
        return 1;
    }
    if(empresa.getNumEmp()==NumEmpresa && empresa.getEstado()==false){
        fclose(p);
        return 2;
    }
}
fclose(p);
return -2;
}


int EmpresaArchivo::PosicionRegistro(int numEmpresa){
Empresa empresa;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
    return -1;
}
int pos=0;
while(fread(&empresa,sizeof(empresa),1,p)==1){
    if(empresa.getNumEmp()==numEmpresa && empresa.getEstado()==true){
        fclose(p);
        return pos;
    }
    pos++;
}
fclose(p);
return -2;
}

bool EmpresaArchivo::GuardarEmpresa(Empresa newEmpresa){
FILE *p;
p=fopen(_nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&newEmpresa,sizeof(Empresa),1,p);
fclose(p);
return true;
}

//////////////////////////////////////////////////////////
int EmpresaArchivo::CantRegistros(){
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(Empresa);
}


Empresa EmpresaArchivo::BuscarEmpresa(int numEmpresa){
Empresa empresa;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
    empresa.setCategoria(-1);
    return empresa;
}
while(fread(&empresa,sizeof(empresa),1,p)==1){
    if(empresa.getNumEmp()==numEmpresa && empresa.getEstado()==true){
        fclose(p);
        return empresa;
    }
}
empresa.setCategoria(-2);
fclose(p);
return empresa;
}

Empresa EmpresaArchivo::ListarEmpresa(int posicion){
Empresa empresa;
FILE *p;
p=fopen(_nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return empresa;
}
fseek(p,sizeof(Empresa)*posicion,0);
fread(&empresa,sizeof(empresa),1,p);
    fclose(p);
    return empresa;
}


bool EmpresaArchivo::ModificarArchivo(Empresa EmpresaModificada,int posicion){
FILE *p;
p=fopen(_nombre,"rb+");
if(p==NULL){
    return false;
}
fseek(p,sizeof(Empresa)*posicion,0);
fwrite(&EmpresaModificada,sizeof(Empresa),1,p);
fclose(p);
return true;
}

bool EmpresaArchivo::CopiaSeguridad(){
   FILE *pbak=fopen("empresas.bkp","wb");
   Empresa reg;
     if(pbak==NULL){
    cout<<"No se pudo abrir"<<endl;
    return false;
}
    int cantReg = CantRegistros();
    for(int i=0;i<cantReg;i++){
    reg=ListarEmpresa(i);
    fwrite(&reg,sizeof reg,1,pbak);
}

    fclose(pbak);
    return true;
}

bool EmpresaArchivo::UsarCopiaSeguridad(){
    FILE *p;
    Empresa reg;
    EmpresaArchivo archivo("empresas.bkp");
    p=fopen("empresas.dat","wb");
    if(p==NULL){
    cout<<"No se pudo abrir"<<endl;
    return false;
}
    int cantReg = archivo.CantRegistros();
    for(int i=0;i<cantReg;i++){
    reg=archivo.ListarEmpresa(i);
    fwrite(&reg,sizeof(Empresa),1,p);
}
    fclose(p);
    return true;
}

bool EmpresaArchivo::RestaurarDatosInicio(){
    Empresa empresa;
    EmpresaArchivo archivo("empresas.ini");
    FILE *p;
    p=fopen("empresas.dat","wb");
    if(p==NULL){
        return false;
    }
    int cant=archivo.CantRegistros();
    for(int i=0;i<cant;i++){
        empresa=archivo.ListarEmpresa(i);
        empresa.Mostrar();
        system("pause");
        fwrite(&empresa,sizeof(Empresa),1,p);
    }
    fclose(p);
    return true;
}

#endif // CLASEARCHIVOEMPRESAS_H_INCLUDED
