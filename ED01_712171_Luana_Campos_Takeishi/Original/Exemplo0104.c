/*
    Exemplo0104 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0104      exemplo0104.c
    Windows:    gcc -o exemplo0104.exe  exemplo0104.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0104
    Windows:    exemplo0104
*/

//dependencias
//para entradas e saidas
#include <stdio.h>
//para valores logicos
#include <stdbool.h>

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
    bool x = false;
                    //obs: insidpensavel usar minusculas

    //identificar
    printf("\n%s\n", "Exemplo0104 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valor inicial
    printf("%s%d\n", "x=", x);
                                //obs: formato para equivalente inteiro -> %d

    //ler do teclado
    printf("Entrar com um valor logico: ");
    scanf("%d", &x);
                    //obs: usar equivalente inteiro -> 0=false
    
    //mostrar valor lido
    printf("%s%d\n","x= ", x);

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
aparece o cabecalho, o valor inicial logico, procedimento 
para entrada do valor, retorno do valor e fim do programa.
observacao: funciona para os equivalentes 0 e 1, mas para o true o
valor retornado e' igual a zero, pois usa-se %d de numeros
---------------------------------------------- previsao de testes
a.) 1
b.) 0
c.) true
---------------------------------------------- historico
Versao  Data     Modificacao
0.1     21/08     esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) leitura e exibicao de inteiro
0.2 02. ( OK ) leitura e exibicao de real
0.3 01. ( OK ) leitura e exibicao de caractere
0.4 01. ( OK ) leitura e exibicao de logica
*/