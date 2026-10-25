#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Member{
    private:
        int ID;
        std::string Nome;
        std::vector<std::string> LivrosEmprestados;
    public:
        //construtor padrao
        Member();
        //construtor parametrizado
        Member(int id, const std::string& Nome);

        //metodos
        int getID() const;
        std::string getNome() const;
        std::vector<std::string> getLivrosEmprestados() const;
        void adicionarLivro (const std::string& ISBN); 
        void removerLivro (const std::string& ISBN);
        void exibirDados() const;
};

#endif