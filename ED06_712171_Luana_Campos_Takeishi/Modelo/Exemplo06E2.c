/**
    Exemplo06E2 - Versao 0.1 - 30/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para mostrar os impares
 * crescentes iniciando em 1
*/
int impar (int n)
{
    //condicao para a recursividade
    if (n > 0)
    {
        return( n + impar (n-2) );
    }//end if
}//end impar

/**
 * Funcao recursiva para calcular o fatorial 
 * de um numero impar
*/
int fatorial ( int fat )
{
    int f = impar((2 * fat) - 1 );
    //calcular fatorial
    if( f == 0 )
    {
        return (1);
    }
    else
    {
        return( f * fatorial(fat - 1) );
    }//end if
}//end fatorial

/**
 * Funcao recursiva para somar o inverso dos fatoriais
*/
int soma_inv( int fat)
{
    //variavel com valor inicial
    int soma = 1;
    double inverso = 0.0;
    int i = impar( (fat * 2) - 3 );
    int f = fatorial ( fat );
    if (fat > 0)
    {
        inverso = (double) i / f;
        soma = soma + soma_inv( fat - 1);
    }
    return(soma);
}//end soma_inv

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio06E2( )
{
    //identificar
    IO_id("\nEXEMPLO06E2 - Programa - v0.1");
    //ler do teclado
    int q = quantidadesL("quantidade: ");
    //e mostrar resultado, se e' multiplo
    IO_printf("soma = %d", soma_inv( q ));
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio06E2

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular o valor indicado abaixo,
lido o número de termos (n) do teclado:
e = 1 + 1/3! + 3/5! + 5/7! + 7/9! + ...
---------------------------------------------- notas / observacoes / comentarios
OBS: nao finalizado, somente esboço da logica.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         03/10          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 E.2       01.   ( OK )  03/10  - soma dos inversos de fatoriais de numeros impares
*/