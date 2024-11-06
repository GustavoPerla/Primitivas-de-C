#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "Vector.h"
#include <stdio.h>
#include <string.h>

#define ERROR_ARCH 3
#define MAX_LINE 700
#define aforsne(i,s,n,e) for(void* i=(s);i<(n);i=i+(e))
#define daforsne(i,s,n,e) for(void* i=(n-e);i>=(s);i=i-(e))

typedef struct{
    int leg;
    char nya[65];
    char cod[513];
    float saldo;
}Clientes;

typedef struct{
    int ori;
    int des;
}Permutaciones;

int restArchClientes(char* nomArch1,char* nomArch2);
int crearArch();

#endif // ARCHIVOS_H_INCLUDED
