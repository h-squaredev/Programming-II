#include <iostream>
#include <string>

class Livro {
    private:
        std::string titulo;
        std::string autor;
        int anoPublicacao;
        int numeroPaginas;
    public:
        // Construtor
        Livro (std::string t, std::string a, int ano, int num) : titulo (t) , autor (a) , anoPublicacao (ano) , numeroPaginas(num) {};
        // Metodos Seletores (getters / GET)
        std::string getTitulo() {return titulo;}
        std::string getAutor() {return autor;}
        int getAnoPublicacao() {return anoPublicacao;}
        int getPaginas() {return numeroPaginas;}
        // Metodos Modificadores (setters / SET)
        void setTitulo (std::string t) {titulo = t;}
        void setAutor (std::string a) {autor = a;}
        void setAnoPublicacao (int ano) {anoPublicacao = ano;}
        void setPaginas (int num) {numeroPaginas = num;}

        //funcao para mostrar os dados da classe
        void mostrarDados(){
            std::cout << "Titulo: " << titulo << ", Autor: " << autor << ", Ano de Publicacao: " << anoPublicacao << ", Numero de Pg: " << numeroPaginas << std::endl;
        }

};

int main(){
    Livro l1("1984", "George Orwell", 1949, 328);

    l1.mostrarDados(); // Titulo: 1984, Autor: George Orwell, Ano: 1949, Paginas: 328

    Livro l2("Fogo Morto", "Graciliano Ramos", 1933, 229);
    l2.mostrarDados(); // Titulo: Fogo Morto, Autor: Graciliano Ramos, Ano: 1933, Paginas: 229 

    l2.setPaginas(299);
    l2.mostrarDados(); // Titulo: Fogo Morto, Autor: Graciliano Ramos, Ano: 1933, Paginas: 299
    
    return 0;
}