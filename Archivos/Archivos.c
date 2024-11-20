#include "Archivos.h"

void empleados(FILE* arch){
    Emp emp[]=  {{10,"Maria Pia",200.},
                {20,"Juan Perez",300.},
                {30,"Diego Beltran",200.},
                {40,"Diego Martinez",200.},
                {50,"Nicolas Sattel",200.},
                {60,"Marcela De Negri",150.},
                {80,"Damian Cale",800.}
                };
    forn(i,7)
        fwrite(&emp[i],sizeof(Emp),1,arch);
}

void novedades(FILE* arch){
    Nove nove[]={{{17,"Ana Benites",300.},'a'},
                {{20,"Juan Perez Beltran",250.},'m'},
                {{33,"Jorge Asraliam",300.},'a'},
                {{55,"Badon Daniel",250.},'b'},
                {{80,"Damian Cale",800.},'b'},
                {{85,"Santiago Franco",800.},'m'},
                {{87,"Anabel Docaso",150.},'b'},
                {{88,"Martina Capusso",200.},'a'}
                };
    forn(i,8)
        fwrite(&nove[i],sizeof(Nove),1,arch);
}

int crearArch(const char* arch1,const char* arch2){
    FILE* arch=fopen(arch1,"wb");
    if(!arch)
        return ERROR_ARCH;
    empleados(arch);
    fclose(arch);
    arch=fopen(arch2,"wb");
    if(!arch)
        return ERROR_ARCH;
    novedades(arch);
    fclose(arch);
    return TODO_OK;
}

int abrirArch(FILE* arch1,const char* nom,const char* ap){
    arch1=fopen(nom,ap);
    if(!arch1)
        return ERROR_ARCH;
    return TODO_OK;
}

int mergeArch(const char* nomArch1,const char* nomArch2){
    FILE* arch1,* arch2,* temp,* error=NULL;
    if(abrirArch(arch1,nomArch1,"rb"))
        return ERROR_ARCH;
    if(abrirArch(arch2,nomArch2,"rb")){
        fclose(arch1);
        return ERROR_ARCH;
    }
    if(abrirArch(temp,"temp.dat","wb")){
        fclose(arch1);
        fclose(arch2);
        return ERROR_ARCH;
    }

    Emp emp;
    Nove nove;
    fread(&emp,sizeof(Emp),1,arch1);
    fread(&nove,sizeof(Nove),1,arch2);
    while(!feof(arch1) && !feof(arch2)){
        if(emp.leg<nove.emp.leg){
            fwrite(&emp,sizeof(Emp),1,temp);
            fread(&emp,sizeof(Emp),1,arch1);
        }else
            if(nove.emp.leg==emp.leg){
                if(nove.tipo=='m')
                    fwrite(&nove.emp,sizeof(Emp),1,temp);
                fread(&nove,sizeof(Nove),1,arch2);
                fread(&emp,sizeof(Emp),1,arch1);
            }else
                if(nove.tipo=='a'){
                    fwrite(&nove.emp,sizeof(Emp),1,temp);
                    fread(&nove,sizeof(Nove),1,arch2);
                }else{
                    if(!error)
                        if(crearArch(error,errores.txt,"wt")){
                            fclose(arch1);
                            fclose(arch2);
                            fclose(temp);
                            return ERROR_ARCH;
                        }
                    fprintf(error,"%d|%s|%.1f",nove.emp.leg,nove.emp.nom,nove.emp.sueldo);
                }

    }
}



