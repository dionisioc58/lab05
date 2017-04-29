#include "funcionario.h"

Funcionario::Funcionario() {
    nome = "";
    salario = 0;
}

Funcionario::Funcionario(Funcionario &f) {
    nome = f.getNome();
    salario = f.getSalario();
    admissao = f.getAdmissao();
}

Funcionario::~Funcionario() {
    //VAZIO
}

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

std::chrono::system_clock::time_point Funcionario::getAdmissao() {
    return admissao;
}

void Funcionario::setAdmissao(std::chrono::system_clock::time_point a) {
    admissao = a;
}