/*
    Exemplo0405 - Versao 0.1 - 09/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0405      exemplo0405.c
    Windows:    gcc -o exemplo0405.exe  exemplo0405.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0405
    Windows:    exemplo0405
*/

// dependencias
#include "io.h" // para definicoes proprias

/**
Method00 - nao faz nada.
*/
void method00()
{
    // nao faz nada
} // fim method00 ( )

/**
Method01 - Repeticao para ler certa quantidade de valores.
*/
void method01()
{
    // definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    // identificar
    IO_id("EXEMPLO0405 - Method01 - v0.0");
    // ler do teclado
    quantidade = IO_readint("Entrar com uma quantidade: ");
    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler valor do teclado
        valor = IO_readint(IO_concat(
            IO_concat("", IO_toString_d(controle)),
            ": "));
        // passar ao proximo valor
        controle = controle + 1;
    } // fim repetir
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
Funcao para determinar se valor inteiro e' positivo.
@return true, se positivo; false, caso contrario
@param x - valor a ser testado
*/
bool positive(int x)
{
    // definir dado local
    bool result = false;
    // testar a condicao
    if (x > 0)
    {
        result = true;
    } // fim se
    return (result);
} // fim positive ( )

/**
Method02 - Ler valores e contar positivos.
*/
void method02()
{
    // definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    // identificar
    IO_id("EXEMPLO0405 - Method02 - v0.0");
    // ler do teclado
    quantidade = IO_readint("Entrar com uma quantidade: ");
    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler valor do teclado
        valor = IO_readint(IO_concat(
            IO_concat("", IO_toString_d(controle)),
            ": "));
        // testar e contar se valor for positivo
        if (positive(valor))
        {
            contador = contador + 1;
        } // fim se
        // passar ao proximo valor
        controle = controle + 1;
    } // fim repetir
    // mostrar a quantidade de valores positivos
    IO_printf("%s%d\n", "Positivos = ", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method02 ( )

/**
Funcao para determinar se valor inteiro pertence a intervalo aberto.
@return true, se pertencer; false, caso contrario
@param x - valor a ser testado
*/
bool belongsTo(int x, int inferior, int superior)
{
    // definir dado local
    bool result = false;
    // testar a condicao
    if (inferior < x && x < superior)
    {
        result = true;
    } // fim se
    return (result);
} // fim belongsTo ( )

/**
Method03 - Ler valores e contar positivos menores que 100.
*/
void method03()
{
    // definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    // identificar
    IO_id("EXEMPLO0405 - Method03 - v0.0");
    // ler do teclado
    quantidade = IO_readint("Entrar com uma quantidade: ");
    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler valor do teclado
        valor = IO_readint(IO_concat(
            IO_concat("", IO_toString_d(controle)),
            ": "));
        // testar e contar se valor for positivo
        if (belongsTo(valor, 0, 100))
        {
            contador = contador + 1;
        } // fim se
        // passar ao proximo valor
        controle = controle + 1;
    } // fim repetir
    // mostrar a quantidade de valores positivos
    IO_printf("%s%d\n", "Positivos menores que 100 = ", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method03 ( )

/**
Funcao para determinar se valor inteiro e' par.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/
bool even(int x)
{
    // definir dado local
    bool result = false;
    // testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero )
    if (x % 2 == 0)
    {
        result = true;
    } // fim se
    return (result);
} // fim even ( )

/**
Method04 - Ler valores e contar positivos menores que 100 e pares.
*/
void method04()
{
    // definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    // identificar
    IO_id("EXEMPLO0405 - Method04 - v0.0");
    // ler do teclado
    quantidade = IO_readint("Entrar com uma quantidade: ");
    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler valor do teclado
        valor = IO_readint(IO_concat(
            IO_concat("", IO_toString_d(controle)),
            ": "));
        // testar e contar se valor for positivo menor que 100 e par
        if (belongsTo(valor, 0, 100) && even(valor))
        {
            contador = contador + 1;
        } // fim se
        // passar ao proximo valor
        controle = controle + 1;
    } // fim repetir
    // mostrar a quantidade de valores positivos
    IO_printf("%s%d\n", "Positivos menores que 100 e pares = ", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method04 ( )

/**
Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
*/
void method05()
{
    // definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    bool ok = false;
    // identificar
    IO_id("EXEMPLO0405 - Method05 - v0.0");
    // ler do teclado
    quantidade = IO_readint("Entrar com uma quantidade: ");
    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler valor do teclado
        valor = IO_readint(IO_concat(
            IO_concat("", IO_toString_d(controle)),
            ": "));
        // testar e contar se valor for positivo menor que 100 e par
        ok = belongsTo(valor, 0, 100);
        ok = ok && even(valor);
        if (ok)
        {
            contador = contador + 1;
        } // fim se
        // passar ao proximo valor
        controle = controle + 1;
    } // fim repetir
    // mostrar a quantidade de valores positivos
    IO_printf("%s%d\n", "Positivos menores que 100 e pares = ", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method05 ( )

/**
Method06.
*/
void method06()
{
    // identificar
    IO_id("EXEMPLO0405 - Method06 - v0.0");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
Method07.
*/
void method07()
{
    // identificar
    IO_id("EXEMPLO0405 - Method07 - v0.0");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method07 ( )

/**
Method08.
*/
void method08()
{
    // identificar
    IO_id("EXEMPLO0405 - Method08 - v0.0");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method08 ( )

/**
Method09.
*/
void method09()
{
    // identificar
    IO_id("EXEMPLO0405 - Method09 - v0.0");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method09 ( )

/**
Method10.
*/
void method10()
{
    // identificar
    IO_id("EXEMPLO0405 - Method10 - v0.0");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method10 ( )

/*
Funcao principal.
@return codigo de encerramento
*/
int main()
{
    // definir dado
    int x = 0;
    // repetir até desejar parar
    do
    {
        // identificar
        IO_id("EXEMPLO0405 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - ler certa quantidade de valores");
        IO_println(" 2 - ler, testar e mostrar quantos valores sao positivos");
        IO_println(" 3 - ler, testar e mostrar quantos valores pertencem a ]0,100[");
        IO_println(" 4 - ler, testar e mostrar quantos valores sao positivos, pares < 100");
        IO_println(" 5 - valores positivos, menores que 100 e pares (alternativo)");
        IO_println(" 6 - ");
        IO_println(" 7 - ");
        IO_println(" 8 - ");
        IO_println(" 9 - ");
        IO_println("10 - ");
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        // testar valor
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
        case 8:
            method08();
            break;
        case 9:
            method09();
            break;
        case 10:
            method10();
            break;
        default:
            IO_pause("ERRO: Valor invalido.");
        } // fim escolher
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
a.) -1
b.) 0
c.) 7 e { -10, 20, 30, 45, 5, 100, 0 }
---------------------------------------------- historico
Versao Data Modificacao
0.1   09/09 esboco
---------------------------------------------- testes
   Versao  Teste
0.1 01. ( OK ) metodo para ler uma quantidade de valores
0.2 01. ( OK ) metodo para ler uma quantidade de valores, testar os positivos e mostrar quantidade
0.3 01. ( OK ) metodo para ler uma quantidade de valores, testar os se estao dentro do intervalo ]0,100[
0.4 01. ( OK ) metodo para ler uma quantidade de valores, testar se sao pares, dentro do intervalo ]0,100[
0.5 01. ( OK ) metodo alternativo para valores pares, positivos e menores que 100

*/