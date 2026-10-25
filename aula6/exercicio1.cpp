#include <iostream>
#include <string>

class Produto {
    private:
        std::string nome;
        double preco;
        int quantidade;
    public:
        // Construtor
        Produto (std::string n, double p, int q) : nome (n) , preco (p) , quantidade (q) {};
        // Metodos Seletores (getters / GET)
        std::string getNome() {return nome;}
        double getPreco() {return preco;}
        int getQuantidade() {return quantidade;}
        // Metodos Seletores (setters / SET)
        void setNome (std::string n) {nome = n;}
        void setPreco (double p) {preco = p;}
        void setQuantidade (int q) {quantidade = q;}

        //funcao booleana para adicionar no estoque 
        bool adicionarEstoque(int q) {
            quantidade += q;
            return true;
        }

        //funcao booleana para remover do estoque 
        bool removerEstoque (int q) {
            if (quantidade >= q){
            quantidade -= q;
            return true;
        }else{
            return false;
        }
        }

        //funcao para mostrar os dados da classe
        void mostrarDados(){
            std::cout << "Nome: " << nome << ", Preco: " << preco << ", Quantidade: " << quantidade << std::endl;
        }

};

int main () {
    Produto p1 ("Notebook", 2500.0 , 10);
    p1.mostrarDados (); // Nome: Notebook, Preco: 2500, Quantidade: 10

    p1.adicionarEstoque (5);
    p1.removerEstoque (3);
    p1.mostrarDados (); // Nome: Notebook, Preco: 2500, Quantidade: 12

    return 0;
}