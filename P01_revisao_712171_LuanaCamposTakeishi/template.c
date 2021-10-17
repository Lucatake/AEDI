/**
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico 01
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
  * 3. O uso da biblioteca io.h e' opcional.
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

#include "io.h"

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

void Exercicio01( );
void Exercicio02( );
void Exercicio03( );
int placas ( chars p, int d );

// ---------------------------------------------- definicao do metodo principal

int main ( void )
{
//definir dados
   int opcao = 0;

//repetir ate' desejar parar
   do
   {
   //identificar
      IO_printf  ( "\n\n" );   // para saltar linha
      IO_println ( "\tProva_01 - v.0.2 - 02/11/2020"       );
      IO_println ( "    Matricula: 712171 Nome: Luana Campos Takeishi\n" );
      IO_println ( "" );     // para saltar linha
   
   //mostrar opcoes
      IO_println ( "Opcoes:"       );
      IO_println ( "0 - parar"     );
      IO_println ( "1 - Exercicio 01" );
      IO_println ( "2 - Exercicio 02" );
      IO_println ( "3 - Exercicio 03" );
      IO_println ( "" );     // para saltar linha

   //ler opcao
      opcao = IO_readint ( "Qual exercicio? " );

   //para teste direto (inputs e outputs)
      //scanf ( "%d", &opcao );

   //escolher acao
      switch ( opcao )
      {
         case 0:
            break;
         case 1:
            Exercicio01 ( );
            break;
         case 2:
            Exercicio02 ( );
            break;
         case 3:
            Exercicio03 ( );
            break;
         default:
            IO_printf ( "\nERRO: Opcao invalida.\n" );
            break;
      }//end switch case
   }
   while ( opcao != 0 );

}//end main ( )

// ---------------------------------------------- metodos

/**
  * Exercicio01.
  * Um dos jogadores sera o computador e
    usara um valor aleatorio gerado no intervalo [1:100).
    Serao permitidas ate sete (7) tentativas
    para poder acertar o valor determinado.
    A cada tentativa do outro jogador,
    o computador respondera
    "OK"   - se houver acerto
    "UP"   - se o valor informado foi menor que o gerado
    "DOWN" - se o valor informado foi maior que o gerado
     Verificar possibilidades de erros.
*/
void Exercicio01 ( )
{
//definir dados com valor inicial
   int quantidade = 7;     //para maximo de 7 tentativas
   int controle   = 0;
   int valor      = 0;
   int gerados    = 0;
   int jogador    = 0;

//identificar
   IO_println ( "\nExercicio01" );

//acoes
   srand ( time ( NULL ) );   // escolher a semente aleatoria dependente do tempo

//gerar numero aleatorio no intervalo [1:100)
   do
   {
      valor = rand();
      gerados = gerados + 1;
   } while ( ! ((valor >= 1) && (valor < 100)) ); 
   //IO_printf("%d", valor);    //para conferencia dos valores
   
//repetir um numero de vezes (7)
   controle = 1;
   while (controle <= quantidade)
   {
   //ler do teclado o valor do jogador
      jogador = IO_readint("\n Valor: ");
      //IO_printf("%d", jogador);    //para conferencia dos valores

   //se valor for valido
      if (jogador != NULL)
      {
      //comparar o jogador com o computador
         if (jogador == valor)
         {
            IO_println(" OK"); //se acertou o valor
         //terminar tentativas
            controle = 7;
         }
         else
         {
            if (jogador > valor)
            {
               IO_println(" DOWN"); //se valor maior que
            }
            else
            {
               IO_println(" UP"); //se vamor menor que
            }//end if
         }//end if
      } else
      {
         IO_println(" valor invalido.");
      }//end if

   //passar para a proxima tentativa
      controle = controle + 1;
   }//end while
//encerrar
   IO_pause("Apertar ENTER para continuar.");
}//end Exercicio01 ( )

/**
  * Exercicio02.
  *         1     1     3     6     10     15     21           d
    soma = ___ + ___ + ___ - ___ + ____ + ____ - ____ + ...  _____

            1     2     4     8     16     32     64           D
    para certo numero de parcelas a ser informado pelo teclado.
    Verificar possibilidades de erros.
*/
void Exercicio02 ( )
{
//definir dados com valor inicial
   int d = 1;
   int v = 2;
   int D = 2;
   int q = 0;
   double inverso = 0;
   double soma = 0;
   int termo = 1;

//identificar
   IO_println ( "\nExercicio02" );

//ler do teclado
   q = quantidades("\n numero de repeticoes: ");

//repetir (q) vezes a partir da 1a
   for (int i = 1; i < q; i++)
   {
   //se divisivel por 3 : subrtacao
      if ((termo % 3) == 0)
      {
      //calcular a divisao
         inverso = (double) d / D;
      //subtrair
         soma = soma - inverso;
         //printf("\n ++%d/%d inv = %.4lf ", d, D, inverso);   conferencia dos valores
      } else  // : soma
      {
      //calcular a divisao
         inverso = (double) d / D;
      //somar
         soma = soma + inverso;
         //printf("\n ++%d/%d inv = %.4lf ", d, D, inverso);   conferencia dos valores
      }//end if
   //achar os proximos numeros
      d = d + v;
      v = v + 1;
      D = 2 * D;
      termo++;
   }//end for 
//para o primeiro valor
   soma = soma + 1;
//mostrar resultado
   printf(" soma = %.4lf ", soma);
//encerrar
   IO_pause("\nApertar ENTER para continuar.");
}//end Exercicio02 ( )

