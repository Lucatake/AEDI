/**
    Metodo para testar todos os exercicios em um so' programa
    Lista de exercicios de recuperacao - Versao 0.1 - 03/11/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o recuperacao01      recuperacao01.c
    Windows:    gcc -o recuperacao01.exe  recuperacao01.c
    Para executar em terminal (janela de comandos):
    Linux:      ./recuperacao01
    Windows:    recuperacao01
*/

//--------------------------------------------dependencias
//para definicoes proprias
#include "io.h"

//para metodos proprios
#include "Luana.h"

//lista de funcoes
int menu(void);
void analisaArray( int n, int array[] );
void analisaNumArray( int n, int array[] );
void operador(char cadeia);
void analisaCadeia( char caractere, int n, int array[]);
void calculaMediaN( int q, double array[], double medias[4] );
double somaCubosInv( int n, int array[], int *a, int *b);
void valoresIntervalos(double a, double b, int n, double array[]);
void analisaOrdem( double x, double y, double z );
void analisaOrdemChar( char x, char y, char z );
void analisaString( chars x, chars y, chars z );
int alfabetica( char a, char b );

//lista dos metodos
void exercicio01( );
void exercicio02( );
void exercicio03( );
void exercicio04( );
void exercicio05( );
void exercicio06( );
void exercicio07( );
void exercicio08( );
void exercicio09( );
void exercicio10( );

//--------------------------------------------funcao principal

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
            exercicio01( );
            break;
        case 2:
            exercicio02( );
            break;
        case 3:
            exercicio03( );
            break;
        case 4:
            exercicio04( );
            break;
        case 5:
            exercicio05( );
            break; 
        case 6:
            exercicio06( );
            break;
        case 7:
            exercicio07( );
            break;
        case 8:
            exercicio08( );
            break;
        case 9:
            exercicio09( );
            break;
        case 10:
            exercicio10( );
            break;
        default:
            IO_println("\nValor diferente das opcoes.");
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
    IO_println(" 1 - Exercicio1 | 2 - Exercicio2 | 3 - Exercicio3 | 4 - Exercicio4 |  5 - Exercicio5");
    IO_println(" 6 - Exercicio6 | 7 - Exercicio7 | 8 - Exercicio8 | 9 - Exercicio9 | 10 - Exercicio10");
    //ler do teclado
    e = IO_readint("\nEntrar com uma opcao: ");
    //retornat valor lido
    return (e);
}//end menu( )

//--------------------------------------------metodos

