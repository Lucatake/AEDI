/*
    Exemplo0204 - Versao 0.1 - 25/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0204      exemplo0204.c
    Windows:    gcc -o exemplo0204.exe  exemplo0204.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0204
    Windows:    exemplo0204
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
    double x = 0.0;      //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0204 - Programa - v0.1");
    
    //ler do teclado
    x = IO_readdouble ( "Entrar com um valor real: " );
    
    //testar valor
    if (1.0 <= x && x <= 10.0)
    {
        IO_printf("%s (%lf)\n", "Valor dentro do intervalo [1:10] ", x);
    }
    else
    {
        IO_printf("%s (%lf)\n", "Valor fora do intervalo [1:10] ", x);
        if (x < 1.0)
        {
            IO_printf("%s (%lf)\n", "Valor abaixo do intervalo [1:10] ", x);
        }
        else
        {
            IO_printf("%s (%lf)\n", "Valor acima do intervalo [1:10]", x);
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
a.) 0
b.) 1
c.) 10
d.) -1
e.) 100
---------------------------------------------- historico
Versao Data Modificacao
0.1 25/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) teste valor inteiro igual ou diferente de zero if-if
0.2 01. ( OK ) teste valor inteiro igual ou diferente de zero if-else
0.3 01. ( OK ) teste valor inteiro igual ou diferente de zero (maior ou menor)
0.4 01. ( OK ) teste valor real entre um intervalo determinado
*/