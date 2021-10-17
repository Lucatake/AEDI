/**
 * Exemplo0512 - v0.1. - 23/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
//#include "Luana.h"  //para metodos proprios

/**
 * paresM3( ) - metodo para mostrar quantidade de valores 
 * pares multiplos de 3
 * @return valor inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
int paresM3(int quantidade)
{
    //definir variaveis com valor inicial
    int multiplo = 0, i = 0, par = i;

    //repetir o numero de vezes pedido
    for (i = 0; i < quantidade; i++)
    {
        //incrementar par
        par = i * 2;
        //alterar o valor para um multiplo
        multiplo = 3 * par;
        //mostrar o valor
        IO_printf("\n[%d]", multiplo);
    }//end for
}//end  paresM3( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
/*int main( )
{
    //identificar
    IO_id("EXEMPLO0512 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("Quantidade de valores a serem testados: ");
    paresM3( quantidade );
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )*/

/**
---------------------------------------------- documentacao complementar
exercicio:
para ler uma quantidade inteira do teclado e, mediante um metodo
mostrar essa quantidade em valores pares multiplos de 3 em ordem crescente.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 10 [0] [6] [12] [18] [24] [30] [36] [42] [48] [54]
b.) 5 [0] [6] [12] [18] [24]
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         23/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  23/09  - mostrar certa quantidade de valores multiplos de 2 e 3
 1.2       01.   ( OK )  23/09  - mostrar certa quantidade de valores pares multiplos de 3
*/