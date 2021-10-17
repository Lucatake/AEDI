/*
Exemplo1410 - v1.0. - 23 / 11 / 2020
Author: Luana Campos Takeishi
*/
// ----------------------------------------------- preparacao
// dependencias
#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ifstream; // para ler arquivo
using std::ofstream; // para gravar arquivo
// outras dependencias
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )
// ----------------------------------------------- classes
#include "Erro.hpp" // classe para tratar erros
class MyString : public Erro
{
public:
    /**
* Funcao para obter mensagem
* relativa ao código de erro.
* @return mensagem sobre o erro
*/
    std::string getErroMsg()
    {
        return (NO_ERROR); // COMPLETAR A DEFINICAO
    }                      // end getErroMsg ( )
};                         // fim classe MyString
// ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos
/**
Method00 - nao faz nada.
*/
void method00()
{
    // nao faz nada
} // fim method00 ( )
/**
Method01 - Testar definicoes da classe.
*/
void method01()
{
    // definir dados
    MyString *s = new MyString();
    // identificar
    cout << "\nEXEMPLO1401 - Method01 - v0.0\n"
         << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method01 ( )

// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/
int main(int argc, char **argv)
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1301 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - testar definicao. " << endl;
        // ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;
        // escolher acao
        switch (x)
        {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;

        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        } // fim escolher
    } while (x != 0);
    // encerrar
    pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data   Modificacao
 0.1   23/11  esboco
---------------------------------------------- testes
Versao   Teste
0.1 01. ( OK ) teste das definicoes.

*/