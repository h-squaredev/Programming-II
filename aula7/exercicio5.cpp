//Exercicio 5: Sistema de Transporte

#include <iostream>
#include <vector>

using namespace std;

//Classe  pai / Base de forma Abstrata
class Transporte {
public:
    virtual void iniciar() = 0;
    virtual void parar() = 0;

    // Destrutor virtual
    virtual ~Transporte() {}
};

// Classe Carro
class Carro : public Transporte {
public:
    void iniciar() override {
        cout << "Carro iniciando" << endl;
    }

    void parar() override {
        cout << "Carro parando" << endl;
    }
};

// Classe Bicicleta
class Bicicleta : public Transporte {
public:
    void iniciar() override {
        cout << "Bicicleta iniciando" << endl;
    }

    void parar() override {
        cout << "Bicicleta parando" << endl;
    }
};

//Classe Aviao 
class Aviao : public Transporte {
public:
    void iniciar() override {
        cout << "Aviao decolando" << endl;
    }

    void parar() override {
        cout << "Aviao pousando" << endl;  
    }
};

int main() {
    // Vetor de ponteiros para a classe base
    vector<Transporte*> transportes;

    transportes.push_back(new Carro());
    transportes.push_back(new Bicicleta());
    transportes.push_back(new Aviao());

    // Loop para percorrer e executar os metodos
    for (Transporte* t : transportes) {
        t->iniciar();
        t->parar();
    }

    // Limpeza de memoria
    for (Transporte* t : transportes) {
        delete t;
    }

    return 0;
}