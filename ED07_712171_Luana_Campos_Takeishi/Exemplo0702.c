/**
 * Exemplo0702 - Versao 0.1 - 06/10/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//lista de dependencias
//para definicoes proprias
#include "io.h"
#include "Luana.h"

/**
 * writeInts - Gravar em arquivo texto certa quantidade de valores.
 * @param fileName - nome do arquivo
 * @param x - quantidade de valores
*/
void writeInts(chars fileName, int x)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 0;
    // repetir para a quantidade de dados
    for (y = 1; y <= x; y = y + 1)
    {
        // gravar valor
        fprintf(arquivo, "%d\n", y);
    } // fim repetir
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeInts ( )

/**
 * Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    // identificar
    IO_id("EXEMPLO0701 - Method01 - v0.1");
    // executar o metodo auxiliar
    writeInts("DADOS1.TXT", 10);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
 * readInts - Ler de arquivo texto certa quantidade de valores.
 * @param fileName - nome do arquivo
 * @param x - quantidade de valores
*/
void readInts(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    int x = 0;
    // tentar ler o primeiro
    fscanf(arquivo, "%d", &x);
    // repetir enquanto houver dados
    while (!feof(arquivo))
    {
        // mostrar valor
        printf("%d\n", x);
        // tentar ler o proximo
        fscanf(arquivo, "%d", &x);
    } // fim repetir
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // fim readInts ( )

/**
 * Method02.
*/
void method02()
{
    // identificar
    IO_id("EXEMPLO0702 - Method02 - v0.1");
    // executar o metodo auxiliar
    readInts("DADOS1.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method02 ( )

/**
 * Funcao principal
 * @return codigo de encerramento
*/
int main()
{
    //definir variaveis com valor inicial
    int x = 0;

    //identificar
    IO_id("\nESTUDO DIRIGIDO 07 - Programa - v0.1");

    do
    {
        // ler do teclado
        IO_println("Opcoes:");
        IO_println(" 0 - Parar.");
        IO_println(" 1 - Gravar em arquivo texto certa quantidade de valores.");
        IO_println(" 2 - Ler de arquivo texto certa quantidade de valores.");
        IO_println(" 3 - ");
        IO_println(" 4 - ");
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
        default:
            IO_println("ERRO: Valor invalido.");
        } //end switch-case
    } while (x != 0);

    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
} //end main

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
1
2
3
4
5
6
7
8
9
10
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         06/10          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 0.1       01.   ( OK )  06/10  - Gravar em arquivo texto certa quantidade de valores. (int)
 0.2       01.   ( OK )  06/10  - Ler de arquivo texto certa quantidade de valores.

*/