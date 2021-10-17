/*
    Exemplo0212 - Versao 0.1 - 26/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0212      exemplo0212.c
    Windows:    gcc -o exemplo0212.exe  exemplo0212.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0212
    Windows:    exemplo0212
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    valueIoP - funcao paraa testar se um valor par ou impar
    @param ip - valor a ser testado e exibido
*/
void valueIoP ( int ip )
{
    //definir dado
    int o = ip;       //definir variavel com valor inicial

    //testar o valor e mostrar os resultados
    if (o < 0)
    {
        //para resolver o problema dos numeros negativos impares
        o = ip * (-1);     
    }
    if ((o % 2) == 1) 
    {
        if (ip < 100)       //impar
        {
            //se resto = 1 -> impar, para valor < 100
            IO_printf("\nValor (%d) e' impar e menor que 100", ip);
        }
        else
        {
            //se resto = 1 -> impar, para valor > 100
            IO_printf("\nValor (%d) impar nao esta' entre os numeros definidos", ip);
        }//end if
        
    } 
    else
    {
        if (o != 0)
        {
            if (ip > (-100))    //par
            {
                //se resto = 0 e valor != 0 -> par, para valor > -100
                IO_printf("\nValor (%d) e' par e maior que -100", ip);
            }
            else
            {
                //se resto = 0 e valor != 0 -> par, para valor < -100
                IO_printf("\nValor (%d) par nao esta' entre os numeros definidos", ip);
            }//end if
            
        }
        else                    //nulo
        {
            //se valor = 0 -> nenhuma das opcoes
            IO_printf("\nValor (%d) e' nao e' par nem impar", ip);
        }//end if
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
    int ip = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0212 - Programa - v0.1");
    
    //ler do teclado
    ip = IO_readint ("\nEntrar com um valor inteiro: ");
    
    //testar valor e mostrar resultado
    valueIoP( ip );
    
    
    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler um valor inteiro do teclado e
- dizer se e' par e maior que -100, ou impar e menor que 100
---------------------------------------------- notas / observacoes / comentarios
0.1 
mudanca na funcao valueIoP da questao anterior
---------------------------------------------- previsao de testes
a.) 0
b.) -50
c.) 200
d.) -151
e.) 51
f.) -200
g.) 151
---------------------------------------------- historico
Versao   Data    Modificacao
 0.1     26/08     esboco
---------------------------------------------- testes
Versao Teste
1.1 03. ( OK ) exercicio 1 - teste valor impar ou par
1.2 01. ( OK ) exercicio 2 - teste valor impar ou par
*/