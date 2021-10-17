/*
    Exemplo0220 - Versao 0.1 - 27/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0220      exemplo0220.c
    Windows:    gcc -o exemplo0220.exe  exemplo0220.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0220
    Windows:    exemplo0220
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    compABC - funcao para comparar tres valores reais
    @param a, b e c - valores a serem testados e exibidos
*/
void compABC ( double a, double b, double c )
{
    //definicao de variavel
    double d = a / 2;      //definindo a metade do valor

    //testar os valores e mostrar os resultados
    if ( (d != b) && (b != c) && (d != c) )     //se todos diferentes
    {
        if ( (d>b) && (d<c) )   //se d esta' entre b e c (BAC)
        {
            IO_printf("\n(%lf) < (%lf) < (%lf)", b, d, c);
        }
        else
        {
            IO_printf("\n(%lf) (metade de (%lf)), (%lf) e (%lf) nao se encaixam na opcao", d, a, b, c);
        }        
    } 
    else
    {
        IO_printf("\n(%lf) (metade de (%lf)), (%lf) e (%lf) sao iguais", d, a, b, c);
    }//end if
}//end CompABC( )

/*
    Funcao principal.
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main( )
{
    //definir dado
    double a = 0.0, b = 0.0, c = 0.0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0220 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com tres valores reais: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    //testar valor e mostrar resultado
    compABC (a, b, c);
    
    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler tres valores reais do teclado e
dizer se a metade do primeiro nao esta entre os outros dois, 
quando forem diferentes entre si
---------------------------------------------- notas / observacoes / comentarios
0.1 
modificacao na funcao CompABC ( )
---------------------------------------------- previsao de testes
a.) 10.53     3.45     12.87
b.) 2.21    9.12     -1.38
c.) -13.4   -6.7     -6.7
d.) -12.8   -24.34   14.6
---------------------------------------------- historico
Versao   Data    Modificacao
 0.1     27/08     esboco
---------------------------------------------- testes
Versao Teste
1.1 03. ( OK ) exercicio 1  - teste valor impar ou par
1.2 01. ( OK ) exercicio 2  - teste valor impar ou par
1.3 01. ( OK ) exercicio 3  - teste valor entre intervalo ]20:64[
1.4 01. ( OK ) exercicio 4  - teste valor par entre intervalo [20:64]
1.5 01. ( OK ) exercicio 5  - teste valor entre intervalos [15:48] [33:75]
1.6 01. ( OK ) exercicio 6  - teste dois valores inteiros (impar e par)
1.7 01. ( OK ) exercicio 7  - teste dois valores inteiros (impar e par, positivo e negativo)
1.8 01. ( OK ) exercicio 8  - teste comparacao de dois valores reais
1.9 01. ( OK ) exercicio 9  - teste comparacao de tres valores reais
2.0 01. ( OK ) exercicio 10 - teste comparacao de tres valores reais (metade de um)
*/