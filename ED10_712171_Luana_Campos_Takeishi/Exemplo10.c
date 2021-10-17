/**
    Metodo para testar todos os exercicios em um so' programa
    Exemplo10 - Versao 0.1 - 28/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo10      exemplo10.c
    Windows:    gcc -o exemplo10.exe  exemplo10.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo10
    Windows:    exemplo10
*/

//dependencias
//para definicoes proprias
#include "io.h"
#include "Array.h"
//para metodos proprios
#include "Luana.h"
//lista dos exercicios
#include "Exemplo1011.c"
#include "Exemplo1012.c"
#include "Exemplo1013.c"
#include "Exemplo1014.c"
#include "Exemplo1015.c"
#include "Exemplo1016.c"
#include "Exemplo1017.c"
#include "Exemplo1018.c"
#include "Exemplo1019.c"
#include "Exemplo1020.c"
//#include "Exemplo10E1.c"
//#include "Exemplo10E2.c"
//lista de funcoes
int menu(void);
//void Parar( );
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
    IO_id("\nESTUDO DIRIGIDO 10 - Programa - v0.1");
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
            Exercicio1011( );
            break;
        case 2:
            Exercicio1012( );
            break;
        case 3:
            Exercicio1013( );
            break;
        case 4:
            Exercicio1014( );
            break;
        case 5:
            Exercicio1015( );
            break; 
        case 6:
            Exercicio1016( );
            break;
        case 7:
            Exercicio1017( );
            break;
        case 8:
            Exercicio1018( );
            break;
        case 9:
            Exercicio1019( );
            break;
        case 10:
            Exercicio1020( );
            break;
        case 11:
            //Exercicio10E1( );
            break;
        case 12:
            //Exercicio10E2( );
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
0.1         28/10         esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao 1.1      
  1.1       01.   ( OK )  28/10  - Gravar array de numeros aleatorios em arquivo.
  1.2       01.   ( OK )  28/10  - Procurar valor em arranjo.
  1.3       01.   ( OK )  29/10  - Comparar arranjos.
  1.4       01.   ( OK )  29/10  - Somar dois arranjos e um deles multiplicado por constante.
  1.5       01.   ( OK )  29/10  - Verificar se arranjo esta ordenado decrescente.
  1.6       01.   ( OK )  29/10  - Verificar se matrizes sao transpostas.
  1.7       01.   ( OK )  29/10  - Verificar se matrizes sao zeros.
  1.8       01.   ( OK )  30/10  - Verificar se matrizes sao diferentes.
  1.9       01.   ( OK )  30/10  - Somar matrizes multiplicadas por uma constante.
  2.0       01.   ( OK )  30/10  - Multiplicar duas matrizes. 
*/