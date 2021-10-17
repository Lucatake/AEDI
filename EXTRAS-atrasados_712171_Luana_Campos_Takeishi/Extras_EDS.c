/**
    Metodo para testar todos os exercicios em um so' programa
    Extras_EDS - Versao 0.1 - 05/11/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o Extras_EDS      Extras_EDS.c
    Windows:    gcc -o Extras_EDS.exe  Extras_EDS.c
    Para executar em terminal (janela de comandos):
    Linux:      ./Extras_EDS
    Windows:    Extras_EDS
*/

//dependencias
//para definicoes proprias
#include "io.h"
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
//para metodos proprios
#include "Luana.h"
#include "Array.h"
//lista dos exercicios
void E01E1( );   //extraED01
void E01E2( );   //extraED01
void E07E1( );   //extraED07
void E07E2( );   //extraED07
void E08E1( );   //extraED08
void E08E2( );   //extraED08
void E09E1( );   //extraED09
void E09E2( );   //extraED09
void E10E1( );   //extraED10
void E10E2( );   //extraED10
//lista de funcoes
int menu(void);
void writeDivs(chars fileName, int valor);
int readSomeWords(chars fileName);
void divisores(int valor, int n, int array[]);
void procuraPalavras( chars fileName, int n, chars palavras[] );
void printStringArray( int n, chars palavras[] );
void geraMatrizDCol(chars fileName, int linhas, int colunas, int matriz[][colunas]);
void geraMatrizDLin(chars fileName, int linhas, int colunas, int matriz[][colunas]);
void ordenaArray(chars fileName, int n, int array[], int tipo);

//----------------------------------------------------funcao principal
/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param e escolha do menu
*/
int main( int e )
{
    //identificar
    IO_id("\nESTUDO DIRIGIDO 07 - Programa - v0.1");
    //definir dado com valor inicial
    int x = 0;
    //repetir ate desejar parar
    do
    {
        //ler do teclado
        x = menu( );
        //testar valor
        //escolha do exercicio a ser executado
        switch (x)
        {
        case 0:
            Parar( );
            break;
        case 1:
            E01E1( );
            break;
        case 2:
            E01E2( );
            break;
        case 3:
            E07E1( );
            break;
        case 4:
            E07E2( );
            break;
        case 5:
            E08E1( );
            break; 
        case 6:
            E08E2( );
            break;
        case 7:
            E09E1( );
            break;
        case 8:
            E09E2( );
            break;
        case 9:
            E10E1( );
            break;
        default:
            IO_println("\nValor diferente das opcoes");
            break;
        }//end switch-case
    } while ( x!=0 ); //end do-while
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

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
    IO_println(" 0 - Parar");
    IO_println(" 1 - Extra1_ED01  |  2 - Extra2_ED01  |  3 - Extra1_ED07");
    IO_println(" 4 - Extra2_ED07  |  5 - Extra1_ED08  |  6 - Extra2_ED08");
    IO_println(" 7 - Extra1_ED09  |  8 - Extra2_ED09  |  9 - Extra1_ED10");
    //ler do teclado
    e = IO_readint("\nEntrar com uma opcao: ");
    //retornat valor lido
    return (e);
}//end menu( )

