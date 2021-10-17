/**
 * Exemplo0514 - v0.1. - 23/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
#include "Luana.h"  //para metodos proprios

/**
 * inversosM4( ) - metodo para mostrar quantidade de valores 
 * inversos multiplos de 4 ordem crescente
 * @return valor  real 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
double inversosM4(int quantidade)
{
    //definir variaveis com valor inicial
    double inverso = 0.0;
    int multiplo = 0;

    //repetir o numero de vezes pedido
    for (int i = 1; i <= quantidade; i++)
    {
        //alterar o valor para um multiplo
        multiplo = i * 4;
        //calcular os inversos
        inverso = 1.0 / multiplo;
        //mostrar o valor
        IO_printf("\n1/%d = [%lf]", multiplo, inverso);
    }//end for
}//end  inversosM4( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("EXEMPLO0514 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("Quantidade de valores a serem testados: ");
    inversosM4(quantidade);
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/**
---------------------------------------------- documentacao complementar
exercicio:
para ler uma quantidade inteira do teclado e, mediante um metodo,
mostrar essa quantidade em valores crescentes nos denominadores
(sequencia dos inversos) multiplos de 4: 1/4 1/8 1/12 1/16 1/20 ...
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 10 
1/4 = [0.250000]
1/8 = [0.125000]
1/12 = [0.083333]
1/16 = [0.062500]
1/20 = [0.050000]
1/24 = [0.041667]
1/28 = [0.035714]
1/32 = [0.031250]
1/36 = [0.027778]
1/40 = [0.025000]
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         23/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  23/09  - mostrar certa quantidade de valores multiplos de 2 e 3
 1.2       01.   ( OK )  23/09  - mostrar certa quantidade de valores pares multiplos de 3
 1.3       01.   ( OK )  23/09  - mostrar certa quantidade de valores impares multiplos de 3
 1.4       01.   ( OK )  23/09  - mostrar certa quantidade de valores inversos multiplos de 4

*/