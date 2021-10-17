/**
    Exemplo0613 - Versao 0.1 - 29/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para mostrar os multiplos de 4
 * crescente com base 1
*/
int multiplo_4 (int n)
{
    //condicao para a recursividade
    if (n > 1) 
    {   
        //chamar o proximo de si
        multiplo_4( n - 1 );
        //e mostrar resultado
        IO_printf("\n[%d]", (n - 1) * 4 );
    }
    else
    {
        IO_printf("\n[%d]", 1 );
    }//end if
    return( 0 );
}//end multiplo_4

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0613( )
{
    //identificar
    IO_id("\nEXEMPLO0613 - Programa - v0.1");
    //ler do teclado
    int q = quantidadesL("\nvalor inteiro: ");
    //chamar metodo
    multiplo_4( q );
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0613

/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores da sequencia: 1 4 8 12 ...
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 5
[1]
[4]
[8]
[12]
[16]
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.3       01.   ( OK )  29/09  - multiplos de 4 crescente com base 1
*/