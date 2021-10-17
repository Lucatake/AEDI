/*
    Exemplo02E2 - Versao 0.1 - 27/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo02E2      exemplo02E2.c
    Windows:    gcc -o exemplo02E2.exe  exemplo02E2.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo02E2
    Windows:    exemplo02E2
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    compABC - funcao para comparar tres valores literais
    @param a, b e c - valores de caracteres a serem testados e exibidos
*/
void compABC ( char a, char b, char c )
{
    //testar os valores e mostrar os resultados
    if ( (a != b) && (b != c) && (a != c) ) //se todos diferentes
    {
        if ( (b < c) && (! ((a > b) && (a < c))) ) //se a esta' fora de [b, c]
        {
            IO_printf("\n(%c) esta' fora do intervalo [%c, %c]", a, b, c);
        }
        else
        {
            if ( (b > c) && (! ((a < b) && (a > c))) ) //se a esta' fora de [c, b]
            {
                IO_printf("\n(%c) esta' fora do intervalo [%c, %c]", a, c, b);
            }
            else
            {
                IO_printf("\n(%c) (%c) (%c) sao diferentes e nao se encaixam na opcao", a, b, c);
            }//end if
        }//end if
    }//end if
    else
    {
        IO_printf("\n(%c) (%c) (%c) nao se encaixam na opcao", a, b, c);
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
    char a = '0', b = '0', c = '0';       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO02E2 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com tres valores literais: ");
    scanf("%c %c %c", &a, &b, &c);
    
    //testar valor e mostrar resultado
    compABC (a, b, c);
    
    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler tres valores literais (caracteres) do teclado e
dizer se o primeiro valor lido esta fora do intervalo definido pelos outros dois,
se todos forem diferentes entre si
OBS.: Notar que nao ha garantias de ser o segundo menor que o terceiro
---------------------------------------------- notas / observacoes / comentarios
0.1 
modificacao na funcao CompABC ( )
---------------------------------------------- previsao de testes
a.) a f o
b.) b a c
c.) a h c
d.) a = ?
e.) b a c
---------------------------------------------- historico
Versao   Data    Modificacao
 0.1     27/08     esboco
---------------------------------------------- testes
Versao Teste
1.1 03. ( OK ) exercicio 1        - teste valor impar ou par
1.2 01. ( OK ) exercicio 2        - teste valor impar ou par
1.3 01. ( OK ) exercicio 3        - teste valor entre intervalo ]20:64[
1.4 01. ( OK ) exercicio 4        - teste valor par entre intervalo [20:64]
1.5 01. ( OK ) exercicio 5        - teste valor entre intervalos [15:48] [33:75]
1.6 01. ( OK ) exercicio 6        - teste dois valores inteiros (impar e par)
1.7 01. ( OK ) exercicio 7        - teste dois valores inteiros (impar e par, positivo e negativo)
1.8 01. ( OK ) exercicio 8        - teste comparacao de dois valores reais
1.9 01. ( OK ) exercicio 9        - teste comparacao de tres valores reais
2.0 01. ( OK ) exercicio 10       - teste comparacao de tres valores reais (metade de um)
E.1 01. ( OK ) exercicio extra E1 - teste comparacao valor literal entre um intervalo
E.2 01. ( OK ) exercicio extra E2 - teste comparacao valor literal fora do intervalo
*/