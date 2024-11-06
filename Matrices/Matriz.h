#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_MEM -1

#define FILAS 33
#define COLUMNAS 35

#define forsn(i,s,n) for(int i=(s);i<(n);i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=(n-1);i>=(s);i--)
#define dforn(i,n) dforsn(i,0,n)


typedef void (*Accion)(void* e1,const void* e2);
typedef void (*Mst)(const void* e1);

void** crearMat(const size_t,const size_t,const size_t);
void elimMat(void**,const size_t);
void llenarMat(void**,const size_t,const size_t,const void*,const size_t,Accion);
void identidad(void**,const size_t,const size_t,const void*,const size_t,Accion);
void contraria(void**,const size_t,const size_t, const void*,const size_t,Accion);
void triangularSup(void**,const size_t,const size_t,const void*,const size_t,Accion);
void triangularInf(void**,const size_t,const size_t,const void*,const size_t,Accion);
void trianguloSup(void**,const size_t,const size_t,const void*,const size_t,Accion);
void trianguloDer(void**,const size_t,const size_t,const void*,const size_t,Accion);
void trianguloIzq(void**,const size_t,const size_t,const void*,const size_t,Accion);
void trianguloInf(void**,const size_t,const size_t,const void*,const size_t,Accion);
void mostrarMat(const void**,const size_t,const size_t,const size_t,Mst);

#endif // MATRIZ_H_INCLUDED
