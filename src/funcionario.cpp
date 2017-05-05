#include "funcionario.h"

Funcionario::Funcionario() {
    nome = "";
    salario = 0;
    admissao = std::time(NULL);
}

/*Funcionario::Funcionario(Funcionario &f) {
    nome = f.getNome();
    salario = f.getSalario();
    admissao = f.getAdmissao();
}*/

string Funcionario::getNome() {
    return nome;
}

void Funcionario::setNome(string n) {
    nome = n;
}

float Funcionario::getSalario() {
    return salario;
}

void Funcionario::setSalario(float s) {
    salario = s;
}

std::time_t Funcionario::getAdmissao() {
    return admissao;
}

void Funcionario::setAdmissao(std::time_t a) {
    admissao = a;
}

bool Funcionario::Experiencia() {
    std::time_t agora = std::time(NULL);
    double difference = std::difftime(agora, admissao) / (60 * 60 * 24);
    if(difference > 90)
        return false;
    return true;
}

/** 
* @details O operador é sobrecarregado para representar a empresa e seus funcionários
* @param	os Referência para stream de saída
* @param	f Referência para o objeto Funcionario a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Funcionario &f) {
	os << "Nome: " << f.nome << "\t| ";
	os << "Salário: " << f.salario << "\t| ";
    os << "Admissão: ";
    char mbstr[20];
    if (std::strftime(mbstr, sizeof(mbstr), "%d/%m/%Y", std::localtime(&f.admissao)))
        os << mbstr;
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	f Referência para o objeto Funcionário a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Funcionario &f) {
    string adm;
	is >> f.nome >> f.salario >> adm;

    int dia, mes, ano;
    dia = stoi(adm.substr(0, 2));
    mes = stoi(adm.substr(3, 2));
    ano = stoi(adm.substr(6, 4));
    std::tm a = {0, 0, 0, dia, mes - 1, ano - 1900};
    f.admissao = std::mktime(&a);
	
    return is;
}