/**
 * Exemplo05E1 - v0.1. - 24/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
//#include "Luana.h"  //para metodos proprios

/**
 * fatorial( ) - metodo para mostrar a soma dos inversos
 * de valores naturais, comecando no 1
 * @return valor  inteiro 
*/
int fatorial()
{
    //definir variaveis com valor inicial positivos
    unsigned long int fatorial = 1, valor = 0;
    //ler do teclado
    valor = IO_readint("\nEntre com um valor inteiro: ");
    //calcular o fatorial se n > 0
    for( int n = valor; n > 0; n--)
    {
        fatorial = fatorial * n;
    }//end for
    //mostrar o resultado
    printf("Fatorial [%d!] = %d", valor, fatorial);

}//end  fatorial( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
/*int main( )
{
    //identificar
    IO_id("EXEMPLO05E1 - Programa - v0.1");
    //chamar metodos
    fatorial( );
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )*/

/**
---------------------------------------------- documentacao complementar
exercicio:
para ler um numero inteiro do teclado e, mediante o uso da funcao, 
calcular e mostrar o fatorial desse valor:
n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1    se n>0
---------------------------------------------- notas / observacoes / comentarios
obs: maximo suportado e' o fatorial de 12
---------------------------------------------- previsao de testes
a.) 5  Fatorial [5!] = 120
b.) 10 Fatorial [10!] = 3628800
c.) 11 Fatorial [11!] = 39916800
d.) 12 Fatorial [12!] = 479001600
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
 1.7       01.   ( OK )  24/09  - mostrar a soma de valores pares* nao multiplos de 5
 1.8       01.   ( OK )  24/09  - mostrar a soma dos primeiros numeros naturais
 1.9       01.   ( OK )  24/09  - mostrar a soma do quadrado dos primeiros numeros naturais
 2.0       01.   ( OK )  24/09  - mostrar a soma dos inversos dos primeiros numeros naturais
 E.1       01.   ( OK )  24/09  - mostrar o fatorial de um valor inteiro
*/