/**
 * exercicio01:
 * ler um valor inteiro (n) do teclado para indicar uma quantidade;
 * ler outros tantos valores inteiros (x) do teclado, um por vez, ate atingir a quantidade;
 * dizer se cada valor lido e' negativo, igual a zero, positivo, e tambem se par ou impar.
 * DICA: Usar alternativas duplas ("se-senao").
*/
void exercicio01( )
{
//declarar variaveis
    int n = quantidades("\n quantidades: ");
    int array[n];
//ler valores a serem testados
    for (int i = 0; i < n; i++)
    {
        array[i] = IO_readint("\n valor: ");
    }//end for
//chamar funcao para testar    
    analisaArray( n, array );
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio01

/**
 * analisaArray - fucao para analisar se numeros
 * no array sao nulos, negativos, positivos, par ou impar
 * @param n - tamanho array
 * @param array - valores a serem testados 
*/
void analisaArray( int n, int array[] )
{
    for (int i = 0; i < n; i++)
    {
    //se positivo
        if (array[i] > 0)
        {
            if (array[i] % 2 == 0)     //se par
            {
                IO_printf("\n valor %d: positivo par.", array[i]);
            } else      //se impar
            {
                IO_printf("\n valor %d: positivo impar.", array[i]);
            }//end if
        } else
        {
        //se negativo
            if (array[i] < 0)
            {
                if (array[i] % 2 == 0)     //se par
                {
                    IO_printf("\n valor %d: negativo par.", array[i]);
                } else      //se impar
                {
                    IO_printf("\n valor %d: negativo impar.", array[i]);
                }//end if
            } else
            {
                IO_printf("\n valor %d: nulo.", array[i]);
            }//end if
        }//end if        
    }//end for
}//end analisaArray

/**
 * exercicio02:
 * ler um valor inteiro (n) do teclado;
 * ler outros (n) valores inteiros do teclado, um por vez, ate atingir a quantidade;
 * e contar separadamente quantos desses valores sao negativos, positivos, pares, impares
 * ou iguais a zero. Dizer qual dessas quantidades e' maior que as outras.
 * DICA: Usar alternativas duplas ("se-senao").
*/
void exercicio02( )
{
//declarar variaveis
    int n = quantidades("\n quantidades: ");
    int array[n];
//ler valores a serem testados
    for (int i = 0; i < n; i++)
    {
        array[i] = IO_readint(" valor: ");
    }//end for
//chamar funcao para testar    
    analisaNumArray( n, array );
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio02

/**
 * analisaNumArray - fucao para analisar se numeros
 * no array sao nulos, negativos, positivos, par ou impar
 * contar quantos sao de cada e mostrar a maior
 * @param n - tamanho array
 * @param array - valores a serem testados 
*/
void analisaNumArray( int n, int array[] )
{
//declarar variaveis
    int maior = 0;
//array para (pares, impares, positivos, negativos, nulos)
//{ 0 - par, 1 - impar, 2 - positivo, 3 - negativo, 4 - nulos }
    int compara[5] = {0,0,0,0,0};
    for (int i = 0; i < n; i++)
    {
    //se positivo
        if (array[i] > 0)
        {
            if (array[i] % 2 == 0)     //se par
            {
                compara[0]++;   //par
                compara[2]++;   //positivo
            } else      //se impar
            {
                compara[1]++;   //impar
                compara[2]++;   //positivo
            }//end if
        } else
        {
        //se negativo
            if (array[i] < 0)
            {
                if (array[i] % 2 == 0)     //se par
                {
                    compara[0]++;   //par
                    compara[3]++;   //negativo
                } else      //se impar
                {
                    compara[1]++;   //impar
                    compara[3]++;   //negativo
                }//end if
            } else
            {
                compara[4]++;   //nulo
            }//end if
        }//end if        
    }//end for
//analisar o maior
    for (int q = 1; q < 5; q++)
    {
    //manter o valor maior
        if (compara[q] > compara[q-1])
        {
            maior = q;
        }//end if
    }//end for
//mostrar resultado
//{ 0 - par, 1 - impar, 2 - positivo, 3 - negativo, 4 - nulos }
    switch (maior)
    {
    case 0:
        IO_println(" maior quantidade de pares.");
        break;
    case 1:
        IO_println(" maior quantidade de impares.");
        break;
    case 2:
        IO_println(" maior quantidade de positivos.");
        break;
    case 3:
        IO_println(" maior quantidade de negativos.");
        break;
    case 4:
        IO_println(" maior quantidade de nulos.");
        break;   
    default:
        IO_println(" nao ha' uma maior quantidade.");
        break;
    }
}//end analisaNumArray

/**
 * exercicio03:
 * ler uma cadeia de caracteres do teclado;
 * dizer se cada simbolo e' um operador 
 * logico (&,|,!), aritmetico (+,-,*,/,%), relacional (>,<,=),
 * separadores (espaço, ponto, virgula, ponto-e-virgula, 
 * dois-pontos, sublinha) ou outro simbolo qualquer.
 * DICA: Definir funcoes para identificar cada um desses tipos de simbolo.
*/
void exercicio03( )
{
//declarar variaveis
    chars cadeia = "\0";
    int tam = 0;
//ler dados do teclado
    cadeia = IO_readln("\n entre com uma cadeia de caracteres: ");
//calcular tamanho da cadeia
    tam = strlen(cadeia);
//chamar funcao
    for (int i = 0; i < tam; i++)
    {
        operador(cadeia[i]);
    }//end for
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio03

/**
 * operador - verificar se e' operador logico, aritmetico,
 * relacional, separador ou outro simbolo
 * @param cadeia - caractere lido
*/
void operador(char cadeia)
{
//verificar caractere
    switch (cadeia)
    {
//logicos
    case '&':
        IO_printf("\n operador logico: %c (AND)", cadeia);
        break;
    case '|':
        IO_printf("\n operador logico: %c (OR)", cadeia);
        break;
    case '!':
        IO_printf("\n operador logico: %c (NOT)", cadeia);
        break;
//aritmeticos
    case '+':
        IO_printf("\n operador aritmetico: %c (SOMA)", cadeia);
        break;
    case '-':
        IO_printf("\n operador aritmetico: %c (SUBTRACAO)", cadeia);
        break;
    case '*':
        IO_printf("\n operador aritmetico: %c (MULTIPLICACAO)", cadeia);
        break;
    case '/':
        IO_printf("\n operador aritmetico: %c (DIVISAO)", cadeia);
        break;
    case '%':
        IO_printf("\n operador aritmetico: %c (MODULO/RESTO)", cadeia);
        break;
//relacionais
    case '>':
        IO_printf("\n operador relacional: %c (MAIOR QUE)", cadeia);
        break;
    case '<':
        IO_printf("\n operador relacional: %c (MENOR QUE)", cadeia);
        break;
    case '=':
        IO_printf("\n operador relacional: %c (IGUAL)", cadeia);
        break;
//separadores
    case ' ':
        IO_printf("\n operador separador: %c (ESPACO)", cadeia);
        break;
    case ',':
        IO_printf("\n operador separador: %c (VIRGULA)", cadeia);
        break;
    case ';':
        IO_printf("\n operador separador: %c (PONTO-E-VIRGULA)", cadeia);
        break;
    case '.':
        IO_printf("\n operador separador: %c (PONTO)", cadeia);
        break;
    case ':':
        IO_printf("\n operador separador: %c (DOIS PONTOS)", cadeia);
        break;
    case '_':
        IO_printf("\n operador separador: %c (UNDERLINE)", cadeia);
        break;

    default:
        IO_printf("\n outro simbolo (%c).", cadeia);
        break;
    }//end switch case4
}//end operador

/**
 * exercicio04:
 * ler um cadeia de caracteres (s) do teclado; 
 * testar cada simbolo na cadeia, um por vez,
 * e contar separadamente quantos desses sao 
 * letras maiusculas, minusculas, digitos e
 * operadores (logicos, aritmeticos e relacionais) e separadores .
 * DICA: Utilizar funcoes ja definidas para identificar 
 * cada tipo de simbolo (ver acima).
*/
void exercicio04( )
{
//declarar variaveis
    chars cadeia = "\0";
    int tam = 0;
    //para  maiusculas(p0) - minusculas(p1) - digitos(p2)
    //      operadores(p3) - separadores(p4)
    int array[5] = {0,0,0,0,0};
//ler dados do teclado
    cadeia = IO_readln("\n entre com uma cadeia de caracteres: ");
//calcular tamanho da cadeia
    tam = strlen(cadeia); 
//chamar funcao
    for (int i = 0; i < tam; i++)
    {
        analisaCadeia(cadeia[i], 5, array);
    }//end for
//mostrar resultados
    IO_printf("\n %d letras maiusculas", array[0]);
    IO_printf("\n %d letras minusculas", array[1]);
    IO_printf("\n %d digitos", array[2]);
    IO_printf("\n %d operadores", array[3]);
    IO_printf("\n %d separadores", array[4]);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio04

/**
 * analisaCadeia - funcao para analisar uma cadeia de caracteres
 * @param caractere - caractere a ser analisado
 * @param n - tamanho do array
 * @param array - array contendo os dados
*/
void analisaCadeia( char caractere, int n, int array[])
{
    //analisa caractere e armazenar quantidade em array
    if (caractere >= 'A' && caractere <= 'Z')
    {
        //letra maiuscula
        array[0] = array[0] + 1;
    } else if (caractere >= 'a' && caractere <= 'z')
    {
        //letra minuscula
        array[1] = array[1] + 1;
    } else if (caractere >= '0' && caractere <= '9')
    {
        //digito
        array[2] = array[2] + 1;
    } else if (caractere >= '<' && caractere <= '>' || caractere == '&'
            || caractere == '|' || caractere == '!' || caractere == '+'
            || caractere == '-' || caractere == '*' || caractere == '/'
            || caractere == '%')
    {
        //operador
        array[3] = array[3] + 1;
    } else if (caractere >= ' ' && caractere <= '.' || caractere == ';'
            || caractere == ',' || caractere == ':' || caractere == '_')
    {
        //separador
        array[4] = array[4] + 1;
    } //end if-else-if
}//end analisaCadeia

/**
 * exercicio05:
 * ler um valor inteiro (n) do teclado;
 * ler outros (n) valores reais (x) do teclado, um por vez;
 * calcular e mostrar a media dos valores menores que -27.25;
 * a media dos que estao entre -27.25 e 47.75, inclusive esses;
 * e a media dos maiores que 47.75. Dizer qual a menor media de todas.
 * DICA: Definir funcoes para cada calculo. Usar alternativas duplas ("se-senao").
*/
void exercicio05( )
{
//declarar variaveis
    int count = 0;
//ler quantidades do teclado
    int q = quantidades("\n digite uma quantidade: ");
//array de valores lidos
    double valor[q];
//array dos resultados
    //media menores que -27.25 (p0)
    //entre =-27.25 e =47.75 (p1)
    //maiores que 47.75 (p2)
    double medias[4] = {0.0,0.0,0.0,0.0};
//ler valores do teclado
    do
    {
        valor[count] = IO_readdouble(" digite um valor real: ");
        count++;
    } while (count < q);
//chamar funcao para analisar
    calculaMediaN(q, valor, medias);
//mostrar resultados
    IO_printf("\n media valores < -27.25 : %.2lf", medias[0]);
    IO_printf("\n media 47.75 >= valores >= -27.25 : %.2lf", medias[1]);
    IO_printf("\n media valores > 47.75 : %.2lf", medias[2]);
    IO_printf("\n menor media: %.2lf", medias[3]);

//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio05

void calculaMediaN( int q, double array[], double medias[4] )
{
//definir variaveis
    double soma0 = 0.0;
    int valores0 = 0;
    double soma1 = 0.0;
    int valores1 = 0;
    double soma2 = 0.0;
    int valores2 = 0;
//calcular medias
    for (int i = 0; i < q; i++)
    {
        if (array[i] < (-27.25))
        {
            soma0 = soma0 + array[i];
            valores0++;
        } else if ( 47.75 >= array[i] && array[i] >= (-27.25))
        {
            soma1 = soma1 + array[i];
            valores1++;
        } else if ( array[i] > 47.75 )
        {
            soma2 = soma2 + array[i];
            valores2++;
        }//end if-else-if
    }
//armazenar resultados
    medias[0] = soma0/valores0;
    medias[1] = soma1/valores1;
    medias[2] = soma2/valores2;
//analisar a menor media
    medias[3] = medias [0];    
    for (int q = 1; q < 3; q++)
    {
        if (medias[q] < medias[q-1])
        {
            medias[3] = medias[q];
        }//end if
    }//end for
    
}//end calculaMediaN

/**
 * exercicio06:
 * ler dois valores inteiros (a) e (b) do teclado,
 * ler outros valores inteiros do teclado, um por vez,
 * ate que o ultimo valor seja igual a (-1).
 * para todos os valores no intervalo aberto ]a:b[;
 * calcular e mostrar a soma dos cubos dos inversos (1/x3).
 * DICA: Evitar divisao por zero mediante uso de alternativa dupla.
*/
void exercicio06( )
{
//declarar variaveis
    double soma = 0.0;
    int valor = 0;
    int n = 0;
    int array[n];
//ler do teclado os intervalos
    int *a = 0;
    int *b = 0;
    intervalo(&a, &b);
//ler valores ate o -1
    do
    {
        valor = IO_readint("\n entre com um valor inteiro: ");
        array[n] = valor;
        //proximo valor
        n++;
    } while (valor != -1);
//chamar funcao para calcular
    soma = somaCubosInv(n, array, &a, &b);
//mostrar resultados
    IO_printf("\n soma dos cubos inversos de ]%d,%d[: %.4lf", &a, &b, soma);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio06

/**
 * somaCubosInv - somar inverso dos cubos de valores
 * dentro de um intervalo aberto a-b
 * @param n - quantidade de valores
 * @param array - valores
 * @param a - intervalo inferior
 * @param b - intervalo superior
 * @return soma - soma dos cubos inversos
*/
double somaCubosInv( int n, int array[], int *a, int *b)
{
//declarar variaveis
    double inverso = 0.0;
    double soma = 0.0;
//varrer valores
    for (int i = 0; i < n; i++)
    {
    //se estiver dentro do intervalo e diferente de 0
        if ((array[i]>*a) && (array[i]<*b) && (array[i]!=0))
        {
        //calcular inverso do cubo
            inverso = (double) 1/(pow(array[i], 3));
        //calcular soma
            soma = soma + inverso;
        }//end if
    }//end for
//retornar resultado
    return(soma);
}//end somaCubosInv

/**
 * exercicio07:
 * ler dois valores reais (a) e (b) do teclado,
 * ler outros valores reais do teclado, um por vez,
 * ate que o ultimo valor seja igual a zero,
 * e nao considera-lo para os calculos.
 * contar quantos desses valores estao dentro ou fora
 * do intervalo definido pelo intervalo aberto ]a:b[;
 * para os valores fora do intervalo, calcular separadamente
 * as porcentagens dos que estiverem abaixo e acima do intervalo, nessa ordem.
 * DICA: Evitar divisao por zero mediante uso de alternativas duplas.
*/
void exercicio07( )
{
//declarar variaveis
    int n = 0;
    double array[n];
    double valor = 0.0;
//ler intervalo do teclado
    double a = 0.0;
    double b = 0.0;
    a = IO_readdouble("\n digite um valor para ser o intervalo inferior: ");
    do
    {
        b = IO_readdouble("\n digite um valor para ser o intervalo superior: ");
    } while (b <= a);
//ler valores ate 0
    do
    {
        valor = IO_readdouble("\n entre com um valor real: ");
        //proximo valor
        array[n] = valor;
        n++;
    } while (valor != 0.0);
//funcao para analisar quantos valores estao num intervalo
    valoresIntervalos(a, b, n, array);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio07

/**
 * valoresIntervalos - calcular quantos valores estao dentro
 * e fora de um intervalo a-b e quantos estao acima ou abaixo dele
 * @param a - intervalo inferior
 * @param b - intervalo superior
 * @param n - quantidade de valores
 * @param array - valores
*/
void valoresIntervalos(double a, double b, int n, double array[])
{
//declarar variaveis
    int dentro = 0;
    int fora = 0;
    int acima = 0;
    int abaixo = 0;
//varrer valores (menos o ultimo = 0)
    for (int i = 0; i < (n-1); i++)
    {
    //se estiver dentro do intervalo
        if ((array[i] > a) && (array[i] < b))
        {
        //dentro
            dentro++;
            //IO_printf("\ndentro %.2lf",array[i]);
        } else if (array[i] <= a)
        {
        //menor
            abaixo++;
            fora++;
            //IO_printf("\nabaixo %.2lf",array[i]);
        } else
        {
        //maior
            acima++;
            fora++;
            //IO_printf("\nacima %.2lf",array[i]);
        }//end if-else-if       
    }//end for
//mostrar resultados
    IO_printf("\n valores dentro: %d", dentro);
    IO_printf("\n valores fora: %d", fora);
    abaixo = (abaixo *100) / fora;
    IO_printf("\n valores abaixo: %d%%", abaixo);
    acima = (acima *100) / fora;
    IO_printf("\n valores acima: %d%%", acima);
}//end valoresIntervalos

/**
 * exercicio08:
 * ler tres valores reais (x,y,z) do teclado, um por vez;
 * dizer se esses valores estao em ordem crescente, decrescente,
 * ou em nenhuma dessas ordens e, nesse caso, o menor e o maior.
 * DICA: Usar testes com maior numero de comparacoes usando conectivos logicos ( &&, || e ! ).
 * Definir funcoes para testar as ordens crescente e decrescente.
*/
void exercicio08( )
{
//definir variaveis e ler seus valores
    double x = IO_readdouble("\n digite um valor real: ");
    double y = IO_readdouble("\n digite outro valor real: ");
    double z = IO_readdouble("\n digite outro valor real: ");
//chamar funcao
    analisaOrdem(x, y, z);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio08

/**
 * analisaOrdem - analisa ordem dos valores
 * @param x,y,z - valores
*/
void analisaOrdem( double x, double y, double z )
{
//se todos diferentes
    if ((x != y) && (y != z) && (z != x))
    {
    //se ordem decrescente
        if ((x > y) && (y > z))
        {
            IO_printf("\n estao em ordem decrescente %.2lf>%.2lf>%.2lf", x,y,z);
        } else 
    //se ordem crescente
        if ((z > y) && (y > x))
        {
            IO_printf("\n estao em ordem crescente %.2lf<%.2lf<%.2lf", x,y,z);
        } else 
    //se y o maior e z menor
        if ((y > x) && (x > z))
        {
            IO_printf("\n desordenados: maior %.2lf / menor %.2lf", y,z);
        } else
    //se y maior e x menor
        if ((y > z) && (z > x))
        {
            IO_printf("\n desordenados: maior %.2lf / menor %.2lf", y,x);
        } else
    //se z maior e y menor
        if ((z > x) && (x > y))
        {
            IO_printf("\n desordenados: maior %.2lf / menor %.2lf", z,y);
        } else
    //se x maior e y menor
        if ((x > z) && (z > y))
        {
            IO_printf("\n desordenados: maior %.2lf / menor %.2lf", x,y);
        }//end if
    } else
    {
    // x == y e x != z
        if ((x != z) && (x == y))
        {
            IO_printf("\n desordenados: (%.2lf = %.2lf) != %.2lf", x,y,z);
        } else 
    // x == z e x != y
        if ((x != y) && (x == z))
        {
            IO_printf("\n desordenados: %.2lf (!= %.2lf !=) %.2lf", x,y,z);
        } else 
    // z == y e z != x
        if ((z != x) && (z == y))
        {
            IO_printf("\n desordenados: %.2lf != (%.2lf = %.2lf)", x,y,z);
        } else
        {
            IO_printf("\n desordenados: %.2lf = %.2lf = %.2lf", x,y,z);
        }//end if
    }//end if
}//end analisaOrdem

/**
 * exercicio09:
 * ler tres caracteres (x,y,z) do teclado, um por vez;
 * dizer se esses valores estao em ordem crescente, decrescente,
 * ou em nenhuma dessas ordens.
 * DICA: Usar uma funcao logica para comparar os codigos inteiros de cada caractere,
 * e dizer se o segundo sucede o primeiro em ordem alfabetica.
 * Definir funcoes para testar as ordens alfabeticas crescente e decrescente.
*/
void exercicio09( )
{
//definir variaveis e ler seus valores
    char x = IO_readchar("\n digite um caractere: ");
    char y = IO_readchar("\n digite outro caractere: ");
    char z = IO_readchar("\n digite outro caractere: ");
//chamar funcao
    analisaOrdemChar(x, y, z);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio09

/**
 * analisaOrdemChar - analisa ordem de tres caracteres
 * @param x,y,z - caracteres lidos e analisados
*/
void analisaOrdemChar( char x, char y, char z )
{
    //para comparar ordem alfabetica independente
    //da ordem tabela ascii (maiuscula ou minuscula)
    int a = (int) x;
    int b = (int) y;
    int c = (int) z;
    if ( a >= 65 && a <= 90)
    {
        a = a + 32;
    }//end if
    if ( b >= 65 && b <= 90)
    {
        b = b + 32;
    }//end if
    if ( c >= 65 && c <= 90)
    {
        c = c + 32;
    }//end if
//comparar valores
    //se todos diferentes
    if ((a != b) && (b != c) && (c != a))
    {
    //se ordem decrescente
        if ((a > b) && (b > c))
        {
            IO_printf("\n estao em ordem decrescente %c>%c>%c", x,y,z);
        } else 
    //se ordem crescente
        if ((c > b) && (b > a))
        {
            IO_printf("\n estao em ordem crescente %c<%c<%c", x,y,z);
        } else 
        {
            IO_printf("\n x, y, z - desordenados.");
        }//end if-else-if
    } else
    {
        IO_printf("\n x, y, z - desordenados.");
    }//end if
}//end analisaOrdemChar

/**
 * exercicio10:
 * ler tres cadeias de caracteres (x,y,z) do teclado, uma por vez;
 * dizer se essas cadeias estao em ordem alfabetica crescente,
 * decrescente ou em nenhuma dessas ordens e, nesse caso, a menor e a maior.
 * DICA: Usar strcmp( ) da biblioteca <string.h> e comparar o resultado com zero.
 * A funcao para a comparacao podera retornar um dentre os seguintes resultados:
 * negativo: se a primeira cadeia preceder a segunda (resultado menor que zero);
 * nulo: se as cadeias forem iguais (resultado igual a zero);
 * positivo: se a primeira cadeia suceder a segunda (resultado maior que zero).
 * Exemplo:
 * char s1 [ ] = “abc”;
 * char s2 [ ] = “ABC”;
 * if ( strcmp ( s1, s2 ) != 0 )
 * {
 * IO_println ( “diferentes” );
 * } // end if
*/
void exercicio10( )
{
//definir variaveis e ler seus valores
    chars x = IO_readstring("\n digite uma string: ");
    chars y = IO_readstring("\n digite outra string: ");
    chars z = IO_readstring("\n digite outra string: ");
//chamar funcao
    analisaString(x, y, z);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio10

/**
 * analisaOrdemChar - analisa ordem de tres caracteres
 * @param x,y,z - caracteres lidos e analisados
*/
void analisaString( chars x, chars y, chars z )
{
//declarar variaveis
    int controle = 0;
    int alfa = 0;
//analisar string
    //string x
    for (int i = 1; i < strlen(x); i++)
    {
        alfa = alfa+ alfabetica( x[i-1], x[i] );
    }//end for
    if (alfa == (strlen(x)-1) *2) 
    {
        IO_printf("\n x esta em ordem alfabetica decrescente.");
    } else if (alfa == (strlen(x)-1))
    {
        IO_printf("\n x esta em ordem alfabetica crescente.");
    } else
    {
        IO_printf("\n x nao esta ordenado.");
    }//end ifelseif
    alfa = 0;
    //string y
    for (int i = 1; i < strlen(y); i++)
    {
        alfa = alfa+ alfabetica( y[i-1], y[i] );
    }//end for
    if (alfa == (strlen(y)-1) *2) 
    {
        IO_printf("\n y esta em ordem alfabetica decrescente.");
    } else if (alfa == (strlen(y)-1))
    {
        IO_printf("\n y esta em ordem alfabetica crescente.");
    } else
    {
        IO_printf("\n y nao esta ordenado.");
    }//end ifelseif
    alfa = 0;
    //string z
    for (int i = 1; i < strlen(z); i++)
    {
        alfa = alfa+ alfabetica( z[i-1], z[i] );
    }//end for
    
    if (alfa == (strlen(z)-1) *2) 
    {
        IO_printf("\n z esta em ordem alfabetica decrescente.");
    } else if (alfa == (strlen(z)-1))
    {
        IO_printf("\n z esta em ordem alfabetica crescente.");
    } else
    {
        IO_printf("\n z nao esta ordenado.");
    }//end ifelseif
    
//comparar cadeias
    //x e y
    if ( strcmp(x, y) == 0 )
    {
        IO_printf("\n x = y.");
    } else if (strcmp(x, y) > 0)
    {
        IO_printf("\n x > y.");
    } else
    {
        IO_printf("\n x < y.");
    }
    //x e z
    if ( strcmp(x, z) == 0 )
    {
        IO_printf("\n x = z.");
    } else if (strcmp(x, z) > 0)
    {
        IO_printf("\n x > z.");
    } else
    {
        IO_printf("\n x < z.");
    }
    //z e y
    if ( strcmp(z, y) == 0 )
    {
        IO_printf("\n z = y.");
    } else if (strcmp(z, y) > 0)
    {
        IO_printf("\n z > y.");
    } else
    {
        IO_printf("\n z < y.");
    }

}//end analisaString

/**
 * alfabetica - analisar se esta na ordem alfabetica
 * @param a, b - letras comparadas
 * @return inteiro indicando alfabetica crescente (1) ou decrescente (2)
*/
int alfabetica( char a, char b )
{
    //para comparar ordem alfabetica independente
    //da ordem tabela ascii (maiuscula ou minuscula)
    if ( a >= 65 && a <= 90)
    {
        a = a + 32;
    }//end if
    if ( b >= 65 && b <= 90)
    {
        b = b + 32;
    }//end if

    if (a == b )
    {
        //sem ordem
        return(0);
    } else if (a > b)
    {
        //decrescente
        return(2);
    } else
    {
        //crescente
        return(1);
    }//end if else if
    
}//end alfabetica

/**
 * 
*/

/**
--------------------------------------------documentacao complementar

--------------------------------------------notas / observacoes / comentarios

--------------------------------------------previsao de testes e testes

- Exercicio 01:
    -Teste 1: quantidades: 5 \ valor: 1 \ valor: 0 \ valor: -1 \ valor: 100 \ valor: -100
     valor 1: positivo impar.
     valor 0: nulo.
     valor -1: negativo impar.
     valor 100: positivo par.
     valor -100: negativo par.

- Exercicio 02:  quantidades: 5
    -Teste 1:
     valores: 1, -2, -4, 4, 6
     maior quantidade de negativos.
    -Teste 2:
     valores: 3, 6, 8, 0, -2
     maior quantidade de positivos.
    -Teste 3:
     valores: -5, 5, -3, 3, 0
     maior quantidade de impares.
    -Teste 4:
     valores: 2, -2, 4, -4, 0
     maior quantidade de positivos.
    -Teste 5:
     valores: 0, 0, -4, 3, 0
     maior quantidade de nulos.

-Exercicio 3:
    -Teste 1: cadeia - !|&=><-+/*% ;:,._aB@('
     operador logico: ! (NOT)       operador logico: | (OR)      operador logico: & (AND)
     operador relacional: = (IGUAL)                     operador relacional: > (MAIOR QUE)
     operador relacional: < (MENOR QUE)                 operador aritmetico: - (SUBTRACAO)
     operador aritmetico: + (SOMA)                      operador aritmetico: / (DIVISAO)
     operador aritmetico: * (MULTIPLICACAO)             operador aritmetico: % (MODULO/RESTO)
     operador separador:   (ESPACO)                     operador separador: ; (PONTO-E-VIRGULA)
     operador separador: : (DOIS PONTOS)                operador separador: , (VIRGULA)
     operador separador: . (PONTO)                      operador separador: _ (UNDERLINE)
     outro simbolo (a).  outro simbolo (B).  outro simbolo (@).  outro simbolo (().  outro simbolo (').
    -Teste 2: cadeia - Ab||Cd=!23.
     outro simbolo (A).          outro simbolo (b).      operador logico: | (OR)
     operador logico: | (OR)     outro simbolo (C).      outro simbolo (d).
     operador relacional: = (IGUAL)                      operador logico: ! (NOT)
     outro simbolo (2).          outro simbolo (3).      operador separador: . (PONTO)

-Exercicio 4:
    -Teste 1: cadeia -  Aa-+=lL/*!|98;0.,><LU|! _opa_=19
     previsao: 4, 5, 5, 12, 6
     resultado: 4 letras maiusculas  5 letras minusculas  5 digitos  12 operadores  6 separadores
    -Teste 2: cadeia: ALZalz&|!+-*%/><= .,;:_0195
     previsao: 3,3,4,11,6
     resultado: 3 letras maiusculas  3 letras minusculas  4 digitos  11 operadores  6 separadores

-Exercicio 5: 
    -Teste 1: quantidades: 7 | valores: -27.25, 47.75, -30.13, -59.67, 50.63, 63.94, 12.78
     media valores < -27.25 : -44.90
     media 47.75 >= valores >= -27.25 : 11.09
     media valores > 47.75 : 57.28
     menor media: -44.90

-Exercicio 6:
    -Teste 1: intervalo ]-5,10[     valores 0, 1, 2, 3, -4, -1
     soma dos cubos inversos de ]-5,10[: 0.1464
    -Teste 2: intervalo ]-10,20[    valores -5, -6, 2, 3, 0, 30, -20, -1
     soma dos cubos inversos de ]a,b[: -0.8506

-Exercicio 7:
    -Teste 1: ERRO - se o valor esta dentro ou fora do intervalo quando intervalos mistos
        ]-10.45, 10.45[ valores: -5.74, -15.67, 13.87, 7.89, 0
        ERRO - acima 7.89 (OBS: nao identificado o motivo)
         valores dentro: 1   valores fora: 3     valores abaixo: 33%    valores acima: 66%
              ERRO - com muitos valores o programa trava e fecha. (OBS: talvez array nao seja a melhor opcao)
    -Teste 2: ]-30.67, -1.67[   valores: 10.43, -2.56,, -40.83, -15.32, 0
     valores dentro: 2   valores fora: 2     valores abaixo: 50%   valores acima: 50%
    -Teste 3: ]1.45, 45.67[ valores: -10.45, -2.34, 9.54, 43.76, 90.45, 0
     valores dentro: 2  valores fora: 3      valores abaixo: 66%   valores acima: 33%

-Exercicio 8: 
    -Teste 1: 10.45, 36.89, 100.63
     estao em ordem crescente 10.45<36.89<100.63
    -Teste 2: 100.54, .98, -10.24
     estao em ordem decrescente 100.54>0.98>-10.24
    -Teste 3: -5.98, -3.85, -16.93
     desordenados: maior -3.85 / menor -16.93
    -Teste 4: 9.43, -9.87, 15.83
     desordenados: maior 15.83 / menor -9.87
    -Teste 5: 109.32, 204.76, -10.54
     desordenados: maior 204.76 / menor -10.54
    -Teste 6: 34.9, 405.32, 274.98
     desordenados: maior 405.32 / menor 34.90
    -Teste 7: 10.45, 10.45, 10.45
     desordenados: 10.45 = 10.45 = 10.45
    -Teste 8: 10.45, 10.45, 98.54
     desordenados: (10.45 = 10.45) != 98.54
    -Teste 9:  10.45, 98.76, 10.45
     desordenados: 10.45 (!= 98.76 !=) 10.45
    -Teste 10: 34.67, 10.45, 10.45
     desordenados: 34.67 != (10.45 = 10.45)

-Exercicio 9:
    -Teste 1: A, b, C
     estao em ordem crescente A<b<C
    -Teste 2: f, e, d
     estao em ordem decrescente f>e>d
    -Teste 3: o, P, Q
     estao em ordem crescente o<P<Q
    -Teste 4: P, A, M
     x, y, z - desordenados.

-Exercicio 10:
    -Teste 1: x = abcdef    y = fedcba    z = opasfef
     x esta em ordem alfabetica crescente.   y esta em ordem alfabetica decrescente.   z nao esta ordenado.
     x < y.      x < z.      z > y.
    -Teste 2: x = luana     y = luana     z = opanes
     x nao esta ordenado.    y nao esta ordenado.    z nao esta ordenado.
     x = y.     x < z.       z > y.
    -Teste 3: x = luanaC    y = LuaNaC    z = luanaC
     x nao esta ordenado.    y nao esta ordenado.    z nao esta ordenado.
     x > y.     x = z.       z > y.
--------------------------------------------historico
Versao       Data        Modificacao
0.1         03/11         esboco
--------------------------------------------versionamento
Exercicio   Versao  Teste   Data    Descricao
   1.0       0.1    (OK)   30/10   - Testar quantidade 'n' de valores.
   2.0       0.1    (OK)   30/10   - Analisar quantidade 'n' de valores.
   3.0       0.1    (OK)   01/11   - Testar quantidade 'n' de caracteres de uma string.
   4.0       0.1    (OK)   01/11   - Analisar quantidade 'n' de caracteres de uma string.
   5.0       0.1    (OK)   02/11   - Calcular as medias de quantidade 'n' de valores em intervalos.
   6.0       0.1    (OK)   02/11   - Calcular a soma dos cubos inversos de valores no intervalo ]a;b[.
   7.0       0.1    (OK)   03/11   - Analisa valores, se estao dentro de um intervalo.
   8.0       0.1    (OK)   02/11   - Analisar ordenamento de tres numeros (x,y,z).
   9.0       0.1    (OK)   02/11   - Analisar ordenamento de tres caracteres (x,y,z).
  10.0       0.1    (OK)   03/11   - Compara e analisa tres strings.
*/
