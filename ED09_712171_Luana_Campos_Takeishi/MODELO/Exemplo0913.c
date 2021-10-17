/**
    Exemplo0913 - Versao 0.1 - 23/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * freadMatrixLinhas - Ler tamanho (linhas) da matriz com valores inteiros.
 * @return quantidade de linhas da matriz
 * @param fileName - nome do arquivo
*/
int freadMatrixLinhas(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    ints array = NULL;
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // fim se
    // retornar dado lido
    return (n);
} // freadMatrixLinhas ( )

/**
 * freadMatrixcolunas - Ler tamanho (colunas) da matriz com valores inteiros.
 * @return quantidade de colunas da matriz
 * @param fileName - nome do arquivo
*/
int freadMatrixColunas(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    IO_fscanf(arquivo, "%d", &n);
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // fim se
    // retornar dado lido
    return (n);
} // freadMatrixcolunas ( )

/**
 * freadRealMatrix - Ler arranjo bidimensional com valores reais.
 * @param fileName - nome do arquivo
 * @param linhas - quantidade de valores
 * @param colunas - quantidade de valores
 * @param matrix - grupo de valores reais
*/
void freadRealMatrix(chars fileName, int linhas, int colunas, int matrix[][colunas])
{
    // definir dados locais
    int i = 0,  j = 0;
    int z = 0;
    FILE *arquivo = fopen(fileName, "rt");
    //ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &i);
    IO_fscanf(arquivo, "%d", &j);
    if (linhas <= 0 || linhas > i || colunas <= 0 || colunas > j)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        //ler e guardar valores em arranjo
        i = 0;
        while (!feof(arquivo) && i < linhas)
        {
            j = 0;
            while (!feof(arquivo) && j < colunas)
            {
                // ler valor
                IO_fscanf(arquivo, "%d", &z);
                // guardar valor
                matrix[i][j] = z;
                // passar ao proximo
                j++;
            }//end while
            //passar ao proximo
            i++;
        }//end while
    }//end if
}//end freadRealMatrix ( )

/**
 * eParImpar - testar se e' par ou impar
 * @param valor - valor a ser testado
 * @return indicador de par ou impar
*/
int eParImpar( int valor )
{
    //se par
    if( valor % 2 == 0)
    {
        return(2);
    }
    else        //se impar
    {
        return(1);
    }//end if
}//end eParImpar

/**
 * readDiagonalP - ler diagonal principal da matrix
 * @param linhas - quantidade de valores
 * @param colunas - quantidade de valores
 * @param matrix - grupo de valores reais
*/
void readDiagonalP( int linhas, int colunas, int matrix[][colunas] )
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
                if ( i == j ){
                    //testar se e' par
                    confirma = eParImpar( matrix[i][j] );
                    if (confirma == 2)
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
        IO_printf("\n diagonal principal com valores pares: %s", diagonal);
    }
    else
    {
        IO_printf("\n invalido.");
    }
    
}//end readDiagonalP

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0913( )
{
    //identificar
    IO_id("\nEXEMPLO0913 - Programa - v0.1");
    //id_cabecalho( "Dados_0913.txt", "0913", "v0.1 - 23/10/20" );
    //ler do teclado as dimensoes da matriz
    int linhas = freadMatrixLinhas("Array0913.txt");
    int colunas = freadMatrixColunas("Array0913.txt");
    // definir dados 
    int matrix[linhas][colunas];
    //ler matrix
    freadRealMatrix("Array0913.txt", linhas, colunas, matrix);
    //chamar funcao
    readDiagonalP( linhas, colunas, matrix);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0913

/**
---------------------------------------------- documentacao complementar
exercicio:
mostrar somente os valores pares na diagonal principal de uma matriz real,
se for quadrada.
---------------------------------------------- notas / observacoes / comentarios
diagonal principal com valores pares:  2  4  6  8
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         15/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.3       01.   ( OK )  23/10  - Mostrar diagonal principal valores pares.
*/