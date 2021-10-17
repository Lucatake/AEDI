/**
    Exemplo0813 - Versao 0.1 - 20/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * intervalo - metodo para receber um intervalo valido
 * @param a intervalo inferior
 * @param b intevalo superior
 * @param texto texto exibido na tela
*/
void intervalo (int *a, int *b, chars texto)
{
    //ler valor de a
    *a = IO_readint(texto);
    do{
        //ler valor de b
        *b = IO_readint(texto);
    }while (*b <= *a);
}//end intervalo

/**
 * randomico - metodo para gerar 'n' valores aleatorios
 * em um intervalo [a,b]
 * @param a intervalo inferior
 * @param b intevalo superior
 * @param n quantidade
*/
void randomico( int *a, int *b, int n, int array[])
{
    //definir variaveis com valor inicial
    int valor = 0;
    int controle = 1; 
    //acoes
    srand(time(NULL));      //escolher a semente aleatoria dependente do tempo
    //IO_printf ( "%d ", *a );
    //IO_printf ( "%d \n", *b );
    //repetir n vezes
    while ( controle <= n )
    {
        valor = rand ( ); 
        if ( *a <= valor && valor <= *b ) //gerar no intervalo [a:b]
        {
            IO_printf ( "%d ", valor );
            array[controle] = valor;
            controle++;
        }//end if
    }//end while
}

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0813( )
{
    //identificar
    IO_id("\nEXEMPLO0813 - Programa - v0.1");
    //id_cabecalho( "Dados_0813.txt", "0813", "v0.1 - 14/10/20" );
    //definir dados
    int *a = 0;
    int *b = 0;
    //definir intervalo
    intervalo(&a, &b, "\n Digite um valor para o intervalo: ");
    //n quantidades de valores testados
    int n = quantidadesL("\n Quantidade de valores: ");
    //definir arranjo
    int array[n];
    //gerar valor aleatorio
    randomico( &a, &b, n, array);
    //gravar array
    fprintIntArray("DADOS0813.txt", n, array);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0813

/**
---------------------------------------------- documentacao complementar
exercicio:
gerar um valor inteiro aleatoriamente dentro de um intervalo,
cujos limites de inicio e de fim serao recebidos como parametros;
Para para testar, ler os limites do intervalo do teclado;
ler a quantidade de elementos ( N ) a serem gerados;
gerar essa quantidade ( N ) de valores aleatorios
dentro do intervalo e armazena-los em arranjo;
grava-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo devera informar a quantidade
de numeros aleatorios ( N ) que serao gravados em seguida.
DICA: Usar a funçao rand( ), mas tentar limitar valores muito grandes (usar mod=%).
Conveniente usar, inicialmente, uma vez apenas, srand(time(0)) para maior aleatoriedade.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 Digite um valor para o intervalo: 12

 Digite um valor para o intervalo: 98

 Quantidade de valores: 7

66 28 51 93 21 35 85
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         19/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.3       01.   ( OK )  20/10  - Gravar um arranjo de numeros int aleatorios a partir de um intervalo.
*/