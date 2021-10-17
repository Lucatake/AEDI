/**
 * Exemplo0706 - Versao 0.1 - 06/10/2020
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
 * writeDoubles - Gravar em arquivo texto certa quantidade de valores.
 * @param fileName - nome do arquivo
 * @param x - quantidade de valores
*/
void writeDoubles(chars fileName, int x)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 0;
    // gravar quantidade de valores
    IO_fprintf(arquivo, "%d\n", x);
    // repetir para a quantidade de dados
    for (y = 1; y <= x; y = y + 1)
    {
        // gravar valor
        IO_fprintf(arquivo, "%lf\n", (0.1 * y));
    } // fim repetir
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeDoubles ( )

/**
 * Method03.
*/
void method03()
{
    // identificar
    IO_id("EXEMPLO0703 - Method03 - v0.2");
    // executar o metodo auxiliar
    writeDoubles("DADOS2.TXT", 10);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method03 ( )

/**
 * readDoubles - Ler de arquivo texto certa quantidade de valores.
 * @param fileName - nome do arquivo
 * @param x - quantidade de valores
*/
void readDoubles(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    int x = 0;
    int y = 1;
    double z = 0.0;
    // tentar ler a quantidade de dados
    fscanf(arquivo, "%d", &x);
    // repetir enquanto houver dados e
    // quantidade nao tiver sido alcancada
    while (!feof(arquivo) && y <= x)
    {
        // tentar ler
        fscanf(arquivo, "%lf", &z);
        // mostrar valor
        printf("%2d: %lf\n", y, z);
        // passar ao proximo
        y = y + 1;
    } // fim repetir
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // fim readDoubles ( )

/**
 * Method04.
*/
void method04()
{
    // identificar
    IO_id("EXEMPLO0704 - Method04 - v0.1");
    // executar o metodo auxiliar
    readDoubles("DADOS2.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method04 ( )

/**
 * writeText - Gravar em arquivo texto certa quantidade de valores.
 * @param fileName - nome do arquivo
 * @param x - quantidade de valores
*/
void writeText(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    chars linha = IO_new_chars(STR_SIZE);
    // repetir ate' desejar parar
    IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");
    do
    {
        // ler do teclado
        strcpy(linha, IO_readln(""));
        // gravar valor
        IO_fprintf(arquivo, "%s\n", linha);
    } while (strcmp("PARAR", linha) != 0);
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeText ( )

/**
 * Method05.
*/
void method05()
{
    // identificar
    IO_id("EXEMPLO0705 - Method05 - v0.1");
    // executar o metodo auxiliar
    writeText("DADOS3.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method05 ( )

/**
 * readText - Ler de arquivo texto certa quantidade de valores.
 * @param fileName - nome do arquivo
*/
void readText(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    // tentar ler o primeiro
    strcpy(linha, IO_freadln(arquivo));
    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp("PARAR", linha) != 0)
    {
        // mostrar valor
        printf("%s\n", linha);
        // tentar ler o proximo
        strcpy(linha, IO_freadln(arquivo));
    } // fim repetir
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // fim readText ( )

/**
 * Method06.
*/
void method06()
{
    // identificar
    IO_id("EXEMPLO0706 - Method06 - v0.1");
    // executar o metodo auxiliar
    readText("DADOS3.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

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
        IO_println(" 1 - Gravar em arquivo texto certa quantidade de valores (int).");
        IO_println(" 2 - Ler de arquivo texto certa quantidade de valores (int).");
        IO_println(" 3 - Gravar em arquivo texto certa quantidade de valores (double).");
        IO_println(" 4 - Ler de arquivo texto certa quantidade de valores (double).");
        IO_println(" 5 - Gravar em arquivo texto certa quantidade de valores (char).");
        IO_println(" 6 - Ler de arquivo texto certa quantidade de valores (char).");
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
            method05();
            break;
        case 6:
            method06();
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
s
a
b
c
d
e
f
g
h
i
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         06/10          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 0.1       01.   ( OK )  06/10  - Gravar em arquivo texto certa quantidade de valores. (int)
 0.2       01.   ( OK )  06/10  - Ler de arquivo texto certa quantidade de valores. (int)
 0.3       01.   ( OK )  06/10  - Gravar em arquivo texto certa quantidade de valores. (double)
 0.4       01.   ( OK )  06/10  - Ler de arquivo texto certa quantidade de valores. (double)
 0.5       01.   ( OK )  06/10  - Gravar em arquivo texto certa quantidade de valores. (char)
 0.6       01.   ( OK )  06/10  - Ler de arquivo texto certa quantidade de valores. (char)
*/