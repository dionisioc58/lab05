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
    };

#endif // !FUNCIONARIO_H