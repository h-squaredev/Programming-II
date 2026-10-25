#include <iostream>
#include <string>

using namespace std;

int main(){
    string s("hello world");
    for (auto &c : s){ //s é um ponteiro para o primeiro caractere da string
        c = toupper(c);
    }
    cout << "c" << endl;
}