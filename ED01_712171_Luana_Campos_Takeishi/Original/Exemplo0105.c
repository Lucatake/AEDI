/*
    Exemplo0105 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0105      exemplo0105.c
    Windows:    gcc -o exemplo0105.exe  exemplo0105.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0105
    Windows:    exemplo0105
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
    //definir variavel com valor inicial
    char x[] = "abc";
                    //obs: necessario utilizar aspas duplas

    //identificar
    printf("\n%s\n", "Exemplo0105 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valor inicial
    printf("%s%s\n", "x=", x);
                                //obs: formato para equivalente caractere -> %s

    //ler do teclado
    printf("Entrar com uma cadeia de caracteres: ");
    scanf("%s", x);
                    //obs: nao deve ser usado o endereco desta vez
    
    //mostrar valor lido
    printf("%s%s\n","x= ", x);

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
aparece o cabecalho, a cadeia de caracteres incial 'abc', procedimento 
para entrada de nova cadeia, retorno da mesma e fim do programa.
observacao: para ser cadeia de caracteres precisa estar junto, 
no caso b. d e f so e' reconhecido o d, a primeira cadeia. nos outros
casos a. def e c. d_e_f a cadeia e' totalmente exibida, sendo '_' um caractere.
---------------------------------------------- previsao de testes
a.) def
b.) d e f
c.) d_e_f
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
*/