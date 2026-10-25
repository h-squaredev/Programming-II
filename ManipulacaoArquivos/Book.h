#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>

class Book{
private:
    std::string ISBN;
    std::string titulo;
    bool disponivel;
public:
    //construtor padrao
    Book();
    //construtor parametrizado
    Book(const std::string& isbn, const std::string& titulo, bool disponivel = true);

    //metodos
    std::string getISBN() const;
    std::string getTitulo() const;
    bool isDisponivel() const;
    void emprestar();
    void devolver();
    void exibirDados() const;
};

#endif