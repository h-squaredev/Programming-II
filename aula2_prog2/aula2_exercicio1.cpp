#include <iostream>
#include <string>

using namespace std;


string formata_data (const string& DD, const string& MM, const string AA){
    string data_formatada = DD + "/" + MM + "/" + AA;
    cout << data_formatada << endl;
    return 0;

}

int main(){
    string dia, mes, ano;
    cout << "Digite o dia: ";
    cin >> dia;
    cout << "Digite o mes: ";
    cin >> mes;
    cout << "Digite o ano: ";
    cin >> ano;

    formata_data(dia, mes, ano);

    return 0;
}