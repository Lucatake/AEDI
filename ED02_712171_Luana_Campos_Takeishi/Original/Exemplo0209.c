/*
    Exemplo0209 - Versao 0.1 - 25/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0209      exemplo0209.c
    Windows:    gcc -o exemplo0209.exe  exemplo0209.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0209
    Windows:    exemplo0209
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
    int x = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0209 - Programa - v0.1");
    
    //ler do teclado
    x = IO_readint ("Entrar com um inteiro [0,1,2,3]: ");

    //testar valor
    switch (x)
    {
    case 0:
        IO_printf("%s (%d)\n", "Valor igual a zero", x);
        break;
    case 1:
        IO_printf("%s (%d)\n", "Valor igual a um ", x);
        break;
    case 2:
        IO_printf("%s (%d)\n", "Valor igual a dois", x);
        break;
    case 3:
        IO_printf("%s (%d)\n", "Valor igual a tres", x);
        break;
    default:        //se nenhuma alguma das opcoes anteriores
        IO_printf("%s (%d)\n", "Valor diferente das opcoes [0,1,2,3]", x);
    } //end switch

    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 2
d.) 3
e.) 4
f.) -1
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
0.8 01. ( OK ) teste de entrada de caracteres especificos
0.9 01. ( OK ) teste de entrada de numeros especificos
*/