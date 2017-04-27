#include <iostream>
using std::cout;
using std::endl;

#include "funcionario.h"
#include "empresa.h"

int main(int argc, char* argv[]) {
    Empresa *emp = new Empresa[2];
    emp[0].setNome("Airton Ltda");
    emp[1].setNome("Dionísio Corp.");

    Funcionario *func = new Funcionario[2];
    func[0].setNome("Josivan");
    func[1].setNome("Daniel");

    emp[0].addFuncionario(func[0]);
    emp[0].addFuncionario(func[1]);

    emp[1].addFuncionario(func[1]);

    // cout << emp[0].getNome() << endl;
    // cout << emp[1].getNome() << endl;

    //cout << func[0].getNome() << endl;
    //cout << func[1].getNome() << endl;

    for(int j = 0; j < 2; j++) {
        cout << "Funcionários da empresa " << emp[j].getNome() << endl;
        for(int i = 0; i < emp[j].getQtde(); i++)
            cout << "-----> " << emp[j].getFuncionario(i).getNome() << endl;
    }

    return 0;
}