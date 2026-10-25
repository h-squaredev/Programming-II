//Exercicio 2: Sistema de Pagamento


#include <iostream>
#include <vector>
#include <string>
#include <memory>

//classe pai / base de forma abstrata
class Empregado {
    public:
        virtual double getSalarioMensal() = 0; // Metodo virtual puro
        virtual void imprimirDetalhes() = 0; // Metodo virtual puro
        virtual ~Empregado() = default; //Destrutor virtual
};

//Classe filha / derivada para empregado assalariado
class EmpregadoAssalariado : public Empregado {
    private:
        double salarioMensal;
    public:
        EmpregadoAssalariado (double salario) : salarioMensal(salario) {}
        double getSalarioMensal() override {return salarioMensal;}
        void imprimirDetalhes() override {
            std::cout << "Empregado Assalariado, Salario Mensal: " << salarioMensal << std::endl;
        }
};

//Classe filha / derivada para empregado horista
class EmpregadoHorista : public Empregado {
    private:
        double horasTrabalhadas;
        double taxaPorHora;
    public:
        EmpregadoHorista (double horas, double taxa) : horasTrabalhadas(horas), taxaPorHora(taxa) {}
        double getSalarioMensal() override {return horasTrabalhadas * taxaPorHora;}
        void imprimirDetalhes() override {
            std::cout << "Empregado Horista, Horas Trabalhadas: " << horasTrabalhadas << ", Taxa por Hora: " << taxaPorHora << std::endl;
        }
};


int main(){
    std::vector<std::shared_ptr<Empregado>> empregados;
    empregados.push_back(std::make_shared<EmpregadoAssalariado>(3000.00));
    empregados.push_back(std::make_shared<EmpregadoHorista>(160, 25.00));

    for (const auto& empregado : empregados){
        empregado->imprimirDetalhes();

        std::cout << "Salario Mensal: " << empregado->getSalarioMensal() << std::endl;
    }

    return 0;
}

/* Saida esperada:
Empregado Assalariado, Salario Mensal: 3000
Salario Mensal: 3000
Empregado Horista, Horas Trabalhadas: 160, Taxa por Hora: 25
Salario Mensal: 4000 */