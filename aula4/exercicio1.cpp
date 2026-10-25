//Exercicio 1: Controle de Estoque de Loja (std::array e constexpr)

#include <format>
#include <iostream>
#include <array>
#include <algorithm>

int main () {
    constexpr size_t NUM_PRODUTOS (5); // Número de produtos na loja
    constexpr double IMPOSTO = 0.15; // Imposto sobre vendas (15%)

    std::array<double, NUM_PRODUTOS> precosBase {};

    //atibuindo preços base
    for (size_t i{0}; i < precosBase.size(); ++i) {
        std::cout << "Digite o preco base do produto " << i + 1 << ": ";
        std::cin >> precosBase.at(i);
    }

    //calculando preços com imposto
    int i = 0;
    for (const auto &precosBase : precosBase) {
        double precoComImposto = precosBase * (1 + IMPOSTO);
        std::cout << "Preco final do produto " << i + 1 << " com imposto: \t" << precoComImposto << std::endl;
    }

    return 0;
}
