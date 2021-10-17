/*
    Exemplo0414 - Versao 0.1 - 14/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0414      exemplo0414.c
    Windows:    gcc -o exemplo0414.exe  exemplo0414.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0414
    Windows:    exemplo0414
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * letraMn04( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar e mostrar as letras maiusculas < 'N'
 * @param cadeia - caracteres a serem testados
*/
void letraMn04(chars cadeia)
{
    //definir variaveis com valor inicial
    chars letras = "";
    int count = 0, letra = 0, quantidade = 0;

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula menor que 'N'
        if (cadeia[count] >= 'A' && cadeia[count] < 'N')
        {
            //concatenar caracteres
            letras = IO_concat(letras, IO_toString_c(cadeia[count]));
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade > 0)
    {
        IO_printf("\n %s e' a nova cadeia de caracteres somente com letras maiusculas menores que 'N'.", letras);
    }
    else
    {
        IO_println("NAO existem letras maiusculas menores que 'N'.");
    }//end if
}//end letraMn04

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO0414 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    letraMn04(cadeia);

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler uma sequencia de caracteres do teclado;
- mostrar as letras maiusculas menores que 'N' separadas em 
outra cadeia mediante uma funcao definida para receber uma 
cadeia de caracteres como parametro.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) rstDEF123-+=OPQ
b.) ABCdef123-+=LM
c.) GHI123-+=abcDEF
d.) abc123-+=OPQ
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         14/09          esboco
---------------------------------------------- testes
Exercicio    Versao  Teste
 0.1  14/09 - 01.   ( OK )  - quantidade de valores reais pares dentro de um intervalo real e fora.
 0.2  14/09 - 01.   ( OK )  - quantidade de letras maiusculas. 
 0.3  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N'. 
 0.4  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N' separadas em outra cadeia.

*/
