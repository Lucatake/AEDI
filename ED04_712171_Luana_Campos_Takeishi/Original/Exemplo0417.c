/*
    Exemplo0417 - Versao 0.1 - 14/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0417      exemplo0417.c
    Windows:    gcc -o exemplo0417.exe  exemplo0417.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0417
    Windows:    exemplo0417
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * digitoI07( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar os digitos impares
 * @param cadeia - caracteres a serem testados
*/
void digitoI07(chars cadeia)
{
    //definir variaveis com valor inicial
    int count = 0, digito = 0, quantidade = 0;

    //comparar cada digito repeticao crescente
    for(count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' digito e impar
        if(cadeia[count] >= '0' && cadeia[count] <= '9')
        {
            //transferir digito para int
            digito = (int) cadeia[count];
            //se resto da divisao por 2 nao e' zero
            if(digito % 2 != 0)
            {
                //e contar quantidade
                quantidade++;
            }//end if
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade > 0)
    {
        IO_printf("\n Sao %d digitos impares.", quantidade);
    }
    else
    {
        IO_println("NAO existem digitos impares.");
    }//end if
}//end digitoI07

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO0417 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    digitoI07(cadeia);

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler uma sequencia de caracteres do teclado;
- mostrar a quantidade de digitos impares em uma cadeia 
de caracteres contados por uma funcao definida para 
receber uma cadeia de caracteres como parametro.
DICA: Considerar o valor inteiro do codigo equivalente (type casting).
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) rst123789OPQ
b.) -+=098abc123
c.) 98,57.23abcd
d.) abc-+=OPQ246
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         14/09          esboco
---------------------------------------------- testes
Exercicio    Versao  Teste
 0.1  14/09 - 01.   ( OK )  - quantidade de valores reais pares dentro de um intervalo real e fora.
 0.2  14/09 - 01.   ( OK )  - quantidade de letras maiusculas. 
 0.3  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N'. 
 0.4  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N' separadas em outra cadeia.
 0.5  14/09 - 01.   ( OK )  - quantidade de letras maiores que 'N'/'n'.
 0.6  14/09 - 01.   ( OK )  - quantidade de letras maiores que 'N'/'n' separadas em outra cadeia.
 0.7  14/09 - 01.   ( OK )  - quantidade de digitos impares.

*/