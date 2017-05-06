#include "empresa.h"

Empresa::Empresa() {
    nome = "";
    cnpj = "";
    qtde = 0;
}

/*Empresa::Empresa(int f) {
    nome = "";
    cnpj = "";
    qtde = f;
    funcionarios = new Funcionario[f];
}*/

/*Empresa::Empresa(Empresa &e) {
    nome = e.getNome();
    cnpj = e.getCnpj();
    qtde = e.getQtde();
    //funcionarios = new Funcionario[e.getQtde()];
    funcionarios = e.getFuncionarios();
}*/

Empresa::~Empresa() {
    if(qtde > 0)
        delete[] funcionarios;
}

string Empresa::getNome() {
    return nome;
}

void Empresa::setNome(string n) {
    nome = n;
}

string Empresa::getCnpj() {
    return cnpj;
}

void Empresa::setCnpj(string c) {
    cnpj = c;
}

int Empresa::getQtde() {
    return qtde;
}

Funcionario *Empresa::getFuncionarios() {
    return funcionarios;
}

void Empresa::setFuncionarios(Funcionario *f, int n) {
    funcionarios = new Funcionario[n];
    for(int i = 0; i < n; i++) {
        funcionarios[i].setNome(f[i].getNome());
        funcionarios[i].setSalario(f[i].getSalario());
        funcionarios[i].setAdmissao(f[i].getAdmissao());
    }
    qtde = n;
}

bool Empresa::addFuncionario(Funcionario *f) {
    if(pertenceQuadro(f->getNome())) 
        return false;

    //Cria um vetor maior
    Funcionario *arr = new Funcionario[qtde + 1];

    //Se já tem funcionários, copia a antiga lista para um novo maior
    for(int i = 0; i < qtde; i++)
        arr[i] = funcionarios[i];

    if(qtde > 0)
        delete[] funcionarios;
    
    funcionarios = arr;     //Vetor antigo recebe a nova lista
    funcionarios[qtde++] = f[0];  //Guarda o elemento informado e incrementa a quantidade de funcionarios
    
    return true;
}

bool Empresa::delFuncionario(int f) {
    if((f < 0) || (f >= qtde))
        return false;

    //Cria um vetor menor
    Funcionario *arr = new Funcionario[qtde - 1];

    //Se já tem funcionários, copia a antiga lista para uma nova menor
    int j = 0;
    for(int i = 0; i < qtde; i++) {
        if(i != f)    //Se não é o funcionário à remover, copie
            arr[j++] = funcionarios[i];
    }
    delete[] funcionarios;

    funcionarios = arr;     //Vetor antigo recebe a nova lista
    qtde--;
    
    return true;
}

bool Empresa::pertenceQuadro(string n) {
    for(int i = 0; i < qtde; i++)
        if(funcionarios[i].getNome() == n)
            return true;
    return false;
}

void Empresa::aumento(float percentual) {
    for(int i = 0; i < qtde; i++)
        funcionarios[i].setSalario(funcionarios[i].getSalario() * (1 + (percentual/100)));
}

string Empresa::exportar() {
    return "empr;" + nome + ";" + cnpj;
}

/** 
* @details O operador é sobrecarregado para representar a empresa e seus funcionários
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Empresa a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Empresa &e) {
	os << "Nome: " << e.nome << " - ";
	os << "CNPJ: " << e.cnpj;
	return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Empresa a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Empresa &e) {
	is >> e.nome >> e.cnpj;
	return is;
}