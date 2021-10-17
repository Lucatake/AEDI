/*
    Exemplo0216 - Versao 0.1 - 26/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0216      exemplo0216.c
    Windows:    gcc -o exemplo0216.exe  exemplo0216.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0216
    Windows:    exemplo0216
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    valueIoP - funcao para testar se o primeiro valor
    e' impar e o segundo e' par
    @param ip1 e ip2 - valores a serem testados e exibidos
*/
void valueIoP ( int ip1, int ip2 )
{
    //definir dado
    int t1 = ip1, t2 = ip2;       //definir variaveis com valor inicial

    //testar os valores e mostrar os resultados
    if ( ip1 < 0)
    {
        //para resolver o problema dos numeros negativos impares
        t1 = ip1 * (-1);     
    }
    if ( ip2 < 0)
    {
        //para resolver o problema dos numeros negativos impares
        t2 = ip2 * (-1);     
    }

    //calculando o resto
    t1 = t1 % 2;
    t2 = t2 % 2;

    //testando as condicoes
    if ( (t1 == 1) && (t2 == 0) && (ip1 != 0) && (ip2 != 0) ) 
    {
        //se resto = 1 -> impar | se resto = 0 e valor != 0 -> par
        IO_printf("\nValor 01 - (%d) e' impar e valor 02 - (%d) e' par", ip1, ip2);
    } 
    else
    {
        //se nao, nenhum dos resultados possiveis
         IO_printf("\nValor 01 - (%d) e valor 02 - (%d) nao se encaixam na especificacao", ip1, ip2);
    }//end if
}//end valueIoP( )

/*
    Funcao principal.
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main( )
{
    //definir dado
    int ip1 = 0, ip2 = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0216 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com dois valores inteiros: ");
    scanf("%d %d", &ip1, &ip2);
    
    //testar valor e mostrar resultado
    valueIoP (ip1, ip2);
    
    
    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler dois valores inteiros do teclado e
dizer se o primeiro e impar e o segundo e par
---------------------------------------------- notas / observacoes / comentarios
0.1 
modificacao da funcao valueIoP ( )
---------------------------------------------- previsao de testes
a.) 1 2
b.) 2 1
c.) 0 1
d.) 1 0
e.) -101 -200
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
1.6 01. ( OK ) exercicio 6 - teste dois valores inteiros (impar e par)
*/