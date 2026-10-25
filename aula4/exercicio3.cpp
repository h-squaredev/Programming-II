#include <iostream>
#include <array>
#include <algorithm>
#include <string>

int main() {
    std::array<int, 6> pontuacoes = {850, 420, 610, 900, 300, 750};

    int pontuacaoAlvo = 610;

    std::sort(pontuacoes.begin(), pontuacoes.end());

    std::cout << "--- Placar de Lideres Ordenado ---" << std::endl;
    for (int pontuacao : pontuacoes) {
        std::cout << pontuacao << " pontos" << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;

    bool alvoEncontrado = std::binary_search(pontuacoes.begin(), pontuacoes.end(), pontuacaoAlvo);

    if (alvoEncontrado) {
        std::cout << "\nResultado: A pontuacao alvo (" << pontuacaoAlvo << ") FOI encontrada no placar!" << std::endl;
    } else {
        std::cout << "\nResultado: A pontuacao alvo (" << pontuacaoAlvo << ") NAO foi encontrada no placar." << std::endl;
    }

    int pontuacaoFalsa = 421;
    bool falsoEncontrado = std::binary_search(pontuacoes.begin(), pontuacoes.end(), pontuacaoFalsa);

    if (!falsoEncontrado) {
         std::cout << "Resultado (teste): A pontuacao (" << pontuacaoFalsa << ") NAO foi encontrada no placar." << std::endl;
    }

    return 0;
}