/**
    Exemplo0617 - Versao 0.1 - 29/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para mostrara soma de n
 * valores inversos de pares* a partir de 2
*/
double somainv_pares (int n)
{
    //variavel com valor inicial
    double soma = 0.0, inverso = 0.0;
    //condicao para a recursividade
    if( n > 0 )
    {
        //calcular o inverso
        inverso = (double) 1.0/n;
        //somar valores e chamar a si
        soma = inverso + somainv_pares(n-2);
    }//end if
    return (soma);
}//end somainv_pares

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0617( )
{
    //identificar
    IO_id("\nEXEMPLO0617 - Programa - v0.1");
    //ler do teclado
    int q = quantidadesL("\nvalor inteiro: ");
    //chamar metodo e mostrar resultado
    IO_printf("soma = %.4lf", somainv_pares(q * 2));
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0617

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular a soma dos inversos (1/x) dos primeiros valores pares positivos começando em 2.
Testar essa funcao para quantidades diferentes.
---------------------------------------------- notas / observacoes / comentarios
obs: uso de arredondamento para 4 casas decimais.
---------------------------------------------- previsao de testes
 5
soma = 1.1417
 6
soma = 1.2250
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.7       01.   ( OK )  29/09  - soma dos inversos dos valores pares positivos comecando em 2
*/