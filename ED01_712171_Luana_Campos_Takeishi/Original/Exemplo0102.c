/*
    Exemplo0102 - Versao 0.2 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0102      exemplo0102.c
    Windows:    gcc -o exemplo0102.exe  exemplo0102.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0102
    Windows:    exemplo0102
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
    double x = 0.0;
                    //obs: definir a parte fracionaria e' util

    //identificar
    printf("\n%s\n", "Exemplo0102 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valor inicial
    printf("%s%lf\n", "x=", x);
                                //obs: formato para double -> %lf

    //ler do teclado
    printf("Entrar com um valor real: ");
    scanf("%lf", &x);
                    //obs: necessario indicar o endereco -> &
    
    //mostrar valor lido
    printf("%s%lf\n","x= ", x);

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
---------------------------------------------- notas / observacoes / comentarios
programa funcionou como o esperado para todos os valores testados.
aparece o cabecalho, o valor inicial, procedimento para entrada de valores,
o valor digitado e o fim do programa.
observacao: para melhor precisao de numeros com mais casas,
necessarios especificar uma quantidade maior, pois somente
%lf gera uma precisao de 6 casas decimais (com arredondamento),
para isso %.xlf, onde x = numero de casas decimais 
(utilizado .8 para o caso c. 1.23456789)
---------------------------------------------- previsao de testes
a.) 0.5
b.) -0.5
c.) 1.23456789
---------------------------------------------- historico
Versao  Data     Modificacao
0.1     21/08     esboco
0.2     21/08     mudanca no %lf - %.8lf
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) leitura e exibicao de inteiro
0.2 02. ( OK ) leitura e exibicao de real
*/