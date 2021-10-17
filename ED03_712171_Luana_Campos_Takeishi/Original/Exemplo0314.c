/**
    Exemplo0314 - Versao 0.2 - 06/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0314      exemplo0314.c
    Windows:    gcc -o exemplo0314.exe  exemplo0314.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0314
    Windows:    exemplo0314
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * letra04( ) - Metodo para ler uma cadeia de caracteres
 * contar e mostrar as letras minusculas ou maiusculas
*/
void letra04( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0";
    int count = 0, letra = 0, quantidade = 0;

    //identificar
    IO_id("\nEXEMPLO0314 - Programa - v0.1");

    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);
    //comparar cada letra
    for (count = 0; count < quantidade; count++)
    {
        if ((cadeia[count] >= 'a' && cadeia[count] <= 'z') || 
            (cadeia[count] >= 'A' && cadeia[count] <= 'Z'))
        {
            IO_printf(" %c ", cadeia[count]);
            letra = letra + 1;
        }        
    }
    if(letra > 1)
    {
        IO_printf("\nsao %d letras dentro da cadeia de caracteres.", letra);
    }
    else
    {
        IO_println("NAO existem letras dentro dessa cadeia de caracteres.");
    }

}//end letra04


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    letra04( );

    //encerrar
    IO_pause("Apertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar todos simbolos que forem letras, ou maiusculas ou minusculas.
---------------------------------------------- notas / observacoes / comentarios
obs: o programa, caso tenha duas ou mais letras maiusculas menores que N
elas sao mostradas o numero de vezes que existem, repetindo
erro: estava fazendo a comparacao na tabela ascII mas foi notado que
as letras minusculas e maiusculas sao separadas por simbolos.
---------------------------------------------- previsao de testes
a.) abo/[]123pq
b.) 123ABCDopq
c.) abc-+/OPQ
d.) NAV++abcd11DEF
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         09/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do comeco
 0.2       01.   ( OK )  - letras maiusculas de uma palavra maior que 'N' do comeco
 0.3       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do fim
 0.4       02.   ( OK )  - letras dentro de uma cadeia de caracteres 

*/