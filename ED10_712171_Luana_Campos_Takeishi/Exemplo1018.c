/**
    Exemplo1018 - Versao 0.1 - 30/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1018( )
{
    //identificar
    IO_id("\nEXEMPLO1018 - Programa - v0.1");

    //definir variaveis
    //matriz A != B
    int linhas = freadMatrixRows("MATRIX1.TXT");
    int colunas = freadMatrixColumns("MATRIX1.TXT");
    int matrix [linhas][colunas];
    freadIntMatrix("MATRIX1.TXT", linhas, colunas, matrix);

    //matriz B
    int l = freadMatrixRows("MATRIX2.TXT");
    int c = freadMatrixColumns("MATRIX2.TXT");
    int m [l][c];
    freadIntMatrix("MATRIX2.TXT", l, c, m);

    //matriz C == B
    int linhas1 = freadMatrixRows("MATRIX4.TXT");
    int colunas1 = freadMatrixColumns("MATRIX4.TXT");
    int matrix1 [linhas1][colunas1];
    freadIntMatrix("MATRIX4.TXT", linhas1, colunas1, matrix1);

    //comparar matrizes
    IO_printf( comparaMatriz( l, c, m, linhas, colunas, matrix) ? 
                "\n sao iguais" : "\n sao diferentes");
    IO_printf( comparaMatriz( l, c, m, linhas1, colunas1, matrix1) ? 
                "\n sao iguais" : "\n sao diferentes");

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1018

/**
---------------------------------------------- documentacao complementar
exercicio:
testar se duas matrizes sao diferentes.
Para testar, receber dados de arquivos e
aplicar a funcao sobre as matrizes com os valores lidos.
DICA: Verificar, primeiro, se os tamanhos sao compativeis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
matriz2 = lerMatrizDeArquivo ( "DADOS2.TXT" );
resposta = compararMatriz ( matriz1, matriz2 );
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 sao diferentes
 sao iguais
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         30/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.8       01.   ( OK )  30/10  - Verificar se matrizes sao diferentes.
*/