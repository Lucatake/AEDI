/*
    Exemplo0117 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0117      exemplo0117.c
    Windows:    gcc -o exemplo0117.exe  exemplo0117.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0117
    Windows:    exemplo0117
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
    int volume = 0;


    //identificar - cabecalho
    IO_id("Exemplo0117 - Programa = Versao0.1");

    //ler valores do teclado
    lado = IO_readint ("\nDigite um valor inteiro: ");

    //definir como lado 
    lado = lado * 5;
    //calcular o volume de um cubo
    volume = pow(lado, 3);

    //mostrar na tela valores finais
    printf("\n%s %d", "Lado do cubo: ", lado);
    printf("\n%s %d", "Volume do cubo: ", volume);

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
- supor que esse valor represente a medida de lados de um cubo,
calcular e mostrar o volume do solido com cinco vezes a medida do lado.
---------------------------------------------- notas / observacoes / comentarios
programa funcionou como o esperado para todos os valores testados.
obs: para o valor 1 acontece um erro, o volume fica igual a 124.
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
1.7 01. ( OK ) exercicio 07 - volume de um cubo
*/