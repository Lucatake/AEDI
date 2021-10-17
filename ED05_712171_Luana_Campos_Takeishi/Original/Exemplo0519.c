/**
 * Exemplo0519 - v0.1. - 24/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
#include "Luana.h"  //para metodos proprios

/**
 * somaQuad( ) - metodo para mostrar a soma de valores 
 * naturais, comecando no 1
 * @return valor  inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
int somaQuad(int quantidade)
{
    //definir variaveis com valor inicial
    int natural = 1, i = 0;
    double soma = 0.0, quadrado = 0.0;

    //realizar o procedimento um numero de vezes
    for (i = 0; i < quantidade; i++)
    {
        //quadrado do numero
        quadrado = pow(natural , 2);
        //soma dos quadrados
        soma = soma + quadrado;
        IO_printf("\n[%d^2] = [%.1lf]", natural, quadrado);
        //ir para o proximo natural
        natural++;
    }//end for
    //retornar valores
    IO_printf("\n soma = %.1lf", soma);
}//end  somaQuad( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main ( )
{
    //identificar
    IO_id("EXEMPLO0519 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("\nQuantidade de valores a serem testados: ");
    somaQuad(quantidade);
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular, por meio de repeticao, a soma dos quadrados dos 
primeiros numeros naturais, comecando em 1.
Testar essa funcao para quantidades diferentes de valores.
---------------------------------------------- notas / observacoes / comentarios
obs: uso do double pois com o int estava ocorrendo um erro de precisao para
valores naturais maior do que 10, ex: quadrado de 10 = 99
---------------------------------------------- previsao de testes
a.) 5 
[1^2] = [1.0]   [2^2] = [4.0]   [3^2] = [9.0]
[4^2] = [16.0]  [5^2] = [25.0]   soma = 55.0
b.) 15 
[1^2] = [1.0]       [2^2] = [4.0]       [3^2] = [9.0]   
[4^2] = [16.0]      [5^2] = [25.0]      [6^2] = [36.0]
[7^2] = [49.0]      [8^2] = [64.0]      [9^2] = [81.0]
[10^2] = [100.0]    [11^2] = [121.0]    [12^2] = [144.0]
[13^2] = [169.0]    [14^2] = [196.0]    [15^2] = [225.0]
 soma = 1240.0
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
*/