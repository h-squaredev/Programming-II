#include <iostream>
#include <string>

//classe representando os livros
class livro {
    public:
    std::string titulo;
    std::string autor;
    int ano;
    int livroID;
    bool status;

    void mostrarDados(){
        std::cout << "\n=============== DADOS DO LIVRO ABAIXO ===============" << std::endl;
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Autor: " << autor << std::endl;
        std::cout << "Ano: " << ano << std::endl;
        std::cout << "ID do Livro: " << livroID << std::endl;
        std::cout << "Status: " << (status ? "Disponivel" : "Emprestado") << std::endl;
    }

    void cadastrar(std::string novoTitulo, std::string novoAutor, int novoAno, int novoLivroID){
        titulo = novoTitulo;
        autor = novoAutor;
        ano = novoAno;
        livroID = novoLivroID;
        status = true; // Disponivel por padrao
    }

    bool emprestar(){
        if(status == true){
            status = false;
            return true;
        }else{
            return false;
        }   
    }

    bool devolver(){
        if(status == false){
            status = true;
            return true;
        }else{
            return false;
        }
    }

    
};

//classe representando os leitores
class leitor {
    public:
    std::string nome;
    int leitorID;
    int quantidadeEmprestimos;

    void mostrarDados(){
        std::cout << "\n=============== DADOS DO LEITOR ABAIXO ===============" << std::endl;
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "ID do Leitor: " << leitorID << std::endl;
        std::cout << "Quantidade de Emprestimos: " << quantidadeEmprestimos << std::endl;

    }

    void cadastrar(std::string novoNome, int novoLeitorID){
        nome = novoNome;
        leitorID = novoLeitorID;
        quantidadeEmprestimos = 0;
    }

    void adicionarEmprestimos(){
        quantidadeEmprestimos++;
    }

};

//funcao para realizar emprestimo
bool realizarEmprestimo(livro &l, leitor &le){
    if(l.emprestar()){
        le.adicionarEmprestimos();
        std::cout << "Emprestimo realizado com sucesso para " << le.nome << "!" << std::endl;
        return true;
    }else{
        std::cout << "Falha: O livro '" << l.titulo << "' ja esta emprestado." << std::endl;
        return false;
    }
}

//funcao para realizar devolucao
bool realizarDevolucao(livro &l){
    if(l.devolver()){
        std::cout << "Devolucao realizada com sucesso!" << std::endl;
        return true;
    }else{
        std::cout << "Erro: Este livro ja estava na biblioteca." << std::endl;
        return false;
    }
}

//funcao principal
int main(){
    livro livro1;
    leitor leitor1;

    livro1.cadastrar("1984", "George Orwell", 1949, 101);
    leitor1.cadastrar("Alice", 1809);

    livro1.mostrarDados();
    leitor1.mostrarDados();

    realizarEmprestimo(livro1, leitor1);
    livro1.mostrarDados();  
    leitor1.mostrarDados();

    realizarDevolucao(livro1);
    livro1.mostrarDados();

    return 0;
}