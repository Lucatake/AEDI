/*
    Exemplo0207 - Versao 0.1 - 25/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0207      exemplo0207.c
    Windows:    gcc -o exemplo0207.exe  exemplo0207.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0207
    Windows:    exemplo0207
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
    IO_id("EXEMPLO0207 - Programa - v0.1");
    
    //ler do teclado
    x = IO_readchar("Entrar com um caractere: ");

    //testar valor
    if ( ! (('a' <= x && x <= 'z') ||       //NAO (minuscula
            ('A' <= x && x <= 'Z')) )       // OU maiuscula)
    {
        IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
    }
    else
    {
        IO_printf ( "%s (%c)\n", "Letra", x );
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
c.) 1
d.) -
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
0.6 01. ( OK ) teste se um valor e' uma letra (maiuscula ou minuscula)
0.7 01. ( OK ) teste se um valor nao e' letra (maiuscula ou minuscula)
*/