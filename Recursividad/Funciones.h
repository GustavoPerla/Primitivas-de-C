#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "../Vector/Vector.h"
#include <stdlib.h>
#include <stdbool.h>

#define LETRA(l) (((l)>='a' && (l)<='z') || ((l)>='A' && (l)<='Z'))
#define DERECHA 1
#define IZQUIERDA 0

typedef void (*Accion)(void*);

size_t Pstrlen(const char*);
char* Pstrchr(char*,const int);
char* Pstrrchr(char*,const int);
void mapR(Vector*,Accion);
bool esPalindromo(char*);
#endif // FUNCIONES_H_INCLUDED
