#include <iostream>
#include "Vetor2D.h"

int main(){
    lista10::Vetor2D v1(10.5f, 20.0f);
    lista10::Vetor2D v2(5.5f, 10.0f);

    lista10::Vetor2D v3 = v1 + v2;

    std::cout << "Vetor 1: " << v1 << std::endl;
    std::cout << "Vetor 2: " << v2 << std::endl;
    std::cout << "Soma (v3): " << v3 << std::endl;

    if (v1 == v2) {
        std::cout << "Os vetores sao iguais." << std::endl;
    } else {
        std::cout << "Os vetores sao diferentes." << std::endl;
    }

    return 0;


}