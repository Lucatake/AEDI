/**
    Exemplo0312 - Versao 0.1 - 02/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0312      exemplo0312.c
    Windows:    gcc -o exemplo0312.exe  exemplo0312.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0312
    Windows:    exemplo0312
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * letra02( ) - Metodo para ler uma palvra do teclado
 * contar e mostrar as letras minusculas maiores do que N
 * do começo da palavra ate' o fim
*/
void letra02( )
{
    //definir variaveis com valor inicial
    chars palavra = "0";
    int count = 0, letra = 0, quantidade = 0;

    //identificar
    IO_id("\nEXEMPLO0312 - Programa - v0.1");

    palavra = IO_readstring("\nEntre com uma palavra: ");

    //comparar cada letra
    for (count = 0; count < strlen(palavra); count++)
    {
        if (palavra[count] <= 'Z' && palavra[count] > 'N')
        {
            IO_printf(" %c ", palavra[count]);
            letra = 1;
            quantidade++;
        }        
    }
    if(letra == 1)
    {
        IO_printf("\nsao %d letras maiusculas maiores que N", quantidade);
    }
    else
    {
        IO_println("NAO existem letras maiusculas maiores que N.");
    }

}//end letra02


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    letra02( );

    //encerrar
    IO_pause("Apertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercício:
- ler uma palavra do teclado;
- contar e mostrar apenas as letras maiusculas maiores que 'N'.
---------------------------------------------- notas / observacoes / comentarios
obs: o programa, caso tenha duas ou mais letras maiusculas menores que N
elas sao mostradas o numero de vezes que existem, repetindo
---------------------------------------------- previsao de testes
a.) abopq
b.) ABCDopq
c.) abcOPQ
d.) NAVabcOOPD
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         01/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N'
 0.2       01.   ( OK )  - letras maiusculas de uma palavra mmaior que 'N'

*/