/**
  * Exercicio03.
  * Fazer um programa que utilize uma funcao para verificar
    se uma placa de veiculo esta de acordo com o padrao do
    Mercosul: tres letras seguidas, um numero, uma letra e
    depois mais dois numeros.
    Testar varias placas e encerrar com a placa "AAA0A00".
    Se a placa for valida, a funcao devera retornar 1;
    caso contrario, devera retornar 0.
    Mostrar, ao final, a quantidade de placas testadas,
    a quantidade de placas aceitas e a porcentagem de
    placas rejeitadas.
*/
void Exercicio03 ( )
{
//definir variaveis com valor inicial
   int dado = 0, r = 0;
   chars p = " ";
   int x = 0, tot = 0, ac = 0;
   double ng = 0.0;

//identificar
   IO_println ( "\nExercicio03" );

//para repetir "n" vezes 
   do
   {
   //ler do teclado uma placa com tamanho valido
      do
      {
      //ler do teclado
         p = IO_readstring("\n placa: ");
         dado = strlen(p);
      }while( dado != 7 );

   //chamada de funcao e mostrar retorno 
      r = placas( p , dado );
      IO_printf(" return %d\n", r);
   //somar mais uma placa testada
      tot++;
      if ( r == 1 )
      {
      //somar mais uma placa aceita
         ac++;
      }//end if
   //verificar se chegou o fim AAA0A00
      if (  p[0] == 'A' && p[1] == 'A' && p[2] == 'A'
         && p[3] == '0' && p[4] == 'A' && p[5] == '0' && p[6] == '0')
      {
         x = 1;
      }//end if
   } while ( x != 1 );

//calcular estatistica
   if (tot > 0)
   {
      ng = (double) (tot - ac)/ tot; 
   //mostrar estatistica
      printf("\n total de placas testatas: %d", tot);
      printf("\n placas aceitas: %d", ac);
      printf("\n placas rejeitadas: %.1lf%%", ng*100);
   }//end if
//encerrar
   IO_pause("\nApertar ENTER para continuar.");
}//end Exercicio03 ( )

/**
 * placas - funcao para detrerminar se uma placa de veiculo esta
 * no padrao Mercosul.
 * @param p - placa (letras e numeros)
 * @param d - quantidade de chars
 * @return - 1 para valido e 0 para invalico
*/
int placas ( chars p, int d )
{
//variavel com valor inicial
   int valido = 0;
   int count = 0;

//testar placa
   for (int count = d; count >= 0; count--)
   {
   //se valor e' numero  e esta na posicao 4 6 7
      if ( (count == 3) || (count == 5) || (count == 6) )
      {
         if (  (p[count] >= '0') && (p[count] <= '9') )
         {
            valido++;
         }//end if
      } else
      {
      //se valor esta nas outras posicoes e' letra
         if ((p[count] >= 'A') && (p[count] <= 'Z'))
         {
            valido++;
         }//end if
      }//end if
   }//end for

//retornar valor
   if(valido == 7)
   {
      return(1);
   } else
   {
      return(0);
   }//end if
}//end placas

/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes e testes

Exercicio 1 - 
   -Teste 1: Numero gerado: 36
   Valores testados e resultados:
   Valor: 12 UP | Valor: 12 UP | Valor: 35 UP | Valor: 89 DOWN | Valor: 07 UP
                  Valor: 67 DOWN | Valor: 45 DOWN | Valor: 67 DOWN
   -Teste 2: Numero gerado: 96
   Valores testados e resultados: 
   Valor: 96 OK
   -Teste 3: Numero gerado: 77
   Valores testados e resultados:
   Valor: A valor invalido. | Valor: AB valor invalido. | Valor: ABC valor invalido.
   Valor: A34 valor invalido. | Valor: adf valor invalido. | Valor: 56 UP | Valor: 77 OK

Exercicio 2 -
   -Teste 1: numero de repeticoes: 5   soma = 2.1250
   -Teste 2: numero de repeticoes: 0   Valor invalido.
    numero de repeticoes: 2   soma = 1.5000
   -Teste 3: numero de repeticoes: -19 Valor invalido.
    numero de repeticoes: 10  soma = 2.5371
   -Teste 4:  numero de repeticoes: ABc Valor invalido.
    numero de repeticoes: asc Valor invalido.

Exercicio 3 -
   -Teste 1:
    Placas: ABC0D12    OPQ94EE    1234oper    opera023    AAA0A00
           return 1    return 0                           return 1
    Resultados:
      total de placas testatas: 3
      placas aceitas: 2
      placas rejeitadas: 33.3%
   -Teste 2:
    Placas:  AEf9U23     AEF9U23     OIL9U10     AAA0A00
             return 0    return 1    return 1    return 1
    Resultados:
      total de placas testatas: 4
      placas aceitas: 3
      placas rejeitadas: 25.0%

*/
