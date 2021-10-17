/**
    Metodo para testar todos os exercicios em um so' programa
    Exemplo05 - Versao 0.1 - 24/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo05      exemplo05.c
    Windows:    gcc -o exemplo05.exe  exemplo05.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo05
    Windows:    exemplo05
*/

//dependencias
//para definicoes proprias
#include "io.h"
//para metodos proprios
//#include "Luana.h"
//lista dos exercicios
#include "Exemplo0511.c"
#include "Exemplo0512.c"
#include "Exemplo0513.c"
#include "Exemplo0514.c"
#include "Exemplo0515.c"
#include "Exemplo0516.c"
#include "Exemplo0517.c"
#include "Exemplo0518.c"
#include "Exemplo0519.c"
#include "Exemplo0520.c"
#include "Exemplo05E1.c"
#include "Exemplo05E2.c"
//lista de funcoes
int menu(void);
void Parar( );
int quantidades(chars texto);

/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param e escolha do menu
*/
int main( int e )
{
    //identificar
    IO_id("\nESTUDO DIRIGIDO 05 - Programa - v0.1");

    //definir dado com valor inicial
    int x = 0, quantidade = 0;

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
            //identificar
            IO_id("\nEXEMPLO0511 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            multiplo2e3( quantidade );
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        case 2:
            //identificar
            IO_id("\nEXEMPLO0512 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            paresM3( quantidade );
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        case 3:
            //identificar
            IO_id("\nEXEMPLO0513 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            imparesM3( quantidade );
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;
            
        case 4:
            //identificar
            IO_id("\nEXEMPLO0514 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            inversosM4( quantidade );
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;
            
        case 5:
            //identificar
            IO_id("\nEXEMPLO0515 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            potenciasI(quantidade);
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;
            
        case 6:
            //identificar
            IO_id("\nEXEMPLO0516 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            somaInaoM7(quantidade);
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        case 7:
            //identificar
            IO_id("\nEXEMPLO0517 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            somaIParNM5(quantidade);
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        case 8:
            //identificar
            IO_id("\nEXEMPLO0518 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            somaNat(quantidade);
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        case 9:
            //identificar
            IO_id("\nEXEMPLO0519 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            somaQuad(quantidade);
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        case 10:
            //identificar
            IO_id("\nEXEMPLO0520 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de valores a serem testados: ");
            somaInvNat(quantidade);
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        case 11:
            //identificar
            IO_id("\nEXEMPLO05E1 - Programa - v0.1");
            //chamar metodos
            fatorial( );
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        case 12:
            //identificar
            IO_id("\nEXEMPLO05E2 - Programa - v0.1");
            //chamar metodos
            quantidade = quantidades("\nQuantidade de repeticoes: ");
            somaFn(quantidade);
            //encerrar
            IO_pause("\nApertar ENTER para continuar");
            break;

        default:
            //encerrar
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
    IO_println(" 1 - Exercicio1(EXEMPLO0511)  |  2 - Exercicio2(EXEMPLO0512) |  3 - Exercicio3(EXEMPLO0513)");
    IO_println(" 4 - Exercicio4(EXEMPLO0514)  |  5 - Exercicio5(EXEMPLO0515) |  6 - Exercicio6(EXEMPLO0516)");
    IO_println(" 7 - Exercicio7(EXEMPLO0517)  |  8 - Exercicio8(EXEMPLO0518) |  9 - Exercicio9(EXEMPLO0519)");
    IO_println("10 - Exercicio10(EXEMPLO0520) | 11 - Extra01(EXEMPLO05E1)    | 12 - Extra02(EXEMPLO05E2)");
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
 * quantidades( ) - Metodo para testar se quantidade valida
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
}//end quantidades( )

/**
documentacao complementar || notas / observacoes / comentarios
previsao de testes ::: dentro de cada arquivo especifico do exercicio
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         24/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.1       01.   ( OK )  23/09  - mostrar certa quantidade de valores multiplos de 2 e 3
 1.2       01.   ( OK )  23/09  - mostrar certa quantidade de valores pares multiplos de 3
 1.3       01.   ( OK )  23/09  - mostrar certa quantidade de valores impares multiplos de 3
 1.4       01.   ( OK )  23/09  - mostrar certa quantidade de valores inversos multiplos de 4
 1.5       01.   ( OK )  23/09  - mostrar quantidade de valores inversos de x elevado a impares 
 1.6       01.   ( OK )  24/09  - mostrar a soma de valores impares* nao multiplos de 7
 1.7       01.   ( OK )  24/09  - mostrar a soma de valores pares* nao multiplos de 5
 1.8       01.   ( OK )  24/09  - mostrar a soma dos primeiros numeros naturais
 1.9       01.   ( OK )  24/09  - mostrar a soma do quadrado dos primeiros numeros naturais
 2.0       01.   ( OK )  24/09  - mostrar a soma dos inversos dos primeiros numeros naturais
 E.1       01.   ( OK )  24/09  - mostrar o fatorial de um valor inteiro
 E.2       02.   ( OK )  24/09  - mostrar a soma de 1 com impares divididos por fatoriais pares
*/