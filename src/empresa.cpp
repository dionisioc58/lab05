#include "empresa.h"

Empresa::Empresa() {
    nome = "";
    cnpj = "";
    qtde = 0;
}

Empresa::Empresa(Empresa &e) {
    nome = e.getNome();
    cnpj = e.getCnpj();
    qtde = e.getQtde();
    funcionarios = new Funcionario[e.getQtde()];
    funcionarios = e.getFuncionarios();
}

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

bool Empresa::addFuncionario(Funcionario f) {
    if(pertenceQuadro(f.getNome())) 
        return false;

    //Cria um vetor maior
    Funcionario *arr = new Funcionario[qtde + 1];

    //Se já tem funcionários, copia a antiga lista para um novo maior
    for(int i = 0; i < qtde; i++)
        arr[i] = funcionarios[i];
    
    funcionarios = arr;     //Vetor antigo recebe a nova lista
    funcionarios[qtde++] = f;  //Guarda o elemento informado e incrementa a quantidade de funcionarios
    
    return true;
}

bool Empresa::pertenceQuadro(string n) {
    for(int i = 0; i < qtde; i++)
        if(funcionarios[i].getNome() == n)
            return true;
    return false;
}