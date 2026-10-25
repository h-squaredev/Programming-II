#include <iostream>
#include <string>

using namespace std;

//funcao que busca a primeira vogal e conta o total de vogais

string::size_type busca_vogal_e_conta(const string &s, string::size_type &total_vogais){
    string vogais = "aeiouAEIOU";
    total_vogais = 0;

    string::size_type pos_primeira_vogal = s.size(); // valor inicial "nao encontrada"

    for (string::size_type i = 0; i < s.size(); i++)
    {
        if (vogais.find(s[i]) != string::npos)
        {
            // contar sempre que for encontrado
            total_vogais++;

            //    apenas guardamos a posicao 'i' se for a PRIMEIRA vez que encontramos uma vogal 
            //    (ou seja, se 'pos_primeira_vogal' ainda tiver o valor inicial)
            if (pos_primeira_vogal == s.size())
            {
                pos_primeira_vogal = i;
            }
        }
    }

    // Retornamos a posicao da primeira vogal so DEPOIS do loop terminar
return pos_primeira_vogal;

}

int main(){
    string texto;
    cout << "Digite uma string: ";
    getline(cin, texto);

    string::size_type total_vogais = 0;
    string::size_type pos = busca_vogal_e_conta(texto, total_vogais); // chamando a funcao

    if (pos != texto.size()){
        cout << "\nPrimeira vogal encontrada na posicao: " << pos << endl;

    }else{
        cout << "Nenhuma vogal encontrada." << endl;
    }

    cout << "Total de vogais na string: " << total_vogais << endl;

    return 0;
}
