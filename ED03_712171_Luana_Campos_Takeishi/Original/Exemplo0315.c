/**
    Exemplo0315 - Versao 0.1 - 06/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0315      exemplo0315.c
    Windows:    gcc -o exemplo0315.exe  exemplo0315.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0315
    Windows:    exemplo0315
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * digito05( ) - Metodo para ler uma cadeia de caracteres
 * contar e mostrar as digitos do fim ao comeco
*/
void digito05( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0";
    int count = 0, digito = 0, quantidade = 0;

    //identificar
    IO_id("\nEXEMPLO0315 - Programa - v0.1");

    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);
    //comparar cada digito
    for (count = quantidade; count >= 0; count--)
    {
        if (cadeia[count] >= '0' && cadeia[count] <= '9')
        {
            IO_printf(" %c ", cadeia[count]);
            digito = digito + 1;
        }        
    }
    if (digito > 1)
    {
        IO_printf("\nsao %d digitos dentro da cadeia de caracteres.", digito);
    }
    else
    {
        IO_println("NAO existem digitos dentro dessa cadeia de caracteres.");
    }

}//end digito05


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    digito05( );

    //encerrar
    IO_pause("Apertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar todos os digitos, percorrendo desde 
o fim ate o inicio da cadeia de caracteres.
---------------------------------------------- notas / observacoes / comentarios
obs: o programa, caso tenha duas ou mais letras maiusculas menores que N
elas sao mostradas o numero de vezes que existem, repetindo
---------------------------------------------- previsao de testes
a.) abo123pq
b.) 123ABCDopq
c.) abc-+/
d.) NAV++abcd11DEF
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         06/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do comeco
 0.2       01.   ( OK )  - letras maiusculas de uma palavra maior que 'N' do comeco
 0.3       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do fim
 0.4       01.   ( OK )  - letras dentro de uma cadeia de caracteres 
 0.5       01.   ( OK )  - digitos dentro de uma cadeia de caracteres do fim

*/