/**
    Exemplo0912 - Versao 0.1 - 23/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * fprintRealMatrix - Gravar arranjo bidimensional com valores reais.
 * @param fileName - nome do arquivo
 * @param linhas - quantidade de linhas
 * @param colunas - quantidade de colunas
 * @param matrix - grupo de valores reais
*/
void fprintRealMatrix(chars fileName, int linhas, int colunas, int matrix[][colunas])
{
    //definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    //gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", linhas);
    IO_fprintf(arquivo, "%d\n", colunas);
    //gravar valores no arquivo
    for (int i = 0; i < linhas; i = i + 1)
    {
        for (int j = 0; j < colunas; j = j + 1)
        {
            // gravar valor
            IO_fprintf(arquivo, "%.6lf", matrix[i][j]*0.000001);
        }//end for
    }//end for
    //fechar arquivo
    fclose(arquivo);
}//end fprintRealMatrix

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0912( )
{
    //identificar
    IO_id("\nEXEMPLO0912 - Programa - v0.1");
    //id_cabecalho( "Dados_0912.txt", "0912", "v0.1 - 23/10/20" );
    //ler do teclado as dimensoes da matriz
    int linhas = quantidadesL(" numero de linhas: ");
    int colunas = quantidadesL(" numero de colunass: ");
    // definir dados 
    int matrix[linhas][colunas];
    //chamar funcao
    readRealMatrix(linhas, colunas, matrix);
    fprintRealMatrix("Array0912.txt", linhas, colunas, matrix);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0912

/**
---------------------------------------------- documentacao complementar
exercicio:
gravar uma matriz real em arquivo.
A matriz e o nome do arquivo serao dados como parametros.
Para testar, usar a leitura da matriz do problema anterior.
Usar outro metodo para ler e recuperar a matriz do arquivo, antes de mostra-la na tela.
---------------------------------------------- notas / observacoes / comentarios
 numero de linhas: 3
 numero de colunass: 2
0, 0 : 1.34
0, 1 : 3.56
1, 0 : 5.78
1, 1 : 7.90
2, 0 : 11.02
2, 1 : 27.45
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         15/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.2       01.   ( OK )  23/10  - Gravar matriz real do teclado.
*/