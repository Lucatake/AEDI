/*
    Exemplo0307 - Versao 0.1 - 31/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0307      exemplo0307.c
    Windows:    gcc -o exemplo0307.exe  exemplo0307.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0307
    Windows:    exemplo0307
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
    IO_id("\nEXEMPLO0307 - Method01 - v0.1");

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
    IO_id("\nEXEMPLO0307 - Method02 - v0.1");

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
    IO_id("\nEXEMPLO0307 - Method03 - v0.0");

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

/**
    Method04 - Repeticao com teste no inicio e variacao.
*/
void method04( )
{
    //definir dado
    int x = 0;
    int y = 0;

    //identificar
    IO_id("\nEXEMPLO0307 - Method04 - v0.0");

    //ler do teclado
    x = IO_readint("\nEntrar com uma quantidade: ");

    //repetir (x) vezes
    //inicio teste variacao
    for (y = 1; y <= x; y = y + 1)
    {
        //mostrar valor atual
        IO_printf("%d\n", y);
    }//fim repetir

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//fim method04( )

/**
    Method05 - Repeticao com teste no inicio e variacao.
*/
void method05( )
{
    //definir dado
    int x = 0;
    int y = 0;

    //identificar
    IO_id("\nEXEMPLO0307 - Method05 - v0.0");

    //ler do teclado
    x = IO_readint("\nEntrar com uma quantidade: ");

    //repetir (x) vezes
    //inicio teste variacao
    for (y = x; y >= 1; y = y - 1)
    {
        //mostrar valor atual
        IO_printf("%d\n", y);
    }//fim repetir

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//fim method05( )

/**
    Method06 - Repeticao sobre cadeia de caracateres.
*/
void method06( )
{
    //definir dado
    int x = 0;
    int y = 0;
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;

    //identificar
    IO_id("\nEXEMPLO0307 - Method06 - v0.0");

    //ler do teclado
    palavra = IO_readstring("\nEntrar com uma palavra: ");

    //repetir para cada letra
    tamanho = strlen(palavra) - 1;

    //inicio teste variacao
    for (y = tamanho; y >= 0; y = y - 1)
    {
        //mostrar valor atual
        IO_printf("%d: [%c]\n", y, palavra[y]);
    }//fim repetir

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//fim method06 ( )

/**
    Method07 - Repeticao sobre cadeia de caracateres.
*/
void method07( )
{
    //definir dado
    int x = 0;
    int y = 0;
    char palavra[STR_SIZE];
    int tamanho = 0;

    //identificar
    IO_id("\nEXEMPLO0307 - Method07 - v0.0");

    //ler do teclado
    IO_printf("\nEntrar com uma palavra: ");
    scanf("%s", palavra);

    //repetir para cada letra
    tamanho = strlen(palavra);

    //inicio teste variacao
    for (y = 0; y < tamanho; y = y + 1)
    {
        //mostrar valor atual
        IO_printf("%d: [%c]\n", y, palavra[y]);
    }//fim repetir

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//fim method07( )

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
        IO_id("\nEXEMPLO0307 - Programa - v0.1");
        //ler do teclado
        IO_println("\nOpcoes");
        IO_println("0 - parar");
        IO_println("1 - repeticao com teste no inicio (decrescente)");
        IO_println("2 - repeticao com teste no inicio (alternativo)");
        IO_println("3 - repeticao com teste no inicio (crescente)");
        IO_println("4 - repeticao com teste no inicio e variacao (crescente)");
        IO_println("4 - repeticao com teste no inicio e variacao (decrescente)");
        IO_println("6 - repeticao sobre cadeia de caracteres (decrescente)");
        IO_println("7 - repeticao sobre cadeia de caracteres (crescente)");
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
        case 4:
            method04();
            break;  
        case 5:
            method05();
            break;  
        case 6:
            method06();
            break; 
        case 7:
            method07();
            break; 
        default:
            IO_pause ( "ERRO: Valor invalido." );
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
o programa conta de forma decrescente a cadeia de caracteres
obs: para c.)abc def o programa le somente a primeira cadeia
---------------------------------------------- previsao de testes
a.) "a"
b.) "abc"
c.) "abc def"
d.) "palavra"
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         31/08          esboco
---------------------------------------------- testes
Versao Teste
 0.1    01. ( OK ) metodos e contagem decrescente de um valor
 0.2    01. ( OK ) metodos e contagem (alternativo)
 0.3    01. ( OK ) metodos e contagem crescente de um valor (while)
 0.4    01. ( OK ) metodos e contagem crescente de um valor (for)
 0.5    01. ( OK ) metodos e contagem decrescente de um valor (for)
 0.6    01. ( OK ) metodos e contagem cadeia de caracteres (decrescente)
 0.7    01. ( OK ) metodos e contagem cadeia de caracteres (crescente)
*/