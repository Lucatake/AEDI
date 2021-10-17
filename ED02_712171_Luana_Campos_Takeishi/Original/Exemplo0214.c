/*
    Exemplo0214 - Versao 0.1 - 26/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0214      exemplo0214.c
    Windows:    gcc -o exemplo0214.exe  exemplo0214.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0214
    Windows:    exemplo0214
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    intervA - funcao para testar se o valor 
    e' par e esta entre [20:64]
    @param a - valor a ser testado e exibido
*/
void intervA ( int a )
{
    //definir dados
    int o = a % 2;      //teste (do resto) se variavel e' par

    //teste do valor e exibicao do resultado
    if ( (a >= 20) && (a <= 64) && (o == 0) )
    {
        IO_printf("\nValor (%d) e' par e pertence ao intervalo [20:64]", a);
    }
    else
    {
        IO_printf("\nValor (%d) NAO corresponde as especificacoes", a);
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
    IO_id("EXEMPLO0214 - Programa - v0.1");
    
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
- dizer e par e tambem pertence ao intervalo fechado entre [20:64]
---------------------------------------------- notas / observacoes / comentarios
0.1 
modificacao da funcao intervA ( ) do exercicio anterior
---------------------------------------------- previsao de testes
a.) 40
b.) 20
c.) 64
d.) 65
e.) 18
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
1.4 01. ( OK ) exercicio 4 - teste valor par entre intervalo [20:64]
*/