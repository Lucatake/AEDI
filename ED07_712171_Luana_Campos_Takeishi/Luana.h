
/**
 * IO_lib - v0.1 - 23/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * Parar( ) - nao faz nada
*/
void Parar( )
{
    //nao faz nada
}//end Parar

/**
 * quantidade( ) - Metodo para testar se quantidade valida
 * @return quantidade - numero de vezes a testar
*/
int quantidades(chars texto)
{
    //definir dados com valor inicial
    int quantidade = 0, x = 0;

    do{
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint(texto);
        //testar se maior que zero
        if ( quantidade > 0 )
        {
            //se sim, sair do procedimento
            x = 1;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Valor invalido.");
            //e repetir o procedimento
            x = 0;
        }//end if
    } while ( x == 0 );

    //retornar quantidade de vezes a ser repetido
    return(quantidade);
}//end quantidade

/**
 * multiplos( ) - metodo para mostrar quantidade de valores multiplos de N
 * @return valor inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
 * @param multiplo - numero a ser o multiplo
 * @param modelo - para inverso (i) ou nao (m)
*/
int multiplos(int quantidade, int multiplo, char c)
{
    //definir variaveis com valor inicial
    int valor = 0;
    double inverso = 0.0;
    char v = '0';

    //se a opcao escolhida for multiplo
    if ( v == 'm' )
    {
        //repetir o numero de vezes pedido
        for (int i = 0; i < quantidade; i++)
        {
            //alterar o valor para um multiplo
            valor = multiplo * i;
            //mostrar o valor
            IO_printf("\n[%d]", valor);
        }//end for
    }
    else
    {   
        //se a opcao escolhida for multiplo inverso
        if ( v == 'i' )
        {
            //repetir o numero de vezes pedido
            for (int i = 1; i <= quantidade; i++)
            {
                //alterar o valor para um multiplo
                valor = i * 4;
                //calcular os inversos
                inverso = 1.0 / valor;
                //mostrar o valor
                IO_printf("\n1/%d = [%lf]", valor, inverso);
            }//end for
        }
        else    //se opcoes invalidas
        {
            IO_println("Entrada de opcoes invalida.");
        }//end if
    }//enf if
        

    
    
}//end multiplos( )
