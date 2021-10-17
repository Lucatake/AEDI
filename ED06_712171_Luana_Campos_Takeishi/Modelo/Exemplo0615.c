/**
    Exemplo0615 - Versao 0.1 - 29/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para mostrar os caracteres de uma
 * cadeia de caracteres de tras para frente
*/
char caract (chars cadeia, int count)
{
    //condicao para a recursividade
    if (count > 0)
    {
        //e mostrar caractere
        IO_printf("[%c]\n", cadeia[count-1]);
        //passar para a proxima
        caract(cadeia, count-1);
    }//end if
    return (' ');
}//end caract

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0615( )
{
    //identificar
    IO_id("\nEXEMPLO0615 - Programa - v0.1");
    //ler do teclado
    chars cadeia = IO_readstring("\nCadeia de caracteres: ");
    //separar posicoes dos caracteres
    int position = strlen(cadeia);
    //chamar metodo
    caract( cadeia, position );
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0615

/**
---------------------------------------------- documentacao complementar
exercicio:
ler uma cadeia de caracteres e chamar procedimento recursivo para
mostrar cada simbolo separadamente, um por linha, de tras para frente.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
1palavra+
[+]
[a]
[r]
[v]
[a]
[l]
[a]
[p]
[1]
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.5       01.   ( OK )  29/09  - caractere de tras para frente de uma cadeia
*/