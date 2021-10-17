/**
 * Exemplo0517 - v0.1. - 24/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
#include "Luana.h"  //para metodos proprios

/**
 * somaIParNM5( ) - metodo para mostrar a soma de valores 
 * inversos pares nao multiplos de 5, comecando no 4
 * @return valor  inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
int somaIParNM5(int quantidade)
{
    //definir variaveis com valor inicial
    int pares = 4, par = 3, multiplo = 0, i = 0;
    double soma = 0.0, inverso = 0.0;

    //realizar o procedimento um numero de vezes
    while(i < quantidade)
    {
        //verificar nao multiplo de 5
        multiplo = pares % 5;
        if(multiplo != 0)
        {
            //se nao multiplo, somar valores inversos
            inverso = 1.0 / pares;
            soma = soma + inverso;
            IO_printf("\n[1/%d] = [%.2lf]", pares, inverso);
            //incrementar valor
            i++;
        }//end if
        //ir para o proximo numero par
        pares = (par * 2);
        par++;
    }//end while
    //retornar valores
    IO_printf("\n soma = %.6lf", soma);
}//end  somaIParNM5( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("EXEMPLO0517 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("\nQuantidade de valores a serem testados: ");
    somaIParNM5(quantidade);
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular a soma dos inversos (1/x) dos primeiros valores 
pares positivos, começando em 4 e nao multiplos de 5.
Testar essa funcao para quantidades diferentes.
---------------------------------------------- notas / observacoes / comentarios
obs: precisao de 2 casas no inverso e 6 casas na soma
---------------------------------------------- previsao de testes
a.) 6
[1/4] = [0.25]      [1/6] = [0.17]
[1/8] = [0.13]      [1/12] = [0.08]
[1/14] = [0.07]     [1/16] = [0.06]
 soma = 0.7589
b.) 15
[1/4] = [0.25]      [1/6] = [0.17]      [1/8] = [0.13]
[1/12] = [0.08]     [1/14] = [0.07]     [1/16] = [0.06]
[1/18] = [0.06]     [1/22] = [0.05]     [1/24] = [0.04]
[1/26] = [0.04]     [1/28] = [0.04]     [1/32] = [0.03]
[1/34] = [0.03]     [1/36] = [0.03]     [1/38] = [0.03]
 soma = 1.090536
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
 
*/