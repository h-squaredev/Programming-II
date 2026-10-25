#include <iostream>
#include <vector>
#include <iomanip> 

constexpr double TAXA_CONVERSAO = 0.93;

void converterParaEuro(std::vector<double>& vendas) {
    for (size_t i = 0; i < vendas.size(); ++i) {
        vendas.at(i) = vendas.at(i) * TAXA_CONVERSAO;
    }
}

int main() {
    std::vector<double> minhasVendas = {100.0, 50.0, 200.0};

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "--- Valores Originais (em Reais) ---" << std::endl;
    for (double valor : minhasVendas) {
        std::cout << "R$ " << valor << std::endl;
    }

    converterParaEuro(minhasVendas);

    std::cout << "\n--- Valores Convertidos (em Euros) ---" << std::endl;
    for (double valor : minhasVendas) {
        std::cout << "EUR " << valor << std::endl;
    }

    return 0;
}