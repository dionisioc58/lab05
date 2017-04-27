#include "empresa.h"

Empresa::Empresa() {
    nome = "";
    cnpj = "";
    qtde = 0;
    //funcionarios = new Funcionario[1];
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

bool Empresa::addFuncionario(Funcionario f) {
    if(qtde > 0) {
        //Se já tem funcionários, aumenta o vetor, copia a antiga lista para um novo maior
        Funcionario *resize_arr = new Funcionario[qtde + 1];
        for(int i = 0; i < (qtde); i++)
            resize_arr[i] = funcionarios[i];
        funcionarios = resize_arr;
        delete[] resize_arr;
    } else //Se não, basta criar um vetor com um elemento
        funcionarios = new Funcionario[1];

    funcionarios[qtde] = f;  //Guarda o elemento informado
    ++qtde;                  //Incrementa a quantidade de funcionarios
    return true;
}

Funcionario Empresa::getFuncionario(int n) {
    return funcionarios[n];
}

int Empresa::getQtde() {
    return qtde;
}