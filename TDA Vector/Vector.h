#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdlib.h>

#define forsn(i,s,n) for(int i=(s);i<(n);i++)
#define forn(i,n) forsn(i,0,n)

#define POR_INCRE 1.5
#define SIN_MEM -1
#define TODO_OK 0

typedef void (*Agr) (void*,const void*);
typedef void (*Msg) (const void*);

typedef struct{
    void* vec;
    size_t ce;
    size_t cap;
    size_t tamElem;
}Vector;

int crearVector(Vector*,size_t,size_t);
void eliminarVector(Vector*);
int insertarFinal(Vector*,const void*,Agr);
void mostrarVector(Vector*,Msg);


#endif // VECTOR_H_INCLUDED
