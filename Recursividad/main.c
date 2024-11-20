#include <stdio.h>

#include "Funciones.h"
#include "../Vector/Vector.c"

void doble(void* e1){
    int* elem=(int*)e1;
    *elem*=2;
}

void agregar(void* e1,const void* e2){
    *(int*)e1=*(int*)e2;
}

void ver(const void* e1){
    printf("%d ",*(int*)e1);
}

int main(){
    char pal[]="Juan";
    printf("%ld\n",Pstrlen(pal));
    char* pun=Pstrrchr(pal,' ');
    if(!pun)
        printf("%c",'0');
    else{
        *pun='\0';
        printf("%s\n",pal);
    }

    Vector* vec=crearVector(5,sizeof(int));
    if(!vec)
        return SIN_MEM;
    int n=3;
    insertarFinal(vec,&n,agregar);
    n=2;
    insertarFinal(vec,&n,agregar);
    n=9;
    insertarFinal(vec,&n,agregar);
    n=8;
    insertarFinal(vec,&n,agregar);
    n=19;
    insertarFinal(vec,&n,agregar);

    mapR(vec,doble);
    mostrarVector(vec,ver);
    char pal1[]="an a,,,n";
    printf("\n%d",esPalindromo(pal1));
    eliminarVector(vec);
return 0;
}
