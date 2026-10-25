#include <iostream>
#include <string>
#include <memory>
#include <utility> // Para std :: move

void receberChave(std :: unique_ptr<std :: string> chave){
    std::cout << " - Funcao recebeu a chave : ’" << *chave << "’" << std ::endl;
}

    std::unique_ptr<std :: string> forjarNovaChave(){
    // TODO : Crie e retorne um unique_ptr para " Chave de Ouro ".
    return std::make_unique<std::string>(" Chave de Ouro ");

}

int main(){
    auto chaveInicial = std :: make_unique<std :: string>(" Chave de Prata ");
    // TODO: Chame ’receberChave’, transferindo a ’chaveInicial’.
    receberChave(std::move(chaveInicial));

    // TODO: Verifique se ’chaveInicial’ eh nullptr .
    if (chaveInicial == nullptr) {
        std::cout << "chaveInicial eh nullptr" << std::endl;
    } else {
        std::cout << "chaveInicial nao eh nullptr" << std::endl;
    }

    // TODO:  Chame ’forjarNovaChave’ e armazene o resultado .
    auto novaChave = forjarNovaChave();
    std::cout << "Nova chave forjada: " << *novaChave << std::endl;

    return 0;
}