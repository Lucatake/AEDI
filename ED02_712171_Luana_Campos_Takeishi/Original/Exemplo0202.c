/*
    Exemplo0202 - Versao 0.1 - 25/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0202      exemplo0202.c
    Windows:    gcc -o exemplo0202.exe  exemplo0202.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0202
    Windows:    exemplo0202
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
    int x = 0;      //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0202 - Programa - v0.1");
    
    //ler do teclado
    x = IO_readint("\nEntrar com um valor inteiro: ");
    
    //testar valor
    if (x == 0)
    {
        IO_printf("%s (%d)\n", "Valor igual a zero", x);
    }//end if
    else 
    {
        IO_printf("%s (%d)\n", "Valor diferente de zero ", x);
    }//end else
    
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 5
c.) -5
---------------------------------------------- historico
Versao Data Modificacao
0.1 25/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) teste valor inteiro igual ou diferente de zero if-if
0.2 01. ( OK ) teste valor inteiro igual ou diferente de zero if-else
*/