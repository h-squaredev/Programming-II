#include <iostream>

using namespace std;

int calcular_mdc(int a, int b){
    int resto{1}, resultado;
    while (resto != 0){;

    resto = a % b;
    resultado = b;
    b = resto;
    a = b;
    }
    
return resultado;

}



int main(){
    int a, b;

    cout << "Digite o primerio valor \n" << "\n";
    cin >> a;
    cout << "Agora digite o segundo valor \n" << "\n";
    cin >> b;

    cout << "O valor do MDC eh: " << calcular_mdc(a, b) << "\n";
}