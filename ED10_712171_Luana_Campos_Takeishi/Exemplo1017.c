/**
    Exemplo1017 - Versao 0.1 - 29/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1017( )
{
    //identificar
    IO_id("\nEXEMPLO1017 - Programa - v0.1");

    //definir variaveis
    //ler matrix  NAO zerada
    int linhas = freadMatrixRows("MATRIX1.TXT");
    int colunas = freadMatrixColumns("MATRIX1.TXT");
    int matrix [linhas][colunas];
    freadIntMatrix("MATRIX1.TXT", linhas, colunas, matrix);

    //ler matrix ZERADA
    int l = freadMatrixRows("MATRIX3.TXT");
    int c = freadMatrixColumns("MATRIX3.TXT");
    int m [l][c];
    freadIntMatrix("MATRIX3.TXT", l, c, m);

    //testar matrizes
    IO_printf( matrixZerada(linhas, colunas, matrix) ? "\n matriz zeros" : "\n matriz NAO zeros");
    IO_printf( matrixZerada(l, c, m) ? "\n matriz zeros" : "\n matriz NAO zeros");
    

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1017

/**
---------------------------------------------- documentacao complementar
exercicio:
testar se uma matriz so contem valores iguais a zero.
Para testar, receber dados de arquivos e
aplicar a funcao sobre as matrizes com os valores lidos.
DICA: Verificar, primeiro, se os tamanhos sao compativeis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
resposta = zeroMatriz ( matriz1 );
---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
 matriz NAO zeros
 matriz zeros
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.7       01.   ( OK )  29/10  - Verificar se matrizes sao zeros.
*/