#include "Funciones.h"
#include <string.h>

size_t Pstrlen(const char* pal){
    if(*pal=='\0')
        return 0;
    return 1+Pstrlen(pal+1);
}

char* Pstrchr(char* pal,const int elem){
    if(*pal=='\0')
        return NULL;
    if(*pal==elem)
        return pal;
    return Pstrchr(pal+1,elem);
}

char* __Pstrrchr(const char* ini,char* pal,const int elem){
    if(*pal==elem)
        return pal;
    if(pal==ini)
        return NULL;
    return __Pstrrchr(ini,pal-1,elem);
}

char* Pstrrchr(char* pal,const int elem){
    return __Pstrrchr(pal,pal+Pstrlen(pal),elem);
}

void __mapR(Vector* vec,size_t lug,Accion acc){
    if(vec->ce==lug)
        return;
    acc(vec->vec+lug*vec->tamElem);
    __mapR(vec,lug+1,acc);
}

void mapR(Vector* vec,Accion acc){
    __mapR(vec,0,acc);
}

size_t esLetra(char* pos,bool op,size_t mov){
    if(LETRA(*pos))
        return mov;
    return (op?esLetra(pos-1,op,mov+1):esLetra(pos+1,op,mov+1));
}

bool __palindromo(char* izq,char* der){
    izq+=esLetra(izq,IZQUIERDA,0);
    der-=esLetra(der,DERECHA,0);
    if(izq>=der)
        return 1;
    if(*izq==*der)
        return __palindromo(izq+1,der-1);
    else
        return 0;
}

bool esPalindromo(char* pal){
    size_t tam=Pstrlen(pal);
    return __palindromo(pal,pal+tam);
}


