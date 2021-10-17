/*
    Exemplo0415 - Versao 0.1 - 14/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0415      exemplo0415.c
    Windows:    gcc -o exemplo0415.exe  exemplo0415.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0415
    Windows:    exemplo0415
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * letraNn05( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar e mostrar as letras > 'N' | 'n'
 * @param cadeia - caracteres a serem testados
*/
void letraNn05(chars cadeia)
{
    //definir variaveis com valor inicial
    int count = 0, letra = 0, quantidade = 0;

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula > que 'N' ou minuscula > 'n'
        if ((cadeia[count] > 'N' && cadeia[count] <= 'Z') || (cadeia[count] > 'n' && cadeia[count] <= 'z'))
        {
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade > 0)
    {
        IO_printf("\n Sao %d letras maiores que 'N'||'n'.", quantidade);
    }
    else
    {
        IO_println("NAO existem letras maiores que 'N'||'n'.");
    }//end if
}//end letraNn05

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO0415 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    letraNn05(cadeia);

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler uma sequencia de caracteres do teclado;
- mostrar a quantidade de letras (tanto maiusculas, 
quanto minusculas), maiores que 'N', contadas por uma funcao
definida para receber uma cadeia de caracteres como parametro.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) rst123OPQ
b.) ABCdef123-+=
c.) OPQ098rst-+=Uvx
d.) abc123-+=ABC
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         14/09          esboco
---------------------------------------------- testes
Exercicio    Versao  Teste
 0.1  14/09 - 01.   ( OK )  - quantidade de valores reais pares dentro de um intervalo real e fora.
 0.2  14/09 - 01.   ( OK )  - quantidade de letras maiusculas. 
 0.3  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N'. 
 0.4  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N' separadas em outra cadeia.
 0.5  14/09 - 01.   ( OK )  - quantidade de letras maiores que 'N'||'n'.

*/