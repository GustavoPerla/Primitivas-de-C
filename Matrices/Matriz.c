#include "Matriz.h"

size_t min(const size_t n1,const size_t n2){
    return (n1>n2?n2:n1);
}

void elimMat(void** mat,const size_t f){
    void** ult=mat+f;
    for(void** i=mat;i<ult;i++)
        free(*i);
    free(mat);
}

void** crearMat(const size_t fila,const size_t col,const size_t tamElem){
    void** mat = malloc(fila*sizeof(void*));
    if(!mat)
        return NULL;

    void** ult= mat+fila;
    for(void** i=mat;i<ult;i++){
        (*i)=malloc(col*tamElem);
        if(!(*i)){
            elimMat(mat,(*i)-(*mat));
            return NULL;
        }
    }
    return mat;
}

void llenarMat(void** mat,const size_t f,const size_t c,const void* elem,const size_t tamElem,Accion carga){
    forn(i,f)
        forn(j,c)
            carga(mat[i]+j*tamElem,elem);
}

void identidad(void** mat,const size_t f,const size_t c,const void* elem,const size_t tamElem,Accion carga){
    int m=min(c,f);
    forn(i,m)
        carga(mat[i]+i*tamElem,elem);
}

void contraria(void** mat,const size_t f,const size_t c,const void* elem,const size_t tamElem,Accion carga){
    int m=min(c,f);
    dforn(i,m)
        carga(mat[i]+(m-i-1)*tamElem,elem);
}

void triangularSup(void** mat,const size_t f,const size_t c, const void* elem,const size_t tamElem,Accion carg){
    forn(i,f)
        forsn(j,i+1,c)
            carg(mat[i]+j*tamElem,elem);
}

void triangularInf(void** mat,const size_t f,const size_t c, const void* elem,const size_t tamElem,Accion carg){
    size_t j=0;
    dforn(i,f){
        while(j<c && j<i){
            carg(mat[i]+j*tamElem,elem);
            j++;
        }
        j=0;
    }
}

void trianguloSup(void** mat,const size_t f,const size_t c,const void* elem,const size_t tamElem,Accion carg){
    size_t mid=min(f,c)/2+(!min(f,c)%2?0:1),ini=1,fin=min(c,f)-1,j=ini;
    forn(i,mid){
        while(j<fin){
            carg(mat[i]+j*tamElem,elem);
            j++;
        }
        ini++;
        if(fin)
            fin--;
        j=ini;
    }
}

void trianguloDer(void** mat,const size_t f,const size_t c,const void* elem,const size_t tamElem,Accion carg){
    size_t mid=min(f,c)/2+(!min(f,c)%2?0:1),ini=min(f,c)/2-(min(f,c)%2?0:1),fin=ini+(min(f,c)%2?1:2),i=ini;
    forsn(j,mid,c){
        while(i<fin){
            carg(mat[i]+j*tamElem,elem);
            i++;
        }
        if(ini)
            ini--;
        if(fin<f)
            fin++;
        i=ini;
    }
}

void trianguloIzq(void** mat,const size_t f,const size_t c,const void* elem,const size_t tamElem,Accion carg){
    size_t mid=min(f,c)/2+(min(f,c)%2?0:1),ini=0,fin=min(f,c)-1,i=ini+1;
    forsn(j,0,mid){
        while(i>ini && i<fin){
            carg(mat[i]+j*tamElem,elem);
            i++;
        }
        ini++;
        fin--;
        i=ini+1;
    }
}

void trianguloInf(void** mat,const size_t f,const size_t c,const void* elem,const size_t tamElem,Accion carg){
    size_t mid=min(f,c)/2+(!min(f,c)%2?0:1),ini=min(c,f)/2-(min(c,f)%2?0:1),fin=ini+(min(f,c)%2?1:2),j=ini;
    forsn(i,mid,f){
        while(j<fin){
            carg(mat[i]+j*tamElem,elem);
            j++;
        }
        if(ini)
            ini--;
        if(fin<c)
            fin++;
        j=ini;
    }
}

void mostrarMat(const void** mat,const size_t f,const size_t c,const size_t tamElem,Mst mst){
    forn(i,f){
        forn(j,c)
            mst(mat[i]+j*tamElem);
        printf("\n");
    }
}
