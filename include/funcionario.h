#ifndef FUNCIONARIO_H
    #define FUNCIONARIO_H

    #include <iostream>
    #include <string>
    #include <sstream>
    using std::string;
    using std::ostream;
    using std::istream;
    using std::stringstream;
    #include <ctime>
    
    class Funcionario {
    private:
        string nome;
        float salario;
        std::time_t admissao;
    public:
        Funcionario();
        //Funcionario(Funcionario &f);
        string getNome();
        void setNome(string n);
        float getSalario();
        void setSalario(float s);
        std::time_t getAdmissao();
        void setAdmissao(std::time_t a);
        bool experiencia();
        string exportar();
        friend ostream& operator<<(ostream& os, Funcionario &f); /** @brief Sobrecarga do operador de inserção em stream */
        friend istream& operator>>(istream& is, Funcionario &f); /** @brief Sobrecarga do operador de extração de stream */
    };

#endif // !FUNCIONARIO_H