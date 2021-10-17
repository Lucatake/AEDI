/*
    Exemplo0303 - Versao 0.1 - 31/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0303      exemplo0303.c
    Windows:    gcc -o exemplo0303.exe  exemplo0303.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0303
    Windows:    exemplo0303
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
    IO_id("\nEXEMPLO0303 - Method01 - v0.1");

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

/**
    Method02 - Repeticao com teste no inicio.
*/
void method02( )
{
    //definir dado
    int x = 0;
    int y = 0;

    //identificar
    IO_id("\nEXEMPLO0303 - Method02 - v0.1");

    //ler do teclado
    x = IO_readint("\nEntrar com uma quantidade: ");

    //repetir (x) vezes
    y = x;      //copiar o valor lido (e' melhor)
    while (y > 0)
    {
        //mostrar valor atual
        IO_println(IO_toString_d(x));

        //passar ao proximo valor
        y = y - 1;
    }//fim repetir

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//fim method02( )

/**
    Method03 - Repeticao com teste no inicio.
*/
void method03( )
{
    //definir dado
    int x = 0;
    int y = 0;

    //identificar
    IO_id("\nEXEMPLO0303 - Method03 - v0.0");

    //ler do teclado
    x = IO_readint("\nEntrar com uma quantidade: ");

    //repetir (x) vezes
    y = 1;      //copiar o valor lido (e' melhor)
    while (y <= x)
    {
        //mostrar valor atual
        IO_printf("%d\n", y);

        //passar ao proximo valor
        y = y + 1;
    }//fim repetir

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//fim method03( )

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
        IO_id("\nEXEMPLO0303 - Programa - v0.1");
        //ler do teclado
        IO_println("\nOpcoes");
        IO_println("0 - parar");
        IO_println("1 - repeticao com teste no inicio (decrescente)");
        IO_println("2 - repeticao com teste no inicio (alternativo)");
        IO_println("3 - repeticao com teste no inicio (crescente)");
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
        case 2:
            method02();
            break;    
        case 3:
            method03();
            break;  
        default:
            IO_pause(IO_concat("Valor diferente das opcoes [0,1,2,3] (",
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
o programa conta de forma crescente, para valores negativos nao funciona
erro: (IO_concat("Valor diferente das opcoes [0,1] (",
                               IO_concat(IO_toString_d(x), ")")));
    a juncao dos dois valores gera caracteres estranhos
correcao: erro estava na biblioteca 'io.h'
---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 3
d.) 5
e.) -5
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         31/08          esboco
---------------------------------------------- testes
Versao Teste
 0.1    01. ( OK ) metodos e contagem decrescente de um valor
 0.2    01. ( OK ) metodos e contagem (alternativo)
 0.3    01. ( OK ) metodos e contagem crescente de um valor
*/
