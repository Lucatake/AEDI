/*
    Exemplo0103 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0103      exemplo0103.c
    Windows:    gcc -o exemplo0103.exe  exemplo0103.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0103
    Windows:    exemplo0103
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
    char x = 'A';
                    //obs: insidpensavel usar apostrofos

    //identificar
    printf("\n%s\n", "Exemplo0103 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valor inicial
    printf("%s%c\n", "x=", x);
                                //obs: formato para char -> %c

    //ler do teclado
    printf("Entrar com um caractere: ");
    scanf("%c", &x);
                    //obs: necessario indicar o endereco -> &
    
    //mostrar valor lido
    printf("%s%c\n","x= ", x);

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
aparece o cabecalho, o valor inicial de um caractere, procedimento 
para entrada de caracteres, o valor digitado e o fim do programa.
observacao: somente 1 caractere.
---------------------------------------------- previsao de testes
a.) U
b.) L
c.) A
---------------------------------------------- historico
Versao  Data     Modificacao
0.1     21/08     esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) leitura e exibicao de inteiro
0.2 02. ( OK ) leitura e exibicao de real
0.3 01. ( OK ) leitura e exibicao de caractere
*/