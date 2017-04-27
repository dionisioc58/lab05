#include "empresa.h"

string Empresa::getNome() {
    return nome;
}

void Empresa::setNome(string n) {
    nome = n;
}

string Empresa::getCnpj() {

}

void Empresa::setCnpj(string c) {

}

bool Empresa::addFuncionario(Funcionario f) {
    qtde++;
    funcionarios = new Funcionario[qtde];
    funcionarios[qtde-1] = f;
    return true;
}

Funcionario *Empresa::getFuncionarios() {
    return funcionarios;
}

int Empresa::getQtde() {
    return qtde;
}