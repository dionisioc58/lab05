#ifndef FUNCIONARIO_H
    #define FUNCIONARIO_H

    #include <iostream>
    #include <string>
    using std::string;
    using std::ostream;
    using std::istream;
    
    class Funcionario {
    private:
        string nome;
        float salario;
        string admissao;
    public:
        Funcionario();
        //Funcionario(Funcionario &f);
        string getNome();
        void setNome(string n);
        float getSalario();
        void setSalario(float s);
        string getAdmissao();
        void setAdmissao(string a);
        friend ostream& operator<<(ostream& os, Funcionario &f); /** @brief Sobrecarga do operador de inserção em stream */
        friend istream& operator>>(istream& is, Funcionario &f); /** @brief Sobrecarga do operador de extração de stream */
    };

#endif // !FUNCIONARIO_H