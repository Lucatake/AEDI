/**
    Exemplo0611 - Versao 0.1 - 29/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para mostrar os impares
 * crescentes iniciando em 3
*/
int impares (int n)
{
    //condicao para a recursividade
    if (n > 1)
    {
        //mostrar resultado e chamar a si
        IO_printf("\n[%d]", n + impares (n-2) );
    }//end if
    return( 0 );
}//end impares

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0611( )
{
    //identificar
    IO_id("\nEXEMPLO0611 - Programa - v0.1");
    //ler do teclado
    int q = quantidadesL("\nvalor inteiro: ");
    //chamar metodo
    impares( (2 * q) + 1 );
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0611


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores impares em ordem crescente começando em 3.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 5
[3]
[5]
[7]
[9]
[11]
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  29/09  - impares crescentes comecando em 3
*/