/*
    Exemplo0418 - Versao 0.1 - 14/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0418      exemplo0418.c
    Windows:    gcc -o exemplo0418.exe  exemplo0418.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0418
    Windows:    exemplo0418
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * Nalfanumerico08( ) - Metodo para ler cadeia de caracteres do 
 * e mostrar os cinco primeiros simbolos nao alfanumericos
 * @param cadeia - caracteres a serem testados
*/
void Nalfanumerico08(chars cadeia)
{
    //definir variaveis com valor inicial
    chars Nalfanum = "";
    int count = 0, quantidade = 0;

    //comparar cada digito repeticao crescente ate' 5 simbolos
    for(count = 0; count < strlen(cadeia); count++)
    {        
        //se caractere e' nao alfanumerico
        if( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') ||
               (cadeia[count] >= 'A' && cadeia[count] <= 'Z') ||
               (cadeia[count] >= 'a' && cadeia[count] <= 'z') ))
        {
            //concatenar nao alfanumericos
            Nalfanum = IO_concat(Nalfanum, IO_toString_c(cadeia[count]));
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
        IO_printf("\n %s sao os primeiros simbolos nao alfanumericos.", Nalfanum);
    }
    else
    {
        IO_println("NAO existem simbolos nao alfanumericos.");
    }//end if
}//end Nalfanumerico08

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO0418 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    Nalfanumerico08(cadeia);

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler uma sequencia de caracteres do teclado;
- mostrar os cinco primeiros simbolos nao alfanumericos 
(letras e digitos), em uma cadeia de caracteres, se houver,
separados por meio de uma funcao.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) -+=abc!@#OPQ([])
b.) -94+=Abc
c.) .;[asa]$s
d.) abc123OPQ
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

*/