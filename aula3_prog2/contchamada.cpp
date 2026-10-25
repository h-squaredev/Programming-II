#include <iostream> // Para std::cout e std::endl
#include <cstdlib> // Para rand ()
#include <ctime> // Para time ()

void registrarEvento () {
    // TODO : Declare uma variavel local static para o ID do evento .
    static int idEvento = 1 ;

    // TODO : Declare uma variavel local para o Codigo de Processamento .
    int codigoProcessamento = rand ();

    // TODO : Imprima o ID e o Codigo.
    std::cout << "Evento ID: " << idEvento << " - Codigo de Processamento: " << codigoProcessamento << std:: endl;

    // TODO : Incremente o ID para a proxima chamada .
    idEvento ++ ;
}

int main () {
    srand ( time (0) ) ;
    std :: cout << " --- Registrando 5 eventos ---" << std :: endl ;
    for (int i = 0; i < 5; ++ i ) {
    registrarEvento () ;
    }
return 0;
}