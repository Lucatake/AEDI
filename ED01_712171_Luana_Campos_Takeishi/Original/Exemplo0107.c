/*
    Exemplo0107 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0107      exemplo0107.c
    Windows:    gcc -o exemplo0107.exe  exemplo0107.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0107
    Windows:    exemplo0107
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
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    //identificar
    printf("\n%s\n", "Exemplo0107 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valores iniciais
    printf("%s%lf\n", "x=", x);
    printf("%s%lf\n", "y=", y);
                                //obs: formato para double -> %lf 

    //ler do teclado 2 valores
    printf("Entrar com um valor real: ");
    scanf("%lf", &x);
    printf("Entrar com outro valor real: ");
    scanf("%lf", &y);
                    //obs: necessario indicar o endereco -> &
    
    //operar valores
    z = pow(x,y);
              //elevar a base (x) 'a potencia (y)

    //mostrar valor resultante
    printf("%s(%lf)^(%lf)=(%lf)\n","z= ", x,y,z);

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
para entrada de novos valores, retorno do resultado da potencia
e fim do programa.
observacao: no pdf do estudo haviam alguns erros de digitacao nos comentarios - 
// OBS.: O formato para int -> %d (ou %i)
e no valor resultante onde foi usado ^ em vez de * - 
printf ( "%s(%lf)*(%lf) = (%lf)\n", "z = ", x, y, z );
---------------------------------------------- previsao de testes
a.)  2.0  e  3.0
b.)  3.0  e  2.0
c.) -3.0  e  2.0
d.) -2.0  e -3.0
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
*/