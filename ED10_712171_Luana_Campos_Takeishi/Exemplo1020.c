/**
    Exemplo1020 - Versao 0.1 - 30/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * multiplicaMatriz - verifica se uma matriz e' igual a outra
 * @param l, linhas - linhas das matrizes
 * @param c, colunas - colunas das matrizes
 * @param matrix2, matrix1 - matrizes comparadas
*/
void multiplicaMatriz( int l, int c, int matrix[][c],
                int linhas1, int colunas1, int matrix1[][colunas1], 
                int linhas2, int colunas2, int matrix2[][colunas2] )
{
    //testar se sao do mesmo tamanho
    if (linhas1 == linhas2 && colunas1 == colunas2)
    {
        for (int i = 0; i < linhas1; i++)
        {
            for (int q = 0; q < colunas1; q++)
            {
                matrix[i][q] = matrix1[i][q] * matrix2[i][q];
            }//end for
        }//end for
        l = linhas1;
        c = colunas1;
    } else
    {
        IO_printf("\n matrizes com tamanhos diferentes.");
    }//end if
}//end multiplicaMatriz

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1020( )
{
    //identificar
    IO_id("\nEXEMPLO1020 - Programa - v0.1");

    //definir variaveis
    //matriz 1 A
    int linhas1 = freadMatrixRows("MATRIX1.TXT");
    int colunas1 = freadMatrixColumns("MATRIX1.TXT");
    int matrix1 [linhas1][colunas1];
    freadIntMatrix("MATRIX1.TXT", linhas1, colunas1, matrix1);

    //matriz 2 B
    int linhas2 = freadMatrixRows("MATRIX2.TXT");
    int colunas2 = freadMatrixColumns("MATRIX2.TXT");
    int matrix2 [linhas2][colunas2];
    freadIntMatrix("MATRIX2.TXT", linhas2, colunas2, matrix2);

    //matriz multiplicada A e B
    int l = freadMatrixRows("MATRIX4.TXT");
    int c = freadMatrixColumns("MATRIX4.TXT");
    int m [l][c];

    //comparar matrizes
    multiplicaMatriz( l, c, m, linhas1, colunas1, matrix1, linhas2, colunas2, matrix2 );

    //mosrtrar matriz
    printIntMatrix( l, c, m );

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1020

/**
---------------------------------------------- documentacao complementar
exercicio:
obter o produto de duas matrizes.
Para testar, receber dados de arquivos e
aplicar a funcao sobre as matrizes com os valores lidos.
DICA: Verificar se os tamanhos sao compativeis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
matriz2 = lerMatrizDeArquivo ( "DADOS2.TXT" );
soma = multiplicarMatriz ( matriz1, matriz2 );
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
  1     115      24      90
115     4489    630     234
 24     630     529     225
 90     234     225     4489
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         30/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 2.0       01.   ( OK )  30/10  - Multiplicar duas matrizes.
*/