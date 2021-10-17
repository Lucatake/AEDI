/*
    Exemplo0111 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0111      exemplo0111.c
    Windows:    gcc -o exemplo0111.exe  exemplo0111.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0111
    Windows:    exemplo0111
*/

//dependencias
//para entradas e saidas
#include <stdio.h>

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
    int area = 0;
    int terco = 0;

    //identificar - cabecalho
    printf("\n%s\n", "Exemplo0111 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("%s\n", "Matricula: 712171");
    printf("\n");   //mudar de linha
    //mostrar o valor inicial da variavel
    printf("lado = %d\n", lado);

    //ler valor do teclado
    printf("\nDigite um valor inteiro para ser o lado de um quadrado: ");
    scanf("%d", &lado);     //guardar valor digitado na variavel 

    //calculando a area e o valor de seu terco
    area = lado * lado;
    terco = area / 3;

    //mostrar valor final
    printf("\n1/3 da area (%d) do quadrado de lado %d e' igual a %d.", area, lado, terco);

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
calcular e mostrar um terco da area do mesmo.
---------------------------------------------- notas / observacoes / comentarios
programa funcionou como o esperado para todos os valores testados.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 21/08 esboco
---------------------------------------------- testes
Versao Teste
1.1 01. ( OK ) exercicio 01 - 1/3 da area de um quadrado
*/