/**
 * Exemplo0513 - v0.1. - 23/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
//#include "Luana.h"  //para metodos proprios

/**
 * imparesM3( ) - metodo para mostrar quantidade de valores 
 * impares multiplos de 3 ordem decrescente
 * @return valor inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
int imparesM3(int quantidade)
{
    //definir variaveis com valor inicial
    int multiplo = 0, i = 0, impar = quantidade;

    //se quantidade e' par
    if (impar % 2 == 0)
    {
        //incrementar impar
        impar = quantidade - 1;
    }

    //repetir o numero de vezes pedido
    for (i = quantidade; i > 0; i--)
    {
        //alterar o valor para um multiplo
        multiplo = 3 * impar;
        //mostrar o valor
        IO_printf("\n[%d]", multiplo);
        //incrementar para impar
        impar = impar - 2;
    }//end for
}//end  paresM3( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
/*int main( )
{
    //identificar
    IO_id("EXEMPLO0513 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("Quantidade de valores a serem testados: ");
    imparesM3( quantidade );
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )*/

/**
---------------------------------------------- documentacao complementar
exercicio:
para ler uma quantidade inteira do teclado e, mediante um metodo,
mostrar essa quantidade em valores impares multiplos de 3 em ordem decrescente.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 10 [27] [21] [15] [9] [3] [-3] [-9] [-15] [-21] [-27]
b.) 5 [15] [9] [3] [-3] [-9]
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         23/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  23/09  - mostrar certa quantidade de valores multiplos de 2 e 3
 1.2       01.   ( OK )  23/09  - mostrar certa quantidade de valores pares multiplos de 3
 1.3       01.   ( OK )  23/09  - mostrar certa quantidade de valores impares multiplos de 3

*/