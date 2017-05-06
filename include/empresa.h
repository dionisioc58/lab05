#ifndef EMPRESA_H
    #define EMPRESA_H

    #include <iostream>
    #include <ctime>
    #include <string>
    using std::string;
    using std::endl;

    #include "funcionario.h"

    class Empresa {
    private:
        string nome;
        string cnpj;
        Funcionario *funcionarios;
        int qtde;
    public:
        Empresa();
        //Empresa(int f);
        //Empresa(Empresa &e);
        ~Empresa();
        string getNome();
        void setNome(string n);
        string getCnpj();
        void setCnpj(string c);
        int getQtde();
        Funcionario *getFuncionarios();
        void setFuncionarios(Funcionario *f, int n);
        bool addFuncionario(Funcionario *f);
        bool delFuncionario(int f);
        bool pertenceQuadro(string n);
        void aumento(float percentual);
        string exportar();
		friend ostream& operator<<(ostream& os, Empresa &e); /** @brief Sobrecarga do operador de inserção em stream */
		friend istream& operator>>(istream& is, Empresa &e); /** @brief Sobrecarga do operador de extração de stream */
    };

#endif