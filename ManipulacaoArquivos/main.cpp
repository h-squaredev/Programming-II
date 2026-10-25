#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

void exibirMenu() {
    cout << "\n====================================\n";
    cout << "        MENU DA Library\n";
    cout << "====================================\n";
    cout << "1. Registrar Book\n";      
    cout << "2. Registrar Member\n";     
    cout << "3. Listar Books\n";        
    cout << "4. Listar Members\n";       
    cout << "5. Emprestar Book\n";      
    cout << "6. Devolver Book\n";       
    cout << "7. Sair\n";                 
    cout << "Escolha uma opcao: ";
}

int main() {
    Library lib;

    lib.carregarLivros("Books.txt");
    lib.carregarMembros("Members.txt");

    int opcao = 0;

    while (opcao != 7) {
        exibirMenu();
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }

        switch (opcao) {
            case 1: {
                string isbn, titulo;
                cout << "Digite o ISBN: ";
                cin >> isbn;
                cout << "Digite o Titulo (sem espacos): ";
                cin >> titulo;
                
                Book novoBook(isbn, titulo, true); 
                lib.registrarLivro(novoBook);
                break;
            }
            case 2: {
                int id;
                string nome;
                cout << "Digite o ID do Member: ";
                cin >> id;
                cout << "Digite o Nome (sem espacos): ";
                cin >> nome;
                
                Member novoMember(id, nome);
                lib.registrarMembro(novoMember);
                break;
            }
            case 3:
                lib.listarLivros();
                break;
            case 4:
                lib.listarMembros();
                break;
            case 5: {
                string isbn;
                int id;
                cout << "Digite o ISBN do Book a emprestar: ";
                cin >> isbn;
                cout << "Digite o ID do Member: ";
                cin >> id;
                lib.emprestarLivro(isbn, id);
                break;
            }
            case 6: {
                string isbn;
                int id;
                cout << "Digite o ISBN do Book a devolver: ";
                cin >> isbn;
                cout << "Digite o ID do Member: ";
                cin >> id;
                lib.devolverLivro(isbn, id);
                break;
            }
            case 7:
                cout << "Salvando dados e encerrando o sistema...\n";
                // Métodos corrigidos
                lib.gravarLivros("Books.txt");
                lib.gravarMembros("Members.txt");
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }

    return 0;
}