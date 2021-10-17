/**
    Exemplo0812 - Versao 0.1 - 19/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * freadIntArray - Ler arranjo com valores inteiros.
 * @param fileName - nome do arquivo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
 * @return t - novo tamanho do array
*/
int freadIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int t = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &x);
    if (n <= 0 || n > x)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        // ler e guardar valores em arranjo
        x = 0;
        while (!feof(arquivo) && x < n)
        {
            // ler valor
            IO_fscanf(arquivo, "%d", &y);
            //testar valor
            if( y > 0 && ((y % 2) == 0) )
            {
                // guardar valor
                array[x] = y;
                IO_printf("%d ",y);
                t++;
            }
            // passar ao proximo
            x = x + 1;
        } // fim repetir
    }//fim se
    //definir o novo tamanho dom arranjo
    return(t);
} // freadIntArray ( )

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0812( )
{
    //identificar
    IO_id("\nEXEMPLO0812 - Programa - v0.1");
    //id_cabecalho( "Dados_0812.txt", "0812", "v0.1 - 14/10/20" );
    //definir dados
    int n = 0;
    //chamar funcao
    n = freadArraySize("Array_0812.txt");
    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        //ler dados
        n = freadIntArray("Array_0812.txt", n, array);
        //escrever dados 
        fprintIntArray("Dados_0812.txt", n, array);
    } // fim se
    
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0812

/**
---------------------------------------------- documentacao complementar
exercicio:
ler um arranjo com inteiros positivos de arquivo.
Valores negativos e tambem os impares deverao ser descartados.
O arranjo e o nome do arquivo serao dados como parametros.
Guardar primeiro o tamanho, depois os elementos, um dado por linha.
Para testar, ler diferentes quantidade de dados.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
ERRO: o arranjo lido e separado corretamente (printado na tela), mas gravado com "lixos"
no arquivo txt.
Array_0812 - 14 10 20 1 2 45 -9 -6 0 24 106 48 63 12 6
Dados_0812 - 
8
10
20
4219183
2
4199634
10
4199136
14
OBS: acontece tambem para outros testes.
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         19/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.2       01.   ( OK )  19/10  - Gravar int positivos pares de um array misto.
*/