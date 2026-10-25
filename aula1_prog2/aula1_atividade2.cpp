#include <iostream>

using namespace std;

bool eh_primo(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int n;

    cout << "Digite seu numero:  \n" << "\n";
    if (!(cin >> n)) {
        cout << "Entrada invalida\n";
        return 1;
    }

    cout << "Seu numero primo eh: " << (eh_primo(n) ? "true" : "false") << "\n";
    return 0;
}