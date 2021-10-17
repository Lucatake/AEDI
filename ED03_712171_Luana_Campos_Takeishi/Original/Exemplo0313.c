/**
    Exemplo0313 - Versao 0.1 - 04/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0313      exemplo0313.c
    Windows:    gcc -o exemplo0313.exe  exemplo0313.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0313
    Windows:    exemplo0313
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * letra03( ) - Metodo para ler uma palvra do teclado
 * contar e mostrar as letras maiusculas menores do que N
 * do fim da palavra ate' o inicio
*/
void letra03( )
{
    //definir variaveis com valor inicial
    chars palavra = "0";
    int count = 0, letra = 0, quantidade = 0;

    //identificar
    IO_id("\nEXEMPLO0313 - Programa - v0.1");

    palavra = IO_readstring("\nEntre com uma palavra: ");

    //contar quantidade de letras
    quantidade = strlen(palavra);
    //comparar cada letra
    for (count = quantidade; count >= 0; count--)
    {
        if (palavra[count] >= 'A' && palavra[count] < 'N')
        {
            IO_printf(" %c ", palavra[count]);
            letra = letra + 1;
        }        
    }
    if(letra > 1)
    {
        IO_printf("\nsao %d letras maiusculas menores que N", letra);
    }
    else
    {
        IO_println("NAO existem letras maiusculas menores que N.");
    }

}//end letra03


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    letra03( );

    //encerrar
    IO_pause("Apertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler uma palavra do teclado;
- contar e mostrar as letras maiusculas menores que 'N", 
desde o fim até o inicio da palavra.
---------------------------------------------- notas / observacoes / comentarios
obs: o programa, caso tenha duas ou mais letras maiusculas menores que N
elas sao mostradas o numero de vezes que existem, repetindo
---------------------------------------------- previsao de testes
a.) abopq
b.) ABCDopq
c.) abcOPQ
d.) NAVabcdDEF
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         04/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do comeco
 0.2       01.   ( OK )  - letras maiusculas de uma palavra maior que 'N' do comeco
 0.3       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do fim

*/