#include "Library.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Library::carregarLivros(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir " << nomeArquivo << "\n";
        return;
    }

    std::string isbn, titulo, status;
    while (arquivo >> isbn >> titulo >> status) {
        bool disponivel = (status == "Disponivel");
        Book novoLivro(isbn, titulo, disponivel);
        livros.push_back(novoLivro);
    }
    arquivo.close();
}

void Library::carregarMembros(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir " << nomeArquivo << "\n";
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        int id;
        std::string nome, isbn;

        ss >> id >> nome;
        Member novoMembro(id, nome);

        while (ss >> isbn) {
            novoMembro.adicionarLivro(isbn);
        }
        membros.push_back(novoMembro);
    }
    arquivo.close();
}

void Library::gravarLivros(const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao gravar " << nomeArquivo << "\n";
        return;
    }

    for (const auto& livro : livros) {
        arquivo << livro.getISBN() << " " 
                << livro.getTitulo() << " " 
                << (livro.isDisponivel() ? "Disponivel" : "Emprestado") << "\n";
    }
    arquivo.close();
}

void Library::gravarMembros(const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao gravar " << nomeArquivo << "\n";
        return;
    }

    for (const auto& membro : membros) {
        arquivo << membro.getID() << " " << membro.getNome();
        for (const auto& isbn : membro.getLivrosEmprestados()) {
            arquivo << " " << isbn;
        }
        arquivo << "\n";
    }
    arquivo.close();
}

void Library::registrarLivro(const Book& livro) {
    livros.push_back(livro);
    std::cout << "Livro registrado!\n";
}

void Library::registrarMembro(const Member& membro) {
    membros.push_back(membro);
    std::cout << "Membro registrado!\n";
}

void Library::listarLivros() const {
    std::cout << "\n--- Livros ---\n";
    for (const auto& livro : livros) {
        livro.exibirDados();
    }
}

void Library::listarMembros() const {
    std::cout << "\n--- Membros ---\n";
    for (const auto& membro : membros) {
        membro.exibirDados();
    }
}

void Library::emprestarLivro(const std::string& isbn, int idMembro) {
    Book* livroEncontrado = nullptr;
    Member* membroEncontrado = nullptr;

    for (auto& livro : livros) {
        if (livro.getISBN() == isbn) {
            livroEncontrado = &livro;
            break;
        }
    }

    if (livroEncontrado == nullptr) {
        std::cout << "Livro nao encontrado.\n";
        return;
    }

    if (!livroEncontrado->isDisponivel()) {
        std::cout << "Livro ja emprestado.\n";
        return;
    }

    for (auto& membro : membros) {
        if (membro.getID() == idMembro) {
            membroEncontrado = &membro;
            break;
        }
    }

    if (membroEncontrado == nullptr) {
        std::cout << "Membro nao encontrado.\n";
        return;
    }

    livroEncontrado->emprestar();
    membroEncontrado->adicionarLivro(isbn);

    std::cout << "Emprestimo realizado!\n";
}

void Library::devolverLivro(const std::string& isbn, int idMembro) {
    Member* membroEncontrado = nullptr;
    Book* livroEncontrado = nullptr;

    for (auto& membro : membros) {
        if (membro.getID() == idMembro) {
            membroEncontrado = &membro;
            break;
        }
    }

    if (membroEncontrado == nullptr) {
        std::cout << "Membro nao encontrado.\n";
        return;
    }

    bool possuiLivro = false;
    for (const auto& livroISBN : membroEncontrado->getLivrosEmprestados()) {
        if (livroISBN == isbn) {
            possuiLivro = true;
            break;
        }
    }

    if (!possuiLivro) {
        std::cout << "O membro nao possui este livro.\n";
        return;
    }

    for (auto& livro : livros) {
        if (livro.getISBN() == isbn) {
            livroEncontrado = &livro;
            break;
        }
    }

    membroEncontrado->removerLivro(isbn);

    if (livroEncontrado != nullptr) {
        livroEncontrado->devolver();
    }

    std::cout << "Devolucao realizada!\n";
}