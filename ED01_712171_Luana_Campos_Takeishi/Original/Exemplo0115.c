/*
    Exemplo0115 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0115      exemplo0115.c
    Windows:    gcc -o exemplo0115.exe  exemplo0115.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0115
    Windows:    exemplo0115
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
    int base = 0;
    int altura = 0;
    int area = 0;

    //identificar - cabecalho
    IO_id("Exemplo0115 - Programa = Versao0.1");

    //ler valores do teclado
    base = IO_readint ("\nDigite um valor inteiro: ");
    altura = IO_readint ("Digite outro valor inteiro: ");

    //definir altura como seu triplo
    altura = altura * 3;
    //calcular a area do triangulo
    area = (base * altura) / 2;
    

    //mostrar na tela valores finais
    printf("\n%s %d", "Base do triangulo: ", base);
    printf("\n%s %d", "Altura do triangulo: ", altura);
    printf("\n%s %d", "Area do triangulo: ", area);

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
- definir e ler dois valores reais do teclado;
- supor que esses dois valores representem base e altura de um triangulo,
calcular e mostrar a area de um triangulo com tres vezes a altura do mesmo.
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
*/