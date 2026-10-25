#include <iostream>
#include <string>

class ContaBancaria {
    private:
        std::string numeroConta;
        double saldo;
        std::string titular;
    public:
        // Construtor
        ContaBancaria ( std::string n, double s, std::string t) : numeroConta (n) , saldo (s), titular (t) {};
        ContaBancaria ( std::string n, std::string t) : numeroConta (n) , saldo (0.0), titular (t) {};
        // Metodos Seletores (getters / GET)
        std::string getNumeroConta() {return numeroConta;}
        double getSaldo() {return saldo;}
        std::string getTitular() {return titular;}
        // Metodos Modificadores (setters / SET)
        void setNumeroConta (std::string n) {numeroConta = n;}
        void setSaldo (double s) {saldo = s;}
        void setTitular (std::string t) {titular = t;}

        //funcao para depositar dinheiro
        void depositar(double valor) {
            saldo += valor;
        }

        //funcao para sacar dinheiro
        bool sacar(double valor) {
            if (saldo >= valor){
                saldo -= valor;
                return true;
            }else{
                return false;
            }
        }

        //funcao para mostrar os dados da classe
        void mostrarDados(){
            std::cout << "Numero da Conta: " << numeroConta << ", Titular: " << titular << ", Saldo: "  << saldo << std::endl;


        }

};

int main(){
    ContaBancaria c1("12345-6", 1000.0, " Joao Silva");
    c1.mostrarDados(); // Conta: 12345-6, Titular: Joao Silva, Saldo: 1000 

    c1.depositar(500.0);
    auto valor = c1.sacar(300.0);
    if (valor > 0)
        std ::cout << "Saque de R$" << valor << " efetuado com sucesso" << std ::endl;
    else
        std ::cout << "Saldo insuficiente" << std ::endl;
    c1.mostrarDados(); // Conta: 12345-6, Titular: Joao Silva, Saldo: 1200 

    ContaBancaria c2("789-0", "Pedro Martins");
    c1.mostrarDados(); // Conta: 789-0 , Titular: Pedro Martins, Saldo: 0
    auto valor2 = c1.sacar(100.0);
    // Idem ao feito na tentativa anterior

    return 0;
}