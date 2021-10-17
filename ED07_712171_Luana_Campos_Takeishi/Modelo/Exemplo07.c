/**
    Metodo para testar todos os exercicios em um so' programa
    Exemplo07 - Versao 0.1 - 01/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo07      exemplo07.c
    Windows:    gcc -o exemplo07.exe  exemplo07.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo07
    Windows:    exemplo07
*/

//dependencias
//para definicoes proprias
#include "io.h"
//para metodos proprios
//#include "Luana.h"
//lista dos exercicios
#include "Exemplo0711.c"
#include "Exemplo0712.c"
#include "Exemplo0713.c"
#include "Exemplo0714.c"
#include "Exemplo0715.c"
#include "Exemplo0716.c"
#include "Exemplo0717.c"
#include "Exemplo0718.c"
#include "Exemplo0719.c"
#include "Exemplo0720.c"
//#include "Exemplo07E1.c"
//#include "Exemplo07E2.c"
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
    IO_id("\nESTUDO DIRIGIDO 07 - Programa - v0.1");
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
            Exercicio0711( );
            break;
        case 2:
            Exercicio0712( );
            break;
        case 3:
            Exercicio0713( );
            break;
        case 4:
            Exercicio0714( );
            break;
        case 5:
            Exercicio0715( );
            break; 
        case 6:
            Exercicio0716( );
            break;
        case 7:
            Exercicio0717( );
            break;
        case 8:
            Exercicio0718( );
            break;
        case 9:
            Exercicio0719( );
            break;
        case 10:
            Exercicio0720( );
            break;
        case 11:
            //Exercicio07E1( );
            break;
        case 12:
            //Exercicio07E2( );
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
Exercicio Versao  Teste   Data    Descricao
 1.1       01.   ( OK )  07/10  - Gravar certa quantidade de pares multiplos de 3. (crescente)
 1.2       01.   ( OK )  07/10  - Gravar certa quantidade de impares multiplos de 3. (decrescente)
 1.3       01.   ( OK )  07/10  - Gravar certa quantidade de multiplos de 5. (crescente)
 1.4       01.   ( OK )  07/10  - Gravar certa quantidade divisoes de 1/7^n . (decrescente) 
 1.5       01.   ( OK )  07/10  - Gravar certa quantidade divisoes de 1/x^n . (crescente)
 1.6       01.   ( OK )  10/10  - Somar quantidade de valores (double) de um arquivo e gravar resultado em outro.
 1.7       01.   ( OK )  10/10  - Somar quantidade de valores (double) de um arquivo e gravar resultado em outro.
 1.8       01.   ( OK )  10/10  - Somar quantidade de valores (double) de Fibonacci e gravar em arquivo.
 1.9       01.   ( OK )  10/10  - Contar minusculas menores que n em cadeias de caracteres de um arquivo txt.
 2.0       01.   ( OK )  10/10  - Contar digitos maiores que 5 em cadeias de caracteres de um arquivo txt.
*/