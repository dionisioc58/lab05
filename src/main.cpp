/**
* @file     main.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    25/04/2017
* @date     25/04/2017
*/

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "funcionario.h"
#include "empresa.h"
#include "menu.h"
#include "bancodados.h"

/**
* @brief        Função principal do programa
* @param[in]	argc	Quantidade de argumentos
* @param[in]    *argv[]	Argumento com o caminho/nome do arquivo de dados a ser lido
* @return		Retorno
*/
int main(int argc, char* argv[]) {
    int qtdemp = 0;         /**< Quantidade de empresas cadastradas */
    Empresa *emp = NULL;    /**< Vetor de empresas que conterá todo o cadastro */
    while(1) {
        switch(showMenuEmp()) { //Exibir o menu
            case 0:             //Sair
                return 0;
                break;
            case 1:             //Cadastrar uma empresa
                emp = cadEmpresa(emp, qtdemp);
                break;
            case 2:             //Listar as empresas
                impEmpresas(emp, qtdemp);
                break;
            case 3:             //Adicionar um funcionário
                emp = addFunc(emp, qtdemp);
                break;
            case 4:             //Listar os funcionários de uma empresa
                impFunc(emp, qtdemp, false);
                break;
            case 5:             //Listar todos os funcionários de todas as empresas
                impFunc(emp, qtdemp, true);
                break;
            case 6:             //Salvar o banco de dados
                salvar("./data/banco.dat", emp, qtdemp); 
                break;
            case 7:             //Recuperar o banco
                abrir("./data/banco.dat", emp, qtdemp); 
                break;
        }
    }

    return 0;
}