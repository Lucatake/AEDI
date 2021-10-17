/**
    Exemplo06E1 - Versao 0.1 - 30/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para somar 'n' valores
 * 'x' elevado a numeros pares (+ 0 e 1)
*/
int soma_pot( int x, int n, int e )
{
    //variaveis com valor inicial
    int soma = 0, potencia = 0;

    //somar as potencias > 1 e passar para a proxima
    if( n > 3 )
    {
        //calcular a potencia
        potencia = pow(x, e);
        //somar
        soma = potencia + soma_pot( x, (n-1), (e-2));
        //IO_printf("pot = %d\n", potencia);
    }
    else 
    {
        //somar potencias 0 e 1 e passar para a proxima
        if( n > 0 )
        {
            //calcular a potencia
            potencia = pow(x, e);
            //somar
            soma = potencia + soma_pot( x, (n-1), (e-1));
            //IO_printf("pot = %d\n", potencia);
        }//end if
    }//end if
    //retornar soma
    return(soma);
}//end soma_pot

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio06E1( )
{
    //identificar
    IO_id("\nEXEMPLO06E1 - Programa - v0.1");
    //ler do teclado
    int x = IO_readint("\nvalor: ");
    int n = quantidadesL("quantidade: ");
    //e mostrar resultado, se e' multiplo
    IO_printf("soma = %d", soma_pot( x, n, ((n*2)-4) ));
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio06E1

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular o valor da funcao definida abaixo,
lidos os valores de (x) e (n) do teclado:
f ( x, n ) = 1 + xe1 + xe2 + xe4 + xe8 + ...
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
valor: 2
quantidade: 5
pot = 1
pot = 2
pot = 4
pot = 16
pot = 64
soma = 87           (com printf de conferencia das potencias)

valor: 2
quantidade: 6
soma = 343
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         30/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 E.1       01.   ( OK )  30/09  - soma de 'n' termos 'x' elevado a pares (com 0 e 1)
*/