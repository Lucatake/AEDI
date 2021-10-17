/**
 * Exemplo0515 - v0.1. - 23/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias
//#include "Luana.h"  //para metodos proprios

/**
 * potenciasI( ) - metodo para mostrar quantidade de valores 
 * inversos elevados a uma potencia x
 * @return valor  real 
 * @param quantidade - numero de vezes a repetir o procedimento
*/
double potenciasI(int quantidade)
{
    //definir variaveis com valor inicial
    double inverso = 0.0, potencia = 0.0, x = 0.0;
    int multiplo = 0;

    //ler do teclado
    x = IO_readdouble("Entre com um valor real: ");

    //repetir o numero de vezes pedido
    for (int i = 1; i <= quantidade; i++)
    {
        //calcular as potencias
        potencia = pow(x,multiplo);
        //calcular os inversos
        inverso = 1.0 / potencia;
        //mostrar o valor
        IO_printf("\n1/(%.4lf^%d) = 1/%.4lf = [%.4lf]", x, multiplo, potencia, inverso);
        //alterar o valor para um multiplo impar
        multiplo = (2 * i) - 1;
    }//end for
}//end  potenciasI( )

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
/*int main( )
{
    //identificar
    IO_id("EXEMPLO0515 - Programa - v0.1");
    //chamar metodos
    int quantidade = quantidades("\nQuantidade de valores a serem testados: ");
    potenciasI(quantidade);
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )*/

/**
---------------------------------------------- documentacao complementar
exercicio:
para ler um valor real real (x) do teclado;
para ler uma quantidade inteira do teclado e, mediante um metodo,
mostrar essa quantidade em valores crescentes nos denominadores
da sequência: 1 1/x 1/x3 1/x5 ...
DICA: Usar da biblioteca <math.h> a função pow ( x, y ) para calcular a potencia.
---------------------------------------------- notas / observacoes / comentarios
obs: limite de 4 casas decimais
---------------------------------------------- previsao de testes
a.) 10 
1/(1.2340^0) = 1/1.0000 = [1.0000]
1/(1.2340^1) = 1/1.2340 = [0.8104]
1/(1.2340^3) = 1/1.8791 = [0.5322]
1/(1.2340^5) = 1/2.8614 = [0.3495]
1/(1.2340^7) = 1/4.3572 = [0.2295]
1/(1.2340^9) = 1/6.6349 = [0.1507]
1/(1.2340^11) = 1/10.1034 = [0.0990]
1/(1.2340^13) = 1/15.3850 = [0.0650]
1/(1.2340^15) = 1/23.4276 = [0.0427]
1/(1.2340^17) = 1/35.6745 = [0.0280]
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         23/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  23/09  - mostrar certa quantidade de valores multiplos de 2 e 3
 1.2       01.   ( OK )  23/09  - mostrar certa quantidade de valores pares multiplos de 3
 1.3       01.   ( OK )  23/09  - mostrar certa quantidade de valores impares multiplos de 3
 1.4       01.   ( OK )  23/09  - mostrar certa quantidade de valores inversos multiplos de 4
 1.5       01.   ( OK )  23/09  - mostrar quantidade de valores inversos de x elevado a impares 
*/