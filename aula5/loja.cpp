#include <iostream>
#include <string>

//classe representando os produtos da loja
class produto {
    public:
    std::string nome;
    float preco;
    int produtoID;  
    int quantidadeEstoque;

    void mostrarDados(){
        std::cout<< "===============================" << std::endl;
        std::cout<< "NOME DO PRODUTO:  "<< nome << std::endl;
        std::cout<< "PRECO:  R$"<< preco << std::endl;
        std::cout<< "IDENTIFICACAO:  " << produtoID << std::endl;
        std::cout<< "QUANTIDADE NO ESTOQUE:  " << quantidadeEstoque << std::endl;
        std::cout<< "===============================" << std::endl;
    }

    void cadastrar(std::string novoNome, float novoPreco, int novoProdutoID, int novaQuantidadeEstoque){
        nome = novoNome;
        preco = novoPreco;
        produtoID = novoProdutoID;
        quantidadeEstoque = novaQuantidadeEstoque;
    }

    bool vender(int quantidadeVendida){
        if(quantidadeEstoque >= quantidadeVendida){
            quantidadeEstoque -= quantidadeVendida;
            return true;
        }else{
            return false;
        }
    }

    bool reabastecer(int quantidadeAdicionada){
        if(quantidadeAdicionada > 0){
            quantidadeEstoque += quantidadeAdicionada;
            return true;
        }else{
            return false;
        }
        }

    bool consultarQuantidade(){
        std::cout << "Quantidade em estoque: " << quantidadeEstoque << std::endl;
        return true;
    }

};

void autorizacaoDeCompra(produto p, int quantidadeDesejada){
    if(p.quantidadeEstoque >= quantidadeDesejada){
        std::cout << "Compra autorizada!" << std::endl;
    }else{
        std::cout << "Compra nao autorizada. Estoque insuficiente." << std::endl;
    }
}

int main(){

    produto p1, p2;

    p1.cadastrar("Notebook", 3500.00, 23456, 80);
    p1.mostrarDados();

    p2.cadastrar("Smartphone", 1500.00, 34567, 110);
    p2.mostrarDados();

    autorizacaoDeCompra(p1, 50);
    autorizacaoDeCompra(p2, 150);

    return 0;
}