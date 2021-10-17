/*
    Metodo para testar todos os exercicios em um so' programa
    Exemplo03 - Versao 0.1 - 31/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo03      exemplo03.c
    Windows:    gcc -o exemplo03.exe  exemplo03.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo03
    Windows:    exemplo03
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

//-------------------------------------------------------------

/**
 * letra01( ) - Metodo para ler uma palvra do teclado
 * e mostrar as letras maiusculas menor do que N
 * do começo da palavra ate' o fim
*/
void letra01( )
{
    //definir variaveis com valor inicial
    chars palavra = "0";
    int count = 0, letra = 0;

    //ler do teclado
    palavra = IO_readstring("\nEntre com uma palavra: ");

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(palavra); count++)
    {
        //se caractere na posicao count entre [A,N[
        if (palavra[count] >= 'A' && palavra[count] < 'N')
        {
            //mostrar caracteres seguidos
            IO_printf(" %c ", palavra[count]);
            //validar que atendeu a especificacao
            letra = 1;
        }//end if   
    }//end for
    //se atendeu a especificacao
    if(letra == 1)
    {
        IO_println("sao letras maiusculas menores que N");
    }
    else
    {
        IO_println("NAO existem letras maiusculas menores que N.");
    }//enf id
}//end letra01

/**
    Exercicio01
    - ler uma palavra do teclado;
    - mostrar as letras maiusculas menor que 'N'.
    DICA: Definir um teste para determinar se um 
    caractere é letra maiuscula.
*/
void Exercicio01( )
{
    //identificar
    IO_id("\nEXEMPLO0311 - Programa - v0.1");

    //chamar funcao
    letra01( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio01

//-------------------------------------------------------------

/**
 * letra02( ) - Metodo para ler uma palvra do teclado
 * contar e mostrar as letras maiusculas maiores do que N
 * do começo da palavra ate' o fim
*/
void letra02( )
{
    //definir variaveis com valor inicial
    chars palavra = "0";
    int count = 0, letra = 0, quantidade = 0;

    //ler do teclado
    palavra = IO_readstring("\nEntre com uma palavra: ");

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(palavra); count++)
    {
        //se caractere na posicao count entre ]N,Z]
        if (palavra[count] <= 'Z' && palavra[count] > 'N')
        {
            //mostrar caracteres seguidos
            IO_printf(" %c ", palavra[count]);
            //validar que atendeu a especificacao
            letra = 1;
            //contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(letra == 1)
    {
        IO_printf("\nsao %d letras maiusculas maiores que N", quantidade);
    }
    else
    {
        IO_println("NAO existem letras maiusculas maiores que N.");
    }//end if
}//end letra02

/**
    Exercicio02
    - ler uma palavra do teclado;
    - contar e mostrar apenas as letras 
    maiusculas maiores que 'N'.
*/
void Exercicio02( )
{
    //identificar
    IO_id("\nEXEMPLO0312 - Programa - v0.1");

    //chamar funcao
    letra02( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio02

//-------------------------------------------------------------

/**
 * letra03( ) - Metodo para ler uma palvra do teclado
 * contar e mostrar as letras maiusculas menores do que N
 * do fim da palavra ate' o inicio
*/
void letra03( )
{
    //definir variaveis com valor inicial
    chars palavra = "0";
    int count = 0, letra = 0, quantidade = 0;

    //ler do teclado
    palavra = IO_readstring("\nEntre com uma palavra: ");

    //contar quantidade de letras
    quantidade = strlen(palavra);
    //comparar cada letra repeticao decrescente
    for (count = quantidade; count >= 0; count--)
    {
        //se caractere na posicao count entre [A,N[
        if (palavra[count] >= 'A' && palavra[count] < 'N')
        {
            IO_printf(" %c ", palavra[count]);
            //contar quantidade e validar
            letra = letra + 1;
        }//end if    
    }//end for
    //se valido
    if(letra > 1)
    {
        IO_printf("\nsao %d letras maiusculas menores que N", letra);
    }
    else
    {
        IO_println("NAO existem letras maiusculas menores que N.");
    }//end if
}//end letra03

/**
    Exercicio03
    - ler uma palavra do teclado;
    - contar e mostrar as letras maiusculas menores que 'N', 
    desde o fim até o inicio da palavra.
*/
void Exercicio03( )
{
    //identificar
    IO_id("\nEXEMPLO0313 - Programa - v0.1");

    //chamar funcao
    letra03( );
    
    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio03

//-------------------------------------------------------------

/**
 * letra04( ) - Metodo para ler uma cadeia de caracteres
 * contar e mostrar as letras minusculas ou maiusculas
*/
void letra04( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0";
    int count = 0, letra = 0, quantidade = 0;

    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);
    //comparar cada letra repeticao crescente
    for (count = 0; count < quantidade; count++)
    {
        //se caractere entre [A,Z] E [a,z]
        if ((cadeia[count] >= 'a' && cadeia[count] <= 'z') || 
            (cadeia[count] >= 'A' && cadeia[count] <= 'Z'))
        {   
            //printar cada caractere correspondente
            IO_printf(" %c ", cadeia[count]);
            //contar quantidade de validar
            letra = letra + 1;
        }//end if       
    }//end for
    //se valido
    if(letra > 1)
    {
        IO_printf("\nsao %d letras dentro da cadeia de caracteres.", letra);
    }
    else
    {
        IO_println("NAO existem letras dentro dessa cadeia de caracteres.");
    }//end if
}//end letra04

/**
    Exercicio04
    - ler uma cadeia de caracteres do teclado;
    - contar e mostrar todos simbolos que forem letras, 
    ou maiusculas ou minusculas.
*/
void Exercicio04( )
{
    //identificar
    IO_id("\nEXEMPLO0314 - Programa - v0.1");

    //chamar funcao
    letra04( );
    
    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio04

//-------------------------------------------------------------

/**
 * digito05( ) - Metodo para ler uma cadeia de caracteres
 * contar e mostrar as digitos do fim ao comeco
*/
void digito05( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0";
    int count = 0, digito = 0, quantidade = 0;

    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);
    //comparar cada digito repeticao decrescente
    for (count = quantidade; count >= 0; count--)
    {
        //se caractere entre [0,9]
        if (cadeia[count] >= '0' && cadeia[count] <= '9')
        {
            IO_printf(" %c ", cadeia[count]);
            //contar quantidade de validar
            digito = digito + 1;
        }//end if      
    }//end for
    //se valido
    if (digito > 1)
    {
        IO_printf("\nsao %d digitos dentro da cadeia de caracteres.", digito);
    }
    else
    {
        IO_println("NAO existem digitos dentro dessa cadeia de caracteres.");
    }//end if
}//end digito05

/**
    Exercicio05
    - ler uma cadeia de caracteres do teclado;
    - contar e mostrar todos os digitos, percorrendo desde 
    o fim ate o inicio da cadeia de caracteres.
*/
void Exercicio05( )
{
    //identificar
    IO_id("\nEXEMPLO0315 - Programa - v0.1");

    //chamar funcao
    digito05( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio05

//-------------------------------------------------------------

/**
 * naoDm06( ) - Metodo para ler uma cadeia de caracteres
 * contar e mostrar os caracteres nao digitos e nao minusculas
*/
void naoDm06( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0";
    int count = 0, valido = 0, quantidade = 0;

    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);
    //comparar cada caractere repeticao crescente
    for (count = 0; count < quantidade; count++)
    {
        //se NAO [0,9] OU NAO [a,z]
        if ( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') || 
                (cadeia[count] >= 'a' && cadeia[count] <= 'z')) )
        {
            IO_printf(" %c ", cadeia[count]);
            //contar quantidade e validar
            valido = valido + 1;
        }//end if    
    }//end for
    //se valido
    if (valido > 1)
    {
        IO_printf("\n %d caracteres nao sao digitos nem letras minusculas.", valido);
    }
    else
    {
        IO_println("SO existem digitos e/ou letras minusculas dentro dessa cadeia de caracteres.");
    }//end if 
}//end naoDm06

/**
    Exercicio06
    - ler uma cadeia de caracteres do teclado;
    - contar e mostrar tudo o que nao for digito 
    e tambem nao for letra minuscula.
*/
void Exercicio06( )
{
    //identificar
    IO_id("\nEXEMPLO0316 - Programa - v0.1");

    //chamar funcao
    naoDm06( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio06

//-------------------------------------------------------------

/**
 * valorInt07( ) - Metodo para ler valores inteiros
 * contar e mostrar os que sao multiplos de 2 e 3 e
 * pertencem ao intervalo definido
*/
void valorInt07( )
{
    //definir variaveis com valor inicial
    int intervaloA = 0, intervaloB = 0, quantidade = 0, 
    valores = 0, count = 0, x = 0, total = 0;

    //para receber um intervalo válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readint("\nEntre com um valor inteiro para ser o inicio do intervalo: ");
        intervaloB = IO_readint("Entre com um valor inteiro para ser o fim do intervalo: ");
        //testar se o intervalo e' valido
        if ( intervaloA < intervaloB )
        {
            //se sim, sair da repeticao
            x ++;
        }
        else
        {
            //se nao, retornar invalido 
            IO_println("Intervalo invalido.");
            //e repetir o procedimento
            x = 0;
        }//end if
    } while ( x == 0 );

    //para receber uma quantidade valida > 0
    do{
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint("\nEntre com um valor inteiro para ser a quantidade de valores a serem testados: ");
        //testar se maior que zero
        if ( quantidade > 0 )
        {
            //se sim, sair da repeticao
            x --;
        }
        else
        {
            //se nao, retornar invalido 
            IO_println("Valor invalido.");
            //e repetir o procedimento
            x = 1;
        }//end if
    } while ( x == 1 );

    //repetir o numero de vezes requisitado no passo anterior crescente
    for (count = 0; count < quantidade; count++)
    {
        //entrar com valores a serem testados (1 por vez)
        valores = IO_readint("\nEntre com um valor a ser testado: ");
        //testar se sao multiplos de 2 e 3 e estao no intervalo
        if ((valores % 2 == 0) && (valores % 3 == 0) && (valores >= intervaloA) && (valores <= intervaloB))
        {
            IO_printf("%d e' multiplo de 2 E 3 E pertence ao intervalo.\n", valores);
            total++;
        }
        else
        {
            IO_printf("%d NAO atende todas as especificacoes.\n", valores);
        }//end if
    }//end for

    //mostrar o total de valores
    if (total != 0)
    {
        IO_printf("\nTotal de %d valores multiplos de 2 E 3 E pertencem ao intervalo.", total);
    }
    else
    {
        IO_println("\nOs valores nao estao dentro das especificacoes.");
    }//end if
}//end valorInt07

/**
    Exercicio07
    - ler dois valores inteiros, limites para definirem um intervalo;
    - ler uma quantidade de valores inteiros a serem testados;
    - ler outros tantos valores quantos os indicados pela quantidade, um por vez;
    - contar e mostrar dentre esses valores lidos os que forem multiplos
    de 2 e de 3, ao mesmo tempo, e pertençam ao intervalo.
*/
void Exercicio07( )
{
    //identificar
    IO_id("\nEXEMPLO0317 - Programa - v0.1");

    //chamar funcao
    valorInt07( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio07

//-------------------------------------------------------------

/**
 * valorInt08( ) - Metodo para ler valores inteiros
 * contar e mostrar os que sao multiplos de 3 e nao 5 
 * e pertencem ao intervalo definido
*/
void valorInt08( )
{
    //definir variaveis com valor inicial
    int intervaloA = 0, intervaloB = 0, quantidade = 0, 
    valores = 0, count = 0, x = 0, total = 0;

    //para receber um intervalo válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readint("\nEntre com um valor inteiro para ser o inicio do intervalo: ");
        intervaloB = IO_readint("Entre com um valor inteiro para ser o fim do intervalo: ");
        //testar se o intervalo e' valido
        if ( intervaloA < intervaloB )
        {
            //se sim, sair da repeticao
            x ++;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Intervalo invalido.");
            //e repetir o procedimento
            x = 0;
        }//end if
    } while ( x == 0 );

    //para receber uma quantidade valida > 0
    do{
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint("\nEntre com um valor inteiro para ser a quantidade de valores a serem testados: ");
        //testar se maior que zero
        if ( quantidade > 0 )
        {
            //se sim, sair da repeticao
            x --;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Valor invalido.");
            //e repetir o procedimento
            x = 1;
        }//end if
    } while ( x == 1 );

    //repetir o numero de vezes requisitado no passo anterior
    for (count = 0; count < quantidade; count++)
    {
        //entrar com valores a serem testados (1 por vez)
        valores = IO_readint("\nEntre com um valor a ser testado: ");
        //testar se sao multiplos de 2 e 3 e estao no intervalo
        if ((valores % 3 == 0) && (valores % 5 != 0) && 
            (valores >= intervaloA) && (valores <= intervaloB))
        {
            IO_printf("%d e' multiplo de 3 E NAO 5 E pertence ao intervalo.\n", valores);
            total++;
        }
        else
        {
            IO_printf("%d NAO atende todas as especificacoes.\n", valores);
        }//end if
    }//end for

    //mostrar o total de valores
    if (total != 0)
    {
        IO_printf("\nTotal de %d valores multiplos de 3 E NAO 5 E pertencem ao intervalo.", total);
    }
    else
    {
        IO_println("\nNenhum dos valores estao dentro das especificacoes.");
    }//end if
}//end valorInt08

/**
    Exercicio08
    - ler dois valores inteiros, limites para definirem um intervalo;
    - ler uma quantidade de valores inteiros a serem testados;
    ler outros tantos valores quantos os indicados pela quantidade, uma por vez;
    - contar e mostrar dentre esses valores lidos os que forem multiplos de 3,
    que nao forem tambem multiplos de 5, e pertençam ao intervalo. 
*/
void Exercicio08( )
{
    //identificar
    IO_id("\nEXEMPLO0318 - Programa - v0.1");

    //chamar funcao
    valorInt08( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio08

//-------------------------------------------------------------

/**
 * valorReal09( ) - Metodo para ler valores reais
 * contar e mostrar os que a parte inteira sao impares 
 * e pertencem ao intervalo definido
*/
void valorReal09( )
{
    //definir variaveis com valor inicial
    double intervaloA = 0.0, intervaloB = 0.0, valores = 0.0;
    int quantidade = 0, count = 0, x = 0, total = 0, impar = 0;

    //para receber um intervalo válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readdouble("\nEntre com um valor real para ser o inicio do intervalo: ");
        intervaloB = IO_readdouble("Entre com um valor real para ser o fim do intervalo: ");
        //testar se o intervalo e' valido
        if ( intervaloA < intervaloB )
        {
            //se sim, sair da repeticao
            x ++;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Intervalo invalido.");
            //e repetir o procedimento
            x = 0;
        }//end if
    } while ( x == 0 );

    //para receber uma quantidade valida > 0
    do{
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint("\nEntre com um valor inteiro para ser a quantidade de valores a serem testados: ");
        //testar se maior que zero
        if ( quantidade > 0 )
        {
            //se sim, sair da repeticao
            x --;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Valor invalido.");
            //e repetir o procedimento
            x = 1;
        }//end if
    } while ( x == 1 );

    //repetir o numero de vezes requisitado no passo anterior
    for (count = 0; count < quantidade; count++)
    {
        //entrar com valores reais a serem testados (1 por vez)
        valores = IO_readdouble("\nEntre com um valor a ser testado: ");
        //isolar a parte inteira
        impar = (int) valores;
        //testar se estao no intervalo e se sua parte inteira e' impar
        if ((valores >= intervaloA) && (valores <= intervaloB) && (impar % 2 != 0))
        {
            IO_printf("%f pertence ao intervalo e sua parte inteira (%d) e' impar.\n", valores, impar);
            total++;
        }
        else
        {
            IO_printf("%f NAO atende todas as especificacoes.\n", valores);
        }//end if
    }//end for

    //mostrar o total de valores
    if (total != 0)
    {
        IO_printf("\nTotal de %d valores que pertencem ao intervalo [%f, %f] E tem a parte inteira impar.", total, intervaloA, intervaloB);
    }
    else
    {
        IO_println("\nNenhum dos valores estao dentro das especificacoes.");
    }//end if
}//end valorReal09

/**
    Exercicio09
    - ler dois valores reais, o primeiro menor que o segundo, confirmadamente,
    para definirem um intervalo;
    - ler a quantidade de valores reais a serem testados, e
    ler outros tantos valores quantos os indicados por essa quantidade;
    - contar e mostrar todos os valores lidos, pertencentes ao do intervalo,
    cujas partes inteiras forem numeros impares.
    DICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int),
    antes de testar se e par (ver Exemplo0110). 
*/
void Exercicio09( )
{
    //identificar
    IO_id("\nEXEMPLO0319 - Programa - v0.1");

    //chamar funcao
    valorReal09( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio09

//-------------------------------------------------------------

/**
 * valorReal10( ) - Metodo para ler valores reais
 * contar e mostrar os que estao dentro do intervalo 
 * real de precisao 
*/
void valorReal10( )
{
    //definir variaveis com valor inicial
    double intervaloA = 0.0, intervaloB = 0.0, valores = 0.0, fracao = 0.0;
    int quantidade = 0, count = 0, x = 0, total = 0, inteiro = 0;

    //para receber um intervalo de precisao válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readdouble("\nEntre com um valor real > 0 para ser o inicio do intervalo: ");
        intervaloB = IO_readdouble("Entre com um valor real < 1 para ser o fim do intervalo: ");
        //testar se o intervalo e' valido
        if ((intervaloA > 0.0) && (intervaloB < 1.0) && (intervaloA < intervaloB ))
        {
            //se sim, sair do procedimento
            x ++;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Intervalo invalido.");
            //e repetir o procedimento
            x = 0;
        }//end if
    } while ( x == 0 );

    //para receber uma quantidade valida > 0
    do{
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint("\nEntre com um valor inteiro para ser a quantidade de valores a serem testados: ");
        //testar se maior que zero
        if ( quantidade > 0 )
        {
            //se sim, sair do procedimento
            x --;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Valor invalido.");
            //e repetir o procedimento
            x = 1;
        }//end if
    } while ( x == 1 );

    //repetir o numero de vezes requisitado no passo anterior
    for (count = 0; count < quantidade; count++)
    {
        //entrar com valores reais a serem testados (1 por vez)
        valores = IO_readdouble("\nEntre com um valor real a ser testado: ");
        //parte interia
        inteiro = (int) valores;
        //isolar a parte fracionaria
        fracao = valores - inteiro;
        //testar se parte fracionaria esta dentro do intervalo de precisao 
        if ((fracao >= intervaloA) && (fracao <= intervaloB))
        {
            IO_printf("%f parte fracionaria de %f esta dentro do intervalo de precisao.\n", fracao, valores);
            total++;
        }
        else
        {
            IO_printf("%f NAO esta' dentro do intervalo de precisao.\n", valores);
        }//end if
    }//end for

    //mostrar o total de valores
    if (total != 0)
    {
        IO_printf("\nTotal de %d valores dentro do intervalo [%f, %f] de precisao.", total, intervaloA, intervaloB);
    }
    else
    {
        IO_println("\nNenhum dos valores estao dentro do inteervalo de precisao.");
    }//end if
}//end valorReal10

/**
    Exercicio10
    - ler dois valores reais, maiores que 0 e menores que 1, confirmadamente,
    para definirem um intervalo de precisao;
    - ler uma quantidade de valores reais a serem testados, e
    ler outros tantos valores quantos os indicados por essa quantidade;
    - contar e mostrar todos os valores lidos
    que tenham suas partes fracionarias dentro do intervalo de precisao.
    DICA: Usar conformacao de tipo (type casting) para isolar a parte inteira (int),
    e obter a parte fracionaria mediante a subtracao da parte inteira, antes de testar.
*/
void Exercicio10( )
{
    //identificar
    IO_id("\nEXEMPLO0320 - Programa - v0.1");

    //chamar funcao
    valorReal10( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio10

//-------------------------------------------------------------

/**
 * cadeiaE1( ) - Metodo para ler uma linha do teclado
 * separar em uma cadeia com simbolos nao alfanumericos
*/
void cadeiaE1( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0", cadeia2 = " ";
    char nova = '0';
    int count = 0, valido = 0, quantidade = 0;

    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);

    //comparar cada caractere
    for (count = 0; count < quantidade; count++)
    {
        //se NAO [a,z] ou NAO [A,Z] ou NAO [0,9]
        if ( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') || 
                (cadeia[count] >= 'a' && cadeia[count] <= 'z') || 
                (cadeia[count] >= 'A' && cadeia[count] <= 'Z')) )
        {
            IO_printf("%c", cadeia[count]);     //printa caractere por caractere
            valido = valido + 1;                //para validar a cadeia
            nova = cadeia[count];               //atribuindo ao caractere novo
            //concatenar cadeia2 atual com novo caractere
            cadeia2 = IO_concat(cadeia2, IO_toString_c(nova));  
        }//end if        
    }//end for
    //se valido
    if (valido > 1)
    {
        IO_printf("\n\n %s e' a cadeia de caracteres SO' com os simbolos nao alfanumericos.", cadeia2);
    }
    else
    {
        IO_println("NAO existem simbolos nao alfanumericos.");
    }//end if
}//end cadeiaE1

/**
    ExercicioE1
    - ler uma linha do teclado;
    - separar em outra cadeia de caracteres e mostrar
    todos os simbolos nao alfanumericos (letras ou 
    digitos) na cadeia de caracteres.
*/
void ExercicioE1( )
{
    //identificar
    IO_id("\nEXEMPLO03E1 - Programa - v0.1");

    //chamar funcao
    cadeiaE1( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end ExercicioE1

//-------------------------------------------------------------

/**
 * cadeiaE2( ) - Metodo para ler uma linha do teclado
 * dizer se sequencia contem apenas simbolos
 * nao letras e nao digitos
*/
void cadeiaE2( )
{
    //definir variaveis com valor inicial
    chars cadeia = "0";
    int count = 0, valido = 0, quantidade = 0;

    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia: ");

    //contar quantidade de caracteres
    quantidade = strlen(cadeia);

    //comparar cada caractere, verificar se ha simbolos apenas
    for (count = 0; count < quantidade; count++)
    {
        //se NAO [a,z] ou NAO [A,Z] ou NAO [0,9]
        if ( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') || 
                (cadeia[count] >= 'a' && cadeia[count] <= 'z') || 
                (cadeia[count] >= 'A' && cadeia[count] <= 'Z')) )
        {
            valido = valido + 1;         //para validar a cadeia
        }//end if        
    }//end for
    //se valor contado de simbolos for igual ao valor total de caracteres
    if (valido == quantidade)
    {
        IO_println("Essa sequencia possui apenas simbolos nao alfanumericos.");
    }
    else
    {
        IO_println("Existem outros simbolos alfanumericos na sequencia.");
    }//end if
}//end cadeiaE2

/**
    ExercicioE2
    - ler uma cadeia de caracteres do teclado;
    - dizer se a sequencia contem apenas simbolos
    que nao sao letras, nem digitos.
*/
void ExercicioE2( )
{
    //identificar
    IO_id("\nEXEMPLO03E2 - Programa - v0.1");

    //chamar funcao
    cadeiaE2( );

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end ExercicioE2

//-------------------------------------------------------------

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
        IO_println(" 1 - Exercicio1(EXEMPLO0311)  |  2 - Exercicio2(EXEMPLO0312) |  3 - Exercicio3(EXEMPLO0313)");
        IO_println(" 4 - Exercicio4(EXEMPLO0314)  |  5 - Exercicio5(EXEMPLO0315) |  6 - Exercicio6(EXEMPLO0316)");
        IO_println(" 7 - Exercicio7(EXEMPLO0317)  |  8 - Exercicio8(EXEMPLO0318) |  9 - Exercicio9(EXEMPLO0319)");
        IO_println("10 - Exercicio10(EXEMPLO0320) | 11 - Extra01(EXEMPLO03E1)    | 12 - Extra02(EXEMPLO03E2)");
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
    IO_pause("Apertar <enter> para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         09/09          esboco
---------------------------------------------- testes
Exercicio    Versao  Teste
 0.1  02/09 - 01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do comeco
 0.2  02/09 - 01.   ( OK )  - letras maiusculas de uma palavra maior que 'N' do comeco
 0.3  04/09 - 01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do fim
 0.4  09/09 - 02.   ( OK )  - letras dentro de uma cadeia de caracteres 
 0.5  06/09 - 01.   ( OK )  - digitos dentro de uma cadeia de caracteres do fim
 0.6  08/09 - 01.   ( OK )  - nao digitos e nao letra minuscula dentro de uma cadeia de caracteres
 0.7  08/09 - 01.   ( OK )  - certa quantidade de valores inteiros dentro de um intervalo e multiplos de 2 E 3
 0.8  08/09 - 01.   ( OK )  - certa quantidade de valores inteiros dentro de um intervalo e multiplos de 3 E NAO 5
 0.9  08/09 - 01.   ( OK )  - certa quantidade de valores reais dentro de um intervalo e impares
 1.0  08/09 - 01.   ( OK )  - certa quantidade de valores reais dentro de um intervalo de precisao
 E.1  09/09 - 01.   ( OK )  - nova cadeia de caracteres nao alfanumericos a partir da inicial
 E.2  09/09 - 01.   ( OK )  - se sequencia possui apenas simbolos que nao letras ou numeros
*/