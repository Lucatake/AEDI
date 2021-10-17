/*
    Exemplo0301 - Versao 0.1 - 31/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0301      exemplo0301.c
    Windows:    gcc -o exemplo0301.exe  exemplo0301.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0301
    Windows:    exemplo0301
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
    Method00 - nao faz nada.
*/
void method00( )
{
    //nao faz nada
}//fim method00( )

/**
    Method01 - Repeticao com teste no inicio.
*/
void method01( )
{
    //definir dado
    int x = 0;

    //identificar
    IO_id("\nEXEMPLO0301 - Method01 - v0.1");

    //ler do teclado o valor inicial
    x = IO_readint("\nEntrar com uma quantidade: ");

    //repetir (x) vezes
    while (x > 0)
    {
        //mostrar valor atual
        IO_println(IO_toString_d(x));

        //passar ao proximo valor
        x = x - 1;
    }//fim repetir

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//fim method01( )

/*
    Funcao principal.
    @return codigo de encerramento
*/
int main( )
{
    //definir dado
    int x = 0;

    //repetir até desejar parar
    do
    {
        //identificar
        IO_id("\nEXEMPLO0301 - Programa - v0.1");
        //ler do teclado
        IO_println("\nOpcoes");
        IO_println("0 - parar");
        IO_println("1 - repeticao com teste no inicio");
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        
        //testar valor
        switch (x)
        {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;
        default:
            IO_pause(IO_concat("Valor diferente das opcoes [0,1] (",
                               IO_concat((IO_toString_d(x)), ")")));
                               break;
        }//fim escolher
    } while (x != 0);

    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//fim main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
o programa conta de forma decrescente, para valores negativos nao funciona
obs: com o teste f) -1 o programa fecha
erro: (IO_concat("Valor diferente das opcoes [0,1] (",
                               IO_concat(IO_toString_d(x), ")")));
    a juncao dos dois valores gera caracteres estranhos
correcao: erro estava na biblioteca 'io.h'
---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 2
d.) 3
e.) 4
f.) -1
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         31/08          esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) metodos e contagem decrescente de um valor
*/
