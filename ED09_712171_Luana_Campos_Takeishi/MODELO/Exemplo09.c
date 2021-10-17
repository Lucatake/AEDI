/**
    Metodo para testar todos os exercicios em um so' programa
    Exemplo09 - Versao 0.1 - 01/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo09      exemplo09.c
    Windows:    gcc -o exemplo09.exe  exemplo09.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo09
    Windows:    exemplo09
*/

//dependencias6
//para definicoes proprias
#include "io.h"
//para metodos proprios
//#include "Luana.h"
//lista dos exercicios
#include "Exemplo0911.c"
#include "Exemplo0912.c"
#include "Exemplo0913.c"
#include "Exemplo0914.c"
#include "Exemplo0915.c"
#include "Exemplo0916.c"
#include "Exemplo0917.c"
#include "Exemplo0918.c"
#include "Exemplo0919.c"
#include "Exemplo0920.c"
//#include "Exemplo09E1.c"
//#include "Exemplo09E2.c"
//lista de funcoes
int menu(void);
void Parar( );
int quantidadesL(chars texto);
void id_cabecalho( chars fileName, chars id, chars versao );

/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param e escolha do menu
*/
int main( int e )
{
    //identificar
    IO_id("\nESTUDO DIRIGIDO 09 - Programa - v0.1");
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
            Exercicio0911( );
            break;
        case 2:
            Exercicio0912( );
            break;
        case 3:
            Exercicio0913( );
            break;
        case 4:
            Exercicio0914( );
            break;
        case 5:
            Exercicio0915( );
            break; 
        case 6:
            Exercicio0916( );
            break;
        case 7:
            Exercicio0917( );
            break;
        case 8:
            Exercicio0918( );
            break;
        case 9:
            Exercicio0919( );
            break;
        case 10:
            Exercicio0920( );
            break;
        case 11:
            //Exercicio09E1( );
            break;
        case 12:
            //Exercicio09E2( );
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
    IO_println("10 - Exercicio10 | 11 - Extra01     | 12 - Extra02");
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
 * id_cabecalho para arquivos externos.
 * @param fileName - nome do arquivo
 * @param id - identificacao do programa (exemplo)
 * @param versao - versao, data 
*/
void id_cabecalho( chars fileName, chars id, chars versao )
{
  //definir dados
    FILE *arquivo = fopen(fileName, "wt");
  //gravar dados
   //nome
    IO_fprintf(arquivo, "Luana Campos Takeishi \t Matricula: 712171\n");
   //arquivo
    IO_fprintf(arquivo, "Exemplo%s\n", id);
   //versao
    IO_fprintf(arquivo, "Versao: %s\n", versao);
   //
    IO_fprintf(arquivo, "\n");
   //fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
}//end id_cabecalho

/**
documentacao complementar || notas / observacoes / comentarios
previsao de testes ::: dentro de cada arquivo especifico do exercicio
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         01/10         esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao 1.1      
  01.     ( OK )  23/10  - Montar matrix de real do teclado.
  02.     ( OK )  23/10  - Gravar matriz real do teclado.
  03.     ( OK )  23/10  - Mostrar diagonal principal valores pares.
  04.     ( OK )  23/10  - Mostrar diagonal secundaria valores impares.
  05.     ( OK )  24/10  - testar se triangulo inferior a diagonal principal sao multiplos de 3.
  06.     ( OK )  24/10  - testar se triangulo superior a diagonal principal sao multiplos de 5.
  07.     ( OK )  24/10  - triangulo inferior a diagonal secundaria com multiplos de 3 impares.
  08.     ( OK )  24/10  - triangulo inferior a diagonal secundaria com multiplos de 5 pares.
  09.     ( OK )  24/10  - testar se triangulo inferior a diagonal principal nao sao 0.
  10.     ( OK )  24/10  - testar se triangulo superior a diagonal principal so tem 0.
*/