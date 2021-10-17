/**
    Exemplo0311 - Versao 0.1 - 02/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0311      exemplo0311.c
    Windows:    gcc -o exemplo0311.exe  exemplo0311.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0311
    Windows:    exemplo0311
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * letra01( ) - Metodo para ler uma palvra do teclado
 * e mostrar as letras minusculas menor do que N
 * do começo da palavra ate' o fim
*/
void letra01( )
{
    //definir variaveis com valor inicial
    chars palavra = "0";
    int count = 0, letra = 0;

    //identificar
    IO_id("\nEXEMPLO0311 - Programa - v0.1");

    palavra = IO_readstring("\nEntre com uma palavra: ");

    //comparar cada letra
    for (count = 0; count < strlen(palavra); count++)
    {
        if (palavra[count] >= 'A' && palavra[count] < 'N')
        {
            IO_printf(" %c ", palavra[count]);
            letra = 1;
        }        
    }
    if(letra == 1)
    {
        IO_println("sao letras maiusculas menores que N");
    }
    else
    {
        IO_println("NAO existem letras maiusculas menores que N.");
    }

}//end letra01


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    letra01( );

    //encerrar
    IO_pause("Apertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercício:
- ler uma palavra do teclado;
- mostrar as letras maiusculas menor que 'n'.
DICA: Definir um teste para determinar se um caractere é letra maiuscula.
---------------------------------------------- notas / observacoes / comentarios
obs: o programa, caso tenha duas ou mais letras maiusculas menores que N
elas sao mostradas o numero de vezes que existem, repetindo
---------------------------------------------- previsao de testes
a.) abopq
b.) ABCopq
c.) abcOPQ
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         01/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N'

*/