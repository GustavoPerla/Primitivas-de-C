#include "Vector.h"

int crearVector(Vector* vec,size_t tam,size_t tamElem){
    vec->vec=malloc(tam*tamElem);

    if(!vec->vec)
        return SIN_MEM;
    vec->cap=tam;
    vec->ce=0;
    vec->tamElem=tamElem;
    return TODO_OK;
}

void eliminarVector(Vector* vec){
    free(vec->vec);
    vec->cap=0;
    vec->tamElem=0;
}

int __ampliarVector(Vector* vec){
    size_t nCap=vec->cap+vec->cap*POR_INCRE;
    void* aux=realloc(vec->vec,nCap*vec->tamElem);
    if(!aux)
        return SIN_MEM;
    vec->vec=aux;
    vec->cap=nCap;
    return TODO_OK;
}

int insertarFinal(Vector* vec,const void* elem,Agr agr){
    if(vec->ce==vec->cap)
        if(__ampliarVector(vec))
            return SIN_MEM;
    agr(vec->vec+vec->ce*vec->tamElem,elem);
    vec->ce++;

    return TODO_OK;
}

void mostrarVector(Vector* vec,Msg mos){
    forn(i,vec->ce)
        mos(vec->vec+i*vec->tamElem);
}
