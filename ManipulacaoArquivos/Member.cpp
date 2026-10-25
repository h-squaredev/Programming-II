#include "Member.h"
#include <iostream>

// Construtor padrao
Member::Member() : ID(0), Nome("") {}

// Construtor parametrizado
Member::Member(int id, const std::string& nome) : ID(id), Nome(nome) {}

// Metodos Getters
int Member::getID() const {
    return ID;
}

std::string Member::getNome() const {
    return Nome;
}

std::vector<std::string> Member::getLivrosEmprestados() const {
    return LivrosEmprestados;
}

// Metodos de Acao
void Member::adicionarLivro(const std::string& isbn) {
    LivrosEmprestados.push_back(isbn);
}

void Member::removerLivro(const std::string& isbn) {
    for (auto it = LivrosEmprestados.begin(); it != LivrosEmprestados.end(); ++it) {
        if (*it == isbn) {
            LivrosEmprestados.erase(it);
            break;
        }
    }
}

void Member::exibirDados() const {
    std::cout << "ID: " << ID << " | Nome: " << Nome << std::endl;
    std::cout << "Livros Emprestados (ISBNs): ";
    
    if (LivrosEmprestados.empty()) {
        std::cout << "Nenhum";
    } else {
        for (const std::string& isbn : LivrosEmprestados) {
            std::cout << isbn << " ";
        }
    }
    std::cout << std::endl;
}