/**
    Exemplo03E2 - Versao 0.1 - 09/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo03E2      exemplo03E2.c
    Windows:    gcc -o exemplo03E2.exe  exemplo03E2.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo03E2
    Windows:    exemplo03E2
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * cadeiaE2( ) - Metodo para ler uma linha do teclado
 * dizer se sequencia contem apenas simbolos
 * nao letras e nao digitos
*/
void cadeiaE2( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0";
    int count = 0, valido = 0, quantidade = 0;

    //identificar
    IO_id("\nEXEMPLO03E2 - Programa - v0.1");

    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);

    //comparar cada caractere, verificar se ha simbolos apenas
    for (count = 0; count < quantidade; count++)
    {
        if ( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') || 
                (cadeia[count] >= 'a' && cadeia[count] <= 'z') || 
                (cadeia[count] >= 'A' && cadeia[count] <= 'Z')) )
        {
            valido = valido + 1;                //para validar a cadeia
        }//end if        
    }//end for
    //se valor contado de simbolos for igual ao valor total de caracteres
    if (valido == quantidade)
    {
        IO_println("Essa sequencia possui apenas simbolos nao alfanumericos.");
    }
    else
    {
        IO_println("Existem outros simbolos alfanumericos na sequencia.");
    }//end if
}//end cadeiaE2


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    cadeiaE2( );

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler uma cadeia de caracteres do teclado;
- dizer se a sequencia contem apenas simbolos
que nao sao letras, nem digitos.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) abc-+/123DEF
b.) -+=/?°
c.) -+/acb?@#123
d.) 123abcABC
e.) !@#$%*
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
 E.2       01.   ( OK )  - se sequencia possui apenas simbolos que nao letras ou numeros
*/