/**
 * Exemplo0604 - Versao 0.1 - 28/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//lista de dependencias
//para definicoes proprias
#include "io.h"
#include "Luana.h"

/**
 * Method01a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method01a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);
        // passar ao proximo
        method01a(x - 1); // motor da recursividade
    }                     // fim se
} // fim method01a( )

/**
 * Method01 - Mostrar certa quantidade de valores.
*/
void method01( )
{
    // definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    // identificar
    IO_id("EXEMPLO0601 - Method01 - v0.1");
    // executar o metodo auxiliar
    method01a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
 * Method02a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method02a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // passar ao proximo
        method02a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);
    } // fim se
} // fim method02a( )

/**
 * Method02.
*/
void method02()
{
    // identificar
    IO_id("EXEMPLO0602 - Method02 - v0.1");
    // executar o metodo auxiliar
    method02a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method02 ( )

/**
 * Method03a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method03a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        method03a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%s\n", "Valor = 1");
    } // fim se
} // fim method03a( )

/**
 * Method03.
*/
void method03( )
{
    // identificar
    IO_id("EXEMPLO0603 - Method03 - v0.1");
    // executar o metodo auxiliar
    method03a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method03 ( )

/**
 * Method04a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method04a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        method04a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", 2 * (x - 1));
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%s\n", "Valor = 1");
    } // fim se
} // fim method04a( )

/**
 * Method04.
*/
void method04()
{
    // identificar
    IO_id("EXEMPLO0604 - Method04 - v0.0");
    // executar o metodo auxiliar
    method04a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method04 ( )

/**
 * Funcao principal
 * @return codigo de encerramento
*/
int main( )
{
    //definir variaveis com valor inicial
    int x = 0;

    //identificar
    IO_id("\nESTUDO DIRIGIDO 06 - Programa - v0.1");

    do
    {
        // ler do teclado
        IO_println("Opcoes:");
        IO_println(" 0 - parar");
        IO_println(" 1 - certa quantidade de valores decrescente (recursividade)");
        IO_println(" 2 - certa quantidade de valores (recursividade alternativo)");
        IO_println(" 3 - certa quantidade de valores (recursividade com base)");
        IO_println(" 4 - certa quantidade de valores pares (recursividade base 1)");
        IO_println(" 5 - ");
        IO_println(" 6 - ");
        IO_println(" 7 - ");
        IO_println(" 8 - ");
        IO_println(" 9 - ");
        IO_println("10 - ");
        x = IO_readint("\nEntrar com uma opcao: ");
        IO_println(" ");

        //testar valor
        switch (x)
        {
        case 0:
            Parar();
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
        
            break;
        case 6:
        
            break;
        case 7:
        
            break;
        case 8:
        
            break;
        case 9:
        
            break;
        case 10:
        
            break;
        default:
            IO_println("ERRO: Valor invalido.");
        }//end switch-case
    } while (x != 0);
    
    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
Valor = 1
Valor = 2
Valor = 4
Valor = 6
Valor = 8
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         28/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 0.1       01.   ( OK )  28/09  - certa quantidade de valores decrescente (recursividade)
 0.2       01.   ( OK )  28/09  - certa quantidade de valores crescente (recursividade alternativa)
 0.3       01.   ( OK )  28/09  - certa quantidade de valores crescente (recursividade com base)
 0.4       01.   ( OK )  28/09  - certa quantidade de valores pares (recursividade base 1)

*/