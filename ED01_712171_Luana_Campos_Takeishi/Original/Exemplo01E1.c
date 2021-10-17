/*
    Exemplo01E1 - Versao 0.1 - 22/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo01E1      exemplo01E1.c
    Windows:    gcc -o exemplo01E1.exe  exemplo01E1.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo01E1
    Windows:    exemplo01E1
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
    float area = 0;
    float lado1 = 0;
    float lado2 = 0;
    float perimetro = 0;

    //identificar - cabecalho
    IO_id("Exemplo01E1 - Programa = Versao0.1");

    //ler valores do teclado
    area = IO_readfloat ("\nDigite um valor real: ");

    //achar lados
    lado1 = sqrt(2 * area);
    lado2 = lado1/2;
    //achar perimetro
    perimetro = (lado1*2) + (lado2*2);

    //mostrar na tela valores finais
    printf("\n%s %f", "Area do retangulo: ", area);  
    printf("\n%s %f", "Lado 01 do retangulo: ", lado1); 
    printf("\n%s %f", "Lado 02 do retangulo: ", lado2); 
    printf("\n%s %f", "Perimetro do retangulo: ", perimetro); 

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
- supor que esse valor informe a area de um retangulo com lados 
iguais a metade do outro,
- calcular e mostrar os lados e o perimetro do mesmo.
---------------------------------------------- notas / observacoes / comentarios
programa funcionou como o esperado para todos os valores testados.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 22/08 esboco
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
1.9 01. ( OK ) exercicio 09 - circulo
2.0 01. ( OK ) exercicio 10 - esfera
E.1 01. ( OK ) exercicio extra 01 - retangulo com valor real
*/