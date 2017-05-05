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
                delete[] emp;
                return 0;
                break;
            case 1:              //Cadastrar uma empresa
                emp = cadEmpresa(emp, qtdemp);
                break;
            case 2:              //Excluir uma empresa
                emp = delEmpresa(emp, qtdemp);
                break;
            case 3:              //Listar as empresas
                impEmpresas(emp, qtdemp);
                break;

            case 4:              //Adicionar um funcionário
                emp = addFunc(emp, qtdemp);
                break;
            case 5:              //Adicionar funcionários através de um arquivo
                emp = addFuncArq(emp, qtdemp);
                break;
            case 6:              //Remover um funcionário
                emp = delFunc(emp, qtdemp);
                break;
            case 7:              //Dar aumento
                emp = aumento(emp, qtdemp);
                break;

            case 8:              //Listar os funcionários de uma empresa
                impFunc(emp, qtdemp, false);
                break;
            case 9:              //Listar os funcionários em experiência
                impFuncExp(emp, qtdemp, true);
                break;
            case 10:             //Listar todos os funcionários de todas as empresas
                impFunc(emp, qtdemp, true);
                break;

            case 11:            //Salvar o banco de dados
                salvarBD("./data/banco.dat", emp, qtdemp); 
                break;
            case 12:            //Recuperar o banco
                abrirBD("./data/banco.dat", emp, qtdemp); 
                break;
        }
    }
    
    delete[] emp;
    return 0;
}