#include <stdio.h>
#include "Vector.h"
#include "Archivos.h"

//void agregar(void* lug,const void* elem){
//    *(int*)lug=*(int*)elem;
//}

void mostrar(const void* lug){
    printf("%d ",*(int*)lug);
}

int main(){

    crearArch();
    restArchClientes("Clientes Permutados.txt","perm.txt");

    return 0;
}
