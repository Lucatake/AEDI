/**
    Exemplo0920 - Versao 0.1 - 24/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"


/**
 * trianguloDpSupZeros- ler valores acima da diagonal principal da matrix
 * e verificar se sao todos zeros
 * @param linhas - quantidade de valores
 * @param colunas - quantidade de valores
 * @param matrix - grupo de valores reais
*/
void trianguloDpSupZeros( int linhas, int colunas, int matrix[][colunas] )
{
    //variavel com valor inicial
    int confirma = 0, teste = 0;
    //se matrix for quadrada
    if (linhas == colunas)
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                if ( i != j && i < j ){
                    teste++;
                    if (matrix[i][j] == 0)
                    {
                        confirma++;
                    }//end if
                }//end if
            }//end for
        }//end for
    }//end if
    if ((confirma == teste) != 0)
    {
        IO_printf("\n somente zeros acima da diagonal principal.");
    }
    else
    {
        IO_printf("\n invalido.");
    }
    
}//end trianguloDpSupZeros

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0920( )
{
    //identificar
    IO_id("\nEXEMPLO0919 - Programa - v0.1");
    //id_cabecalho( "Dados_0919.txt", "0919", "v0.1 - 24/10/20" );
    //ler do teclado as dimensoes da matriz
    int linhas = freadMatrixLinhas("Array_0920.txt");
    int colunas = freadMatrixColunas("Array_0920.txt");
    // definir dados 
    int matrix[linhas][colunas];
    //ler matrix
    freadRealMatrix("Array_0920.txt", linhas, colunas, matrix);
    //chamar funcao
    trianguloDpSupZeros( linhas, colunas, matrix);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0920

/**
---------------------------------------------- documentacao complementar
exercicio:
testar se sao zeros os valores acima da diagonal principal de uma matriz real quadrada.
---------------------------------------------- notas / observacoes / comentarios
 somente zeros a cima da diagonal principal.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         24/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 2.0       01.   ( OK )  24/10  - testar se triangulo Superior a diagonal principal só tem 0.
*/