/*
    Exemplo0106 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0106      exemplo0106.c
    Windows:    gcc -o exemplo0106.exe  exemplo0106.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0106
    Windows:    exemplo0106
*/

//dependencias
//para entradas e saidas
#include <stdio.h>
//para valores logicos
#include <stdbool.h>
//para cadeias de caracteres
#include <string.h>

/*
    funcao principal
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main (int argc, char* argv [ ])
{
    //definir dado
    //definir variaveis com valor inicial
    int x = 0;
    int y = 0;
    int z = 0;

    //identificar
    printf("\n%s\n", "Exemplo0106 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valores iniciais
    printf("%s%d\n", "x=", x);
    printf("%s%d\n", "y=", y);
                                //obs: formato para int -> %d ou %i

    //ler do teclado 2 valores
    printf("Entrar com um valor inteiro: ");
    scanf("%d", &x);
    printf("Entrar com outro valor inteiro: ");
    scanf("%i", &y);
                    //obs: necessario indicar o endereco -> &
    
    //operar valores
    z = x * y;
              //guarda em z o produto de x por y

    //mostrar valor resultante
    printf("%s(%i)*(%i)=(%d)\n","z= ", x,y,z);

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
aparece o cabecalho, a os dois valores iniciais de x e y, procedimento 
para entrada de novos valores, retorno do resultado de sua multiplicacao
e fim do programa.
observacao:
---------------------------------------------- previsao de testes
a.)  3  e  5
b.) -3  e  5
c.) -3  e -5
---------------------------------------------- historico
Versao  Data     Modificacao
0.1     21/08     esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) leitura e exibicao de inteiro
0.2 02. ( OK ) leitura e exibicao de real
0.3 01. ( OK ) leitura e exibicao de caractere
0.4 01. ( OK ) leitura e exibicao de logica
0.5 01. ( OK ) leitura e exibicao de cadeia de caracteres
0.6 01. ( OK ) leitura e exibicao do produto de dois inteiros
*/