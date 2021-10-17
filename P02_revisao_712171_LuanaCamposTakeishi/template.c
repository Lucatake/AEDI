/**
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico 02 Reavaliação
  *
  * Autor    : Luana Campos Takeishi
  * Matricula: 712171
  *
  * Instrucoes:
  *
  * 1. Alterar APENAS o nome e a matricula em main( ).
  *
  * 2. Desenvolver cada questao como um metodo.
  *
  * 3. O uso da biblioteca io.h e' opcional,
  *    mas se for usar outra, enviar o arquivo correspondente.
  *
  * 4. Comentarios deverao ser usados para informar
  *    sobre escolhas, restricoes, limites de uso
  *    no projeto de algoritmos.
  *
  * 5. Testes e valores usados para verificar a
  *    correcao de cada metodo deverao ser informados
  *    ao final do programa, como comentarios.
  *
  * 4. Para compilar e testar:
  *
  *    mk template inputs_001.txt outputs_001.txt
  *
  */

// ---------------------------------------------- classes nativas
//                                                ou auxiliares

#include "io.h"     // se na mesma pasta

// ---------------------------------------------- definicao de classe

/**
  * Modelo para definir exemplo de um programa.
  * Obs.: E' recomendado ter o nome do programa
  *       sem espacos em branco, acentos ou cedilha.
  */

// ---------------------------------------------- tratamento de erro

// ---------------------------------------------- definicao de constantes

// ---------------------------------------------- definicao de armazenadores globais

// ---------------------------------------------- definicao de prototipos

// ---------------------------------------------- definicao de metodos
// ---------------------------------------------- metodo 01
/**
 * ler_arranjo - funcao para ler dados de arquivo e retornar tamanho.
 * @param nomeArquivo - nome do arquivo
 * @param arranjo - dados
*/
int ler_arranjo ( char nomeArquivo[ ], int arranjo[ ] )
{
   //para conferencia de dados
      IO_printf("ARRANJO: \n");
//definir dados locais
   int n = 0;
   int i = 0;
   int valor = 0;
   FILE *arquivo = fopen(nomeArquivo, "rt");
//ler a quantidade de dados
   IO_fscanf(arquivo, "%d", &n);
   if (n <= 0)
   {
      IO_println("ERRO: Valor invalido.");
      n = 0;
   } else
   {
   //ler e guardar valores em arranjo
      i = 0;
      while (!feof(arquivo) && i < n)
      {
      //ler valor
         IO_fscanf(arquivo, "%d", &valor);
      //guardar valor
         arranjo[i] = valor;
         //para conferencia de dados
         IO_printf("%d ", arranjo[i]);
      //passar ao proximo
         i++;
      }//end while
   }//end if
   IO_printf("\n");
//retornar tamando array
   return (n);
}//end ler_arranjo( )

/**
 * gravar_arranjo - metodo para gravar arranjo em arquivo.
 * @param nomeArquivo - nome do arquivo
 * @param n - tamanho do arranjo
 * @param arranjo - dados
*/
void gravar_arranjo ( char nomeArquivo[ ], int n, int arranjo[ ] )
{
   //para conferencia de dados
      IO_printf("ARRANJO INTERCALADO:\n");
//definir dados locais
   FILE *arquivo = fopen(nomeArquivo, "wt");
//gravar quantidade de dados
   IO_fprintf(arquivo, "%d\n", n);
//gravar valores no arranjo
   for ( int i = 0; i < n; i++ )
   {
   //gravar valor
      IO_fprintf(arquivo, "%d\n", arranjo[i]);
      //para conferencia de dados
      IO_printf("%d ", arranjo[i]);
   }//end for
   IO_printf("\n");
//fechar arquivo
   fclose(arquivo);
}//end gravar_arranjo( )

