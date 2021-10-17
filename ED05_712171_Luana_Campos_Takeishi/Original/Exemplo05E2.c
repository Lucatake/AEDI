/**
 * Exemplo05E2 - v0.2. - 24/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
#include "Luana.h"  //para metodos proprios

/**
 * cfatorial( ) - metodo para calcular o fatorial
 * @return valor inteiro 
*/
int cfatorial(int valor)
{
    //definir variaveis com valor inicial positivos
    unsigned long int fatorial = 1;
    //calcular o fatorial se n > 0
    for( int n = valor; n > 0; n--)
    {
        fatorial = fatorial * n;
    }//end for
    //mostrar o resultado
    return(fatorial);
}//end  cfatorial( )

/**
 * somaFn( ) - metodo para mostrar a soma dos inversos
 * de valores naturais, comecando no 1
 * @return valor  inteiro 
*/
int somaFn(int quantidade)
{
    //definir variaveis com valor inicial positivos
    unsigned long int fatorial = 1, pares = 0, impares = 0;
    double soma = 0.0, inverso = 0.0, multiplicacao = 1.0;
    int i = 0, par = 2, impar = 2, n = 0;

    //repetir o procedimento i vezes
    while( i < quantidade )
    {
        //valor impar
        impares = (impar * 2) - 1;
        //printf("| %d ", impares);     //para verificacao do valor
        
        //valor par
        pares = par * 2;
        //printf("| %d ", pares);     //para verificacao do valor
        
        //calcular fatorial
        fatorial = cfatorial(pares);
        //printf("| %d ", fatorial);      //para verificacao do valor

        //calcular o inverso
        inverso = (long double) impares / (long double) fatorial;
        //printf("| %lf ", inverso);    //para verificacao do valor

        //calcular a soma
        soma = 1.0 + inverso;
        //printf("| %lf ", soma);     //para verificacao do valor

        // calcular a multiplicação das somas
        multiplicacao = multiplicacao * soma;
        //printf("| %lf\n", multiplicacao);   //para verificacao do valor

        //ir para o proximo teste
        i++;
        //ir para os proximos valores pares e impares
        par++;
        impar++;

        //mostrar os passos
        IO_printf("\n{ [1+ (%d/%d!)] = [1 + (%d/%d)] = [1 + %.10lf] = [%.10lf] } *", 
        impares, pares, impares, fatorial, inverso, soma);
    }//end while

    //mostrar o resultado
    IO_printf("\nResultado da multiplicacao = %.10lf", multiplicacao);
}//end  somaFn( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("EXEMPLO05E2 - Programa - v0.2");
    //chamar metodos
    int quantidade = quantidades("\nQuantidade de valores a serem testados: ");
    somaFn(quantidade);
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/**
---------------------------------------------- documentacao complementar
exercicio:
para ler uma quantidade inteira do teclado e,
mediante o uso da funcao, calcular e mostrar o resultado de
f ( n ) = (1+3/4!) * (1+5/6!) * (1+7/8!) * ...
---------------------------------------------- notas / observacoes / comentarios
Erro: erro nos calculos e no print dos valores em double
Correcao: estava faltando o typedef para mudar de int para double ao fazer a divisao
Obs: para quantidades maiores que 4 a precisao e' comprometida
devido ao limite de memoria das variaveis (na divisao), para melhoria foi usado 
a precisao de 10 casas decimais com .10lf, permitindo ate' 5
repeticoes, no entanto, mais do que 5 o problema passa a ser o limite do fatorial (int).
---------------------------------------------- previsao de testes
a.) 5
{ [1+ (3/4!)] = [1 + (3/24)] = [1 + 0.1250000000] = [1.1250000000] } *
{ [1+ (5/6!)] = [1 + (5/720)] = [1 + 0.0069444444] = [1.0069444444] } *
{ [1+ (7/8!)] = [1 + (7/40320)] = [1 + 0.0001736111] = [1.0001736111] } *
{ [1+ (9/10!)] = [1 + (9/3628800)] = [1 + 0.0000024802] = [1.0000024802] } *
{ [1+ (11/12!)] = [1 + (11/479001600)] = [1 + 0.0000000230] = [1.0000000230] } *
Resultado da multiplicacao = 1.1330120049

b.) 10 --- PRECISAO COMPROMETICA
{ [1+ (3/4!)] = [1 + (3/24)] = [1 + 0.1250000000] = [1.1250000000] } *
{ [1+ (5/6!)] = [1 + (5/720)] = [1 + 0.0069444444] = [1.0069444444] } *
{ [1+ (7/8!)] = [1 + (7/40320)] = [1 + 0.0001736111] = [1.0001736111] } *
{ [1+ (9/10!)] = [1 + (9/3628800)] = [1 + 0.0000024802] = [1.0000024802] } *
{ [1+ (11/12!)] = [1 + (11/479001600)] = [1 + 0.0000000230] = [1.0000000230] } *
{ [1+ (13/14!)] = [1 + (13/1278945280)] = [1 + 0.0000000102] = [1.0000000102] } *
{ [1+ (15/16!)] = [1 + (15/2004189184)] = [1 + 0.0000000075] = [1.0000000075] } *
{ [1+ (17/18!)] = [1 + (17/-898433024)] = [1 + 0.0000000050] = [1.0000000050] } *
{ [1+ (19/20!)] = [1 + (19/-2102132736)] = [1 + 0.0000000087] = [1.0000000087] } *
{ [1+ (21/22!)] = [1 + (21/-522715136)] = [1 + 0.0000000056] = [1.0000000056] } *
Resultado da multiplicacao = 1.1330120467

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         24/09          esboco
0.2         24/09          esboco
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
 E.2       02.   ( OK )  24/09  - mostrar a soma de 1 com impares divididos por fatoriais pares
*/