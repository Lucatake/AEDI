/**
    Exemplo0616 - Versao 0.1 - 29/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para mostrara soma de n
 * valores pares* a partir de 2
*/
int soma_pares (int n)
{
    //variavel com valor inicial
    int soma = 0;
    //condicao para a recursividade
    if( n > 0 )
    {
        //somar valores e chamar a si
        soma = n + soma_pares(n-2);
    }//end if
    return (soma);
}//end soma_pares

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0616( )
{
    //identificar
    IO_id("\nEXEMPLO0616 - Programa - v0.1");
    //ler do teclado
    int q = quantidadesL("\nvalor inteiro: ");
    //chamar metodo e mostrar resultado
    IO_printf("soma = %d", soma_pares(q * 2));
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0616

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular a soma dos (n) primeiros valores pares positivos começando em 2.
Testar essa funcao para quantidades diferentes.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 5 soma = 30
 10 soma = 110
 3 soma = 12
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.6       01.   ( OK )  29/09  - soma de 'n' valores pares positivos comecando em 2
*/