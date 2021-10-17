/**
    Exemplo0901 - Versao 0.1 - 19/10/2020
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
printIntMatrix - Mostrar arranjo bidimensional com valores inteiros.
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void printIntMatrix(int lines, int columns, int matrix[][columns])
{
    // definir dado local
    int x = 0;
    int y = 0;
    // mostrar valores na matriz
    for (x = 0; x < lines; x = x + 1)
    {
        for (y = 0; y < columns; y = y + 1)
        {
            // mostrar valor
            IO_printf("%3d\t", matrix[x][y]);
        } // fim repetir
        IO_printf("\n");
    } // fim repetir
} // printIntMatrix ( )
/**
Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    // definir dado
    int matrix[][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
    // identificar
    IO_id("EXEMPLO0901 - Method01 - v0.1");
    // executar o metodo auxiliar
    printIntMatrix(3, 3, matrix);
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
    IO_id("\nESTUDO DIRIGIDO 09 - Programa - v0.1");
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
            method01();
            break;
        case 2:
            //method02( );
            break;
        case 3:
            //method03( );
            break;
        case 4:
            //method04( );
            break;
        case 5:
            //method05( );
            break;
        case 6:
            //method06( );
            break;
        case 7:
            //method07( );
            break;
        case 8:
            //method08( );
            break;
        case 9:
            //method09( );
            break;
        case 10:
            //method10( );
            break;
        default:
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
    IO_println(" 1 - Mostrar arranjo bidimensional com valores inteiros.");
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
  1       2       3
  4       5       6
  7       8       9
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         19/10         esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 0.1       1.0   ( OK )  19/10    - Mostrar arranjo bidimensional com valores inteiros.
*/