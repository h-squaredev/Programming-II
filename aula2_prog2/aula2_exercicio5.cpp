#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Recebe uma string de senha e retorna "Senha valida" se ela atender aos critérios, ok, 
// caso contrário, retorna "Senha invalida"
string valida_senha(const string &senha) {

    //validação da senha:
    bool tem1_maiuscula = false;
    bool tem1_minuscula = false;
    bool tem1_digito = false;
    bool tem1_caractere_especial = false;
    const string caracteres_especiais = "!@#$%^&*()-+";

        //verifica cada caractere da senha
        for (const char &c : senha) {
            if (isupper(static_cast<unsigned char>(c))) {
                tem1_maiuscula = true;
            } else if (islower(static_cast<unsigned char>(c))) {
                tem1_minuscula = true;
            } else if (isdigit(static_cast<unsigned char>(c))) {
                tem1_digito = true;
            } else if (caracteres_especiais.find(c) != string::npos) {
                tem1_caractere_especial = true;
            }
            }
        
        // validação final e retorno do resultado
        if (senha.length() < 8 || !tem1_maiuscula || !tem1_minuscula || !tem1_digito || !tem1_caractere_especial) {
            return "Senha invalida";
        } else {
            return "Senha valida";
        }
    }

//programa principal
int main (){
    string senha;
    cout << "Digite uma senha: ";
    getline (cin, senha);

    string resultado = valida_senha(senha);
    cout << resultado << endl;

    return 0;
}