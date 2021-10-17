/*
    Exemplo0215 - Versao 0.1 - 26/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0215      exemplo0215.c
    Windows:    gcc -o exemplo0215.exe  exemplo0215.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0215
    Windows:    exemplo0215
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    intervA - funcao para testar se o valor 
    esta entre B[15:48] e C[33:75] ou so' em um
    @param a - valor a ser testado e exibido
*/
void intervA ( int a )
{
    if ( (a >= 15) && (a <= 75) )     //se em algum desses intervalos
    {
        if ( (a >= 33) && (a <= 48) ) //se nos dois intervalos
        {
            IO_printf("Valor (%d) pertence aos intervalos [15:48] e [33:75]", a);
        }
        else
        {
            if ((a >= 15) && (a < 33))     //se somente no intervalo B
            {
                IO_printf("Valor (%d) pertence somente ao intervalo [15:48]", a);
            }//end if
            if ((a > 48) && (a <= 75))     //se somente no intervalo C
            {
                IO_printf("Valor (%d) pertence somente ao intervalo [33:75]", a);
            }//end if
        }//end if
    }
    else    //nenhum dos intervalos
    {
        IO_printf("Valor (%d) NAO pertence 'a nenhum intervalo", a);
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
    IO_id("EXEMPLO0215 - Programa - v0.1");
    
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
- dizer se pertence aos intervalos fechados [15:48] e [33:75], ou a apenas a um deles.
---------------------------------------------- notas / observacoes / comentarios
0.1 
modificacao da funcao intervA ( ) do exercicio anterior
---------------------------------------------- previsao de testes
a.) 15
b.) 48
c.) 33
d.) 75
e.) 70
f.) 40
g.) 100
---------------------------------------------- historico
Versao   Data    Modificacao
 0.1     26/08     esboco
---------------------------------------------- testes
Versao Teste
1.1 03. ( OK ) exercicio 1 - teste valor impar ou par
1.2 01. ( OK ) exercicio 2 - teste valor impar ou par
1.3 01. ( OK ) exercicio 3 - teste valor entre intervalo ]20:64[
1.4 01. ( OK ) exercicio 4 - teste valor par entre intervalo [20:64]
1.5 01. ( OK ) exercicio 5 - teste valor entre intervalos [15:48] [33:75]
*/