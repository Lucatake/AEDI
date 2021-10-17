/**
    Metodo para testar todos os exercicios em um so' programa
    Exemplo08 - Versao 0.1 - 01/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo08      exemplo08.c
    Windows:    gcc -o exemplo08.exe  exemplo08.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo08
    Windows:    exemplo08
*/

//dependencias
//para definicoes proprias
#include "io.h"
//para metodos proprios
//#include "Luana.h"
//lista dos exercicios
#include "Exemplo0811.c"
#include "Exemplo0812.c"
#include "Exemplo0813.c"
#include "Exemplo0814.c"
//#include "Exemplo0815.c"
//#include "Exemplo0816.c"
//#include "Exemplo0817.c"
//#include "Exemplo0818.c"
//#include "Exemplo0819.c"
//#include "Exemplo0820.c"
//#include "Exemplo08E1.c"
//#include "Exemplo08E2.c"
//lista de funcoes
int menu(void);
void Parar( );
int quantidadesL(chars texto);
void id_cabecalho( chars fileName, chars id, chars versao );
void fprintIntArray(chars fileName, int n, int array[]);

/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param e escolha do menu
*/
int main( int e )
{
    //identificar
    IO_id("\nESTUDO DIRIGIDO 08 - Programa - v0.1");
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
            Exercicio0811( );
            break;
        case 2:
            Exercicio0812( );
            break;
        case 3:
            Exercicio0813( );
            break;
        case 4:
            Exercicio0814( );
            break;
        case 5:
            //Exercicio0815( );
            break; 
        case 6:
            //Exercicio0816( );
            break;
        case 7:
            //Exercicio0817( );
            break;
        case 8:
            //Exercicio0818( );
            break;
        case 9:
            //Exercicio0819( );
            break;
        case 10:
            //Exercicio0820( );
            break;
        case 11:
            //Exercicio08E1( );
            break;
        case 12:
            //Exercicio08E2( );
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
 * fprintIntArray - Gravar arranjo com valores inteiros.
 * @param fileName - nome do arquivo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
void fprintIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    int x = 0;
    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", n);
    // gravar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // gravar valor
        IO_fprintf(arquivo, "%d\n", array[x]);
    } // fim repetir
    // fechar arquivo
    fclose(arquivo);
} // fprintIntArray ( )

/**
 * freadArraySize - Ler tamanho do arranjo com valores inteiros.
 * @return quantidade de valores lidos
 * @param fileName - nome do arquivo
*/
int freadArraySize(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // fim se
    // retornar dado lido
    return (n);
} // freadArraySize ( )

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
OBS: erro no fprintIntArray, estão sendo gravados "lixos"
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         01/10         esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao 1.1      
 01.   ( OK )  15/10  - Montar array do teclado com int positivos pares.
 02.   ( OK )  19/10  - Gravar int positivos pares de um array misto.
 03.   ( OK )  20/10  - Gravar um arranjo de numeros int aleatorios a partir de um intervalo.
*/