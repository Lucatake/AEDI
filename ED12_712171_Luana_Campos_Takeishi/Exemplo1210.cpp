/**
 * Exemplo1210 - v0.1. - 06 / 11 / 2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
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
// ----------------------------------------------- classes / pacotes
#include "mymatrix.hpp"
using namespace std;
// ----------------------------------------------- metodos

/**
 * Method00 - nao faz nada.
*/
void method00()
{
    // nao faz nada
} // fim method00 ( )

/**
 * Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    // definir dados
    Matrix<int> int_matrix(2, 2);
    int_matrix.set(0, 0, 1);
    int_matrix.set(0, 1, 2);
    int_matrix.set(1, 0, 3);
    int_matrix.set(1, 1, 4);
    // identificar
    cout << "\nEXEMPLO1201 - Method01 - v0.1\n"
         << endl;
    // mostrar dados
    int_matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
 * Method02 - Ler e guardar dados em matriz.
*/
void method02()
{
    // definir dados
    Matrix<int> matrix(2, 2);
    // identificar
    cout << endl
         << "EXEMPLO1202 - Method02 - v0.1" << endl;
    // ler dados
    matrix.read();
    // mostrar dados
    matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method02 ( )

/**
 * Method03 - Ler e guardar matriz em arquivo..
*/
void method03()
{
    // definir dados
    Matrix<int> matrix(2, 2);
    // identificar
    cout << endl
         << "EXEMPLO1203 - Method03 - v0.1" << endl;
    // ler dados
    matrix.read();
    // mostrar dados
    matrix.print();
    // gravar dados
    matrix.fprint("MATRIX1.TXT");
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method03 ( )

/**
 * Method04 - Ler matriz de arquivo..
*/
void method04()
{
    // definir dados
    Matrix<int> matrix(1, 1);
    // identificar
    cout << endl
         << "EXEMPLO1204 - Method04 - v0.1" << endl;
    // ler dados
    matrix.fread("MATRIX1.TXT");
    // mostrar dados
    matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method04 ( )

/**
 * Method05 - Copiar dados de matriz comum.
*/
void method05()
{
    // definir dados
    Matrix<int> int_matrix1(1, 1);
    Matrix<int> int_matrix2(1, 1);
    // identificar
    cout << endl
         << "EXEMPLO1205 - Method05 - v0.1" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nOriginal\n"
         << endl;
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1;
    // mostrar dados
    cout << "\nCopia\n"
         << endl;
    int_matrix2.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method05 ( )

/**
 * Method06 - Verificar se matriz so contem zeros.
*/
void method06()
{
    // definir dados
    Matrix<int> int_matrix(2, 2);
    int_matrix.set(0, 0, 0);
    int_matrix.set(0, 1, 0);
    int_matrix.set(1, 0, 0);
    int_matrix.set(1, 1, 0);
    // identificar
    cout << endl
         << "EXEMPLO1206 - Method06 - v0.1" << endl;
    // mostrar dados
    int_matrix.print();
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros() << endl;
    // ler dados
    int_matrix.fread("MATRIX1.TXT");
    // mostrar dados
    int_matrix.print();
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros() << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
 * Method07 - Testar se matrizes sao diferentes.
*/
void method07()
{
    // definir dados
    Matrix<int> int_matrix1(1, 1);
    Matrix<int> int_matrix2(1, 1);
    // identificar
    cout << endl
         << "EXEMPLO1207 - Method07 - v0.1" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1;
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // testar condicao
    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;
    // alterar dados
    int_matrix2.set(0, 0, (-1));
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // testar condicao
    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method07 ( )

/**
 * Method08 - Subtrair duas matrizes.
*/
void method08()
{
    // definir dados
    Matrix<int> int_matrix1(1, 1);
    Matrix<int> int_matrix2(1, 1);
    Matrix<int> int_matrix3(1, 1);
    // identificar
    cout << endl
         << "EXEMPLO1208 - Method08 - v0.1" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1;
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // operar dados
    int_matrix3 = int_matrix1 - int_matrix2;
    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method08 ( )

/**
 * Method09 - Calcular produto de matrizes.
*/
void method09()
{
    // definir dados
    Matrix<int> int_matrix1(2, 2);
    int_matrix1.set(0, 0, 1);
    int_matrix1.set(0, 1, 0);
    int_matrix1.set(1, 0, 0);
    int_matrix1.set(1, 1, 1);
    Matrix<int> int_matrix2(1, 1);
    Matrix<int> int_matrix3(1, 1);
    // identificar
    cout << endl
         << "EXEMPLO1209 - Method09 - v0.1" << endl;
    // ler dados
    int_matrix2.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // operar dados
    int_matrix3 = int_matrix1 * int_matrix2;
    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method09 ( )

/**
Method10 -  Acesso externo aos valores na matriz.
*/
void method10()
{
    // definir dados
    Matrix<int> int_matrix(3, 3);
    int x = 0;
    int y = 0;
    // identificar
    cout << endl
         << "EXEMPLO1210 - Method10 - v0.1" << endl;
    // ler dados
    int_matrix.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print();
    // operar dados
    for (int x = 0; x < int_matrix.getRows(); x = x + 1)
    {
        for (int y = 0; y < int_matrix.getColumns(); y = y + 1)
        {
            int_matrix.set(x, y, int_matrix.get(x, y) * (-1));
        } // end for
    }     // end for
    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method10 ( )

// ----------------------------------------------- acao principal

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main(int argc, char **argv)
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1101 - Programa - v0.1\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Mostrar certa quantidade de valores em matriz. " << endl;
        cout << " 2 - Ler e guardar dados em matriz." << endl;
        cout << " 3 - Ler e guardar matriz em arquivo." << endl;
        cout << " 4 - Ler matriz de arquivo." << endl;
        cout << " 5 - Copiar dados de matriz comum." << endl;
        cout << " 6 - Verificar se matriz so contem zeros." << endl;
        cout << " 7 - Testar se matrizes sao diferentes." << endl;
        cout << " 8 - Subtrair duas matrizes." << endl;
        cout << " 9 - Calcular produto de matrizes." << endl;
        cout << "10 - Acesso externo aos valores na matriz." << endl;
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
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();
            break;
        case 8:
            method08();
            break;
        case 9:
            method09();
            break;
        case 10:
            method10();
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
---------------------------------------------- previsao de testes e testes
method01:
    1       2
    3       4
method02:
    0,  0 : 1
    0,  1 : 2       1       2
    1,  0 : 3       3       4
    1,  1 : 4
method03:
    0,  0 : 1
    0,  1 : 2       1       2
    1,  0 : 3       3       4
    1,  1 : 4
    MATRIX1.TXT
        2
        2
        1
        2
        3
        4
method04:
    1       2
    3       4
method05:
     Original             Copia
    1       2           1       2
    3       4           3       4
method06:
    0       0           1       2
    0       0           3       4
    Zeros = 1           Zeros = 0
method07:
    Matrix_1             Matrix_2
    1       2           1       2
    3       4           3       4
            Diferentes = 0
    Matrix_1             Matrix_2
    1       2          -1       2
    3       4           3       4
            Diferentes = 1
method08:
     Matrix_1            Matrix_2           Matrix_3
    1       2           1       2          0       0
    3       4           3       4          0       0
    Matrix_3
method09: 
    Matrix_1            Matrix_2            Matrix_3
    1       0          1       2           1       2
    0       1          3       4           3       4
method10:
      Matrix            Matrix
    1       2         -1      -2
    3       4         -3      -4
---------------------------------------------- historico
Versao Data  Modificacao
 0.1   06/11 esboco
---------------------------------------------- testes
Versao   Teste
0.1 01. ( OK ) - Mostrar certa quantidade de valores.
0.2 01. ( OK ) - Ler e guardar dados em matriz.
0.3 01. ( OK ) - Ler e guardar matriz em arquivo.
0.4 01. ( OK ) - Ler matriz de arquivo.
0.5 01. ( OK ) - Copiar dados de matriz comum.
0.6 01. ( OK ) - Verificar se matriz so contem zeros.
0.7 01. ( OK ) - Testar se matrizes sao diferentes.
0.8 01. ( OK ) - Subtrair duas matrizes.
0.9 01. ( OK ) - Calcular produto de matrizes.
1.0 01. ( OK ) -  Acesso externo aos valores na matriz.
*/