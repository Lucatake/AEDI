/**
    Exemplo0917 - Versao 0.1 - 24/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * trianguloDsInf- ler valores abaixo da diagonal secundaria da matrix
 * @param linhas - quantidade de valores
 * @param colunas - quantidade de valores
 * @param matrix - grupo de valores reais
*/
void trianguloDsInf( int linhas, int colunas, int matrix[][colunas] )
{
    //variavel com valor inicial
    int c1 = 0, c2 = 0;
    chars diagonal = " ";
    //se matrix for quadrada
    if (linhas == colunas)
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                if ( (i+j) > (colunas-1) ){
                    //testar se e' multiplo de 3 impar
                    c1 = multiplo3( matrix[i][j] );
                    c2 = eParImpar( matrix[i][j] );
                    if (c1 == 1 && c2 == 1)
                    {
                        //salvar valores
                        diagonal = IO_concat(diagonal, IO_concat(IO_toString_d(matrix[i][j]), "  "));
                        c1 = 0;
                        c2 = 0;
                    }//end if
                }//end if
            }//end for
        }//end for
    }//end if
    if (diagonal != " ")
    {
        IO_printf("\n multiplos de 3 impares abaixo da diagonal secundaria: %s", diagonal);
    }
    else
    {
        IO_printf("\n invalido.");
    }
    
}//end trianguloDsInf

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0917( )
{
    //identificar
    IO_id("\nEXEMPLO0917 - Programa - v0.1");
    //id_cabecalho( "Dados_0917.txt", "0917", "v0.1 - 24/10/20" );
    //ler do teclado as dimensoes da matriz
    int linhas = freadMatrixLinhas("Array0913.txt");
    int colunas = freadMatrixColunas("Array0913.txt");
    // definir dados 
    int matrix[linhas][colunas];
    //ler matrix
    freadRealMatrix("Array0913.txt", linhas, colunas, matrix);
    //chamar funcao
    trianguloDsInf( linhas, colunas, matrix);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0917

/**
---------------------------------------------- documentacao complementar
exercicio:
mostrar somente os valores multiplos de 3 e impares, abaixo da diagonal secundaria
de uma matriz real, se for quadrada
---------------------------------------------- notas / observacoes / comentarios
multiplos de 3 impares abaixo da diagonal secundaria:  15
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         24/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.7       01.   ( OK )  24/10  - triangulo inferior a diagonal secundaria com multiplos de 3 impares.
*/