/**
 * intercalar - funcao para intercalar dois arranjos.
 * considera arranjos com tamanhos diferentes;
 * o menor valor em posicoes similares sempre vem primeiro;
 * valores iguais em posicoes similares sao guardados apenas uma vez.
 * @param arranjo3 - arranjo intercalado (arranjos 1 e 2)
 * @param n1 - tamanho dos dados do arranjo 1
 * @param arranjo1 - dados 1
 * @param n2 - tamanho dos dados do arranjo 2
 * @param arranjo2 - dados 2
*/
int intercalar ( int arranjo3[ ], int n1, int arranjo1[ ], int n2, int arranjo2[ ] )
{
//definir dados locais
   int n3 = 0;
   int i = 0;
   int tot = 0;
//testar a existencia de dados
   if (n1 != 0 && n2 != 0)
   {
   //definir tamanho
      if (n1 >= n2)
      {
         tot = n1;
      } else
      {
         tot = n2;
      }//end if
   } else
   {
      IO_printf("\n arranjos sem dados.");
   }//end if
//varrer arranjo
   while( i < tot )
   {
   //gravar menor valor ou apenas um no arranjo3
      if (arranjo1[i] > arranjo2[i])
      {
         arranjo3[n3] = arranjo2[i];
         arranjo3[n3+1] = arranjo1[i];
         n3 = n3 + 2;
         i++;
      }
      else if (arranjo1[i] < arranjo2[i])
      {
         arranjo3[n3] = arranjo1[i];
         arranjo3[n3+1] = arranjo2[i];
         n3 = n3 + 2;
         i++;
      }
      else if (arranjo1[i] == arranjo2[i])
      {
         arranjo3[n3] = arranjo2[i];
         n3++;
         i++;
      }//end if
   }//end for
//retornar valor tamanho do arranjo3 
   if ( n1 != n2 )
   {
      n3 = n3 - 1;
   }//end if
   return ( n3 );
}//end intercalar( )

/**
  * Metodo01 - chamar funcoes para ler de arquivo arranjos
  * intercala-los e salvar em arquivo.
  */
void metodo01 ( )
{
//definir dados
   int n1 = 0;
   int n2 = 0;
   int n3 = 0;
   int arranjo1[ STR_SIZE ];
   int arranjo2[ STR_SIZE ];
   int arranjo3[ STR_SIZE ];
//identificar
   IO_println ( "\nMetodo01" );
//ler um arranjo de arquivo
   n1 = ler_arranjo ( "A1.txt", arranjo1 );
//ler outro arranjo de arquivo
   n2 = ler_arranjo ( "A2.txt", arranjo2 );
//intercalar arranjos
   n3 = intercalar  ( arranjo3, n1, arranjo1, n2, arranjo2 );
//gravar arranjo em arquivo
   gravar_arranjo   ( "A3.txt", n3, arranjo3 );
}//end metodo01 ( )

// ---------------------------------------------- metodo 02
/**
 * separarNomes - metodo para separar prenome de sobrenomes
 * @param nomeArquivo1 - prenomes
 * @param nomeArquivo2 - sobrenomes
 * @param nomeArquivo3 - nomes
*/
void separarNomes ( char nomeArquivo1[ ], char nomeArquivo2[ ], char nomeArquivo3[ ] )
{
//definir dados locais
   int n = 0;
   FILE *arquivo3 = fopen(nomeArquivo3, "rt");
   FILE *arquivo2 = fopen(nomeArquivo2, "wt");
   FILE *arquivo1 = fopen(nomeArquivo1, "wt");
   chars nome;
   int pre = 0;
//ler a quantidade de dados
   IO_fscanf(arquivo3, "%d", &n);
//testar a existencia de dados
   if (n != 0)
   {
   //ler dados
      for (int i = 0; i < n; i++)
      {
         //ler nome completo
         IO_fscanf(arquivo3, "%d", &n);
         nome = IO_freadln(arquivo3);
         //gravar nome e sobrenome
         IO_printf("PRENOME:\n");
         for (int j = 0; j <= strlen(nome); j++)
         {
            if (pre == 0)
            {
               IO_fprintf(arquivo1, "%c", nome[j]);
               IO_printf("%c", nome[j]);
            } else
            {
               IO_fprintf(arquivo2, "%c", nome[j]);
               IO_printf("%c", nome[j]);
            }
         //passar para o sobrenomw
            if ((nome[j]== ' ') && pre == 0)
            {
               pre = 1;
               IO_printf("\nSOBRENOME:\n");
            }//end if
         }
         //proximo
         pre = 0;
         IO_fprintf(arquivo1, "\n");
         IO_fprintf(arquivo2, "\n");
         IO_printf("\n");
         IO_printf("\n");
      } //end for
   } else
   {
      IO_printf("\n dados inexistentes.");
   }//end if
}//end separarNomes

/**
  * Metodo02 - chamar metodos para gravar em arquivos separados os
  * prenomes e sobrenomes a partir de um nome.
*/
void metodo02 ( )
{
//identificar
   IO_println ( "\nMetodo02" );
//separar nomes e sobrenomes
   separarNomes ( "PRENOMES.txt", "SOBRENOMES.txt", "NOMES.txt" );
}//end metodo02 ( )

// ---------------------------------------------- metodo 03

/**
 * ler_matrizLinhas - ler quantidade de linhas da matriz
 * @return quantidade de linhas da matriz
 * @param nomeArquivo - nome do arquivo
*/
int ler_matrizLinhas(char nomeArquivo[ ])
{
//definir dados locais
   int linhas = 0;
   FILE *arquivo = fopen(nomeArquivo, "rt");
   ints array = NULL;
//ler a quantidade de dados
   IO_fscanf(arquivo, "%d", &linhas);
   if (linhas <= 0)
   {
      IO_println("ERRO: Valor invalido.");
      linhas = 0;
   }//end if
//retornar linhas
   return (linhas);
}//end ler_matrizLinhas( )

