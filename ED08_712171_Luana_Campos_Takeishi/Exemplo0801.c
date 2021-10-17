/**
    Exemplo0801 - Versao 0.1 - 09/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//dependencias
//para definicoes proprias
#include "io.h"
//para metodos proprios
#include "Luana.h"
//lista de funcoes
int menu(void);
void Parar();

/**
 * printIntArray - Mostrar arranjo com valores inteiros.
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
void printIntArray(int n, int array[])
{
    // definir dado local
    int x = 0;
    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // mostrar valor
        IO_printf("%2d: %d\n", x, array[x]);
    } // fim repetir
} // printIntArray ( )

/**
 * Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    // definir dado
    int array[] = {1, 2, 3, 4, 5};
    // identificar
    IO_id("EXEMPLO0801 - Method01 - v0.1");
    // executar o metodo auxiliar
    printIntArray(5, array);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param e escolha do menu
*/
int main(int e)
{
    //identificar
    IO_id("\nESTUDO DIRIGIDO 08 - Programa - v0.1");
    //definir dado com valor inicial
    int x = 0;
    //repetir ate desejar parar
    do
    {
        //ler do teclado
        x = menu();
        //testar valor
        //escolha do exercicio a ser executado
        switch (x)
        {
        case 0:
            Parar();
            break;
        case 1:
            method01( );
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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
            IO_println("\nValor diferente das opcoes");
            break;
        }             //end switch-case
    } while (x != 0); //end do-while
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} //end main( )

/**
 * Funcao menu de escolhas.
 * @return x opcao escolhida
*/
int menu(void)
{
    //definir variavel com valor inicial
    int e = 0;
    //mostrar as opcoes disponiveis
    IO_println("\nOpcoes:");
        IO_println(" 0 - parar");
        IO_println(" 1 - Mostrar arranjo com valores inteiros.");
        IO_println(" 2 - ");
        IO_println(" 3 - ");
        IO_println(" 4 - ");
        IO_println(" 5 - ");
        IO_println(" 6 - ");
        IO_println(" 7 - ");
        IO_println(" 8 - ");
        IO_println(" 9 - ");
        IO_println("10 - ");
    //ler do teclado
    e = IO_readint("\nEntrar com uma opcao: ");
    //retornat valor lido
    return (e);
} //end menu( )

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas
---------------------------------------------- observacoes / comentarios
---------------------------------------------- previsao de testes
 0: 1
 1: 2
 2: 3
 3: 4
 4: 5
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         09/10         esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 0.1       1.0   ( OK )  09/10    - Mostrar arranjo com valores inteiros.
*/