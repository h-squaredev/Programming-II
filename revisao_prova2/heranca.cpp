#include <iostream>
#include <string>
#include <iomanip> // Necessário para formatar o preço (R$ 50.00)

// 1. CLASSE BASE: PRODUTO
class Produto {
    protected:
        std::string nome;
        double preco;

    public:
        // Construtor da Base
        Produto(std::string n, double p) : nome(n), preco(p) {}

        // Metodo que sera reaproveitado ou modificado
        void exibirDetalhes() {
            std::cout << "Produto: " << nome << " | Preco: R$ " 
                      << std::fixed << std::setprecision(2) << preco << "\n";
        }
};

//Classe filha - Livro (herda de Produto)
class Livro : public Produto {
    private:
        std::string autor;

    public:
        Livro(std::string n, double p, std::string a) : Produto(n, p), autor(a) {}

        // Polimorfismo simples
        void exibirDetalhes() {
            Produto::exibirDetalhes(); 
            std::cout << "Autor: " << autor << "\n";
        }
};

//Classe filha - Eletronico (herda de Produto)
class Eletronico : public Produto {
    private:
        std::string marca;

    public:
        Eletronico(std::string n, double p, std::string m) : Produto(n, p), marca(m) {}

        // Polimorfismo simples
        void exibirDetalhes() {
            Produto::exibirDetalhes(); 
            std::cout << "Marca: " << marca << "\n"; 
        }
};

// Função principal
int main() {
    std::cout << "--- Cadastro de Produtos ---\n\n";

    // Produto
    Produto p1("Suporte para Notebook", 50.00);
    p1.exibirDetalhes();
    std::cout << "\n";

    // Livro (Herda de Produto)
    Livro l1("O Senhor dos Aneis", 120.00, "J.R.R. Tolkien");
    l1.exibirDetalhes();
    std::cout << "\n";

    // Eletronico (Herda de Produto)
    Eletronico e1("Fone Bluetooth", 200.00, "JBL");
    e1.exibirDetalhes();

    return 0;
}