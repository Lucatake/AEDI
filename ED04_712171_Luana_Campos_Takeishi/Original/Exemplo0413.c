/*
    Exemplo0413 - Versao 0.1 - 14/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0413      exemplo0413.c
    Windows:    gcc -o exemplo0413.exe  exemplo0413.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0413
    Windows:    exemplo0413
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * letraMn03( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar e  as letras maiusculas < 'N'
 * @param cadeia - caracteres a serem testados
*/
void letraMn03(chars cadeia)
{
    //definir variaveis com valor inicial
    int count = 0, letra = 0, quantidade = 0;

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula menor que 'N'
        if (cadeia[count] >= 'A' && cadeia[count] < 'N')
        {
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade > 0)
    {
        IO_printf("\nSao %d letras maiusculas menores que 'N'.", quantidade);
    }
    else
    {
        IO_println("NAO existem letras maiusculas menores que 'N'.");
    }//end if
}//end letraMn03

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO0413 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    letraMn03(cadeia);

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler uma sequencia de caracteres do teclado;
- mostrar a quantidade de letras maiusculas menores 
que 'N' contadas por uma função definida para receber 
uma cadeia de caracteres como parametro.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) opqDEF123-+=
b.) ABCdef123-+=
c.) 123-+=abcDEF
d.) abc123-+=OPQ
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         14/09          esboco
---------------------------------------------- testes
Exercicio    Versao  Teste
 0.1  14/09 - 01.   ( OK )  - quantidade de valores reais pares dentro de um intervalo real e fora.
 0.2  14/09 - 01.   ( OK )  - quantidade de letras maiusculas. 
 0.3  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N'. 

*/
