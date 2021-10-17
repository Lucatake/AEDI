/*
    Exemplo0218 - Versao 0.1 - 27/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0218      exemplo0218.c
    Windows:    gcc -o exemplo0218.exe  exemplo0218.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0218
    Windows:    exemplo0218
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    compAB - funcao para comparar dois valores reais
    @param a e b - valores a serem testados e exibidos
*/
void compAB ( double a, double b )
{
    //definir dado
    double d = 0.0;       //definir variavel com valor inicial

    //testar os valores e mostrar os resultados
    //calculando o dobro
    d = a * 2;

    //testando as condicoes
    if ( d > b ) 
    {
        //se o dobro maior que
        IO_printf("\n(%lf) dobro do valor (%lf) e' MAIOR que (%lf)", d, a, b);
    } 
    else
    {
        if ( d < b ) 
        {
            //se o dobro menor que
            IO_printf("\n(%lf) dobro do valor (%lf) e' MENOR que (%lf)", d, a, b);
        } 
        else
        {
            if ( d == b ) 
            {
                //se o dobro igual a
                IO_printf("\n(%lf) dobro do valor (%lf) e' IGUAL a (%lf)", d, a, b);
            }//end if
        }//end if
    }//end if
}//end CompAB( )

/*
    Funcao principal.
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main( )
{
    //definir dado
    double a = 0.0, b = 0.0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0218 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com dois valores reais: ");
    scanf("%lf %lf", &a, &b);
    
    //testar valor e mostrar resultado
    compAB (a, b);
    
    
    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler dois valores reais do teclado e
dizer se o dobro do primeiro e maior, menor ou igual ao segundo
---------------------------------------------- notas / observacoes / comentarios
0.1 
funcao CompAB ( )
obs: com float, os valores reais com mais casas decimais, (exemplo b. e.)
 ao serem apresentados, completam as casas vazias com outros valores
 está adicionando ou retirando 0.000001 dos valores
0.2
modificacao: com double o problema do float foi resolvido
---------------------------------------------- previsao de testes
a.) 22.5     45.0
b.) 25.234   55.898
c.) 20.78    20.1
d.) 10.6     10.6
e.) 44.9825  89.965
---------------------------------------------- historico
Versao   Data    Modificacao
 0.1     27/08     esboco
---------------------------------------------- testes
Versao Teste
1.1 03. ( OK ) exercicio 1 - teste valor impar ou par
1.2 01. ( OK ) exercicio 2 - teste valor impar ou par
1.3 01. ( OK ) exercicio 3 - teste valor entre intervalo ]20:64[
1.4 01. ( OK ) exercicio 4 - teste valor par entre intervalo [20:64]
1.5 01. ( OK ) exercicio 5 - teste valor entre intervalos [15:48] [33:75]
1.6 01. ( OK ) exercicio 6 - teste dois valores inteiros (impar e par)
1.7 01. ( OK ) exercicio 7 - teste dois valores inteiros (impar e par, positivo e negativo)
1.8 01. ( OK ) exercicio 8 - teste comparacao de dois valores reais
*/