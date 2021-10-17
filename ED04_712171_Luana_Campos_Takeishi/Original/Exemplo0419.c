/*
    Exemplo0419 - Versao 0.1 - 14/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0419      exemplo0419.c
    Windows:    gcc -o exemplo0419.exe  exemplo0419.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0419
    Windows:    exemplo0419
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * alfanumerico09( ) - Metodo para ler cadeia de caracteres do 
 * e mostrar os cinco primeiros simbolos alfanumericos
 * @param cadeia - caracteres a serem testados
*/
void alfanumerico09(chars cadeia)
{
    //definir variaveis com valor inicial
    chars alfanum = "";
    int count = 0, quantidade = 0;

    //comparar cada digito repeticao crescente ate' 5 simbolos
    for(count = 0; count < strlen(cadeia); count++)
    {        
        //se caractere e' alfanumerico
        if( (cadeia[count] >= '0' && cadeia[count] <= '9') ||
            (cadeia[count] >= 'A' && cadeia[count] <= 'Z') ||
            (cadeia[count] >= 'a' && cadeia[count] <= 'z') )
        {
            //concatenar alfanumericos
            alfanum = IO_concat(alfanum, IO_toString_c(cadeia[count]));
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if
        //se chegar a 5, parar
        if( quantidade == 5)
        {
            break;
        }//end if
    }//end for

    //se atendeu a especificacao
    if(quantidade <= 5 && quantidade != 0)
    {
        IO_printf("\n %s sao os primeiros simbolos alfanumericos.", alfanum);
    }
    else
    {
        IO_println("NAO existem simbolos alfanumericos.");
    }//end if
}//end alfanumerico09

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO0419 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    alfanumerico09(cadeia);

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler uma sequencia de caracteres do teclado;
- mostrar os cinco primeiros simbolos alfanumericos 
(letras e digitos) em uma cadeia de caracteres, 
se houver, separados por meio de uma funcao.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 123-=+abcDEF
b.) DEF098.;,opq
c.) -=+.;,/?°
d.) a1C[]{}
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
 0.8  14/09 - 01.   ( OK )  - cinco primeiros simbolos nao alfanumericos separados em uma cadeia.
 0.9  14/09 - 01.   ( OK )  - cinco primeiros simbolos alfanumericos separados em uma cadeia.

*/