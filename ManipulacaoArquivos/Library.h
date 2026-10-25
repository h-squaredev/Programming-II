#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <vector>
#include <string>

class Library {
    private:
        std::vector<Book> livros;
        std::vector<Member> membros;
    public:
        //construtor padrao
        Library() {}

        //metodos
        void carregarLivros(const std::string& nomeArquivo);
        void carregarMembros(const std::string& nomeArquivo);
        void registrarLivro(const Book& livro);
        void registrarMembro(const Member& membro);
        void gravarLivros(const std::string& nomeArquivo);
        void gravarMembros(const std::string& nomeArquivo);
        void listarLivros() const;
        void listarMembros() const;
        void emprestarLivro(const std::string& isbn, int idMembro);
        void devolverLivro(const std::string& isbn, int idMembro);
};


#endif