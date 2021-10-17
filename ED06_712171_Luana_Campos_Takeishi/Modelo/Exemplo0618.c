/**
    Exemplo0618 - Versao 0.1 - 29/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao para achar o termo 'n' da sequencia de Fibonacci
 * (recursividade nao e' vantajosa nesse caso)
*/
int fibonacci (int n)
{
    //variavel com valor inicial
    int fibo = 1, f = 0;
    //verificar o termo
    //se nao for o primeiro ou segundo termo
    if( n > 2)
    {
        for( int i = 1; i < n; i = i + 2 )
        {
            f = f + fibo;       //termo 1
            fibo = fibo + f;    //termo 2
        }//end for
        if( (n % 2) == 0 )
        {
            fibo = f;
        }//end if
    }//end if
    
    //mostrar termo e retornar valor
    IO_printf("termo de Fibonacci = %d", fibo);
    return(fibo);
}//end fibonacci

/**
 * Funcao recursiva para verificar se
 * n e' multiplo de 3
*/
chars multiplo_3 (int f)
{
    //se divisivel por 3
    if ( (f % 3) == 0)
    {
        return("sim");
    }
    else
    {
        return("nao");
    }//end if
}//end multiplo_3

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0618( )
{
    //identificar
    IO_id("\nEXEMPLO0618 - Programa - v0.1");
    //ler do teclado
    int q = quantidadesL("\nposicao: ");
    //chamar metodo para calcular o termo
    int fibo = fibonacci( q );
    //e mostrar resultado, se e' multiplo
    IO_printf("\nmultiplo? %s", multiplo_3(fibo));
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0618

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular certo termo multiplo de 3 da serie de Fibonacci começando em 1.
Testar essa funcao para quantidades diferentes.
DICA: Separar em metodos diferentes o calculo do termo e 
o teste para verificar se e' multiplo de 3.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
posicao: 8
termo de Fibonacci = 21
multiplo? sim

posicao: 10
termo de Fibonacci = 55
multiplo? nao

posicao: 2
termo de Fibonacci = 1
multiplo? nao

posicao: 12
termo de Fibonacci = 144
multiplo? sim
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.8       01.   ( OK )  29/09  - se termo 'n' de Fibonacci e' multiplo de 3
*/