//---------------------------------------------------metodos e funcoes
// Estudo Dirigido 01
/**
 * E01E1:
 * definir e ler um valor real do teclado; supor que esse 
 * valor informe a area de um retangulo com lados iguais a 
 * metade do outro, calcular e mostrar os lados e o perimetro do mesmo.
*/
void E01E1( )
{
    //definir dado
    //definir variavel com valor inicial
    float area = 0.0;
    float lado1 = 0.0;
    float lado2 = 0.0;
    float perimetro = 0.0;

    //identificar - cabecalho
    IO_id("Exemplo01E1 - Programa - V0.1");

    //ler valores do teclado
    area = IO_readfloat ("\nDigite um valor real: ");

    //achar lados
    lado1 = sqrt(2 * area);
    lado2 = lado1/2;
    //achar perimetro
    perimetro = (lado1*2) + (lado2*2);

    //mostrar na tela valores finais
    IO_printf("\n%s %f", "Area do retangulo: ", area);  
    IO_printf("\n%s %f", "Lado 01 do retangulo: ", lado1); 
    IO_printf("\n%s %f", "Lado 02 do retangulo: ", lado2); 
    IO_printf("\n%s %f", "Perimetro do retangulo: ", perimetro); 

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E01E1( )

/**
 * E01E2:
 * definir e ler um valor real do teclado;
 * supor que esse valor represente o volume de um cone com 
 * raio igual a metade da altura;
 * calcular e mostrar o raio e a area de sua superficie.
*/
void E01E2( )
{
    //definir dado
    //definir variavel com valor inicial
    float volume = 0.0;
    float raio = 0.0;
    float altura = 0.0;
    float areaS = 0.0;
    float pi = M_PI;        //definindo pi

    //identificar - cabecalho
    IO_id("Exemplo01E2 - Programa - V0.1");

    //ler valores do teclado
    volume = IO_readfloat ("\nDigite um valor real: ");

    //achar raio e altura
    altura = pow(((36*volume)/(3*pi)), (1/3));
    raio = altura/2;
    //calcular area de superficie
    areaS = pi * raio * ( (2 * pow(altura,2)) + raio );

    //mostrar na tela valores finais
    IO_printf("\n%s %f", "Volume de um cone: ", volume);  
    IO_printf("\n%s %f", "Raio do cone: ", raio); 
    IO_printf("\n%s %f", "Altura do cone: ", altura); 
    IO_printf("\n%s %f", "Area de superficie do cone: ", areaS); 

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E01E2( )

// Estudo Dirigido 07
/**
 * E07E1:
 * programa ler um valor inteiro do teclado, e
 * gravar em arquivo os seus divisores em ordem crescente.
*/
void E07E1( )
{
    //identificar - cabecalho
    IO_id("Exemplo07E1 - Programa - V0.1");
    //ler valor do teclado
    int valor = IO_readint("\n digite um valor: ");
    //chamar funcao
    writeDivs("Extra07E1.txt", valor);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E07E1

/**
 * writeDivs - Gravar em arquivo divisores de um valor.
 * @param fileName - nome do arquivo
 * @param valor - valor
*/
void writeDivs(chars fileName, int valor)
{
    //definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int v = valor * -1;
    //repetir ate o valor
    //se positivo
    for (int y = 1; y <= valor; y++)
    {
        //se for divisor
        if (valor % y == 0)
        {
            //gravar divisor
            fprintf(arquivo, "%d\n", y);
        }//end if
    }//end for
    //fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
}//end writeDivs ( )

/**
 * E07E2:
 * ler palavras de um arquivo, uma por linha, e
 * contar quantas começam com a letra 'a' (ou 'A') e que não terminem em 'a' (ou 'A').
*/
void E07E2( )
{
    //identificar - cabecalho
    IO_id("Exemplo07E2 - Programa - V0.1");
    //chamar funcao
    int palavras = readSomeWords("Extra07E2.txt");
    IO_printf("\n %d palavras iniciadas em 'A'||'a' e NAO terminadas em 'A'||'a'", palavras);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E07E1

/**
 * readSomeWords - Ler palavras de arquivo e verificar
 * se comecam com A ou a e NAO terminam com A ou a.
 * @param fileName - nome do arquivo
 * @return quantidade de palavras
*/
int readSomeWords(chars fileName)
{
    //definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    int palavras = 0;
    //tentar ler a primeira
    strcpy(linha, IO_fread(arquivo));
    //repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp("PARAR", linha) != 0)
    {
        int q = strlen(linha)-1;
        if ((linha[0]=='A'||linha[0]=='a') && (linha[q]!='A'&&linha[q]!='a'))
        {
            palavras++;
        }//end if
        //tentar ler o proximo
        strcpy(linha, IO_fread(arquivo));
    }//end while
    //fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
    //retornar quantidades
    return(palavras);
}//end readSomeWords ( )

// Estudo Dirigido 08
/**
 * E08E1:
 * ler um valor inteiro do teclado,
 * e mediante funcoes para calcular e retornar a quantidade
 * e seus divisores guardados em arranjo,
 * o qual devera ser mostrado na tela apos o retorno,
 * bem como gravado em arquivo ( "DIVISORES.TXT" ).
 * DICA: Supor que a quantidade de divisores
 * sera menor ou igual ao proprio numero.
*/
void E08E1( )
{
    //identificar - cabecalho
    IO_id("Exemplo08E1 - Programa - V0.1");
    //definir dados
    int n = 0;
    int array[n];
    //ler valor do teclado
    int valor = IO_readint("\n digite um valor: ");
    //chamar funcao
    divisores(valor, n, array);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E08E1

/**
 * dividores - calcular os divisores de um numero e armazenar em arranjo
 * que devera ser guardado tambem em arquivo.
*/
void divisores(int valor, int n, int array[])
{
    //achar divisores
    for (int y = 1; y <= valor; y++)
    {
        //se for divisor
        if (valor % y == 0)
        {
            //gravar divisor
            array[n] = y;
            n++;
        }//end if
    }//end for
    //guardar resultado
    fprintIntArray("divisores.txt", n, array);
    //mostrar resultado
    IO_printf("\n %d divisores: ", n);
    IO_println("");
    printIntArray(n, array);
}// divisores( )

/**
 * E08E2:
 * ler um arquivo ( "PALAVRAS.TXT" ),
 * e mediante uma funcao retornar as dez primeiras palavras
 * que comecem e terminem com a letra 'a' (ou 'A'), se houver.
 * As palavras encontradas deverao ser exibidas na tela, apos retorno.
 * DICA: Supor que a quantidade de palavras nao ultrapassara 100.
*/
void E08E2( )
{
    //identificar - cabecalho
    IO_id("Exemplo08E2 - Programa - V0.1");
    //definir dados
    int n = 10;
    chars palavras[n];
    //chama funcao 
    procuraPalavras("palavras.txt", n, palavras);
    //mostrar array com as palavras
    //printStringArray( n, palavras );
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E08E2

/**
 * procuraPalavras - procura e mostra as 10 primeiras palavras
 * que comecem e terminem com 'A' ou 'a'
 * @param fileName - arquivo onde ler as palavras
 * @param palavras - array contendo as palavras encontradas
 * @param n - quantidade de palavras
*/
void procuraPalavras( chars fileName, int n, chars palavras[] )
{
    //definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    int m = 0;
    //tentar ler a primeira
    strcpy(linha, IO_fread(arquivo));
    //repetir enquanto houver dados
    while (!feof(arquivo) && strcmp(".", linha) != 0)
    {
        //verificar primeira e ultima letra
        int q = strlen(linha)-1;
        if ((linha[0]=='A'||linha[0]=='a') && (linha[q]=='A'||linha[q]=='a'))
        {
            //guardar as 10 primeiras
            if (m < n)
            {
                //guardar palavra em arranjo
                palavras[m] = linha;
                IO_printf("\n %s", palavras[m]);
                //IO_printf("\n %d", m);
                m++;          
            }//end if
        }//end if
        //tentar ler o proximo
        strcpy(linha, IO_fread(arquivo));
    }//end while
    //fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
}//end procuraPalavras( )

/**
 * printStringArray - mostrar palavras de array
 * @param n - quantidade de palavras
 * @param palavras - arranjo com as palavras
*/
void printStringArray( int n, chars palavras[] )
{
    //mostrar strings
    for (int i = 0; i < n; i++)
    {
        IO_printf("\n %s", palavras[i]);
    }//end for
}//end printStringArray

// Estudo Dirigido 09
/**
 * E09E1:
 * ler do teclado as quantidades de linhas e colunas de uma matriz,
 * e montar uma matriz com a caracteristica abaixo,
 * a qual devera ser gravada em arquivo, apos o retorno.
 *                             16  12  8   4
 *             9   6   3       15  11  7   3
 * 4   2       8   5   2       14  10  6   2
 * 3   1       7   4   1       13  9   5   1
*/
void E09E1( )
{
    //identificar - cabecalho
    IO_id("Exemplo09E1 - Programa - V0.1");
    //criar matriz
    int linhas = quantidades("\n quantidade de linhas=colunas: ");
    int colunas = linhas;
    int matriz[linhas][colunas];
    //chamar funcao
    geraMatrizDCol("matriz09E1.txt", linhas, colunas, matriz);
    //verificar matriz
    printIntMatrix(linhas, colunas, matriz);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E09E1

/**
 * geraMatrizDCol - gerar matrizes quadradas decrescentes 
 * de cima paraxo, por colunas.
 * @param fileName - nome do arquivo
 * @param linhas - linhas da matriz
 * @param colunas - colunas da matriz
 * @param matriz - matriz
*/
void geraMatrizDCol(chars fileName, int linhas, int colunas, int matriz[][colunas])
{
    //definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int valor = linhas*colunas;
    int auxiliar = linhas*colunas;
    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", linhas);
    IO_fprintf(arquivo, "%d\n", colunas);
    //linhas
    for (int i = 0; i < linhas; i++)
    {
        //colunas
        for (int j = 0; j < colunas; j++)
        {
            //armazenar valor
            matriz[i][j] = valor;
            //gravar valor
            IO_fprintf(arquivo, "%d\n", matriz[i][j]);
            //proximo valor
            valor=valor-linhas;
        }//end for
        //voltar valor
        auxiliar--;
        valor = auxiliar;
    }//end for
    //fechar arquivo
    fclose(arquivo);
}//end geraMatrizDCol( )

/**
 * E09E2:
 * ler do teclado as quantidades de linhas e colunas de uma matriz,
 * e montar uma matriz com a caracteristica abaixo,
 * a qual devera ser gravada em arquivo, apos o retorno.
 *                             16  15  14  13
 *             9   8   7       12  11  10   9
 * 4   3       6   5   4        8   7   6   5
 * 2   1       3   2   1        4   3   2   1
*/
void E09E2( )
{
    //identificar - cabecalho
    IO_id("Exemplo09E2 - Programa - V0.1");
    //criar matriz
    int linhas = quantidades("\n quantidade de linhas=colunas: ");
    int colunas = linhas;
    int matriz[linhas][colunas];
    //chamar funcao
    geraMatrizDLin("matriz09E2.txt", linhas, colunas, matriz);
    //verificar matriz
    printIntMatrix(linhas, colunas, matriz);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E09E2

/**
 * geraMatrizDLin - gerar matrizes quadradas decrescentes 
 * de cima paraxo, por linhas.
 * @param fileName - nome do arquivo
 * @param linhas - linhas da matriz
 * @param colunas - colunas da matriz
 * @param matriz - matriz
*/
void geraMatrizDLin(chars fileName, int linhas, int colunas, int matriz[][colunas])
{
    //definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int valor = linhas*colunas;
    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", linhas);
    IO_fprintf(arquivo, "%d\n", colunas);
    //linhas
    for (int i = 0; i < linhas; i++)
    {
        //colunas
        for (int j = 0; j < colunas; j++)
        {
            //armazenar valor
            matriz[i][j] = valor;
            //gravar valor
            IO_fprintf(arquivo, "%d\n", matriz[i][j]);
            //proximo valor
            valor--;
        }//end for
    }//end for
    //fechar arquivo
    fclose(arquivo);
}//end geraMatrizDLin( )

// Estudo Dirigido 10
/**
 * E10E1:
 * colocar um arranjo em ordem, pelo metodo de trocas de posicao.
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre o arranjo com os valores lidos,
 * informando se e desejado a ordem crescente (0) ou a decrescente (1).
 * Exemplo: arranjo1 = lerArquivo ( "DADOS1.TXT" );
 * ordenado = ordenar ( tipo, arranjo );
*/
void E10E1( )
{
    //identificar - cabecalho
    IO_id("Exemplo10E1 - Programa - V0.1");
    //ler arranjo de arquivo
    int n = freadArraySize("arrayDesord.txt");
    int array[n];
    freadIntArray("arrayDesord.txt", n, array);
    //perguntar se decrente ou crescente
    int tipo = IO_readint("\n digite 0 para crescente e 1 para decrescente: ");
    //chamar funcao pra ordenar
    if (tipo == 1 || tipo == 0)
    {
        ordenaArray("arrayOrd.txt", n, array, tipo);
        //mostrar array ordenado
        printIntArray(n, array);
    } else
    {
        IO_printf("\n valor invalido.");
    }//end if 
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end E10E1

/**
 * ordenaArray  ordenar array de forma decrescente ou crescente
 * @param fileName - arquivo a gravar arranjo ordenado
 * @param n - tamanho array
 * @param array - arranjo
 * 
*/
void ordenaArray(chars fileName, int n, int array[], int tipo)
{
    //definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int auxiliar = 0;
    //crescente - 0
    if( tipo == 0 )
    {
	for (int q = 0; q < n; q++)
	{
		for (int i = 1; i < n; i++)
        	{
            		if (array[i]<array[i-1])
            		{
                		auxiliar = array[i];
                		array[i] = array[i-1];
                		array[i-1] = auxiliar;
            		}//end if  
        	}//end for
	}//end for
    } else 
    //decrescente - 1
    if ( tipo == 1 )
    {
	for (int q = 0; q < n; q++)
	{
		for (int i = 1; i < n; i++)
        	{
            		if (array[i]>array[i-1])
            		{
                		auxiliar = array[i];
                		array[i] = array[i-1];
                		array[i-1] = auxiliar;
            		}//end if
        	}//end for
	}//end for
    }//end if
    //fechar arquivo
    fclose(arquivo);
}//end ordenaArray( )

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes e testes
Extra01 ED01:
    -Teste 1: Digite um valor real: 12.56
        Area do retangulo:  12.560000       Lado 01 do retangulo:  5.011986
        Lado 02 do retangulo:  2.505993     Perimetro do retangulo:  15.035957
    -Teste 2: Digite um valor real: 2.67
        Area do retangulo:  2.670000        Lado 01 do retangulo:  2.310844
        Lado 02 do retangulo:  1.155422     Perimetro do retangulo:  6.932532
Extra02 ED01:
    -Teste 1: Digite um valor real: 12.67
        Volume de um cone:  12.670000       Raio do cone:  0.500000
        Altura do cone:  1.000000           Area de superficie do cone:  3.926991
    -Teste 2: Digite um valor real: 4.92
        Volume de um cone:  4.920000        Raio do cone:  0.500000
        Altura do cone:  1.000000           Area de superficie do cone:  3.926991

Extra01 ED07:
    -Teste 1: valor - 100
     valores gravados: 1, 2, 4, 5, 10, 20, 25, 50, 100
    -Teste 2: valor - 1500
     valores gravados: 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 25, 30, 50, 60,
                      75, 100, 125, 150, 250, 300, 375, 500, 750, 1500
    -Teste 3: valor - 0 - nao grava nada
    -Teste 4: para negativos nao funciona
Extra02 ED07:
    -Teste 1: palavras - Amora, amora, Amar, amar, Alçapão, alçapão, 
              Afofar, afofar, ameba, Ameba, opa, Opa, Luana, luana
     6 palavras iniciadas em 'A'||'a' e NAO terminadas em 'A'||'a'
    -Teste 2: palavras - Amare, amare, abcde, Abcde, palavra, Palavra
              Aba, aba, Apo, Opa
     5 palavras iniciadas em 'A'||'a' e NAO terminadas em 'A'||'a'

Extra01 ED08:
    -Teste 1: valor - 100
     tela: 9 divisores: 0: 1     1: 2    2: 4    3: 5    4: 10
                        5: 20   6: 25   7: 50   8: 100
     arquivo: 9, 1, 2, 4, 5, 10, 20, 25, 50, 100
    -Teste 2: valor - 50
     tela:  6 divisores: 0: 1    1: 2    2: 5    3: 10   4: 25   5: 50
     arquivo: 6, 1, 2, 5, 10, 25, 50
    -Teste 3: para 0 e valores negativos nao e' calculado
Extra02 ED08:
    -Teste 1: o array esta sendo preenchido com "." em procuraPalavras ao sair do while
    OBS: erro nao identificado o motivo.
    -Teste 2: palavras do arquivo: ameba Ameba opa Opa Luana luana Ama ama amarela Amarela
              azul Azula ela Ala alia Amora amora amo Aveza avezea Apola apola .
    resultado: ameba Ameba Ama ama amarela Amarela Azula Ala alia Amora
    
Extra01 ED09:
    -Teste 1: quantidade de linhas=colunas: 3
  9       6       3
  8       5       2
  7       4       1
    -Teste 2: quantidade de linhas=colunas: 4
 16      12       8       4
 15      11       7       3
 14      10       6       2
 13       9       5       1
Extra02 ED09:
    -Teste 1: quantidade de linhas=colunas: 4
 16      15      14      13
 12      11      10       9
  8       7       6       5
  4       3       2       1
    -Teste 2: quantidade de linhas=colunas: 3
  9       8       7
  6       5       4
  3       2       1

Extra01 ED10: array: [9] 10 2 9 4 8 3 5 6 7
    -Teste 1: digite 0 para crescente e 1 para decrescente: 0
     0: 2    1: 3    2: 4    3: 5    4: 6    5: 7    6: 8    7: 9    8: 10
    -Teste 2: digite 0 para crescente e 1 para decrescente: 1
     0: 10   1: 9    2: 8    3: 7    4: 6    5: 5    6: 4    7: 3    8: 2
    -Teste 3:  digite 0 para crescente e 1 para decrescente: 6
      valor invalido.

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         05/11         esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
  E.1       01. ( OK )  04/11    ED01 - retangulo com valor real.
  E.2       01. ( OK )  04/11    ED01 - cone com valor real.
  E.1       07. ( OK )  04/11    ED01 - gravar divisores em ordem crescente.
  E.2       07. ( OK )  04/11    ED01 - contar palavras comecadas com a/A e nao terminem com a/A.
  E.1       08. ( OK )  04/11    ED01 - gravar e retornar divisores em arranjo.
  E.2       08. ( OK )  04/11    ED01 - retirna 10 primeiras palavras iniciadas e terminadas com a/A de arquivo.
  E.1       09. ( OK )  04/11    ED01 - gerar matriz quadrada decrescente coluna.
  E.2       09. ( OK )  04/11    ED01 - gerar matriz quadrada decrescente linha.
  E.1       10. ( OK )  04/11    ED01 - ordenar array de arquivo decrescente ou crescente.
*/