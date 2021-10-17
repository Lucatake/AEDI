/**
    Exemplo0911 - Versao 0.1 - 23/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * readRealMatrix - Ler arranjo bidimensional com valores reais.
 * @param linhas - quantidade de linhas
 * @param colunas - quantidade de colunas
 * @param matrix - grupo de valores reais
*/
void readRealMatrix(int linhas, int colunas, int matrix[][colunas])
{
    //definir dados locais
    double z = 0.0;
    //ler e guardar valores em arranjo
    for (int i = 0; i < linhas; i = i + 1)
    {
        for (int j = 0; j < colunas; j = j + 1)
        {
            z = IO_readdouble("\nvalor real: ");
            // guardar valor 
            matrix[i][j] = z * 1000000 ;
        }//end for
    }//end for
}//end readRealMatrix

/**
 * printRealMatrix - Mostrar arranjo bidimensional com valores reais.
 * @param linhas - quantidade de linhas
 * @param colunas - quantidade de colunass
 * @param matrix - grupo de valores reais
*/
void printRealMatrix(int linhas, int colunas, int matrix[][colunas])
{
    //mostrar valores na matriz
    for (int i = 0; i < linhas; i = i + 1)
    {
        for (int j = 0; j < colunas; j = j + 1)
        {
            //mostrar valor
            IO_printf("%.6lf\t", matrix[i][j] * 0.000001);
        }//end for
        IO_printf("\n");
    }//end for
}//end printRealMatrix

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0911( )
{
    //identificar
    IO_id("\nEXEMPLO0911 - Programa - v0.1");
    //id_cabecalho( "Dados_0911.txt", "0911", "v0.1 - 23/10/20" );
    //ler do teclado as dimensoes da matriz
    int linhas = quantidadesL("\n numero de linhas: ");
    int colunas = quantidadesL("\n numero de colunass: ");
    // definir dados 
    int matrix[linhas][colunas];
    //chamar funcao
    readRealMatrix(linhas, colunas, matrix);
    printRealMatrix(linhas, colunas, matrix);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0911

/**
---------------------------------------------- documentacao complementar
exercicio:
ler as dimensoes (quantidade de linhas e de colunass) de uma matriz real do teclado,
bem como todos os seus elementos (apenas valores positivos).
Verificar se as dimensoes nao sao nulas ou negativas.
Para testar, ler dados e mostra-los na tela por outro metodo.
---------------------------------------------- notas / observacoes / comentarios
OBS: questao problema - para matriz com reais seria necessario transformar para "int"
e depois retransformar como fiz? pois assim teria um problema de precisao ne?
---------------------------------------------- previsao de testes
 numero de linhas: 4
 numero de colunass: 3
0, 0 : 1.98
0, 1 : 2.45
0, 2 : 6.34
1, 0 : 9.86
1, 1 : 10.24
1, 2 : 6.34
2, 0 : 7.85
2, 1 : 3.45
2, 2 : 7.89
3, 0 : 10.23
3, 1 : 4.67
3, 2 : .423
1.97    2.45    6.33
9.85    10.24   6.33
7.84    3.45    7.88
10.23   4.66    0.42
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         15/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.1       01.   ( OK )  23/10  - Montar matrix de real a partir do teclado.
*/