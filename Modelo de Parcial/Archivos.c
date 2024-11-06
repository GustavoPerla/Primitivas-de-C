#include "Archivos.h"

#define CLIENTES    {{1,"John McEnroe","1123512315",300.00},\
                    {10,"Jimmy Connors","112355555",200.00},\
                    {20,"Steffi Graf","11235545413",10.00},\
                    {30,"Monica Seles","112354545",50.00},\
                    {45,"Chris Evert","112357989",300.00},\
                    {75,"Bjorn Borg","1123512134",200.00},\
                    {80,"Billie Jean King","1123578923",100.00},\
                    {90,"Gabriela Sabatini","112351111",100.00}\
                    }
#define PERM    {{0,1},\
                {1,3},\
                {2,6},\
                {3,4},\
                {4,1},\
                {5,4},\
                {6,6},\
                {7,6}\
                }

void agregar(void* des,const void* ori){
    memcpy(des,ori,sizeof(Clientes));
}

void agregar1(void* des,const void* ori){
    memcpy(des,ori,sizeof(Permutaciones));
}

int crearArch(){
    Vector vec;
    if(crearVector(&vec,5,sizeof(Clientes)))
        return SIN_MEM;

    Clientes clie[8]=CLIENTES,aux;
    forn(i,8)
        insertarFinal(&vec,&clie[i],agregar);

    FILE* arch=fopen("Clientes Permutados.txt","wt");
    if(!arch)
        return ERROR_ARCH;

    aforsne(i,vec.vec,vec.vec+vec.ce*vec.tamElem,vec.tamElem){
        aux=*(Clientes*)i;
        fprintf(arch,"%d|%s|%s|%.2f\n",aux.leg,aux.nya,aux.cod,aux.saldo);
    }
    fclose(arch);
    eliminarVector(&vec);

    if(crearVector(&vec,5,sizeof(Permutaciones)))
        return SIN_MEM;

    Permutaciones per[]=PERM,permu;
    forn(i,8)
        insertarFinal(&vec,&per[i],agregar1);
    arch=fopen("perm.txt","wb");
    if(!arch)
        return ERROR_ARCH;

    aforsne(i,vec.vec,vec.vec+vec.ce*vec.tamElem,vec.tamElem){
        permu=*(Permutaciones*)i;
        fprintf(arch,"%d %d\n",permu.ori,permu.des);
    }
    eliminarVector(&vec);
    fclose(arch);
    return TODO_OK;
}

int cargarArch1(char* nomArch,Vector* vec){
    FILE* arch=fopen(nomArch,"rt");
    char linea[MAX_LINE];
    if(!arch)
        return ERROR_ARCH;

    Clientes cli;
    while(fgets(linea,MAX_LINE,arch)){
        sscanf(linea,"%d|%[^|]|%[^|]|%f",&cli.leg,cli.nya,cli.cod,&cli.saldo);
        insertarFinal(vec,&cli,agregar);
    }

    fclose(arch);
    return TODO_OK;
}

int cargarArch2(char* nomArch,Vector* vec){
    FILE* arch=fopen(nomArch,"rt");
    if(!arch)
        return ERROR_ARCH;

    Permutaciones per;
    while(fscanf(arch,"%d %d",&per.ori,&per.des)==2){
        insertarFinal(vec,&per,agregar1);
    }
    fclose(arch);
    return TODO_OK;
}

void permutar(Vector* clien,Vector* cam){
    void* ult=cam->vec+cam->ce*cam->tamElem;
    Permutaciones* per;
    Clientes* cli1,*cli2;
    float aux;
    daforsne(i,cam->vec,ult,cam->tamElem){
        per=(Permutaciones*)i;
        cli1=((Clientes*)clien->vec)+per->ori;
        cli2=((Clientes*)clien->vec)+per->des;
        aux=cli2->saldo;
        cli2->saldo=cli1->saldo;
        cli1->saldo=aux;
    }
}

int crearActualizado(const char* nomArch,Vector* vec){
    FILE* arch=fopen(nomArch,"wb");
    if(!arch)
        return ERROR_ARCH;
    Clientes* clie;

    aforsne(i,vec->vec,vec->vec+vec->ce*vec->tamElem,vec->tamElem){
        clie=(Clientes*)i;
        fprintf(arch,"%d|%s|%s|%.2f\n",clie->leg,clie->nya,clie->cod,clie->saldo);
    }
    fclose(arch);
    return TODO_OK;
}

int restArchClientes(char* nomArch1,char* nomArch2){
    Vector clienPer,perm;
    if(crearVector(&clienPer,5,sizeof(Clientes)))
        return SIN_MEM;
    if(cargarArch1(nomArch1,&clienPer)){
        eliminarVector(&clienPer);
        return ERROR_ARCH;
    }

    if(crearVector(&perm,5,sizeof(Permutaciones))){
        eliminarVector(&clienPer);
        return SIN_MEM;
    }
    if(cargarArch2(nomArch2,&perm)){
        eliminarVector(&clienPer);
        eliminarVector(&perm);
        return ERROR_ARCH;
    }

    permutar(&clienPer,&perm);
    eliminarVector(&perm);

    crearActualizado("Archivo Original.txt",&clienPer);
    eliminarVector(&clienPer);
    return TODO_OK;
}
