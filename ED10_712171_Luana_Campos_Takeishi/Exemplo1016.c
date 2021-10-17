/**
    Exemplo1016 - Versao 0.1 - 30/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1016( )
{
    //identificar
    IO_id("\nEXEMPLO1016 - Programa - v0.1");

    //definir variaveis
    //ler matrix de arquivo
    int linhas = freadMatrixRows("MATRIX1.TXT");
    int colunas = freadMatrixColumns("MATRIX1.TXT");
    int matrix [linhas][colunas];
    freadIntMatrix("MATRIX1.TXT", linhas, colunas, matrix);

    //ler outra matrix
    int l = freadMatrixRows("MATRIX2.TXT");
    int c = freadMatrixColumns("MATRIX2.TXT");
    int m [l][c];
    freadIntMatrix("MATRIX2.TXT", l, c, m);

    //comparar matrizes
    IO_printf( eTransposta( l, c, m, linhas, colunas, matrix) ? 
                "\n uma e' transposta da outra" : "\n nao sao transpostas");

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1016

/**
---------------------------------------------- documentacao complementar
exercicio:
obter a transposta de uma matriz.
Para testar, receber dados de arquivos e
aplicar a funcao sobre as matrizes com os valores lidos.
DICA: Verificar, primeiro, se os tamanhos sao compativeis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
matriz2 = transpostaMatriz ( matriz1 );
---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         30/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.6       01.   ( OK )  30/10  - Verificar se matrizes sao transpostas.
*/