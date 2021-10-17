/*
    Exemplo0412 - Versao 0.1 - 14/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0412      exemplo0412.c
    Windows:    gcc -o exemplo0412.exe  exemplo0412.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0412
    Windows:    exemplo0412
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * letraM02( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar e mostrar as letras maiusculas
*/
void letraM02( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0", letras = "";
    int count = 0, letra = 0, quantidade = 0;

    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula
        if (cadeia[count] >= 'A' && cadeia[count] <= 'Z')
        {
            //concatenar caracteres
            letras = IO_concat(IO_toString_c(cadeia[count]), letras);
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade > 0)
    {
        IO_printf("\n[%s] sao %d letras maiusculas.", letras, quantidade);
    }
    else
    {
        IO_println("NAO existem letras maiusculas.");
    }//end if
}//end letraM02

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO0412 - Programa - v0.1");

    //chamar funcao
    letraM02( );

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler uma sequencia de caracteres do teclado;
- contar e mostrar a quantidade de letras maiusculas.
DICA: Definir uma funcao para determinar se um caractere 
e' letra maiuscula menor que 'N'.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) abcDEF123-+=
b.) ABCdef123-+=
c.) 123-+=abcDEF
d.) abc123-+=
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         14/09          esboco
---------------------------------------------- testes
Exercicio    Versao  Teste
 0.1  14/09 - 01.   ( OK )  - quantidade de valores reais pares dentro de um intervalo real e fora.
 0.2  14/09 - 01.   ( OK )  - quantidade de letras maiusculas.

*/
