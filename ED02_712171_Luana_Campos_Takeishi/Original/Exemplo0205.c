/*
    Exemplo0205 - Versao 0.1 - 25/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0205      exemplo0205.c
    Windows:    gcc -o exemplo0205.exe  exemplo0205.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0205
    Windows:    exemplo0205
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    Funcao principal.
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main( )
{
    //definir dado
    char x = '_';       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0205 - Programa - v0.1");
    
    //ler do teclado
    x = IO_readchar("Entrar com um caractere: ");
    
    //testar valor
    if ('a' <= x && x <= 'z')
    {
        IO_printf("%s (%c)\n", "Letra minuscula", x);
    }
    else
    {
        IO_printf("%s (%c)\n", "Valor diferente de minuscula", x);
        if ('A' <= x && x <= 'Z')
        {
            IO_printf("%s (%c)\n", "Letra maiuscula", x);
        }
        else
        {
            if ('0' <= x && x <= '9')
            {
                IO_printf("%s (%c)\n", "Algarismo", x);
            }
            else
            {
                IO_printf("%s (%c)\n", "Valor diferente de algarismo", x);
            }//end if
        }//end if
    }//end if

    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) a
b.) A
c.) 0
d.) #
---------------------------------------------- historico
Versao Data Modificacao
0.1 25/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) teste valor inteiro igual ou diferente de zero if-if
0.2 01. ( OK ) teste valor inteiro igual ou diferente de zero if-else
0.3 01. ( OK ) teste valor inteiro igual ou diferente de zero (maior ou menor)
0.4 01. ( OK ) teste valor real entre um intervalo determinado
0.5 01. ( OK ) teste do tipo de um valor (se caractere ou algarismo)
*/