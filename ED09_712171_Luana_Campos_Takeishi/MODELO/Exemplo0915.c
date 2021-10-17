/**
    Exemplo0915 - Versao 0.1 - 24/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * multiplo3 - testar se e' multiplo de 3
 * @param valor - valor a ser teeado
 * @return confirmcao
*/
int multiplo3(int valor)
{
    //testar valor
    if (valor % 3 == 0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
    //end if    
}//end multiplo3

/**
 * trianguloDpInf- ler valores abaixo da diagonal principal matrix
 * @param linhas - quantidade de valores
 * @param colunas - quantidade de valores
 * @param matrix - grupo de valores reais
*/
void trianguloDpInf( int linhas, int colunas, int matrix[][colunas] )
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
                if ( i != j && i > j ){
                    //testar se e' multiplo de 3
                    confirma = multiplo3( matrix[i][j] );
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
        IO_printf("\n multiplos de 3 abaixo da diagonal principal: %s", diagonal);
    }
    else
    {
        IO_printf("\n invalido.");
    }
    
}//end trianguloDpInf

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0915( )
{
    //identificar
    IO_id("\nEXEMPLO0915 - Programa - v0.1");
    //id_cabecalho( "Dados_0915.txt", "0915", "v0.1 - 24/10/20" );
    //ler do teclado as dimensoes da matriz
    int linhas = freadMatrixLinhas("Array0913.txt");
    int colunas = freadMatrixColunas("Array0913.txt");
    // definir dados 
    int matrix[linhas][colunas];
    //ler matrix
    freadRealMatrix("Array0913.txt", linhas, colunas, matrix);
    //chamar funcao
    trianguloDpInf( linhas, colunas, matrix);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0915

/**
---------------------------------------------- documentacao complementar
exercicio:
mostrar somente os valores múltiplos de 3, abaixo da diagonal principal de uma matriz real,
se for quadrada.
---------------------------------------------- notas / observacoes / comentarios
multiplos de 3 abaixo da diagonal principal:  12  15
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         24/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.5       01.   ( OK )  24/10  - testar se triangulo inferior a diagonal principal tem numeros multiplos de 3.
*/