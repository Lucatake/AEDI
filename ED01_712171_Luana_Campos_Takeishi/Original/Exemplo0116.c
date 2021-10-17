/*
    Exemplo0116 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0116      exemplo0116.c
    Windows:    gcc -o exemplo0116.exe  exemplo0116.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0116
    Windows:    exemplo0116
*/

//dependencias
//para entradas e saidas
#include <stdio.h>
#include "io.h"
#include <math.h>

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
    float altura = 0;
    float area = 0;
    float perimetro = 0;

    //identificar - cabecalho
    IO_id("Exemplo0116 - Programa = Versao0.1");

    //ler valores do teclado
    lado = IO_readint ("\nDigite um valor inteiro: ");

    //calcular altura do triangulo
    altura = (lado * sqrt(3)) / 2;
    //calcular a area do triangulo
    area = (lado * altura) / 2;
    //calcular o perimetro do triangulo
    perimetro = lado * 3;

    //mostrar na tela valores finais
    printf("\n%s %d", "Lado do triangulo equilatero: ", lado);
    printf("\n%s %.2f", "Altura do triangulo equilatero: ", altura);
    printf("\n%s %.2f", "Area do triangulo equilatero: ", area);
    printf("\n%s %.2f", "Perimetro do triangulo equilatero: ", perimetro);

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
- definir e ler um valor real do teclado;
- supor que esse valor represente o lado de um triangulo equilatero,
calcular e mostrar a altura, area e o perimetro do mesmo.
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
1.4 01. ( OK ) exercicio 04 - area e perimetro de um retangulo
1.5 01. ( OK ) exercicio 05 - area de um triangulo
1.6 01. ( OK ) exercicio 06 - altura, area e perimetro de triangulo equilatero
*/