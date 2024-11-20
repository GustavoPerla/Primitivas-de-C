#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define forsn(i,s,n) for(int i=(s);i<(n);i++)
#define forn(i,n) forsn(i,0,n)

typedef struct{
    int leg;
    char nom[30];
    float sueldo;
}Emp;

typedef struct{
    Emp emp;
    char tipo;
}Nove;

#define ERROR_ARCH 3
#define TODO_OK 0


#endif // ARCHIVOS_H_INCLUDED
