//Exercicio 4: Biblioteca de Midia

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Classe PAi / Base
class Midia {
protected: //permite que as classes filhas acessem essa variável diretamente
    string titulo; 

public:
    //Construtor
    Midia(string t) : titulo(t) {}

    // Metodos puramente virtuais
    virtual void exibirInfo() = 0;
    virtual void reproduzir() = 0;

    // Destrutor virtual
    virtual ~Midia() {}
};

// Classe Livro
class Livro : public Midia {
private:
    string autor;
public:
    // Repassa o titulo para a classe pai (Midia) e guarda o autor aqui
    Livro(string t, string a) : Midia(t), autor(a) {}

    void exibirInfo() override {
        cout << "Livro: " << titulo << " por " << autor << endl;
    }

    void reproduzir() override {
        cout << "Abrindo o livro " << titulo << endl;
    }
};

// Classe CD
class CD : public Midia {
private:
    string artista;
public:
    CD(string t, string a) : Midia(t), artista(a) {}

    void exibirInfo() override {
        cout << "CD: " << titulo << " por " << artista << endl;
    }

    void reproduzir() override {
        cout << "Tocando CD " << titulo << endl;
    }
};

// Classe DVD
class DVD : public Midia {
private:
    string diretor;
public:
    DVD(string t, string d) : Midia(t), diretor(d) {}

    void exibirInfo() override {
        cout << "DVD: " << titulo << " dirigido por " << diretor << endl;
    }

    void reproduzir() override {
        cout << "Reproduzindo DVD " << titulo << endl;
    }
};

int main() {
    // Vetor de ponteiros para a classe base
    vector<Midia*> biblioteca;

    biblioteca.push_back(new Livro("O Senhor dos Anéis", "J.R.R. Tolkien"));
    biblioteca.push_back(new CD("Thriller", "Michael Jackson"));
    biblioteca.push_back(new DVD("Inception", "Christopher Nolan"));

    // Loop para percorrer e executar os metodos
    for (Midia* item : biblioteca) {
        item->exibirInfo();
        item->reproduzir();
    }

    // Limpeza de memoria
    for (Midia* item : biblioteca) {
        delete item;
    }

    return 0;
}