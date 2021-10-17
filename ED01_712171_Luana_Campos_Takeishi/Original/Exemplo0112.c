/*
    Exemplo0112 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0112      exemplo0112.c
    Windows:    gcc -o exemplo0112.exe  exemplo0112.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0112
    Windows:    exemplo0112
*/

//dependencias
//para entradas e saidas
#include <stdio.h>
#include "io.h"

/*
    funcao principal
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main (int argc, char* argv [ ])
{
    //definir dado
    //definir variavel com valor inicial
    int lado = 0;

    //identificar - cabecalho
    IO_id("Exemplo0112 - Programa = Versao0.1");

    //ler valor do teclado
    lado = IO_readint ("\nDigite um valor inteiro: ");

    //mostrar na tela os valores indicados
    printf("\n%s %d", "Lado do quadrado: ", lado/2);
    printf("\n%s %d", "Area do quadrado: ", (lado/2)*2);
    printf("\n%s %d", "Perimetro do quadrado: ", (lado/2)*4);

    //encerrar
    printf("\n\nAperte <enter> para terminar.");
    //limpar entrada de dados
    fflush(stdin);
    //aguardar por enter
    getchar( );
    //voltar ao SO (sem erros)
    return(0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
instrucoes:
- definir e ler um valor inteiro do teclado;
- supor que esse valor represente o lado de um quadrado,
calcular e mostrar a area e o perimetro de um quadrado 
com a metade do tamanho do lado.
---------------------------------------------- notas / observacoes / comentarios
programa funcionou como o esperado para todos os valores testados.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 21/08 esboco
---------------------------------------------- testes
Versao Teste
1.1 01. ( OK ) exercicio 01 - 1/3 da area de um quadrado
1.2 01. ( OK ) exercicio 02 - area e perimetro de um quadrado
*/