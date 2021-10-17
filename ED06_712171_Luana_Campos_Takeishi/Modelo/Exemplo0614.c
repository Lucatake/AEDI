/**
    Exemplo0614 - Versao 0.1 - 29/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para mostrar os inversos
 * das potencias de 4 decrescente com base 1
*/
double pot_inversa (int n)
{
    //variavel com valor inicial
    double potencia = 0.0;
    //condicao para a recursividade
    if (n > 0) 
    {   
        //calcular potencia
        potencia = pow(4,n);
        //mostrar resultado
        IO_printf( "\n[1/%.0lf] = %.4lf", potencia, 1.0/potencia );
        //e chamar o proximo de si
        pot_inversa( n - 1 );
    }
    else
    {
        IO_printf("\n[%d]", 1 );
    }//end if
    return( 0.0 );
}//end pot_inversa

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0614( )
{
    //identificar
    IO_id("\nEXEMPLO0614 - Programa - v0.1");
    //ler do teclado
    int q = quantidadesL("\nvalor inteiro: ");
    //chamar metodo
    pot_inversa( q - 1 );
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0614

/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores decrescentes da sequencia: ... 1/64 1/16 1/4 1.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 5
[1/256] = 0.0039
[1/64] = 0.0156
[1/16] = 0.0625
[1/4] = 0.2500
[1]
5
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.4       01.   ( OK )  29/09  - inversos das potencias de 4 decrescente com base 1
*/