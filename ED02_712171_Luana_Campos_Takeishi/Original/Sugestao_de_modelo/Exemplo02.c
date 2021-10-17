/*
    Proposta de metodo para testar todos os exercicios 
    em um so' programa (com switch-case)
    obs: somente os exercicios a partir do Exemplo10
    Exemplo02 - Versao 0.1 - 1/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo02      exemplo02.c
    Windows:    gcc -o exemplo02.exe  exemplo02.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo02
    Windows:    exemplo02
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
    Parar - nao faz nada.
*/
void Parar( )
{
    //nao faz nada
}//end Parar




/*
    value01 - funcao para testar se um valor inteiro e'par ou impar
    @param ip - valor a ser testado e exibido
*/
void value01 ( int ip )
{
    //definir dado
    int o = ip;       //definir variavel com valor inicial

    //testar o valor e mostrar os resultados
    if (o < 0)
    {
        //para resolver o problema dos numeros negativos impares
        o = ip * (-1);     
    }
    if ((o % 2) == 1) 
    {
        //se resto = 1 -> impar
        IO_printf("Valor (%d) e' impar", ip);
    } 
    else
    {
        if (o != 0)
        {
            //se resto = 0 e valor != 0 -> par
            IO_printf("Valor (%d) e' par", ip);
        }
        else
        {
            //se valor = 0 -> nenhuma das opcoes
            IO_printf("Valor (%d) e' nao e' par nem impar", ip);
        }//end if
    }//end if
}//end value01( )

