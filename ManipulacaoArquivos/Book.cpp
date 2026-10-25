#include "Book.h"
#include <iostream>

// Construtor padrao (inicializa vazio e disponivel)
Book::Book() : ISBN(""), titulo(""), disponivel(true) {}

// Construtor parametrizado
Book::Book(const std::string& isbn, const std::string& titulo, bool disponivel) : ISBN(isbn), titulo(titulo), disponivel(disponivel) {}

// Metodos Getters
std::string Book::getISBN() const {
    return ISBN;
}

std::string Book::getTitulo() const {
    return titulo;
}

bool Book::isDisponivel() const {
    return disponivel;
}

// Metodos de Acao
void Book::emprestar() {
    disponivel = false;
}

void Book::devolver() {
    disponivel = true;
}

void Book::exibirDados() const {
    std::cout << "ISBN: " << ISBN 
              << " | Título: " << titulo 
              << " | Status: " << (disponivel ? "Disponível" : "Emprestado") 
              << std::endl;
}