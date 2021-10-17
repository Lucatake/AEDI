/**
 * Exemplo0511 - v0.1. - 23/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
//#include "Luana.h"  //para metodos proprios

/**
 * multiplo2e3( ) - metodo para mostrar quantidade de valores 
 * multiplos de 2 E 3
 * @return valor inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
int multiplo2e3(int quantidade)
{
    //definir variaveis com valor inicial
    int valor = 6, multiplo = 0;

    //repetir o numero de vezes pedido
    for (int i = 0; i < quantidade; i++)
    {
        //alterar o valor para um multiplo
        multiplo = valor * i;
        //mostrar o valor
        IO_printf("\n[%d]", multiplo);
    }//end for
}//end multiplo2e3( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
/*int main( )
{
    //identificar
    IO_id("EXEMPLO0511 - Programa - v0.1");

    //chamar metodos
    int quantidade = quantidades("Quantidade de valores a serem testados: ");
    multiplo2e3( quantidade );

    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )*/

/**
---------------------------------------------- documentacao complementar
exercicio:
para ler uma quantidade inteira do teclado e, mediante 
um metodo, mostrar essa quantidade em valores multiplos 
de 2 e de 3, ao mesmo tempo, em ordem crescente.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 10 [0] [6] [12] [18] [24] [30] [36] [42] [48] [54]
b.) 6 [0] [6] [12] [18] [24] [30] 
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         23/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  23/09  - mostrar certa quantidade de valores multiplos de 2 e 3

*/