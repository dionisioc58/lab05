#ifndef FUNCIONARIO_H
    #define FUNCIONARIO_H

    #include <chrono>
    #include <string>
    using std::string;
    
    class Funcionario {
    private:
        string nome;
        float salario;
        std::chrono::system_clock::time_point admissao;
    public:
        Funcionario();
        //Funcionario(Funcionario &f);
        string getNome();
        void setNome(string n);
        float getSalario();
        void setSalario(float s);
        std::chrono::system_clock::time_point getAdmissao();
        void setAdmissao(std::chrono::system_clock::time_point a);
    };

#endif // !FUNCIONARIO_H