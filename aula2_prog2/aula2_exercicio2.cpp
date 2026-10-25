#include <iostream>
#include <string>

using namespace std;
int main() {
    string line;
    const string::size_type tamMax = 80; 
    int linhasLongas = 0;
    string primeiraLinhaLonga;

    while(getline(cin, line)) {
        if (line == "SAIR") {
            break;
        }
        
        if (line.size() > tamMax) {
            linhasLongas++;
            if ( primeiraLinhaLonga.empty()) {
             primeiraLinhaLonga = line;
            }
            line = line.substr(0, tamMax);
        }
        cout << line << endl;
        }
        cout << "Total de linhas longas: " << linhasLongas << endl;
        if (linhasLongas > 0) {
        cout << "Primeira linha longa: " <<  primeiraLinhaLonga << endl;
        }


    return 0;
}