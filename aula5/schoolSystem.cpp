#include <iostream>
#include <string>

//Definindo a classs de alunos
class aluno {
    public:
    std::string nome;
    long long matricula;
    int idade;
    std::string mediaFinal;

    //mostrando os dados do aluno
    void mostrarDados(){
        std::cout << "\n=============== DADOS DO ALUNO ABAIXO ===============" << std::endl;
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Matricula: " << matricula << std::endl;
        std::cout << "Idade: " << idade << std::endl;
        std::cout << "Media Final: " << mediaFinal << std::endl;
    }

    //cadastrando o aluno
    void cadastrar(std::string novoNome, int novaMatricula, int novaIdade, std::string novaMediaFinal){
        nome = novoNome;
        matricula = novaMatricula;
        idade = novaIdade;
        mediaFinal = novaMediaFinal;
    }



}; // fim da classe aluno

//Definindo a classe de disciplinas
class disciplina {
    public:
    std::string nomeDisciplina;
    int cargaHoraria;
    std::string codigoDisciplina;
    int notaMinima;

    //mostrando os dados da disciplina
    void mostrarDados(){
        std::cout << "\n=============== DADOS DA DISCIPLINA ABAIXO ===============" << std::endl;
        std::cout << "Nome da Disciplina: " << nomeDisciplina <<  std::endl;
        std::cout << "Carga Horaria: " << cargaHoraria << std::endl;
        std::cout << "Codigo da Disciplina: " << codigoDisciplina << std::endl;
        std::cout << "Nota minima para aprovacao: " << notaMinima << std::endl;
    }

    //cadastrando a disciplina
    void cadastrar(std::string novoNomeDisciplina, std::string novoCodigoDisciplina, int novaCargaHoraria, int novaNotaMinima){
        nomeDisciplina = novoNomeDisciplina;
        cargaHoraria = novaCargaHoraria;
        codigoDisciplina = novoCodigoDisciplina;
        notaMinima = novaNotaMinima;
    }

}; // fim da classe disciplina

//funcao para verificar aprovacao do aluno
bool verificarAprovacao(aluno a, disciplina d){
    if(a.mediaFinal >= std::to_string(d.notaMinima)){
        std::cout << "\nAluno aprovado na disciplina " << d.nomeDisciplina << "!" << std::endl;
        return true;
    }else{
        std::cout << "\nAluno reprovado na disciplina " << d.nomeDisciplina << "." << std::endl;
        return false;
    }
}

//Programa principal
int main(){
    aluno aluno1;
    aluno1.nome = "Humberto Henrique Castro Rocha";
    aluno1.idade = 20;
    aluno1.matricula = 202512722003;
    aluno1.mediaFinal = "4,8"; 

    disciplina disciplina1;
    disciplina1.nomeDisciplina = "Programacao 2";
    disciplina1.cargaHoraria = 64;
    disciplina1.codigoDisciplina = "CCOMP2";
    disciplina1.notaMinima = 5;

    aluno1.mostrarDados();
    disciplina1.mostrarDados();
    verificarAprovacao(aluno1, disciplina1);
    
    return 0;

}