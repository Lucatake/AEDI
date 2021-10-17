/**
 * Exemplo0516 - v0.1. - 24/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
//#include "Luana.h"  //para metodos proprios

/**
 * somaInaoM7( ) - metodo para mostrar a soma de valores 
 * impares nao multiplos de 7, comecando no 3
 * @return valor  inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
int somaInaoM7(int quantidade)
{
    //definir variaveis com valor inicial
    int soma = 0, impares = 3, impar = 3, multiplo = 0, i = 0;

    //realizar o procedimento um numero de vezes
    while(i < quantidade)
    {
        //verificar nao multiplo de 7
        multiplo = impares % 7;
        if(multiplo != 0)
        {
            //se nao multiplo, somar valores
            soma = soma + impares;
            IO_printf(" [%d]", impares);
            //incrementar valor
            i++;
        }//end if
        //ir para o proximo numero impar
        impares = (impar * 2) - 1;
        impar++;
    }//end while
    //retornar valores
    IO_printf("\n soma = %d", soma);
}//end  somaInaoM7( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
/*int main( )
{
    //identificar
    IO_id("EXEMPLO0516 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("\nQuantidade de valores a serem testados: ");
    somaInaoM7(quantidade);
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )*/

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular a soma dos primeiros valores impares positivos 
comecando em 3 e nao multiplos de 7.
Testar essa funcao para quantidades diferentes.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5 [3] [5] [9] [11] [13] soma = 41
b.) 15 [3] [5] [9] [11] [13] [15] [17] [19] [23] [25] [27] [29] [31] [33] [37]
soma = 297
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         24/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  23/09  - mostrar certa quantidade de valores multiplos de 2 e 3
 1.2       01.   ( OK )  23/09  - mostrar certa quantidade de valores pares multiplos de 3
 1.3       01.   ( OK )  23/09  - mostrar certa quantidade de valores impares multiplos de 3
 1.4       01.   ( OK )  23/09  - mostrar certa quantidade de valores inversos multiplos de 4
 1.5       01.   ( OK )  23/09  - mostrar quantidade de valores inversos de x elevado a impares 
 1.6       01.   ( OK )  24/09  - mostrar a soma de valores impares* nao multiplos de 7
*/