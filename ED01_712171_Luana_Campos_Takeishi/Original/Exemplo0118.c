/*
    Exemplo0118 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0118      exemplo0118.c
    Windows:    gcc -o exemplo0118.exe  exemplo0118.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0118
    Windows:    exemplo0118
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
    int comprimento = 0;
    int largura = 0;
    int altura = 0;
    int volume = 0;


    //identificar - cabecalho
    IO_id("Exemplo0118 - Programa = Versao0.1");

    //ler valores do teclado
    comprimento = IO_readint ("\nDigite um valor inteiro: ");
    largura = IO_readint ("\nDigite outro valor inteiro: ");
    altura = IO_readint ("\nDigite outro valor inteiro: ");

    //definir 1/6 dos valores
    comprimento = comprimento/6;
    largura = largura/6;
    altura = altura/6;
    //calcular o volume de um paralelepipedo
    volume = comprimento*largura*altura;

    //mostrar na tela valores finais
    printf("\n%s %d", "Comprimento do paralelepipedo: ", comprimento);
    printf("\n%s %d", "Largura do paralelepipedo: ", largura);
    printf("\n%s %d", "Altura do paralelepipedo: ", altura);
    printf("\n%s %d", "Volume do paralelepipedo: ", volume);

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
- definir e ler tres valores reais do teclado;
- supor que esses valores correspondam ao comprimento, a largura e a altura
de um paralelepipedo, respectivamente,
- calcular e mostrar o volume do solido com um sexto desses valores.
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
1.7 01. ( OK ) exercicio 07 - volume de um cubo
1.8 01. ( OK ) exercicio 08 - paralelepipedo
*/