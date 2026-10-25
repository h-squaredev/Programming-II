#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Lista de palavras menores que devem permanecer em minúsculas
bool eh_palavra_menor(const string& palavra) {
    static const vector<string> palavras_menores = {
        "a", "o", "e", "de", "da", "do", "em", "na", "no", "com", "por"
    };
    return find(palavras_menores.begin(), palavras_menores.end(), 
                    palavra) != palavras_menores.end();
}

// Converte uma palavra para minúscula
void para_minuscula(string& palavra) {
    transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
}

// Converte primeira letra para maiúscula
void capitaliza_primeira_letra(string& palavra) {
    if (!palavra.empty()) {
        palavra[0] = toupper(palavra[0]);
    }
}

void converte_para_title_case(string& texto) {
    istringstream stream(texto);
    string palavra;
    vector<string> palavras;
    
    // Separa o texto em palavras
    while (stream >> palavra) {
        palavras.push_back(palavra);
    }
    
    if (palavras.empty()) return;
    
    // Processa cada palavra
    for (size_t i = 0; i < palavras.size(); i++) {
        para_minuscula(palavras[i]);
        
        // Primeira e última palavras sempre começam com maiúscula
        if (i == 0 || i == palavras.size() - 1) {
            capitaliza_primeira_letra(palavras[i]);
        }
        // Para as demais palavras, verifica se é palavra menor
        else if (!eh_palavra_menor(palavras[i])) {
            capitaliza_primeira_letra(palavras[i]);
        }
    }
    
    // Reconstrói o texto
    texto.clear();
    for (size_t i = 0; i < palavras.size(); i++) {
        texto += palavras[i];
        if (i < palavras.size() - 1) {
            texto += " ";
        }
    }
}

// Função para teste
int main() {
    string texto = "o ladrao de casaca";
    cout << "Texto original: " << texto << endl;
    
    converte_para_title_case(texto);
    cout << "Texto convertido: " << texto << endl;
    
    return 0;
}