/**
    Exemplo03E1 - Versao 0.1 - 09/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo03E1      exemplo03E1.c
    Windows:    gcc -o exemplo03E1.exe  exemplo03E1.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo03E1
    Windows:    exemplo03E1
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * cadeiaE1( ) - Metodo para ler uma linha do teclado
 * separar em uma cadeia com simbolos nao alfanumericos
*/
void cadeiaE1( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0", cadeia2 = " ";
    char nova = '0';
    int count = 0, valido = 0, quantidade = 0;

    //identificar
    IO_id("\nEXEMPLO03E1 - Programa - v0.1");

    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);

    //comparar cada caractere
    for (count = 0; count < quantidade; count++)
    {
        if ( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') || 
                (cadeia[count] >= 'a' && cadeia[count] <= 'z') || 
                (cadeia[count] >= 'A' && cadeia[count] <= 'Z')) )
        {
            IO_printf("%c", cadeia[count]);     //printa caractere por caractere
            valido = valido + 1;                //para validar a cadeia
            nova = cadeia[count];               //atribuindo ao caractere novo
            cadeia2 = IO_concat(cadeia2, IO_toString_c(nova));  //concatenar cadeia2 atual com novo caractere
        }//end if        
    }//end for
    if (valido > 1)
    {
        IO_printf("\n\n %s e' a cadeia de caracteres SO' com os simbolos nao alfanumericos.", cadeia2);
    }
    else
    {
        IO_println("NAO existem simbolos nao alfanumericos.");
    }//end if
}//end cadeiaE1


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    cadeiaE1( );

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler uma linha do teclado;
- separar em outra cadeia de caracteres e mostrar
todos os simbolos nao alfanumericos (letras ou 
digitos) na cadeia de caracteres.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) abc-+/123DEF
b.) -+/abc123
c.) -+/acb?@#123
d.) 123-+/acbDEF?@#
e.) 123abcABC
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         09/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do comeco
 0.2       01.   ( OK )  - letras maiusculas de uma palavra maior que 'N' do comeco
 0.3       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do fim
 0.4       01.   ( OK )  - letras dentro de uma cadeia de caracteres 
 0.5       01.   ( OK )  - digitos dentro de uma cadeia de caracteres do fim
 0.6       01.   ( OK )  - nao digitos e nao letra minuscula dentro de uma cadeia de caracteres
 0.7       01.   ( OK )  - certa quantidade de valores inteiros dentro de um intervalo e multiplos de 2 E 3
 0.8       01.   ( OK )  - certa quantidade de valores inteiros dentro de um intervalo e multiplos de 3 E NAO 5
 0.9       01.   ( OK )  - certa quantidade de valores reais dentro de um intervalo e impares
 1.0       01.   ( OK )  - certa quantidade de valores reais dentro de um intervalo de precisao
 E.1       01.   ( OK )  - nova cadeia de caracteres nao alfanumericos a partir da inicial

*/