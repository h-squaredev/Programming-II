#include <iostream>

void processarDados(){

    int *dadosImportantes = new int(100); //Memory Leak, pois nao ha delete depois da alocacao

    int *valorTemporario = new int(42);
    delete valorTemporario;
    std :: cout << " Valor ( apos delete ): " << *valorTemporario << std ::endl; // after Free, uso do ponteiro apos deleta-lo

    // Double Free, foi deletado duas vezes o mesmo endereco de memoria 
    int *ptrOriginal = new int(99);
    int *ptrCopia = ptrOriginal;
    delete ptrOriginal;
    delete ptrCopia;
}

int main(){
    processarDados();
    std ::cout << " Programa concluiu ." << std :: endl;
    return 0;
}