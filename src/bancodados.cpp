/**
* @file 	bancodados.cpp
* @brief	Arquivo de corpo com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    29/04/2017
* @date     29/04/2017
*/

#include "bancodados.h"

/**
* @brief        Função que coleta os dados para cadastro de uma empresa
* @return       Empresa coletada
*/
Empresa *inputEmpresa() {
    //Coleta dados da empresa
    string input;
    Empresa *nova = new Empresa[1];
    cout << "Digite o nome da empresa: ";
    getline(cin, input);
    nova[0].setNome(input);
    cout << endl << "Digite o CNPJ da empresa: ";
    getline(cin, input);
    nova[0].setCnpj(input);
    return nova;
}

/**
* @brief        Função que coleta os dados para cadastro de um funcionário
* @return       Funcionário coletado
*/
Funcionario *inputFuncionario() {
    //Coleta dados do funcionário
    string input;
    Funcionario *novo = new Funcionario[1];
    cout << "Digite o nome do funcionário: ";
    getline(cin, input);
    novo[0].setNome(input);
    novo[0].setSalario(recebeFloat("Digite o salário: ", 0));
    //novo[0].setAdmissao(now());
    return novo;
}

/**
* @brief        Função que verifica se uma empresa já existe no cadastro
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @param[in]    *nova Empresa à ser verificada
* @return       Retorna true caso já exista
*/
bool existeEmpresa(Empresa *e, int n, Empresa *nova) {
    //Testa se já existe no cadastro
    for(int i = 0; i < n; i++) {
        if(e[i].getCnpj() == nova[0].getCnpj()) {
            cout << "Empresa já cadastrada!" << endl;
            return true;
        }
    }
    return false;
}

/**
* @brief        Função que realiza o cadastro uma empresa
* @param[in]    *e Vetor de empresas do cadastro
* @param[inout] n Número de empresas no cadastro
* @return       Retorna o novo vetor de empresas após o cadastro
*/
Empresa *cadEmpresa(Empresa *e, int &n) {
    Empresa *nova;
    nova = inputEmpresa();
    if(existeEmpresa(e, n, nova))
        return e;

    Empresa *r = new Empresa[n + 1];

    //Se já tem empresas, aumenta o vetor, copia a antiga lista para um novo maior
    for(int i = 0; i < n; i++)
        r[i] = Empresa(e[i]);
    //delete[] r;

    r[n++] = nova[0]; //Guarda o elemento informado
    return r;
}

/**
* @brief        Função que adiciona um funcionário à uma empresa (apresenta escolha)
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @return       Retorna o novo vetor de empresas após o cadastro
*/
Empresa *addFunc(Empresa *e, int n) {
    if(n == 0)
        return e;

    impEmpresas(e, n);
    int selecao = recebeInt("Digite o número da empresa para a adição (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    Funcionario *f = inputFuncionario();
    e[selecao].addFuncionario(f[0]);
    return e;
}

/**
* @brief        Função que imprime as empresas no cadastro
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
*/
void impEmpresas(Empresa *e, int n) {
    cout << "Lista de empresas cadastradas: " << endl;
    for(int i = 0; i < n; i++)
        cout << "-- (" << (i + 1) << ") " << e[i].getNome() << " - CNPJ = " << e[i].getCnpj() << endl;
    cout << endl;
    cout << "Pressione ENTER para continuar...";
    string pausa;
    getline(cin, pausa);
}

/**
* @brief        Função que imprime a lista de funcionários de uma ou todas 
                as empresas do cadastro
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @param[in]    all "true" imprime todos os funcionários de todas as empresas
                "false" imprime apenas os funcionários de uma empresa (apresenta escolha)
* @return       Retorna o novo vetor de empresas após o cadastro
*/
void impFunc(Empresa *e, int n, bool all) {
    if(n == 0)
        return;
    if(!all) {
        impEmpresas(e, n);
        int selecao = recebeInt("Digite o número da empresa (0 para cancelar): ", 0);
        if(selecao == 0)
            return;
        selecao--;  //O usuário vai digitar o número com base em 1
        if(e[selecao].getQtde() > 0) {
            cout << "Funcionários da empresa " << e[selecao].getNome() << endl;
            Funcionario *f = e[selecao].getFuncionarios();
            for(int i = 0; i < e[selecao].getQtde(); i++)
                cout << "-----> " << f[i].getNome() << " - R$ " << f[i].getSalario() << endl;
        } else
            cout << "Nenhum funcionário na empresa selecionada." << endl;
    } else {
        for(int j = 0; j < n; j++) {
            if(e[j].getQtde() > 0) {
                cout << "Funcionários da empresa " << e[j].getNome() << endl;
                Funcionario *f = e[j].getFuncionarios();
                for(int i = 0; i < e[j].getQtde(); i++)
                    cout << "-----> " << f[i].getNome() << " - R$ " << f[i].getSalario() << endl;
            }
        }
    }
    cout << "Pressione ENTER para continuar...";
    string pausa;
    getline(cin, pausa);
}

/**
* @brief        Função que salva o cadastro completo em arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
*/
void salvar(string nome, Empresa *e, int n) {

}

/**
* @brief        Função que recupera o cadastro completo a partir de um arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
*/
void abrir(string nome, Empresa *e, int n) {

}