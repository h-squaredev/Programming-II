#include <iostream>

class Produto {
private:
    int id;
    std::string nome;
    double preco;
    int quantidade;
public:
    Produto(int id, std::string nome, double preco, int quantidade) : id(id), nome(nome), preco(preco), quantidade(quantidade) {}
    void exibir() const {
        std::cout << "Produto: " << nome << " - Preço: " << preco << " - Quantidade: " << quantidade << std::endl;
    }

    bool operator==(const Produto& other) const {
        return id == other.id && nome == other.nome && preco == other.preco && quantidade == other.quantidade;
    }
};

int main() {
    Produto p1(1, "caneta", 29.99, 10);
    Produto p2(1, "caneta", 29.99, 10);

    p1.exibir();
    p2.exibir();

    if (p1 == p2) {
        std::cout << "Os produtos são iguais." << std::endl;
    } else {
        std::cout << "Os produtos são diferentes." << std::endl;
    }    
    
    
    
    
    
    
    
    
    
return 0;
}

