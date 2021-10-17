/**
    Exemplo0817 - Versao 0.1 - 22/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * aOrdem - funcao para mostrar se arrray esta
 * ou nao ordenado de forma decrescente
 * @param n - tamanho array
 * @param array - array
*/
bool aOrdem( int n, int array[])
{
    bool ordem = true;

    for (int i = 0; i < n-1; i++)
    {
        if (array[i] < array[i+1])
        {
            ordem = false;
            i = n;
        }//end if
    }//end for
    return(ordem);
}//end aOrdem


/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0817( )
{
    //identificar
    IO_id("\nEXEMPLO0817 - Programa - v0.1");
    //id_cabecalho( "Dados_0817.txt", "0817", "v0.1 - 14/10/20" );
    //ler dados
    int n = quantidadesL("\n tamanho do array = ");
    //definir array
    int array[n];
    //ler array do teclado
    KreadIntArray(n, array);
    //verificar se esta ordenado decrescente
    bool ordem = aOrdem( n, array );
    //mostrar resultados
    if (ordem)
    {
        IO_printf(" Array ordenado de maneira descrescente.");
    }
    else
    {
        IO_printf(" Array NAO ordenado de maneira decrescente.");
    }//end if
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0817

/**
---------------------------------------------- documentacao complementar
exercicio:
receber como parametro um arranjo
e dizer se esto ordenado, ou nao, em ordem decrescente.
DICA: Testar se nao esta desordenado, ou seja,
se existe algum valor que seja maior que o seguinte.
Não usar break !
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 tamanho do array = 10
0 : 10
1 : 9
2 : 8
3 : 7
4 : 6
5 : 5
6 : 4
7 : 3
8 : 2
9 : 1
 Array ordenado de maneira descrescente.

 tamanho do array = 10
0 : 1
1 : 2
2 : 3
3 : 4
4 : 5
5 : 6
6 : 7
7 : 8
8 : 9
9 : 10
 Array NAO ordenado de maneira decrescente.

 tamanho do array = 5
0 : 6
1 : 34
2 : 7
3 : 3
4 : 23
 Array NAO ordenado de maneira decrescente.
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         22/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.7       01.   ( OK )  22/10  - Testar se arranjo esta desordenado ou nao.
*/