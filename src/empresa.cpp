#include "empresa.h"

Empresa::Empresa() {
    nome = "";
    cnpj = "";
    qtde = 0;
    funcionarios = new Funcionario*[3];
}

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

bool Empresa::addFuncionario(Funcionario *f) {
    funcionarios[qtde] = f;
    qtde++;
    return true;
}

Funcionario **Empresa::getFuncionarios() {
    return funcionarios;
}

int Empresa::getQtde() {
    return qtde;
}