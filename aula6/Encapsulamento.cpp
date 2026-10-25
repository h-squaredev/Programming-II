#include <iostream>

class Triangulo {
    private:
        float base;
        float altura;
    public:
        //construtores
        //...
        //Métodos Seletores (getters / GET)
        float getBase() {return base;}
        float getAltura() {return altura;}
        //Métodos Modificadores (setters / SET)
        void setBase(float b) {base = b;}
        void setAltura(float a) {altura = a;}

};

int main() {
    Triangulo t1;

    t1.setBase(10.0);
    t1.setAltura(20.0);

    std::cout << "Altura: " << t1.getAltura() << "Base: " << t1.getBase() << std::endl;
}