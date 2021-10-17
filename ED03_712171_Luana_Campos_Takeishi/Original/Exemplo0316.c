/**
    Exemplo0316 - Versao 0.1 - 08/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0316      exemplo0316.c
    Windows:    gcc -o exemplo0316.exe  exemplo0316.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0316
    Windows:    exemplo0316
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * naoDm06( ) - Metodo para ler uma cadeia de caracteres
 * contar e mostrar os caracteres nao digitos e nao minusculas
*/
void naoDm06( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0";
    int count = 0, valido = 0, quantidade = 0;

    //identificar
    IO_id("\nEXEMPLO0316 - Programa - v0.1");

    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);
    //comparar cada caractere
    for (count = 0; count < quantidade; count++)
    {
        if ( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') || (cadeia[count] >= 'a' && cadeia[count] <= 'z')) )
        {
            IO_printf(" %c ", cadeia[count]);
            valido = valido + 1;
        }        
    }
    if (valido > 1)
    {
        IO_printf("\n %d caracteres nao sao digitos nem letras minusculas.", valido);
    }
    else
    {
        IO_println("SO existem digitos e/ou letras minusculas dentro dessa cadeia de caracteres.");
    }

}//end naoDm06


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    naoDm06( );

    //encerrar
    IO_pause("Apertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar tudo o que nao for digito e tambem nao for letra minuscula.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) abo123pq
b.) 123ABCDopq
c.) abc-+/
d.) NAV++abcd11DEF
e.) ABCD
f.) abcd
g.) 1234
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         08/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do comeco
 0.2       01.   ( OK )  - letras maiusculas de uma palavra maior que 'N' do comeco
 0.3       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do fim
 0.4       01.   ( OK )  - letras dentro de uma cadeia de caracteres 
 0.5       01.   ( OK )  - digitos dentro de uma cadeia de caracteres do fim
 0.6       01.   ( OK )  - nao digitos e nao letra minuscula dentro de uma cadeia de caracteres

*/