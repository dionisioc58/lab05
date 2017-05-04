#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "funcionario.h"
#include "empresa.h"
#include "menu.h"
#include "bancodados.h"
#include <ctime>
#include <iomanip>

int main() {
    //std::locale::global(std::locale("ja_JP.utf8"));
    std::time_t t = std::time(NULL);
    char mbstr[100];
    if (std::strftime(mbstr, sizeof(mbstr), "%d/%m/%Y %H:%M:%S", std::localtime(&t))) {
        std::cout << "Agora: " << mbstr << '\n';
    }
    return 0;


    /*int ano, mes, dia;
    cout << "digite o dia, o mês e o ano: ";
    cin >> dia >> mes >> ano;
    std::tm a = {0,0,0,dia,mes-1,ano-1900};
    std::tm b = {0,0,0,4,4,117}; // July 5, 2004
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) )
    {
        double difference = std::difftime(y, x) / (60 * 60 * 24);
        std::cout << std::cdate(&x);
        std::cout << std::cdate(&y);
        std::cout << "difference = " << difference << " days" << std::endl;
    }
    return 0;*/

    Empresa *emp = NULL;
    int qtd = 0;
    cout << "Add empresa 1" << endl;
    emp = cadEmpresa(emp, qtd);
    
    cout << "Add func 1" << endl;
    emp = addFunc(emp, qtd);
    
    cout << "Add func 2" << endl;
    emp = addFunc(emp, qtd);
    
    cout << "Aumento" << endl;
    emp = aumento(emp, qtd);

    cout << "Add empresa 2" << endl;
    emp = cadEmpresa(emp, qtd);
    
    cout << "Add func 3" << endl;
    emp = addFunc(emp, qtd);

    /*cout << "Del emp 1" << endl;
    emp = delEmpresa(emp, qtd);
    
    cout << "Del func 1" << endl;
    emp = delFunc(emp, qtd);*/
    
    impFunc(emp, qtd, true, false);

    delete[] emp;
    return 0;
}

/*int qtd = 0;
    Empresa *emp = new Empresa[qtd];
    emp[0].setNome("Dio");
    emp[0].setCnpj("123");
    emp[1].setNome("Nara");
    emp[1].setCnpj("321");

    Funcionario func[3];
    func[0].setNome("Dionisio");
    func[0].setSalario(333);
    func[1].setNome("Zebinha");
    func[1].setSalario(2524);
    func[2].setNome("Maria Joaquina");
    func[2].setSalario(345.15);
    //Adicionar funcionário
    //emp[0].addFuncionario(func[0]);
    //emp[1].addFuncionario(func[1]);

    for(int i = 0; i < qtd; i++) {
        cout << "-- " << emp[i].getNome() << " (" << emp[i].getCnpj() << ")" << endl;
        Funcionario *lista = emp[i].getFuncionarios();
        if(emp[i].getQtde() > 0) {
            for(int j = 0; j < emp[i].getQtde(); j++)
                cout << "------ " << lista[j].getNome() << endl;
        }
    }
    cout << "Fim" << endl;

    //Aumenta o vetor
    qtd += 2;
    Empresa *array = new Empresa[qtd];
    for(int i = 0; i < (qtd - 2); i++)
        array[i] = Empresa(emp[i]);
    emp = array;
    //delete[] array;

    //Adicionar funcionário
    emp[1].addFuncionario(func[1]);

    for(int i = 0; i < qtd; i++) {
        cout << "-- " << emp[i].getNome() << " (" << emp[i].getCnpj() << ")" << endl;
        if(emp[i].getQtde() > 0) {
            for(int j = 0; j < emp[i].getQtde(); j++)
                cout << "------ " << emp[i].getFuncionarios()[j].getNome() << endl;
        }
    }
    cout << "Fim" << endl;

    emp[0].addFuncionario(func[0]);
    
    for(int i = 0; i < qtd; i++) {
        cout << "-- " << emp[i].getNome() << " (" << emp[i].getCnpj() << ")" << endl;
        if(emp[i].getQtde() > 0) {
            for(int j = 0; j < emp[i].getQtde(); j++)
                cout << "------ " << emp[i].getFuncionarios()[j].getNome() << endl;
        }
    }
    cout << "Fim" << endl;

    emp[0].addFuncionario(func[0]);
    emp[0].addFuncionario(func[2]);
    
    for(int i = 0; i < qtd; i++) {
        cout << "-- " << emp[i].getNome() << " (" << emp[i].getCnpj() << ")" << endl;
        if(emp[i].getQtde() > 0) {
            for(int j = 0; j < emp[i].getQtde(); j++)
                cout << "------ " << emp[i].getFuncionarios()[j].getNome() << endl;
        }
    }
    cout << "Fim" << endl;

    cout << "Teste da remoção de um funcionário" << endl;
    emp[0].delFuncionario(func[0]);

    for(int i = 0; i < qtd; i++) {
        cout << "-- " << emp[i].getNome() << " (" << emp[i].getCnpj() << ")" << endl;
        if(emp[i].getQtde() > 0) {
            for(int j = 0; j < emp[i].getQtde(); j++)
                cout << "------ " << emp[i].getFuncionarios()[j].getNome() << endl;
        }
    }
    cout << "Fim" << endl;

    qtd = 1;
    array = new Empresa[qtd];
    for(int i = 0; i < (qtd); i++)
        array[i] = Empresa(emp[i]);
    emp = array;

    for(int i = 0; i < qtd; i++) {
        cout << "-- " << emp[i].getNome() << " (" << emp[i].getCnpj() << ")" << endl;
        if(emp[i].getQtde() > 0) {
            for(int j = 0; j < emp[i].getQtde(); j++)
                cout << "------ " << emp[i].getFuncionarios()[j].getNome() << endl;
        }
    }
    cout << "Fim" << endl;*/