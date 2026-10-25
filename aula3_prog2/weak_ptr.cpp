#include <iostream>
#include <string>
#include <memory>

void verificarTesouro(const std ::weak_ptr<std ::string> &visao){
    std::cout << " Sentinela verificando ..." << std ::endl;
    // TODO : Use visao. lock () para obter um shared_ptr.
    // Se o ponteiro nao for nulo, imprima o conteudo do tesouro.
    // Senao, imprima que o tesouro desapareceu.
    auto sharedVisao = visao.lock();
    if (sharedVisao == nullptr) {
        std::cout << " Tesouro encontrado: " << *sharedVisao << std::endl;
    } else {
        std::cout << " Tesouro desapareceu!" << std::endl;
    }
    
}

int main(){
    auto tesouro = std ::make_shared<std ::string>(" Coroa de Esmeraldas ");
    std :: weak_ptr<std :: string> visaoDoSentinela(tesouro);

    verificarTesouro(visaoDoSentinela);

    std ::cout << "\n!!! O tesouro foi roubado !!!" << std ::endl;
    
    //TODO: Use tesouro.reset () para liberar o objeto.
    tesouro.reset();

    verificarTesouro(visaoDoSentinela);

    return 0;
}