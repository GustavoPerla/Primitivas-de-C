#include <stdio.h>
#include "Vector.h"
#include <string.h>

void agregar(void* e1,const void* e2){
    memcpy(e1,e2,sizeof(int));
}
void ver(const void* el){
    printf("%d ",*(int*)el);
}

int main()
{
    Vector* vec=crearVector(5,sizeof(int));
    if(!vec)
        return SIN_MEM;
    int n=3;
    insertarFinal(vec,&n,agregar);
    n=2;
    insertarFinal(vec,&n,agregar);
    n=9;
    insertarFinal(vec,&n,agregar);
    n=8;
    insertarFinal(vec,&n,agregar);
    n=19;
    insertarFinal(vec,&n,agregar);
    mostrarVector(vec,ver);

    eliminarVector(vec);
    return 0;
}
