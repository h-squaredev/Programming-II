#include <iostream>
#include <string>

//Definindo a classe veiculo
class Veiculo {
    public:
    std::string placa;
    std::string modelo;
    std::string tipo;
    int ano;
    int quilometragem;
    bool status; // true = disponivel, false = indisponivel

    //Mostrando a disponibilidade do veiculo
    bool disponibilidade(){
        if(status == true){
            std::cout << "Em operacao" << std::endl;
            return true;
        }else{
            std::cout << "Em manutenção" << std::endl;
            return false;
        }
    }

    
    //Mostrando os dados do veiculo
    void mostrarDados_veiculo(){
        std::cout << "=============== DADOS DO VEICULO ABAIXO ===============" << std::endl;
        std::cout << "Placa: " << placa << std::endl;
        std::cout << "Modelo: " << modelo << std::endl;
        std::cout << "Tipo: " << tipo << std::endl;
        std::cout << "Ano: " << ano << std::endl;
        std::cout << "Quilometragem: " << quilometragem << std::endl;
        std::cout << "Status: " << (status ? "Em operacao" : "Em manutencao") << std::endl;
    }

    //Cadastrando o veiculo
    void cadastro_veiculo(std::string novaPlaca, std::string novoModelo, std::string novoTipo ,int novoAno, int novaQuilometragem){
        placa = novaPlaca;
        modelo = novoModelo;
        tipo = novoTipo;
        ano = novoAno;
        quilometragem = novaQuilometragem;
    }
};


//Definindo a classe motorista
class motorista {
    public:
    std::string nome;
    int numID;
    int idade;
    std::string CNH;

    //mostrando os dados do motorista
    void mostrarDados_motorista(){
        std::cout << "\n=============== DADOS DO MOTORISTA ABAIXO ===============" << std::endl;
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Numero de Identificacao: " << numID << std::endl;
        std::cout << "Idade: " << idade << std::endl;
        std::cout << "CNH: " << CNH << std::endl;
    }

    //cadastrando o motorista
    void cadastro_motorista(std:: string novoNome, int novoNumID, int novaIdade, std::string novaCNH){
        nome = novoNome;
        numID = novoNumID;
        idade = novaIdade;
        CNH = novaCNH;
    }

};

//autorizacao de motorista para veiculo
void autorizacao(motorista m, Veiculo v){
    if(v.tipo == "Carro" && (m.CNH == "B" || m.CNH == "AB")){
        std::cout << "\nMotorista autorizado a dirigir o veiculo." << std::endl;
    }else{
        std::cout << "\nMotorista nao autorizado a dirigir o veiculo." << std::endl;
    }


}


int main(){
    Veiculo v1;
    v1.cadastro_veiculo("XYZ-9876", "Ford Ka", "Carro", 2018, 45000);
    v1.status = true;
    v1.disponibilidade();
    v1.mostrarDados_veiculo();

    motorista m1;
    m1.cadastro_motorista("Carlos Silva", 67890, 30, "B");
    m1.mostrarDados_motorista();

    autorizacao(m1, v1);
    return 0;
}