/**
    Exercicio01 - teste valor inteiro impar ou par
    @funcao value01( )
*/
void Exercicio01( )
{
    //definir dado
    int ip = 0;       //definir variavel com valor inicial

    //identificar
    IO_id("\nEXEMPLO0211 - Programa - v0.3");
    
    //ler do teclado
    ip = IO_readint ("\nEntrar com um valor inteiro: ");
    
    //testar valor e mostrar resultado
    value01( ip );

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio01




/*
    value02 - funcao para testar se um valor inteiro par ou impar
    com restricoes
    @param ip - valor a ser testado e exibido
*/
void value02 ( int ip )
{
    //definir dado
    int o = ip;       //definir variavel com valor inicial

    //testar o valor e mostrar os resultados
    if (o < 0)
    {
        //para resolver o problema dos numeros negativos impares
        o = ip * (-1);     
    }
    if ((o % 2) == 1) 
    {
        if (ip < 100)       //impar
        {
            //se resto = 1 -> impar, para valor < 100
            IO_printf("Valor (%d) e' impar e menor que 100", ip);
        }
        else
        {
            //se resto = 1 -> impar, para valor > 100
            IO_printf("Valor (%d) impar nao esta' entre os numeros definidos", ip);
        }//end if
        
    } 
    else
    {
        if (o != 0)
        {
            if (ip > (-100))    //par
            {
                //se resto = 0 e valor != 0 -> par, para valor > -100
                IO_printf("\nValor (%d) e' par e maior que -100", ip);
            }
            else
            {
                //se resto = 0 e valor != 0 -> par, para valor < -100
                IO_printf("\nValor (%d) par nao esta' entre os numeros definidos", ip);
            }//end if
            
        }
        else                    //nulo
        {
            //se valor = 0 -> nenhuma das opcoes
            IO_printf("\nValor (%d) e' nao e' par nem impar", ip);
        }//end if
    }//end if
}//end value02( )

/**
    Exercicio02 - teste de valor inteiro impar ou par com restricoes 
    @funcao value02( )
*/
void Exercicio02( )
{
    //definir dado
    int ip = 0;       //definir variavel com valor inicial

    //identificar
    IO_id("\nEXEMPLO0212 - Programa - v0.1");

    //ler do teclado
    ip = IO_readint ("\nEntrar com um valor inteiro: ");
    
    //testar valor e mostrar resultado
    value02( ip );

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio02




/*
    interv03 - funcao para testar se o valor inteiro esta entre ]20:64[
    @param a - valor a ser testado e exibido
*/
void interv03 ( int a )
{
    //teste do valor e exibicao do resultado
    if ( (a > 20) && (a < 64) )
    {
        IO_printf("Valor (%d) pertence ao intervalo ]20:64[", a);
    }
    else
    {
        IO_printf("Valor (%d) NAO pertence ao intervalo ]20:64[", a);
    }//end if
}//end interv03( )

/**
    Exercicio03 - teste se valor inteiro pertence a um conjunto
    @funcao interv03( )
*/
void Exercicio03( )
{
    //definir dado
    int a = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO0213 - Programa - v0.1");
    
    //ler do teclado
    a = IO_readint ("\nEntrar com um valor inteiro: ");
    
    //testar valor e mostrar resultado
    interv03( a );
    
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio03




/*
    interv04 - funcao para testar se o valor inteiro
    e' par e esta entre [20:64]
    @param a - valor a ser testado e exibido
*/
void interv04 ( int a )
{
    //definir dados
    int o = a % 2;      //teste (do resto) se variavel e' par

    //teste do valor e exibicao do resultado
    if ( (a >= 20) && (a <= 64) && (o == 0) )
    {
        IO_printf("Valor (%d) e' par e pertence ao intervalo [20:64]", a);
    }
    else
    {
        IO_printf("Valor (%d) NAO corresponde as especificacoes", a);
    }//end if
}//end interv04( )

/**
    Exercicio04 - teste se valor inteiro par pertence a um conjunto
    @funcao interv04( )
*/
void Exercicio04( )
{
    //definir dado
    int a = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO0214 - Programa - v0.1");
    
    //ler do teclado
    a = IO_readint ("\nEntrar com um valor inteiro: ");
    
    //testar valor e mostrar resultado
    interv04( a );

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio04




/*
    interv05 - funcao para testar se o valor 
    esta entre B[15:48] e C[33:75] ou so' em um
    @param a - valor a ser testado e exibido
*/
void interv05 ( int a )
{
    if ( (a >= 15) && (a <= 75) )     //se em algum desses intervalos
    {
        if ( (a >= 33) && (a <= 48) ) //se nos dois intervalos
        {
            IO_printf("Valor (%d) pertence aos intervalos [15:48] e [33:75]", a);
        }
        else
        {
            if ((a >= 15) && (a < 33))     //se somente no intervalo B
            {
                IO_printf("Valor (%d) pertence somente ao intervalo [15:48]", a);
            }//end if
            if ((a > 48) && (a <= 75))     //se somente no intervalo C
            {
                IO_printf("Valor (%d) pertence somente ao intervalo [33:75]", a);
            }//end if
        }//end if
    }
    else    //nenhum dos intervalos
    {
        IO_printf("Valor (%d) NAO pertence 'a nenhum intervalo", a);
    }//end if
}//end interv05( )

/**
    Exercicio05 - teste se valor esta dentro de intervalos
    @funcao interv05( )
*/
void Exercicio05( )
{
    //definir dado
    int a = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO0215 - Programa - v0.1");
    
    //ler do teclado
    a = IO_readint ("\nEntrar com um valor inteiro: ");
    
    //testar valor e mostrar resultado
    interv05( a );

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio05




/*
    value06 - funcao para testar se o primeiro valor
    e' impar e o segundo e' par
    @param ip1 e ip2 - valores a serem testados e exibidos
*/
void value06 ( int ip1, int ip2 )
{
    //definir dado
    int t1 = ip1, t2 = ip2;       //definir variaveis com valor inicial

    //testar os valores e mostrar os resultados
    if ( ip1 < 0)
    {
        //para resolver o problema dos numeros negativos impares
        t1 = ip1 * (-1);     
    }
    if ( ip2 < 0)
    {
        //para resolver o problema dos numeros negativos impares
        t2 = ip2 * (-1);     
    }

    //calculando o resto
    t1 = t1 % 2;
    t2 = t2 % 2;

    //testando as condicoes
    if ( (t1 == 1) && (t2 == 0) && (ip1 != 0) && (ip2 != 0) ) 
    {
        //se resto = 1 -> impar | se resto = 0 e valor != 0 -> par
        IO_printf("Valor 01 - (%d) e' impar e valor 02 - (%d) e' par", ip1, ip2);
    } 
    else
    {
        //se nao, nenhum dos resultados possiveis
         IO_printf("Valor 01 - (%d) e valor 02 - (%d) nao se encaixam na especificacao", ip1, ip2);
    }//end if
}//end value06( )

/**
    Exercicio06 - teste se valor 1 e' impar e 2 e' par
    @funcao value06( )
*/
void Exercicio06( )
{
    //definir dado
    int ip1 = 0, ip2 = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO0216 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com dois valores inteiros: ");
    scanf("%d %d", &ip1, &ip2);
    
    //testar valor e mostrar resultado
    value06 (ip1, ip2);

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio06




/*
    value07 - funcao para testar se o primeiro valor
    e' impar positivo e o segundo e' par negativo
    @param ip1 e ip2 - valores a serem testados e exibidos
*/
void value07 ( int ip1, int ip2 )
{
    //definir dado
    int t1 = ip1, t2 = ip2;       //definir variaveis com valor inicial

    //testar os valores e mostrar os resultados
    if ( ip1 < 0)
    {
        //para resolver o problema dos numeros negativos impares
        t1 = ip1 * (-1);     
    }
    if ( ip2 < 0)
    {
        //para resolver o problema dos numeros negativos impares
        t2 = ip2 * (-1);     
    }

    //calculando o resto
    t1 = t1 % 2;
    t2 = t2 % 2;

    //testando as condicoes
    if ( (t1 == 1) && (t2 == 0) && (ip1 > 0) && (ip2 < 0) ) 
    {
        //se resto = 1 -> impar | se resto = 0 e valor != 0 -> par
        IO_printf("Valor 01 - (%d) e' impar positivo e valor 02 - (%d) e' par negativo", ip1, ip2);
    } 
    else
    {
        //se nao, nenhum dos resultados possiveis
         IO_printf("Valor 01 - (%d) e valor 02 - (%d) nao se encaixam na especificacao", ip1, ip2);
    }//end if
}//end value07( )

/**
    Exercicio07 - teste de valores inteiros
    impar positivo e par negativo
    @funcao value07( )
*/
void Exercicio07( )
{
    //definir dado
    int ip1 = 0, ip2 = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO0217 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com dois valores inteiros: ");
    scanf("%d %d", &ip1, &ip2);
    
    //testar valor e mostrar resultado
    value07 (ip1, ip2);

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio07




/*
    compAB08 - funcao para comparar dois valores reais
    @param a e b - valores a serem testados e exibidos
*/
void compAB08 ( double a, double b )
{
    //definir dado
    double d = 0.0;       //definir variavel com valor inicial

    //testar os valores e mostrar os resultados
    //calculando o dobro
    d = a * 2;

    //testando as condicoes
    if ( d > b ) 
    {
        //se o dobro maior que
        IO_printf("(%lf) dobro do valor (%lf) e' MAIOR que (%lf)", d, a, b);
    } 
    else
    {
        if ( d < b ) 
        {
            //se o dobro menor que
            IO_printf("(%lf) dobro do valor (%lf) e' MENOR que (%lf)", d, a, b);
        } 
        else
        {
            if ( d == b ) 
            {
                //se o dobro igual a
                IO_printf("(%lf) dobro do valor (%lf) e' IGUAL a (%lf)", d, a, b);
            }//end if
        }//end if
    }//end if
}//end CompAB08( )

/**
    Exercicio08 - comparacao de dois valores reais
    @funcao compAB08( )
*/
void Exercicio08( )
{
    //definir dado
    double a = 0.0, b = 0.0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO0218 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com dois valores reais: ");
    scanf("%lf %lf", &a, &b);
    
    //testar valor e mostrar resultado
    compAB08 (a, b);

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio08




/*
    compABC09 - funcao para comparar tres valores reais
    @param a, b e c - valores a serem testados e exibidos
*/
void compABC09 ( double a, double b, double c )
{
    //testar os valores e mostrar os resultados
    if ( (a != b) && (b != c) && (a != c) )     //se todos diferentes
    {
        if ( (a>b) && (a<c) )   //se a esta' entre b e c (BAC)
        {
            IO_printf("(%lf) < (%lf) < (%lf)", b, a, c);
        }
        else
        {
            IO_printf("Valores (%lf) (%lf) (%lf) nao se encaixam na opcao", a, b, c);
        }        
    } 
    else
    {
        IO_printf("Valores (%lf) (%lf) (%lf) sao iguais", a, b, c);
    }//end if
}//end CompABC09( )

/**
    Exercicio09 - comparacao de tres valores reais com especificacoes
    @funcao compABC09( )
*/
void Exercicio09( )
{
    //definir dado
    double a = 0.0, b = 0.0, c = 0.0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO0219 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com tres valores reais: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    //testar valor e mostrar resultado
    compABC09 (a, b, c);

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio09




/*
    compABC10 - funcao para comparar tres valores reais
    @param a, b e c - valores a serem testados e exibidos
*/
void compABC10 ( double a, double b, double c )
{
    //definicao de variavel
    double d = a / 2;      //definindo a metade do valor

    //testar os valores e mostrar os resultados
    if ( (d != b) && (b != c) && (d != c) )     //se todos diferentes
    {
        if ( (d>b) && (d<c) )   //se d esta' entre b e c (BAC)
        {
            IO_printf("(%lf) < (%lf) < (%lf)", b, d, c);
        }
        else
        {
            IO_printf("(%lf) (metade de (%lf)), (%lf) e (%lf) nao se encaixam na opcao", d, a, b, c);
        }        
    } 
    else
    {
        IO_printf("(%lf) (metade de (%lf)), (%lf) e (%lf) sao iguais", d, a, b, c);
    }//end if
}//end CompABC10( )

/**
    Exercicio10 - comparacao de tres valores reais com especificacoes
    @funcao compABC10( )
*/
void Exercicio10( )
{
    //definir dado
    double a = 0.0, b = 0.0, c = 0.0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO0220 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com tres valores reais: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    //testar valor e mostrar resultado
    compABC10 (a, b, c);
    
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio10




/*
    compABCe1 - funcao para comparar tres valores literais
    @param a, b e c - valores de caracteres a serem testados e exibidos
*/
void compABCe1 ( char a, char b, char c )
{
    //testar os valores e mostrar os resultados
    if ( (a != b) && (b != c) && (a != c) ) //se todos diferentes
    {
        if ( (a > b) && (a < c) ) //se a esta' entre b e c (BAC)
        {
            IO_printf(" (%c) < (%c) < (%c)", b, a, c);
        }
        else
        {
            IO_printf(" (%c) (%c) (%c) sao diferentes e nao se encaixam na opcao", a, b, c);
        }//end if
    }//end if
    else
    {
        if ( (a == b) && (a != c) ) //se igual ao segundo
        {
            IO_printf(" (%c) e (%c) sao iguais", a, b);
        }
        else
        {
            if ( (a == c) && (a != b) ) //se igual ao terceiro
            {
                IO_printf(" (%c) e (%c) sao iguais", a, c);
            }
            else
            {
                if ( (a == b) && (a == c) ) //se todos iguais
                {
                    IO_printf(" (%c) (%c) (%c) sao iguais", a, b, c);
                }
                else
                {
                    IO_printf(" (%c) (%c) (%c) nao se encaixam na opcao", a, b, c);
                }//end if
            }//end if
        }//end if
    }//end if
}//end CompABCe1( )

/**
    ExercicioE1 - comparacao de tres valores literais
    @funcao compABCe1( )
*/
void ExercicioE1( )
{
    //definir dado
    char a = '0', b = '0', c = '0';       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO02E1 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com tres valores literais: ");
    scanf("\n %c %c %c", &a, &b, &c); 
    
    //testar valor e mostrar resultado
    compABCe1 (a, b, c);

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end ExercicioE1




/*
    compABCe2 - funcao para comparar tres valores literais
    @param a, b e c - valores de caracteres a serem testados e exibidos
*/
void compABCe2 ( char a, char b, char c )
{
    //testar os valores e mostrar os resultados
    if ( (a != b) && (b != c) && (a != c) ) //se todos diferentes
    {
        if ( (b < c) && (! ((a > b) && (a < c))) ) //se a esta' fora de [b, c]
        {
            IO_printf(" (%c) esta' fora do intervalo [%c, %c]", a, b, c);
        }
        else
        {
            if ( (b > c) && (! ((a < b) && (a > c))) ) //se a esta' fora de [c, b]
            {
                IO_printf(" (%c) esta' fora do intervalo [%c, %c]", a, c, b);
            }
            else
            {
                IO_printf(" (%c) (%c) (%c) sao diferentes e nao se encaixam na opcao", a, b, c);
            }//end if
        }//end if
    }//end if
    else
    {
        IO_printf(" (%c) (%c) (%c) nao se encaixam na opcao", a, b, c);
    }//end if
}//end CompABCe2( )

/**
    ExercicioE2 - comparacao de tres valores literais
    @funcao compABCe2( )
*/
void ExercicioE2( )
{
    //definir dado
    char a = '0', b = '0', c = '0';       //definir variavel com valor inicial
    
    //identificar
    IO_id("\nEXEMPLO02E2 - Programa - v0.1");
    
    //ler do teclado
    printf("\nEntrar com tres valores literais: ");
    scanf("\n %c %c %c", &a, &b, &c);
    
    //testar valor e mostrar resultado
    compABCe2 (a, b, c);

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end ExercicioE2




/*
    Funcao principal.
    @return codigo de encerramento
*/
int main( )
{
    //definir dado com valor inicial
    int x = 0;

    //repetir ate desejar parar
    do
    {
        //ler do teclado
        IO_println("\nOpcoes");
        IO_println(" 0 - Parar");
        IO_println(" 1 - Exercicio1(EXEMPLO0211)  |  2 - Exercicio2(EXEMPLO0212) |  3 - Exercicio3(EXEMPLO0213)");
        IO_println(" 4 - Exercicio4(EXEMPLO0214)  |  5 - Exercicio5(EXEMPLO0215) |  6 - Exercicio6(EXEMPLO0216)");
        IO_println(" 7 - Exercicio7(EXEMPLO0217)  |  8 - Exercicio8(EXEMPLO0218) |  9 - Exercicio9(EXEMPLO0219)");
        IO_println("10 - Exercicio10(EXEMPLO0220) | 11 - Extra01(EXEMPLO02E1)    | 12 - ExtraE2(EXEMPLO02E2)");
        x = IO_readint("\nEntrar com uma opcao: ");

        //testar valor
        //escolha do exercicio a ser executado
        switch (x)
        {
        case 0:
            Parar( );
            break;
        case 1:
            Exercicio01( );
            break;
        case 2:
            Exercicio02( );
            break;
        case 3:
            Exercicio03( );
            break;
        case 4:
            Exercicio04( );
            break;
        case 5:
            Exercicio05( );
            break;
        case 6:
            Exercicio06( );
            break;
        case 7:
            Exercicio07( );
            break;
        case 8:
            Exercicio08( );
            break;
        case 9:
            Exercicio09( );
            break;
        case 10:
            Exercicio10( );
            break;
        case 11:
            ExercicioE1( );
            break;
        case 12:
            ExercicioE2( );
            break;

        default:
            IO_println("\nValor diferente das opcoes");
            break;
        }//end switch-case
    } while ( x!=0 ); //end do-while
    
    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
erro: nesse modelo nos exercicios EXTRAS 01 e 02, ao entrar com
os valores, o primeiro esta sendo reconhecido como nulo
modificao, na leitura das variaveis estava sendo identificado o primeiro
caractere como '\n', adicionando um \n na leitura o erro foi corrigido
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         01/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       03.   ( OK )  - 26/08 - classificar valor inteiro em par/impar
 0.2       01.   ( OK )  - 26/08 - classificar valor inteiro par/impar com restricao
 0.3       01.   ( OK )  - 26/08 - teste se valor inteiro pertence ao conjunto ]20:64[
 0.4       01.   ( OK )  - 26/08 - teste valor inteiro par pertence ao conjunto [20:64]
 0.5       01.   ( OK )  - 26/08 - teste valor inteiro entre intervalos [15:48] [33:75]
 0.6       01.   ( OK )  - 26/08 - teste dois valores inteiros, se impar e par respectivamente
 0.7       01.   ( OK )  - 27/08 - teste dois valores inteiros, impar e par, positivo e negativo
 0.8       01.   ( OK )  - 27/08 - teste comparacao de dois valores reais 
 0.9       01.   ( OK )  - 27/08 - teste comparacao de tres valores reais (especificacoes)
 1.0       01.   ( OK )  - 27/08 - teste comparacao de tres valores reais (especificacoes)
 E.1       01.   ( OK )  - 27/08 - teste comparacao valor literal entre um intervalo
 E.2       01.   ( OK )  - 27/08 - teste comparacao valor literal fora do intervalo
*/