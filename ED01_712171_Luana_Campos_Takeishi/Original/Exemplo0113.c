/*
    Exemplo0113 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0113      exemplo0113.c
    Windows:    gcc -o exemplo0113.exe  exemplo0113.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0113
    Windows:    exemplo0113
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
    int lado1 = 0;
    int lado2 = 0;
    int area = 0;

    //identificar - cabecalho
    IO_id("Exemplo0113 - Programa = Versao0.1");

    //ler valores do teclado
    lado1 = IO_readint ("\nDigite um valor inteiro: ");
    lado2 = IO_readint ("Digite outro valor inteiro: ");

    //calcular 1/4 da area do retangulo
    area = (lado1*lado2)/4;

    //mostrar na tela valores finais
    printf("\n%s %d", "Lado 01 do retangulo: ", lado1);
    printf("\n%s %d", "Lado 02 do retangulo: ", lado2);
    printf("\n%s %d", "1/4 da area do retangulo: ", area);

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
- definir e ler dois valores inteiros do teclado;
- supor que esses dois valores representem lados de um retangulo,
calcular e mostrar um quarto da area do mesmo.
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
1.3 01. ( OK ) exercicio 03 - 1/4 de area de um retangulo
*/