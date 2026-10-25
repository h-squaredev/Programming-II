#include <iostream>
#include <string>

//classe reperesentando os funiconarios
class funconario {
    public:
    std::string nome;
    int matricula;
    std::string cargo;
    float salario;

    void mostrarDados(){
        std::cout << "\n=============== FUNCIONARIO ===============" << std::endl;
        std::cout << "NOME: " << nome << std::endl;
        std::cout << "MATRICULA: " << matricula << std::endl;
        std::cout << "CARGO: " << cargo << std::endl;
        std::cout << "SALARIO: R$" << salario << std::endl;
    }

    void cadastrar(std::string novoNome, int novaMatricula, std::string novoCargo, float novoSalario){
        nome = novoNome;
        matricula = novaMatricula;
        cargo = novoCargo;
        salario = novoSalario;
    }

    void alterarSalario(float novoSalario){
        salario = novoSalario;
    }

    void acessarSalario(){
        std::cout << "\nSalario atual: R$" << salario << std::endl;
    }


};

    bool mesmoCargo(funconario f1, funconario f2){
        if(f1.cargo != f2.cargo){
            return false;
        }else
            return true;
    }

int main(){
    funconario f1, f2;

    f1.cadastrar("Ana Silva", 1234, "Gerente", 5000.0);
    f2.cadastrar("Joao Souza", 5678, "Gerente", 4500.0);

    f1.mostrarDados();
    f2.mostrarDados();

    if(mesmoCargo(f1, f2)){
        std::cout << "\nOs funcionarios possuem o mesmo cargo." << std::endl;
    }else{
        std::cout << "\nOs funcionarios possuem cargos diferentes." << std::endl;
    }

    f1.acessarSalario();
    f2.acessarSalario();
    f2.alterarSalario(5000.0);
    f2.acessarSalario();

    return 0;
}