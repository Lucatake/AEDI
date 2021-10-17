/*
    Exemplo0213 - Versao 0.1 - 26/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0213      exemplo0213.c
    Windows:    gcc -o exemplo0213.exe  exemplo0213.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0213
    Windows:    exemplo0213
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    intervA - funcao para testar se o valor esta entre ]20:64[
    @param a - valor a ser testado e exibido
*/
void intervA ( int a )
{
    //teste do valor e exibicao do resultado
    if ( (a > 20) && (a < 64) )
    {
        IO_printf("\nValor (%d) pertence ao intervalo ]20:64[", a);
    }
    else
    {
        IO_printf("\nValor (%d) NAO pertence ao intervalo ]20:64[", a);
    }//end if
}//end intervA( )

/*
    Funcao principal.
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main( )
{
    //definir dado
    int a = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0213 - Programa - v0.1");
    
    //ler do teclado
    a = IO_readint ("\nEntrar com um valor inteiro: ");
    
    //testar valor e mostrar resultado
    intervA( a );
    
    
    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler um valor inteiro do teclado e
- dizer se pertence ao intervalo aberto entre ]20:64[
---------------------------------------------- notas / observacoes / comentarios
0.1 
criacao de uma funcao intervA ( )
---------------------------------------------- previsao de testes
a.) 40
b.) 20
c.) 64
d.) 65
e.) 19
f.) 21
g.) 63
---------------------------------------------- historico
Versao   Data    Modificacao
 0.1     26/08     esboco
---------------------------------------------- testes
Versao Teste
1.1 03. ( OK ) exercicio 1 - teste valor impar ou par
1.2 01. ( OK ) exercicio 2 - teste valor impar ou par
1.3 01. ( OK ) exercicio 3 - teste valor entre intervalo ]20:64[
*/