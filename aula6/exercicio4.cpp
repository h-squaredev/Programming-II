#include <iostream>
#include <string>

class Carro {
    private:
        std::string marca;
        std::string modelo;
        int ano;
        double quilometragem;
    public:
        // Construtor
        Carro (std::string mrc, std::string mdl, int an, double km) : marca (mrc) , modelo (mdl) , ano (an) , quilometragem (km) {};
        // Metodos Seletores (getters / GET)
        std::string getMarca() {return marca;}
        std::string getModelo() {return modelo;}
        int getAno() {return ano;}
        double getQuilometragem() {return quilometragem;}
        // Metodos Modificadores (setters / SET)
        void setMarca (std::string mrc) {marca = mrc;}
        void setModelo (std::string mdl) {modelo = mdl;}
        void setAno (int an) {ano = an;}
        void setQuilometragem (double km) {quilometragem = km;}

        //funcao para dirigir o carro, aumentando a quilometragem
        void dirigir(double km) {
            quilometragem += km;
        }

        //funcao para mostrar os dados da classe
        void mostrarDados(){
            std::cout << "Marca: " << marca << ", Modelo: " << modelo << ", Ano: " << ano << ", Quilometragem: " << quilometragem << std::endl;
        }

};

int main(){
    Carro c1("Toyota", "Corolla", 2020, 15000);
    c1.mostrarDados(); // Marca: Toyota, Modelo: Corolla, Ano: 2020, Quilometragem: 15000

    c1.dirigir(500);
    c1.mostrarDados(); // Marca: Toyota, Modelo: Corolla, Ano: 2020, Quilometragem: 15500

    return 0;
}