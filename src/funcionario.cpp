#include "funcionario.h"

Funcionario::Funcionario() {
    nome = "";
    salario = 0;
    admissao = "";
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

string Funcionario::getAdmissao() {
    return admissao;
}

void Funcionario::setAdmissao(string a) {
    admissao = a;
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
    os << "Admissao: " << f.admissao;
	return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	f Referência para o objeto Funcionário a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Funcionario &f) {
	is >> f.nome >> f.salario >> f.admissao;
	return is;
}