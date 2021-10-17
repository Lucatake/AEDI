/*
    Exemplo0108 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0108      exemplo0108.c
    Windows:    gcc -o exemplo0108.exe  exemplo0108.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0108
    Windows:    exemplo0108
*/

//dependencias
//para entradas e saidas
#include <stdio.h>
//para valores logicos
#include <stdbool.h>
//para cadeias de caracteres
#include <string.h>
//para funcoes matematicas
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
    //definir variaveis com valor inicial
    char x[] = "abc";
    char y[] = "def";
    //definir variavel com tamanho inicial
    char z [80];
    //e copiar para (z) a representacao de vazio
    strcpy ( z, "" );

    //identificar
    printf("\n%s\n", "Exemplo0108 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valores iniciais
    printf("%s%s\n", "x=", x);
    printf("%s%s\n", "y=", y);
                                //obs: formato para char -> %s 

    //ler do teclado 2 valores
    printf("Entrar com caracteres: ");
    scanf("%s", x);
    printf("Entrar com outros caracteres: ");
    scanf("%s", y);
                    //obs: nao indicar endereco
    
    //operar valores
    //copiar (z) para (x)
    strcpy(z, x);
    //concatenar (juntar) (y) a (z)
    strcpy(z, y);
                //obs: forma mais eficiente

    //mostrar valor resultante
    printf("%s[%s]*[%s]=[%s]\n","z= ", x,y,z);

    //operar valores de forma alternativa
    strcpy(z, strcat(strdup(x), y));
                                    //copiar para (z)
                                    //o resultado concatenar
                                    //a copia de (x) com (y)
                                    //obs: se nao duplicar, o valor de (x) sera alterado
    
    //mostrar valor resultante
    printf("%s[%s]*[%s]=[%s]\n","z= ", x,y,z);

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
no primeiro metodo junta o vazio (z) com (y), sendo o resultado (y)
no segundo metodo junta o (x) com (y) para (z) sendo o resultado (xy)
observacao:
---------------------------------------------- previsao de testes
a.)  12 e 24
b.)  ab e cd
c.)   a e bc
d.)  ab e c
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
0.7 01. ( OK ) leitura e exibicao da potencia 
0.8 01. ( OK ) leitura e exibicao concatenacao de dois caracteres
*/