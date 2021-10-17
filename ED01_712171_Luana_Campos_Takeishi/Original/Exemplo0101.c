/*
    Exemplo0101 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0101      exemplo0101.c
    Windows:    gcc -o exemplo0101.exe  exemplo0101.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0101
    Windows:    exemplo0101
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
    int x = 0;
    /* forma alternativa de definir variavel:
        int x;      sem definir valor inicial
        x = 0;      definir o valor depois
                    (alternativa menos indicada)
    */

    //identificar
    printf("%s\n", "Exemplo0101 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valor inicial
    printf("%s%d\n", "x=", x);
                                //obs: formato para int -> %d ou %i

    //ler do teclado
    printf("Entrar com um valor inteiro: ");
    scanf("%d", &x);
                    //obs: necessario indicar o endereco -> &
    
    //mostrar valor lido
    printf("%s%i\n","x= ", x);

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
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
0.1 21/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) leitura e exibicao de inteiro
*/