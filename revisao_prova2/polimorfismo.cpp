#include <iostream>
#include <string>
#include <vector>

// Classe Pai (Abstrata)

class Notificacao {
    public:
        virtual void enviar(std::string msg) = 0; // Método puro (obrigatório override)
        
        virtual ~Notificacao() {} // Destrutor virtual
};

// Classe filha: E-mail
class Email : public Notificacao {
    private:
        std::string destinatario;
        std::string assunto;
    
    public:
        Email(std::string dest, std::string ass) : destinatario(dest), assunto(ass) {}

        // Override: Implementação especifica para E-mail
        void enviar(std::string msg) override {
            std::cout << "[EMAIL] Para: " << destinatario << "\n";
            std::cout << "Assunto: " << assunto << "\n";
            std::cout << "Corpo: " << msg << "\n";
        }
};

//Classe filha: SMS
class SMS : public Notificacao {
    private:
        std::string numero;

    public:
        SMS(std::string num) : numero(num) {}

        // Override: Implementação especifica para SMS
        void enviar(std::string msg) override {
            std::cout << "[SMS] Enviando para " << numero << ": " << msg << "\n";
        }
};

//clsse filha: pushNotifacation
class PushNotification : public Notificacao {
    private:
        std::string device;
        std::string app;

    public:
        PushNotification(std::string d, std::string a) : device(d), app(a) {}

        // Override: Implementação especifica para Push
        void enviar(std::string msg) override {
            std::cout << "[PUSH] App: " << app << " | Device: " << device << "\n";
            std::cout << "Msg: " << msg << "\n";
        }
};

// Função principal
int main() {
    std::cout << "--- Sistema de Alerta de Servidores ---\n\n";

    std::vector<Notificacao*> canais;

    canais.push_back(new Email("admin@sys.com", "FALHA CRITICA"));
    canais.push_back(new SMS("11-99999-8888"));
    canais.push_back(new PushNotification("Device-X", "MonitorApp"));

    std::cout << ">>> Ocorreu um erro no Servidor DB-01! Enviando alertas...\n\n";

    std::string erro = "Servidor offline.";


    for (Notificacao* canal : canais) {
        canal->enviar(erro); 
        std::cout << "\n";
    }

    for (auto c : canais) delete c;
    canais.clear();

    return 0;
}