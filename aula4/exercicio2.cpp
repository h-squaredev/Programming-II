//Exercicio 2: Monitoramento de Sensores de Temperatura  (std::vector Dinamico)

#include <format>
#include <iostream>
#include <vector>
#include <algorithm>

int main () {

    std::vector<int> leiturasTemp; // Vetor dinamico para armazenar as leituras de temperatura

    //Simulando a adicao de leituras de temperatura ao vetor
    leiturasTemp.push_back(65);
    leiturasTemp.push_back(70);
    leiturasTemp.push_back(72);

    std::cout << "Tamanho do vetor de leituras: " << leiturasTemp.size() << std::endl;

    //simulando falha de sensor
    leiturasTemp.push_back(85);

    cout << "Valor da ultima leitura (possivel erro): " << leiturasTemp.back() << std::endl;

    //Removendo a leitura incorreta
    leiturasTemp.pop_back();
    
    //Imprimindo a lita final de leituras
    std::cout << "Leituras de temperatura registradas: ";
    for(const auto& leitura : leiturasTemp){
        std::cout << leitura << " ";
    }

    return 0;

}