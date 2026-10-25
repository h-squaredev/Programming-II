#include <iostream>
#include <string>

class PersonagemRPG {
    private:
        std::string nome;
        int nivel;
        int vidaAtual;
        int vidaMaxima;
        int experiencia;
    public:
        //construtores
        PersonagemRPG(std::string n) : nome(n), vidaAtual(vidaMaxima) {
            nivel = 1;              
            experiencia = 0;        
            vidaMaxima = nivel * 50;
            vidaAtual = vidaMaxima;
        }

        //Métodos Seletores (getters / GET)
        std::string getNome () {return nome;}
        int getNivel () {return nivel;}
        int getVidaAtual () {return vidaAtual;}
        int getVidaMaxima () {return vidaMaxima;}
        int getExperiencia () {return experiencia;}

        //Métodos Modificadores (setters / SET)
        void setNome (std::string n) {nome = n;}


        //Metodos Especiais
        void receberDano (int dano) {
            vidaAtual -= dano;
            if (vidaAtual < 0) vidaAtual = 0;
            std::cout << nome << " recebeu " << dano << " de dano!\n";
        }

        void curar (int cura) {
            vidaAtual += cura;
            if (vidaAtual > vidaMaxima) vidaAtual = vidaMaxima;
            std::cout << nome << " foi curado em " << cura << " pontos!\n";
        }

        void ganharExperiencia (int xp) {
            experiencia += xp;
            std::cout << nome << " ganhou " << xp << " de experiencia!\n";
            while (experiencia >= 100) {
                experiencia -= 100;
                nivel++;
                vidaMaxima = nivel * 50;
                vidaAtual = vidaMaxima;
                std::cout << nome << " subiu para o nivel " << nivel << "!\n";
            }
        }
        void exibirStatus() {
            std::cout << "Status de " << nome << ":\n";
            std::cout << "Nivel: " << nivel << "\n";
            std::cout << "Vida: " << vidaAtual << "/" << vidaMaxima << "\n";
            std::cout << "Experiencia: " << experiencia << "/100\n";
        }


};

int main(){
    std::cout << " --- Inicio do Jogo ---\n";
    PersonagemRPG heroi(" Aragorn ");
    heroi.exibirStatus();

    // Teste de Dano
    std ::cout << "\n--- Batalha contra Orc ---\n";
    heroi.receberDano(30);
    heroi.exibirStatus();

    // TENTATIVA DE TRAPACA ( Deve dar erro se descomentado )
    // heroi.vidaAtual = 1000;
    // heroi.nivel = 50;

    // Teste de Cura
    std ::cout << "\n--- Bebendo Pocao ---\n";
    heroi.curar(200); // Nao deve passar da vida maxima !
    heroi.exibirStatus();

    // Teste de Logica de Nivel
    std ::cout << "\n--- Ganho de Experiencia ---\n";
    heroi.ganharExperiencia(80);
    heroi.ganharExperiencia(30); // Total 110 XP -> Level Up + Sobra 10 XP

    std::cout<< "\n--- Status Final ---\n";
    heroi.exibirStatus();

    return 0;
}