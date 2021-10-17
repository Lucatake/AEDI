/*
    Exemplo0210 - Versao 0.2 - 26/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0210      exemplo0210.c
    Windows:    gcc -o exemplo0210.exe  exemplo0210.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0210
    Windows:    exemplo0210
*/

// dependencias
#include "io.h"     //para definicoes proprias

/**
    Method00 - nao faz nada.
*/
void method00( )
{
    //nao faz nada
}//end method00( )

/**
    Method01 - mostrar mensagem com texto constante.
*/
void method01( )
{
    IO_println("Valor igual a um");
}//end method01( )

/**
    Method02 - mostrar mensagem com texto constante e
    valor variavel
    @param x - valor a ser exibido
*/
void method02(int x)
{
    IO_println (IO_concat(
        "Valor igual a (", 
        IO_concat(IO_toString_d(x), ")\n") ) );
}//end method02( )

/**
    Method03 - mostrar mensagem com texto e
    valor variavel
    @param text1 - texto a ser exibido
    @param x - valor a ser exibido
*/
void method03(char *text1, int x)
{
    IO_println (IO_concat(
        IO_concat(" (", text1), 
        IO_concat( IO_toString_d(x), ")\n") ) );
}//end method03( )

/*
    Funcao principal.
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main( )
{
    //definir dado
    int x = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0210 - Programa - v0.1");
    
    //ler do teclado
    x = IO_readint ("Entrar com um inteiro [0,1,2,3]: ");

    //testar valor
    switch (x)
    {
    case 0:
        method00( );
        break;
    case 1:
        method01( );
        break;
    case 2:
        method02( x );
        break;
    case 3:
        method03( "Valor igual a tres ", x );
        break;
    default:        //se nenhuma alguma das opcoes anteriores
        IO_println (IO_concat (
            "Valor diferente das opcoes [0,1,2,3] (", 
            IO_concat ( IO_toString_d ( x ), ")") ) );
    } //end switch

    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
0.1 
erro: nas opcoes 2 o resultado sao caracteres estranhos e
na opcao 3 e != dessas nao aparece nada
0.2 
modificacoes: no metodh03 e default foi refeito a separacao por parenteses, 
corrigido o fato de nao aparecer nada na tela
erro: ainda aparece caracteres estranhos
-> problema em  IO_concat (IO_toString_d ( x ), ")\n") ): mesmo retirado
o IO_toString_d(x) colocando o numero direto, os caracteres ainda aparecem
0.3 PROBLEMA IDENFICADO - problema no io.h resolvido.
---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 2
d.) 3
e.) 4
f.) -1
g.) a
---------------------------------------------- historico
Versao   Data    Modificacao
 0.1     25/08     esboco
 0.2     26/08     esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) teste valor inteiro igual ou diferente de zero if-if
0.2 01. ( OK ) teste valor inteiro igual ou diferente de zero if-else
0.3 01. ( OK ) teste valor inteiro igual ou diferente de zero (maior ou menor)
0.4 01. ( OK ) teste valor real entre um intervalo determinado
0.5 01. ( OK ) teste do tipo de um valor (se caractere ou algarismo)
0.6 01. ( OK ) teste se um valor e' uma letra (maiuscula ou minuscula)
0.7 01. ( OK ) teste se um valor nao e' letra (maiuscula ou minuscula)
0.8 01. ( OK ) teste de entrada de caracteres especificos
0.9 01. ( OK ) teste de entrada de numeros especificos
1.0 01. ( OK ) teste de entrada de numeros especificos com funcoes fora da main
*/