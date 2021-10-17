/**
 * Exemplo0518 - v0.1. - 24/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
//#include "Luana.h"  //para metodos proprios

/**
 * somaNat( ) - metodo para mostrar a soma de valores 
 * naturais, comecando no 1
 * @return valor  inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
int somaNat(int quantidade)
{
    //definir variaveis com valor inicial
    int soma = 0, natural = 1, i = 0;

    //realizar o procedimento um numero de vezes
    for (i = 0; i < quantidade; i++)
    {
        soma = soma + natural;
        IO_printf("[%d] ", natural);
        natural++;
    }//end for
    //retornar valores
    IO_printf("\n soma = %d", soma);
}//end  somaNat( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
/*int main( )
{
    //identificar
    IO_id("EXEMPLO0518 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("\nQuantidade de valores a serem testados: ");
    somaNat(quantidade);
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )*/

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular, por meio de repeticao, a soma dos primeiros 
numeros naturais começando em 1.
Testar essa funcao para quantidades diferentes de valores.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5 [1] [2] [3] [4] [5] soma = 15
b.) 15 [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15] soma = 120
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
*/