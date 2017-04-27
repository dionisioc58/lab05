#ifndef EMPRESA_H
    #define EMPRESA_H

    #include <ctime>
    #include <string>
    using std::string;

    #include "funcionario.h"

    class Empresa {
    private:
        string nome;
        string cnpj;
        Funcionario **funcionarios;
        int qtde;
    public:
        Empresa();
        string getNome();
        void setNome(string n);
        string getCnpj();
        void setCnpj(string c);
        Funcionario **getFuncionarios();
        int getQtde();
        bool addFuncionario(Funcionario *f);
    };

#endif // !FUNCIONARIO_H