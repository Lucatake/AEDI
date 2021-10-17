/**
    Metodo para testar todos os exercicios em um so' programa
    Exemplo06 - Versao 0.1 - 01/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo06      exemplo06.c
    Windows:    gcc -o exemplo06.exe  exemplo06.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo06
    Windows:    exemplo06
*/

//dependencias
//para definicoes proprias
#include "io.h"
//para metodos proprios
//#include "Luana.h"
//lista dos exercicios
#include "Exemplo0611.c"
#include "Exemplo0612.c"
#include "Exemplo0613.c"
#include "Exemplo0614.c"
#include "Exemplo0615.c"
#include "Exemplo0616.c"
#include "Exemplo0617.c"
#include "Exemplo0618.c"
#include "Exemplo0619.c"
#include "Exemplo0620.c"
#include "Exemplo06E1.c"
#include "Exemplo06E2.c"
//lista de funcoes
int menu(void);
void Parar( );
int quantidadesL(chars texto);

/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param e escolha do menu
*/
int main( int e )
{
    //identificar
    IO_id("\nESTUDO DIRIGIDO 06 - Programa - v0.1");
    //definir dado com valor inicial
    int x = 0;
    //repetir ate desejar parar
    do
    {
        //ler do teclado
        x = menu( );
        //testar valor
        //escolha do exercicio a ser executado
        switch (x)
        {
        case 0:
            Parar( );
            break;
        case 1:
            Exercicio0611( );
            break;
        case 2:
            Exercicio0612( );
            break;
        case 3:
            Exercicio0613( );
            break;
        case 4:
            Exercicio0614( );
            break;
        case 5:
            Exercicio0615( );
            break; 
        case 6:
            Exercicio0616( );
            break;
        case 7:
            Exercicio0617( );
            break;
        case 8:
            Exercicio0618( );
            break;
        case 9:
            Exercicio0619( );
            break;
        case 10:
            Exercicio0620( );
            break;
        case 11:
            Exercicio06E1( );
            break;
        case 12:
            Exercicio06E2( );
            break;
        default:
            IO_println("\nValor diferente das opcoes");
            break;
        }//end switch-case
    } while ( x!=0 ); //end do-while
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/**
 * Funcao menu de escolhas.
 * @return x opcao escolhida
*/
int menu(void)
{
    //definir variavel com valor inicial
    int e = 0;
    //mostrar as opcoes disponiveis
    IO_println("\nOpcoes:");
    IO_println(" 0 - Parar");
    IO_println(" 1 - Exercicio1  |  2 - Exercicio2  |  3 - Exercicio3");
    IO_println(" 4 - Exercicio4  |  5 - Exercicio5  |  6 - Exercicio6");
    IO_println(" 7 - Exercicio7  |  8 - Exercicio8  |  9 - Exercicio9");
    IO_println("10 - Exercicio10 | 11 - Extra01     | 12 - NULL Extra02");
    //ler do teclado
    e = IO_readint("\nEntrar com uma opcao: ");
    //retornat valor lido
    return (e);
}//end menu( )

/** 
 * Parar( ) - nao faz nada
*/
void Parar( )
{
    //nao faz nada
}//end Parar

/**
 * quantidadesL( ) - Funcao para testar se quantidade valida
 * @return quantidade - numero de vezes a testar
*/
int quantidadesL(chars texto)
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
}//end quantidadesL

/**
documentacao complementar || notas / observacoes / comentarios
previsao de testes ::: dentro de cada arquivo especifico do exercicio
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         01/10         esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  29/09  - impares crescentes comecando em 3
 1.2       01.   ( OK )  29/09  - multiplos de 5 decrescente encerrando em 5
 1.3       01.   ( OK )  29/09  - multiplos de 4 crescente com base 1
 1.4       01.   ( OK )  29/09  - inversos das potencias de 4 decrescente com base 1
 1.5       01.   ( OK )  29/09  - caractere de tras para frente de uma cadeia
 1.6       01.   ( OK )  29/09  - soma de 'n' valores pares positivos comecando em 2
 1.7       01.   ( OK )  29/09  - soma dos inversos dos valores pares positivos comecando em 2
 1.8       01.   ( OK )  29/09  - se termo 'n' de Fibonacci e' multiplo de 3
 1.9       01.   ( OK )  30/09  - contar digitos impares em uma cadeia de caracteres
 2.0       01.   ( OK )  30/09  - contar quantidade de maiusculas menores que N
 E.1       01.   ( OK )  03/10  - soma de 'n' termos 'x' elevado a pares (com 0 e 1)
 E.2       01.   ( OK )  03/10  - soma dos inversos de fatoriais de numeros impares
*/