#include <iostream>
#include <array>
#include <cmath>
#include <iomanip>

int main() {
    std::array<std::array<int, 3>, 3> pontos3D = {
        {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        }
    };

    std::cout << "--- Coordenadas 3D Armazenadas ---" << std::endl;
    
    for (const auto& ponto : pontos3D) {
        std::cout << "(";
        int contagem = 0;
        
        for (int coordenada : ponto) {
            std::cout << coordenada;
            if (contagem < 2) {
                std::cout << ", ";
            }
            contagem++;
        }
        std::cout << ")" << std::endl;
    }

    double dist1_2 = std::sqrt(
        std::pow(pontos3D[1][0] - pontos3D[0][0], 2) + 
        std::pow(pontos3D[1][1] - pontos3D[0][1], 2) + 
        std::pow(pontos3D[1][2] - pontos3D[0][2], 2)  
    );
    
    double dist2_3 = std::sqrt(
        std::pow(pontos3D[2][0] - pontos3D[1][0], 2) + 
        std::pow(pontos3D[2][1] - pontos3D[1][1], 2) + 
        std::pow(pontos3D[2][2] - pontos3D[1][2], 2)  
    );

    std::cout << "\n--- Calculo de Distancias ---" << std::endl;
    std::cout << std::fixed << std::setprecision(4); 
    
    std::cout << "Distancia do Ponto 1 para o Ponto 2: " << dist1_2 << std::endl;
    std::cout << "Distancia do Ponto 2 para o Ponto 3: " << dist2_3 << std::endl;

    return 0;
}