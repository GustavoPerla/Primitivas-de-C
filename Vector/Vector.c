#include "Vector.h"

Vector* crearVector(size_t tam,size_t tamElem){//Constructor
    Vector* tda=malloc(sizeof(Vector));
    if(!tda)
        return NULL;

    tda->vec=malloc(tam*tamElem);

    if(!tda->vec)
        return NULL;
    tda->cap=tam;
    tda->ce=0;
    tda->tamElem=tamElem;
    return tda;
}

void eliminarVector(Vector* vec){//Destructor
    free(vec->vec);
    free(vec);
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
