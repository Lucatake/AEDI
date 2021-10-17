/**
    Exemplo0816 - Versao 0.1 - 22/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * aMedia - funcao para achar a media
 * em um arranjo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
int aMedia( int n, int array[] )
{
    //definir variaveis com valor inicial
    double media = 0.0;
    int soma = 0;

    //somar todos os numeros
    for (int i = 0; i < n; i++)
    {
        soma += array[i];
    }//end for
    media = (double) soma / n;
    //retornar media   
    return(media);
}//end aMedia

/**
 * metodo para comparar o array com a média
 * gravar em arquivos:
 * pares maiores ou iguais a media
 * impares menores que a media
 * @param filePAR - nome do arquivo par
 * @param fileIMPAR - nome do arquivo impar
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
 * @param media - media dos valores
*/
void aCompara( int media, int n, int array[], chars filePAR, chars fileIMPAR)
{
    //definindo dados
    FILE *arquivoPAR = fopen(filePAR, "wt");
    FILE *arquivoIMPAR = fopen(fileIMPAR, "wt");
    //comparando array
    for (int i = 0; i < n; i++)
    {
        if ((array[i] % 2 == 0) && (array[i] >= (int) media))
        {
           IO_fprintf(arquivoPAR, "%d\n", array[i]);
        } else if ((array[i] % 2 != 0) && (array[i] < (int) media))
        {
            IO_fprintf(arquivoIMPAR, "%d\n", array[i]);
        }
    }
}//end aCompara


/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0816( )
{
    //identificar
    IO_id("\nEXEMPLO0816 - Programa - v0.1");
    //id_cabecalho( "Dados_0816.txt", "0816", "v0.1 - 14/10/20" );
    //ler dados
    int n = freadArraySize("Array_0814.txt");
    //definir array
    int array[n];
    //ler array
    readIntArray("Array_0814.txt", n, array);
    //achar media valor
    double media = aMedia( n, array );
    //mostrar valor
    IO_printf("\n media  = %.lf", media);
    //comparar media e armazenar valores 
    //pares iguais ou maiores e impares menores
    aCompara( media, n, array, "Pares0816.txt", "Impares0816.txt");
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0816

/**
---------------------------------------------- documentacao complementar
exercicio:
para determinar a media valores em um arranjo.
Para testar, ler o arquivo ("DADOS.TXT")
armazenar os dados em um arranjo;
separar em dois outros arquivos,
os valores pares mediaes ou iguais à média, e os ímpares menores que ela.
Exemplo: lerArquivo ( "DADOS.TXT", n, arranjo );
media = acharMedia ( n, arranjo );
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 media  = 34
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         22/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.6       01.   ( OK )  22/10  - Achar a media de um array de arquivo.
*/