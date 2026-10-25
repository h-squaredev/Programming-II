#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{
    auto documento = std ::make_shared<std ::string>(" Conteudo Secreto ");
    std ::cout << "Doc criado . Refs : " << documento.use_count() << std ::endl;

    std ::vector<std ::shared_ptr<std ::string>> usuarios(3);

    std ::cout << "\n--- Adicionando usuarios ---" << std ::endl;
    // TODO: Adicione o ’documento’ 3 vezes ao vetor ’usuarios’
    // A cada adicao , imprima a contagem de referencias.
    for (int i = 0; i < 3; i++ ) {
        usuarios[i] = documento;
        std ::cout  << documento.use_count() << std ::endl;
        
    }
    std ::cout << "\n--- Removendo usuarios ---" << std ::endl;
    // TODO : Enquanto o vetor ’usuarios’ nao estiver vazio, remova
    // o ultimo elemento e imprima a contagem de referencias.
    while (!usuarios.empty()) {
        usuarios.pop_back();
        std ::cout << documento.use_count() << std ::endl;
    }
    
    std ::cout << "\n Ultima ref. prestes a sair do escopo ." << std ::endl;
    return 0;
}