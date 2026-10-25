#include <iostream>
using namespace std;

//anotação do algoritimo:
//Retorna -1 se valores são negativos
//Retorna 0 se B > A
//Retorna MDC (A,B) caso contrário

int calcular_mdc(int A, int B){
    int R = 0;
    if (A <= 0 || B <= 0)
        return -1; //"sinalização" de que a função recebeu parâmetros no qual não precisarei dessa parte

    if (A > B){
        while (B != 0){
            R = A % B;
            A = B;
            B = R;
        }
        return A;

    }else{
        return 0; // "'sinalização" de que a função recebeu a função B > A
    }

}

int main(){
    cout << calcular_mdc(143,15) << endl;
}