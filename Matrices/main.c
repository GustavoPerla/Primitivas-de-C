#include "Matriz.h"

void crgMat(void* e1,const void* e2){
    *(int*)e1=*(int*)e2;
}

void mst(const void* elem){
    printf("%d ",*(int*)elem);
}

int main(){
    int n=0;
    int** mat= (int**)crearMat(FILAS,COLUMNAS,sizeof(int));
    if(!mat)
        return SIN_MEM;

    llenarMat((void**)mat,FILAS,COLUMNAS,&n,sizeof(n),crgMat);
    n=1;
    identidad((void**)mat,FILAS,COLUMNAS,&n,sizeof(n),crgMat);
    n=3;
    contraria((void**)mat,FILAS,COLUMNAS,&n,sizeof(int),crgMat);
    n=5;
    triangularSup((void**)mat,FILAS,COLUMNAS,&n,sizeof(n),crgMat);
    n=2;
    triangularInf((void**)mat,FILAS,COLUMNAS,&n,sizeof(n),crgMat);
    n=4;
    trianguloSup((void**)mat,FILAS,COLUMNAS,&n,sizeof(n),crgMat);
    n=6;
    trianguloDer((void**)mat,FILAS,COLUMNAS,&n,sizeof(n),crgMat);
    n=7;
    trianguloIzq((void**)mat,FILAS,COLUMNAS,&n,sizeof(n),crgMat);
    n=8;
    trianguloInf((void**)mat,FILAS,COLUMNAS,&n,sizeof(n),crgMat);
    mostrarMat((const void**)mat,FILAS,COLUMNAS,sizeof(int),mst);
    elimMat((void**)mat,10);
return 0;
}
