/**
    Exemplo0914 - Versao 0.1 - 23/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * readDiagonalS - ler diagonal secundaria da matrix
 * @param linhas - quantidade de valores
 * @param colunas - quantidade de valores
 * @param matrix - grupo de valores reais
*/
void readDiagonalS( int linhas, int colunas, int matrix[][colunas] )
{
    //variavel com valor inicial
    int confirma = 0;
    chars diagonal = " ";
    //se matrix for quadrada
    if (linhas == colunas)
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                if ( (i + j) == (linhas - 1)){
                    //testar se e' par
                    confirma = eParImpar( matrix[i][j] );
                    if (confirma == 1)
                    {
                        //salvar valores
                        diagonal = IO_concat(diagonal, IO_concat(IO_toString_d(matrix[i][j]), "  "));
                        confirma = 0;
                    }//end if
                }//end if
            }//end for
        }//end for
    }//end if
    if (diagonal != " ")
    {
        IO_printf("\n diagonal secundaria com valores impares: %s", diagonal);
    }
    else
    {
        IO_printf("\n invalido.");
    }
    
}//end readDiagonalS

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0914( )
{
    //identificar
    IO_id("\nEXEMPLO0914 - Programa - v0.1");
    //id_cabecalho( "Dados_0914.txt", "0914", "v0.1 - 23/10/20" );
    //ler do teclado as dimensoes da matriz
    int linhas = freadMatrixLinhas("Array0913.txt");
    int colunas = freadMatrixColunas("Array0913.txt");
    // definir dados 
    int matrix[linhas][colunas];
    //ler matrix
    freadRealMatrix("Array0913.txt", linhas, colunas, matrix);
    //chamar funcao
    readDiagonalS( linhas, colunas, matrix);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0914

/**
---------------------------------------------- documentacao complementar
exercicio:
mostrar somente os valores impares na diagonal secundaria de uma matriz real,
se for quadrada.
---------------------------------------------- notas / observacoes / comentarios
diagonal secundaria com valores impares:  1  3  5  7
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         23/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.4       01.   ( OK )  23/10  - Mostrar diagonal secundaria valores impares.
*/