//Exercicio 3: Formas Geometricas

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Classe Pai / Base de forma Abstrata
class Forma {
public:
    virtual double area() = 0;  // Metodo puramente virtual
    
    virtual ~Forma() {} // Destrutor virtual
};

// Classe Circulo
class Circulo : public Forma {
    private:
        double raio;
    public:
        Circulo(double r) : raio(r) {}
        
        double area() override {
            return M_PI * raio * raio; 
        }
};

// Classe Retangulo
class Retangulo : public Forma {
    private:
        double largura, altura;
    public:
        Retangulo(double l, double a) : largura(l), altura(a) {}
    
        double area() override {
            return largura * altura;
        }
};

// Classe Triangulo
class Triangulo : public Forma {
    private:
        double base, altura;
    public:
        Triangulo(double b, double a) : base(b), altura(a) {}
    
        double area() override {
            return (base * altura) / 2.0;
        }
};

// programa principal
int main() {
    vector<Forma*> formas;
    
    formas.push_back(new Circulo(5.0));
    formas.push_back(new Retangulo(4.0, 6.0));
    formas.push_back(new Triangulo(4.0, 5.0));
    
    for (Forma* forma : formas) {
        cout << "Area: " << forma->area() << endl;
    }
    
    //Limpeza de memoria
    for (Forma* forma : formas) {
        delete forma;
    }
    
    return 0;
}