/**
 * ler_matrizColunas - ler quantidade de colunas da matriz
 * @return quantidade de colunas da matriz
 * @param nomeArquivo - nome do arquivo
*/
int ler_matrizColunas(char nomeArquivo[ ])
{
//definir dados locais
   int colunas = 0;
   FILE *arquivo = fopen(nomeArquivo, "rt");
//ler a quantidade de dados
   IO_fscanf(arquivo, "%d", &colunas);
   IO_fscanf(arquivo, "%d", &colunas);
   if (colunas <= 0)
   {
      IO_println("ERRO: Valor invalido.");
      colunas = 0;
   }//end if
//retornar colunas
   return (colunas);
}//end ler_matrizColunas( )

/**
 * ler_matriz - metodo para ler matriz de arquivo.
 * @param nomeArquivo - nome do arquivo
 * @param linhas - quantidade de linhas
 * @param colunas - quantidade de colunas
 * @param matriz - dados
*/
void ler_matriz ( char nomeArquivo[ ], 
                  int linhas, int colunas,
                  int matriz [ ][ colunas ] )
{
   //conferir dados
         IO_printf("MATRIZ LIDA:\n");
//definir dados locais
   int i = 0;
   int j = 0;
   int valor = 0;
   FILE *arquivo = fopen(nomeArquivo, "rt");
//ler a quantidade de dados
   IO_fscanf(arquivo, "%d", &i);
   IO_fscanf(arquivo, "%d", &j);
   if (linhas <= 0 || linhas > i ||
       colunas <= 0 || colunas > j)
   {
      IO_println("ERRO: Valor invalido.");
   }
   else
   {
   //ler e guardar valores em arranjo
      i = 0;
      while (!feof(arquivo) && i < linhas)
      {
         j = 0;
         while (!feof(arquivo) && j < colunas)
         {
         //ler valor
            IO_fscanf(arquivo, "%d", &valor);
         //guardar valor
            matriz[i][j] = valor;
            //conferir dados
            IO_printf("%d\t", matriz[i][j]);
         //passar ao proximo
            j++;
         }//end while
         IO_printf("\n");
      //passar ao proximo
         i++;
      }//end while
   }//end if
}//end ler_matrix( )

/**
 * grava_matriz - metodo para gravar matriz em arquivo.
 * @param nomeArquivo - nome do arquivo
 * @param linhas - quantidade de linhas
 * @param colunas - quantidade de colunas
 * @param matriz - dados
*/
void gravar_matriz ( char nomeArquivo[ ],
                     int linhas, int colunas,
                     int matriz [ ][ colunas ] )
{
   //conferir dados
         IO_printf("MATRIZ REORGANIZADA:\n");
//definir dados locais
   FILE *arquivo = fopen(nomeArquivo, "wt");
//gravar quantidade de dados
   IO_fprintf(arquivo, "%d\n", linhas);
   IO_fprintf(arquivo, "%d\n", colunas);
//gravar valores no arquivo
   for (int i = 0; i < linhas; i++)
   {
      for (int j = 0; j < colunas; j++)
      {
      //gravar valor
         IO_fprintf(arquivo, "%d\n", matriz[i][j]);
         //conferir dados
         IO_printf("%d\t", matriz[i][j]);
      }//end for
         IO_printf("\n");
   }//end for
//fechar arquivo
   fclose(arquivo);
}//end gravar-matriz( )

void menorSomaPrimeiro ( int linhas, int colunas, 
                         int matriz [ ][ colunas ] )
{
//definir dados locais
   int soma[colunas];
   int valor = 0;
   int menorSoma = 0;
   int menorColuna = 0;
   int auxiliar = 0;
//verificar existencia de dados
   if (colunas != 0 && linhas != 0)
   {
   //varrer matriz e somar
      for (int j = 0; j < colunas; j++)
      {
         soma[j] = 0;
         for (int i = 0; i < linhas; i++)
         {
            soma[j] = soma[j] + matriz[i][j];
         }//end for
      }//end for

   //guardar posicao da coluna com menor soma
      menorSoma = soma[0];
      menorColuna = 0;
      for (int n = 1; n < colunas; n++)
      {
         if (soma[n] < menorSoma)
         {
            menorSoma = soma[n];
            menorColuna = n;
         }//end if
      }//end for

   //trocar colunas de posicao
      for (int i = 0; i < linhas; i++)
      {
         for (int a = 0; a < menorColuna; a++)
         {
            for (int j = 0; j < colunas - 1; j++)
            {
               auxiliar = matriz[i][j];
               matriz[i][j] = matriz[i][j + 1];
               matriz[i][j + 1] = auxiliar;
            }//end while
         }//end for
      }//end for
   } else
   {
      IO_printf("\n nao existem dados.");
   }//end if
}//end menorSomaPrimeiro

