//Exercicio 1: Hierarquia de Animais

#include <iostream>
#include <vector>
#include <string>

// Classe pai / base
class Animal {
    private:
        std::string som;
    public:
        virtual std::string emitirSom(){  // Metodo virtual para ser sobrescrito pelas classes derivadas
            return som;
        }
};

// Classes filhos / derivadas
class Cachorro : public Animal{
    std::string emitirSom() override {return "Au Au";} // Sobrescreve o metodo emitirSom da classe base Animal
};

class Gato : public Animal{
    std::string emitirSom() override {return "Miau";}
};

class Vaca : public Animal{
    std::string emitirSom() override {return "Muuu";}
};


int main(){
    Cachorro cachorro;
    Gato gato;
    Vaca vaca;

    std::vector<Animal*> animais;
    animais.push_back(&cachorro);
    animais.push_back(&gato);
    animais.push_back(&vaca);

    for (Animal* animal : animais) {
       std::cout << animal->emitirSom() << std::endl;
    }
    return 0;
}

/* Saida esperada:
Au Au
Miau
Muuu */