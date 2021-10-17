/*
    Exemplo01E2 - Versao 0.1 - 22/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo01E2      exemplo01E2.c
    Windows:    gcc -o exemplo01E2.exe  exemplo01E2.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo01E2
    Windows:    exemplo01E2
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
    float volume = 0;
    float raio = 0;
    float altura = 0;
    float areaS = 0;
    float pi = M_PI;        //definindo pi

    //identificar - cabecalho
    IO_id("Exemplo01E1 - Programa = Versao0.1");

    //ler valores do teclado
    volume = IO_readfloat ("\nDigite um valor real: ");

    //achar raio e altura
    altura = pow(((36*volume)/(3*pi)), (1/3));
    raio = altura/2;
    //calcular area de superficie
    areaS = pi * raio * ( (2 * pow(altura,2)) + raio );

    //mostrar na tela valores finais
    printf("\n%s %f", "Volume de um cone: ", volume);  
    printf("\n%s %f", "Raio do cone: ", raio); 
    printf("\n%s %f", "Altura do cone: ", altura); 
    printf("\n%s %f", "Area de superficie do cone: ", areaS); 

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
- supor que esse valor represente o volume de um cone com 
raio igual a metade da altura;
- calcular e mostrar o raio e a area de sua superficie.
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
E.2 01. ( OK ) exercicio extra 02 - cone com valor real
*/