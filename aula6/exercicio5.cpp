#include <iostream>
#include <string>

class Aluno {
    private:
    std::string nome;
    int matricula;
    std::string curso;
    int nota;
    public:
    // Construtor
    Aluno (std::string n, int m, std::string c, int nt) : nome (n) , matricula (m) , curso (c) , nota (nt) {};
    // Metodos Seletores (getters / GET)
    std::string getNome() {return nome;}
    int getMatricula() {return matricula;}
    std::string getCurso() {return curso;}
    int getNota() {return nota;}
    // Metodos Modificadores (setters / SET)
    void setNome (std::string n) {nome = n;}
    void setMatricula (int m) {matricula = m;}
    void setCurso (std::string c) {curso = c;}
    void setNota (int nt) {nota = nt;}

    //funcao para mostrar os dados da classe
    void mostrarDados(){
        std::cout << "Nome: " << nome << ", Matricula: " << matricula << ", Curso: " << curso << ", Nota: " << nota << std::endl;
    }

    void calcularMedia(int totalNotas, int numeroNotas) {
        if (numeroNotas > 0) {
            double media = static_cast<double>(totalNotas) / numeroNotas;
            std::cout << "Media: " << media << std::endl;
        } else {
            std::cout << "Media: 0" << std::endl;
        }
    }

    bool verificarAprovacao(int notaMinima) {
        return nota >= notaMinima;
    }

};

int main(){
    Aluno a1("Maria Silva ", 202345, "Engenharia ", 7.5);
    a1.mostrarDados(); // Nome : Maria Silva , Matricula : 202345 , Curso :Engenharia, Nota : 7.5 

    a1.calcularMedia(a1.getNota(), 1);
    std::cout << "Aprovado: " << (a1.verificarAprovacao(7) ? "Sim" : "Nao") << std::endl; // Aprovado: Sim

return 0;

}