/**
  * Metodo03 - chama funcoes para calcular a soma de cada coluna da matriz
  * e reorganiza-la para que a coluna com menor soma fique em primeiro
*/
void metodo03 ( )
{
// definir dados
   int linhas  = ler_matrizLinhas( "M1.txt" );
   int colunas = ler_matrizColunas( "M1.txt" );
   int matriz [ linhas ][ colunas ];

// identificar
   IO_println ( "\nMetodo03" );

//ler matriz de arquivo
   ler_matriz ( "M1.txt", linhas, colunas, matriz );
//montar matriz com a coluna com menor total primeiro
   menorSomaPrimeiro ( linhas, colunas, matriz );
//gravar matriz em arquivo
   gravar_matriz ( "M2.txt", linhas, colunas, matriz );
}//end metodo03 ( )

// ---------------------------------------------- definicao do metodo principal

int main ( void )
{
//definir dados
   int opcao = 0;
//repetir ate' desejar parar
   do
   {
   // identificar
      IO_printf  ( "\n" );   // para saltar linha
      IO_println ( "Exercicio_02 - v.0.5 - 17/11/2020\n"       );
      IO_println ( "Matricula: 712171 Nome: Luana Campos Takeishi\n" );
      IO_println ( "" );     // para saltar linha

   // mostrar opcoes

      IO_println ( "Opcoes:"       );
      IO_println ( "0 - parar"     );
      IO_println ( "1 - metodo 01" );
      IO_println ( "2 - metodo 02" );
      IO_println ( "3 - metodo 03" );
      IO_println ( "" );     // para saltar linha

   // ler opcao
    /*  opcao = IO_readint ( "Qual a sua opcao? " ); */

      scanf ( "%d", &opcao );

   // escolher acao
      switch ( opcao )
      {
         case 0:
            break;
         case 1:
            metodo01 ( );
            break;
         case 2:
            metodo02 ( );
            break;
         case 3:
            metodo03 ( );
            break;
         default:
            IO_printf ( "\nERRO: Opcao invalida.\n" );
            break;
      } // fim escolher
   }
   while ( opcao != 0 );
}//end main ( )

/**
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes e testes
Metodo01:
   -teste1:
      ARRANJO:
      9 7 5 3 1
      ARRANJO:
      9 7 5 3 1
      ARRANJO INTERCALADA:
      9 7 5 3 1
   -teste2:
      ARRANJO:
      9 7 5 3 1
      ARRANJO:
      9 7 8 2 6 1
      ARRANJO INTERCALADA:
      9 7 5 8 2 3 1 6 1
   -teste3: 
      ARRANJO:
      9 7 5 3 1
      ARRANJO:
      8 2 6 6
      ARRANJO INTERCALADA:
      8 9 2 7 5 6 3 6 1

Metodo02:
   -teste1: OBS: problemas para salvar em arquivo, nao esta funcionando o fprintf
   PROBLEMA CORRIGIDO.
   -teste2: NOMES.txt 4 Luana Campos Takeishi \n Maria Joana Silva \n Caetana Velosa \n Osana Ohana 
            PRENOME:
               Luana
            SOBRENOME:
               Campos Takeishi
            PRENOME:
               Maria
            SOBRENOME:
               Joana Silva
            PRENOME:
               Caetana
            SOBRENOME:
               Velosa
            PRENOME:
               Osana
            SOBRENOME:
               Ohana
   -teste3:
            PRENOME:
               Fulano
            SOBRENOME:
               de Sousa e Silva
            PRENOME:
               Beltrano
            SOBRENOME:
               Oliveira Carvalho
            PRENOME:
               Sicrano
            SOBRENOME:
               Ribeiro

Metodo03:
   -teste1:
      MATRIZ LIDA:
      1       4       2       6
      9       1       2       3
      2       8       6       9
      MATRIZ REORGANIZADA:
      2       6       1       4
      2       3       9       1
      6       9       2       8
   -teste2:
      MATRIZ LIDA:
      1       2       3       4
      5       6       7       8
      9       10      11      12
      MATRIZ REORGANIZADA:
      1       2       3       4
      5       6       7       8
      9       10      11      12
   -teste3: 
      MATRIZ LIDA:
      4       3       2       1
      9       7       5       3
      2       4       6       8
      MATRIZ REORGANIZADA:
      1       4       3       2
      3       9       7       5
      8       2       4       6
*/
