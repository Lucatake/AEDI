/**
 * Exemplo0520 - v0.1. - 24/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
//#include "Luana.h"  //para metodos proprios

/**
 * somaInvNat( ) - metodo para mostrar a soma dos inversos
 * de valores naturais, comecando no 1
 * @return valor  inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
int somaInvNat(int quantidade)
{
    //definir variaveis com valor inicial
    int natural = 1, i = 0;
    double soma = 0.0, inverso = 0.0;

    //realizar o procedimento um numero de vezes
    for (i = 0; i < quantidade; i++)
    {
        //fazer o inverso
        inverso = 1.0 / natural;
        //somar os  inversos
        soma = soma + inverso;
        IO_printf("\n[1/%d] =  [%.2lf]", natural, inverso);
        //ir para o proximo natural
        natural++;
    }//end for
    //retornar valores
    IO_printf("\n soma = %.6lf", soma);
}//end  somaInvNat( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
/*int main( )
{
    //identificar
    IO_id("EXEMPLO0520 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("\nQuantidade de valores a serem testados: ");
    somaInvNat(quantidade);
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )*/

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular, por meio de repeticao, a soma dos inversos (1/x) 
dos primeiros numeros naturais, começando em 1.
Testar essa funcao para quantidades diferentes de valores.
---------------------------------------------- notas / observacoes / comentarios
obs: precisao nos inversos de 2 casas decimais e na soma de 6 casas
---------------------------------------------- previsao de testes
a.) 5 
[1/1] =  [1.00]     [1/2] =  [0.50]     [1/3] =  [0.33]
[1/4] =  [0.25]     [1/5] =  [0.20]      soma = 2.283333
b.) 15 
[1/1] =  [1.00]     [1/2] =  [0.50]     [1/3] =  [0.33]
[1/4] =  [0.25]     [1/5] =  [0.20]     [1/6] =  [0.17]
[1/7] =  [0.14]     [1/8] =  [0.13]     [1/9] =  [0.11]
[1/10] =  [0.10]    [1/11] =  [0.09]    [1/12] =  [0.08]
[1/13] =  [0.08]    [1/14] =  [0.07]    [1/15] =  [0.07]
 soma = 3.318229
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
*/