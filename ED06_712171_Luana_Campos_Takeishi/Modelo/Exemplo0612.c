/**
    Exemplo0612 - Versao 0.1 - 29/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para mostrar os multiplos de 5
 * decrescente parando em 5
*/
int multiplo_5 (int n)
{
    //condicao para a recursividade
    if (n > 0) 
    {   
        //mostrar resultado
        IO_printf("\n[%d]", n * 5 );
        //e chamar o proximo de si
        multiplo_5( n - 1 );
    }//end if
    return( 0 );
}//end multiplo_5

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0612( )
{
    //identificar
    IO_id("\nEXEMPLO0612 - Programa - v0.1");
    //ler do teclado
    int q = quantidadesL("\nvalor inteiro: ");
    //chamar metodo
    multiplo_5( q );
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0612


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em multiplos de 5 em ordem decrescente encerrando em 5.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 5
[25]
[20]
[15]
[10]
[5]
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.2       01.   ( OK )  29/09  - multiplos de 5 decrescente encerrando em 5
*/