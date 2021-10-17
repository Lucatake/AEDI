/**
    Metodo para testar todos os exercicios em um so' programa
    Exemplo04 - Versao 0.1 - /09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo04      exemplo04.c
    Windows:    gcc -o exemplo04.exe  exemplo04.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo04
    Windows:    exemplo04
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * Parar - nao faz nada.
*/
void Parar( )
{
    //nao faz nada
}//end Parar

//----------------------------------------------------------------------------------

/**
 * Exercicio01
    - ler dois valores reais para definir um intervalo fechado;
    - ler certa quantidade de valores reais e
    - contar quantos desses valores são pares e estão dentro do 
      intervalo, e quantos estão fora dele.
*/
void Exercicio01( )
{
    //identificar
    IO_id("\nEXEMPLO0411 - Programa - v0.1");

    //definir variaveis com valor inicial
    double intervaloA = 0.0, intervaloB = 0.0, valores = 0.0;
    chars pares = "";
    int quantidade = 0, count = 0, x = 0, totalD = 0, totalF = 0, inteiro = 0;

    //para receber um intervalo de precisao válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readdouble("\nValor real (inicio do intervalo): ");
        intervaloB = IO_readdouble("Valor real (fim do intervalo): ");
        //testar se o intervalo e' valido
        if (intervaloA < intervaloB )
        {
            //se sim, sair do procedimento
            x = 1;
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
        quantidade = IO_readint("\nQuantidade de valores testados (inteiro): ");
        //testar se maior que zero
        if ( quantidade > 0 )
        {
            //se sim, sair do procedimento
            x = 0;
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
        //entrar com os valores reais separados por espaco
        valores = IO_readdouble("\nEntre com valores reais: ");
        //separar parte inteira
        inteiro = (int) valores;
        //se esta' dentro do intevalo
        if(valores >= intervaloA && valores <= intervaloB)
        {
            //se parte inteira e' par
            if(inteiro % 2 == 0)
            {
                //concatenar valores
                pares = IO_concat(IO_concat(pares, 
                        IO_toString_f(valores)), ", ");
                //contar quantidade de valores dentro
                totalD++;
            }//end if
        }
        else
        {
            //contar quantidade de valores fora
            totalF++;
        }
        //end if
    }//end for

    //mostrar o total de valores
    if (totalD != 0)
    {
        IO_printf("\n%ssao %d valores pares dentro do intervalo [%f, %f]", 
                    pares, totalD, intervaloA, intervaloB);
        IO_printf("\n e %d valores estao fora do intervalo [%f, %f].", 
                    totalF, intervaloA, intervaloB);
    }
    else
    {
        IO_println("\nNenhum dos valores estao dentro do intervalo.");
    }//end if

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio01

//----------------------------------------------------------------------------------

/**
 * Exercicio02
    - ler uma sequencia de caracteres do teclado;
    - contar e mostrar a quantidade de letras maiusculas.
*/
void Exercicio02( )
{
    //identificar
    IO_id("\nEXEMPLO0412 - Programa - v0.1");

    //definir variaveis com valor inicial
    chars cadeia = "0", letras = "";
    int count = 0, letra = 0, quantidade = 0;

    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula
        if (cadeia[count] >= 'A' && cadeia[count] <= 'Z')
        {
            //concatenar caracteres
            letras = IO_concat(IO_toString_c(cadeia[count]), letras);
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade != 0)
    {
        IO_printf("\n[%s] sao %d letras maiusculas.", letras, quantidade);
    }
    else
    {
        IO_println("NAO existem letras maiusculas.");
    }//end if

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio02

//----------------------------------------------------------------------------------

void letraMn03(chars cadeia);
/**
 * Exercicio03
    - ler uma sequencia de caracteres do teclado;
    - mostrar a quantidade de letras maiusculas menores 
    que 'N' contadas por uma função definida para receber 
    uma cadeia de caracteres como parametro.
    @param void letraMn03(chars cadeia);
*/
void Exercicio03( )
{
    //identificar
    IO_id("\nEXEMPLO0413 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    letraMn03(cadeia);

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio03

/**
 * letraMn03( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar e  as letras maiusculas < 'N'
 * @param cadeia - caracteres a serem testados
*/
void letraMn03(chars cadeia)
{
    //definir variaveis com valor inicial
    int count = 0, letra = 0, quantidade = 0;

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula menor que 'N'
        if (cadeia[count] >= 'A' && cadeia[count] < 'N')
        {
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade != 0)
    {
        IO_printf("\nSao %d letras maiusculas menores que 'N'.", quantidade);
    }
    else
    {
        IO_println("NAO existem letras maiusculas menores que 'N'.");
    }//end if
}//end letraMn03

//----------------------------------------------------------------------------------

void letraMn04(chars cadeia);
/**
 * Exercicio04
    - ler uma sequencia de caracteres do teclado;
    - mostrar as letras maiusculas menores que 'N' separadas em 
    outra cadeia mediante uma funcao definida para receber uma 
    cadeia de caracteres como parametro.
    @param void letraMn04(chars cadeia);
*/
void Exercicio04( )
{
    //identificar
    IO_id("\nEXEMPLO0414 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    letraMn04(cadeia);

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio04

/**
 * letraMn04( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar e mostrar as letras maiusculas < 'N'
 * @param cadeia - caracteres a serem testados
*/
void letraMn04(chars cadeia)
{
    //definir variaveis com valor inicial
    chars letras = "";
    int count = 0, letra = 0, quantidade = 0;

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula menor que 'N'
        if (cadeia[count] >= 'A' && cadeia[count] < 'N')
        {
            //concatenar caracteres
            letras = IO_concat(letras, IO_toString_c(cadeia[count]));
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade != 0)
    {
        IO_printf("\n %s %s %s", letras,
                  "e' a nova cadeia de caracteres somente", 
                  "com letras maiusculas menores que 'N'.");
    }
    else
    {
        IO_println("NAO existem letras maiusculas menores que 'N'.");
    }//end if
}//end letraMn04

//----------------------------------------------------------------------------------

void letraNn05(chars cadeia);
/**
 * Exercicio05
    - ler uma sequencia de caracteres do teclado;
    - mostrar a quantidade de letras (tanto maiusculas, 
    quanto minusculas), maiores que 'N', contadas por uma funcao
    definida para receber uma cadeia de caracteres como parametro.
    @param void letraNn05(chars cadeia);
*/
void Exercicio05( )
{
    //identificar
    IO_id("\nEXEMPLO0415 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    letraNn05(cadeia);

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio05

/**
 * letraNn05( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar e mostrar as letras > 'N' | 'n'
 * @param cadeia - caracteres a serem testados
*/
void letraNn05(chars cadeia)
{
    //definir variaveis com valor inicial
    int count = 0, letra = 0, quantidade = 0;

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula > que 'N' ou minuscula > 'n'
        if ((cadeia[count] > 'N' && cadeia[count] <= 'Z') || 
            (cadeia[count] > 'n' && cadeia[count] <= 'z')   )
        {
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade != 0)
    {
        IO_printf("\n Sao %d letras maiores que 'N'||'n'.", quantidade);
    }
    else
    {
        IO_println("NAO existem letras maiores que 'N'||'n'.");
    }//end if
}//end letraNn05

//----------------------------------------------------------------------------------

void letraNn06(chars cadeia);
/**
 * Exercicio06
    - ler uma sequencia de caracteres do teclado;
    - mostrar as letras (tanto maiusculas, quanto minusculas), maiores que 'N', 
    separadas em outra cadeia de caracteres mediante uma funcao definida 
    para receber uma cadeia de caracteres como parametro.
    @param void letraNn06(chars cadeia);
*/
void Exercicio06( )
{
    //identificar
    IO_id("\nEXEMPLO0416 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    letraNn06(cadeia);

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio06

/**
 * letraNn06( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar e mostrar as letras > 'N' | 'n'
 * @param cadeia - caracteres a serem testados
*/
void letraNn06(chars cadeia)
{
    //definir variaveis com valor inicial
    chars letras = "";
    int count = 0, letra = 0, quantidade = 0;

    //comparar cada letra repeticao crescente
    for (count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' letra maiuscula > que 'N' ou minuscula > 'n'
        if ((cadeia[count] > 'N' && cadeia[count] <= 'Z') || 
            (cadeia[count] > 'n' && cadeia[count] <= 'z')   )
        {
            //concatenar caracteres
            letras = IO_concat(letras, IO_toString_c(cadeia[count]));
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade != 0)
    {
        IO_printf("\n %s %s %s", letras, 
                  "e' a nova cadeia de caracteres somente", 
                  "com letras maiores que 'N'||'n'.");
    }
    else
    {
        IO_println("NAO existem letras maiores que 'N'||'n'.");
    }//end if
}//end letraNn06

//----------------------------------------------------------------------------------

void digitoI07(chars cadeia);
/**
 * Exercicio07
    - ler uma sequencia de caracteres do teclado;
    - mostrar a quantidade de digitos impares em uma cadeia 
    de caracteres contados por uma funcao definida para 
    receber uma cadeia de caracteres como parametro.
    DICA: Considerar o valor inteiro do codigo equivalente (type casting).
    @param void digitoI07(chars cadeia); 
*/
void Exercicio07( )
{
    //identificar
    IO_id("\nEXEMPLO0417 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    digitoI07(cadeia);

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio07

/**
 * digitoI07( ) - Metodo para ler cadeia de caracteres do 
 * teclado contar os digitos impares
 * @param cadeia - caracteres a serem testados
*/
void digitoI07(chars cadeia)
{
    //definir variaveis com valor inicial
    int count = 0, digito = 0, quantidade = 0;

    //comparar cada digito repeticao crescente
    for(count = 0; count < strlen(cadeia); count++)
    {
        //se caractere e' digito e impar
        if(cadeia[count] >= '0' && cadeia[count] <= '9')
        {
            //transferir digito para int
            digito = (int) cadeia[count];
            //se resto da divisao por 2 nao e' zero
            if(digito % 2 != 0)
            {
                //e contar quantidade
                quantidade++;
            }//end if
        }//end if      
    }//end for
    //se atendeu a especificacao
    if(quantidade != 0)
    {
        IO_printf("\n Sao %d digitos impares.", quantidade);
    }
    else
    {
        IO_println("NAO existem digitos impares.");
    }//end if
}//end digitoI07

//----------------------------------------------------------------------------------

void Nalfanumerico08(chars cadeia);
/**
 * Exercicio08
    - ler uma sequencia de caracteres do teclado;
    - mostrar os cinco primeiros simbolos nao alfanumericos 
    (letras e digitos), em uma cadeia de caracteres, se houver,
    separados por meio de uma funcao.
    @param void Nalfanumerico08(chars cadeia);
*/
void Exercicio08( )
{
    //identificar
    IO_id("\nEXEMPLO0418 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    Nalfanumerico08(cadeia);

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio08

/**
 * Nalfanumerico08( ) - Metodo para ler cadeia de caracteres do 
 * e mostrar os cinco primeiros simbolos nao alfanumericos
 * @param cadeia - caracteres a serem testados
*/
void Nalfanumerico08(chars cadeia)
{
    //definir variaveis com valor inicial
    chars Nalfanum = "";
    int count = 0, quantidade = 0;

    //comparar cada digito repeticao crescente ate' 5 simbolos
    for(count = 0; count < strlen(cadeia); count++)
    {        
        //se caractere e' nao alfanumerico
        if( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') ||
               (cadeia[count] >= 'A' && cadeia[count] <= 'Z') ||
               (cadeia[count] >= 'a' && cadeia[count] <= 'z') ))
        {
            //concatenar nao alfanumericos
            Nalfanum = IO_concat(Nalfanum, IO_toString_c(cadeia[count]));
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if
        //se chegar a 5, parar
        if( quantidade == 5)
        {
            break;
        }//end if
    }//end for

    //se atendeu a especificacao
    if(quantidade <= 5 && quantidade != 0)
    {
        IO_printf("\n %s sao os primeiros simbolos nao alfanumericos.", Nalfanum);
    }
    else
    {
        IO_println("NAO existem simbolos nao alfanumericos.");
    }//end if
}//end Nalfanumerico08

//----------------------------------------------------------------------------------

void alfanumerico09(chars cadeia);
/**
 * Exercicio09
    - ler uma sequencia de caracteres do teclado;
    - mostrar os cinco primeiros simbolos alfanumericos 
    (letras e digitos) em uma cadeia de caracteres, 
    se houver, separados por meio de uma funcao.
    @param void alfanumerico09(chars cadeia);
*/
void Exercicio09( )
{
    //identificar
    IO_id("\nEXEMPLO0419 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    //ler do teclado
    cadeia = IO_readstring("\nEntre com uma cadeia de caracteres: ");
    //chamar funcao
    alfanumerico09(cadeia);

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio09

/**
 * alfanumerico09( ) - Metodo para ler cadeia de caracteres do 
 * e mostrar os cinco primeiros simbolos alfanumericos
 * @param cadeia - caracteres a serem testados
*/
void alfanumerico09(chars cadeia)
{
    //definir variaveis com valor inicial
    chars alfanum = "";
    int count = 0, quantidade = 0;

    //comparar cada digito repeticao crescente ate' 5 simbolos
    for(count = 0; count < strlen(cadeia); count++)
    {        
        //se caractere e' alfanumerico
        if( (cadeia[count] >= '0' && cadeia[count] <= '9') ||
            (cadeia[count] >= 'A' && cadeia[count] <= 'Z') ||
            (cadeia[count] >= 'a' && cadeia[count] <= 'z') )
        {
            //concatenar alfanumericos
            alfanum = IO_concat(alfanum, IO_toString_c(cadeia[count]));
            //validar que atendeu a especificacao
            //e contar quantidade
            quantidade++;
        }//end if
        //se chegar a 5, parar
        if( quantidade == 5)
        {
            break;
        }//end if
    }//end for

    //se atendeu a especificacao
    if(quantidade <= 5 && quantidade != 0)
    {
        IO_printf("\n %s sao os primeiros simbolos alfanumericos.", alfanum);
    }
    else
    {
        IO_println("NAO existem simbolos alfanumericos.");
    }//end if
}//end alfanumerico09

//----------------------------------------------------------------------------------

int quantidade10(void);
int cadeias10(chars cadeia, int total);
/**
 * Exercicio10
    - ler certa quantidade de cadeias de caracteres do teclado;
    - mostrar e contar a quantidade de sDimbolos nao alfanumericos 
    (letras e dígitos) em cada palavra, e calcular o total de 
    todas as palavras, por meio de uma funcao.
    @param int quantidade10(void);
    @param int cadeias10(chars cadeia, int total);
*/
void Exercicio10( )
{
    //identificar
    IO_id("\nEXEMPLO0420 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    int total = 0;

    //ler quantidade e testar se ela e' valida 
    int quantidade = quantidade10( );

    //repetir o metodo a quantidade de vezes desejadas
    do
    {
        //ler do teclado
        cadeia = IO_readstring("\n\nEntre com uma cadeia de caracteres: ");
        //chamar funcao
        //retornar valor total
        total = cadeias10(cadeia, total);
        //diminuir/contar quantidade de vezes testadas
        quantidade--;
    } while (quantidade != 0);
    
    //se atendeu a especificacao, mostrar resultado
    if(total != 0)
    {
        IO_printf("\n Total de %d simbolos nao alfanumericos em todas as cadeias.", total);
    }
    else
    {
        IO_println("\n NAO existem simbolos nao alfanumericos em nenhuma cadeia.");
    }//end if  

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end Exercicio10

/**
 * quantidade10( ) - Metodo para testar se quantidade valida
 * @return quantidade - numero de vezes a testar
*/
int quantidade10(void)
{
    //definir dados com valor inicial
    int quantidade = 0, x = 0;;
    do{
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint("\nQuantidade de cadeia a serem testadas: ");
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
}

/**
 * cadeias10( ) - Metodo para ler cadeias de caracteres 
 * e mostrar simbolos nao alfanumericos de cada uma e
 * contar o total em todas
 * @param @return total - total de simbolos
 * @param cadeia - caracteres a serem testados
*/
int cadeias10(chars cadeia, int total)
{
    //definir variaveis com valor inicial
    chars Nalfanum = "";
    int count = 0, simbolo = 0;

    //teste para cada posicao de caractere dentro da cadeia, crescente
    for(count = 0; count < strlen(cadeia); count++)    
    {
        //testar se simbolo nao alfanumerico
        if( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') ||
               (cadeia[count] >= 'A' && cadeia[count] <= 'Z') ||
               (cadeia[count] >= 'a' && cadeia[count] <= 'z')) )
        {
            //concatenar nao alfanumericos
            Nalfanum = IO_concat(Nalfanum, IO_toString_c(cadeia[count]));
            //somar por cadeia e validar
            simbolo++;
            //somar ao total e validar
            total++;
        }
    }
    //se atendeu a especificacao, mostrar resultado para uma cadeia
    if(simbolo != 0)
    {
        IO_printf(" %s sao %d simbolos nao alfanumericos.", Nalfanum, simbolo);
    }
    else
    {
        IO_println(" NAO existem simbolos nao alfanumericos.");
    }//end if  

    //retornar valor total
    return(total);
}//end cadeias10

//----------------------------------------------------------------------------------

/**
 * ExercicioE1
    - ler certa quantidade de cadeias de caracteres do teclado;
    - contar a quantidade de simbolos nao alfanumericos, 
    incluindo espaços em branco, em cada palavra, e calcular 
    o total de todas as palavras, por meio de uma funcao.
    OBS.: Para a leitura incluir espaços em branco, 
    utilizar IO_readln( ) ou gets( ), por exemplo.
    @param int quantidade10(void);
    @param int cadeias10(chars cadeia, int total);
*/
void ExercicioE1( )
{
    //identificar
    IO_id("\nEXEMPLO04E1 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    int total = 0;

    //ler quantidade e testar se ela e' valida 
    int quantidade = quantidade10( );

    //repetir o metodo a quantidade de vezes desejadas
    do
    {
        //ler do teclado contando os espacos
        cadeia = IO_readln("\n\nEntre com uma cadeia de caracteres: ");
        //chamar funcao
        //retornar valor total
        total = cadeias10(cadeia, total);
        //diminuir/contar quantidade de vezes testadas
        quantidade--;
    } while (quantidade != 0);
    
    //se atendeu a especificacao, mostrar resultado
    if(total != 0)
    {
        IO_printf("\n Total de %d simbolos nao alfanumericos em todas as cadeias.", total);
    }
    else
    {
        IO_println("\n NAO existem simbolos nao alfanumericos em nenhuma cadeia.");
    }//end if  
    
    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end ExercicioE1

/**
 * cadeiasE1( ) - Metodo para ler cadeias de caracteres 
 * e mostrar simbolos nao alfanumericos de cada uma e
 * contar o total em todas
 * @param @return total - total de simbolos
 * @param cadeia - caracteres a serem testados
*/
int cadeiasE1(chars cadeia, int total)
{
    //definir variaveis com valor inicial
    chars Nalfanum = "";
    int count = 0, simbolo = 0;

    //teste para cada posicao de caractere dentro da cadeia, crescente
    for(count = 0; count < strlen(cadeia); count++)    
    {
        //testar se simbolo nao alfanumerico
        if( ! ((cadeia[count] >= '0' && cadeia[count] <= '9') ||
               (cadeia[count] >= 'A' && cadeia[count] <= 'Z') ||
               (cadeia[count] >= 'a' && cadeia[count] <= 'z')) )
        {
            //concatenar nao alfanumericos
            Nalfanum = IO_concat(Nalfanum, IO_toString_c(cadeia[count]));
            //somar por cadeia e validar
            simbolo++;
            //somar ao total e validar
            total++;
        }
    }
    //se atendeu a especificacao, mostrar resultado para uma cadeia
    if(simbolo != 0)
    {
        IO_printf(" %s sao %d simbolos nao alfanumericos.", Nalfanum, simbolo);
    }
    else
    {
        IO_println(" NAO existem simbolos nao alfanumericos.");
    }//end if  

    //retornar valor total
    return(total);
}//end cadeiasE1

//----------------------------------------------------------------------------------

/**
 * ExercicioE2
    - ler duas cadeias de caracteres do teclado;
    - calcular qual das duas sequencias possui a menor 
    quantidade de digitos, por meio de uma funcao.
*/
void ExercicioE2( )
{
    //identificar
    IO_id("\nEXEMPLO04E2 - Programa - v0.1");
    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end ExercicioE2

//----------------------------------------------------------------------------------

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nESTUDO DIRIGIDO 04 - Programa - v0.1");

    //definir dado com valor inicial
    int x = 0;

    //repetir ate desejar parar
    do
    {
        //ler do teclado
        IO_println("\nOpcoes");
        IO_println(" 0 - Parar");
        IO_println(" 1 - Exercicio1(EXEMPLO0411)  |  2 - Exercicio2(EXEMPLO0412) |  3 - Exercicio3(EXEMPLO0413)");
        IO_println(" 4 - Exercicio4(EXEMPLO0414)  |  5 - Exercicio5(EXEMPLO0415) |  6 - Exercicio6(EXEMPLO0416)");
        IO_println(" 7 - Exercicio7(EXEMPLO0417)  |  8 - Exercicio8(EXEMPLO0418) |  9 - Exercicio9(EXEMPLO0419)");
        IO_println("10 - Exercicio10(EXEMPLO0420) | 11 - Extra01(EXEMPLO04E1)    | 12 - Extra02(EXEMPLO04E2)");
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
            Exercicio04( );
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
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main( )

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
OBS: o simbolo ç (cedilha) consta como nao alfanumerico nos exercicios
---------------------------------------------- previsao de testes
Exemplo0411
a.) -5.674  10.7843      4       3.567 -9.879 10.234 26.0134
b.) 5.674   10.7843      5       3.567 -9.879 10.234 6.0134 7.345
c.) 15.674  10.7843
d.) 6.983   23.745      -10

Exemplo0412			Exemplo0413
a.) abcDEF123-+=		a.) opqDEF123-+=
b.) ABCdef123-+=		b.) ABCdef123-+=
c.) 123-+=abcDEF		c.) 123-+=abcDEF
d.) abc123-+=			d.) abc123-+=OPQ

Exemplo0414			Exemplo0415
a.) rstDEF123-+=OPQ		a.) rst123OPQ
b.) ABCdef123-+=LM		b.) ABCdef123-+=
c.) GHI123-+=abcDEF		c.) OPQ098rst-+=Uvx
d.) abc123-+=OPQ		d.) abc123-+=ABC

Exemplo0416			Exemplo0417
a.) rst123OPQ			a.) rst123789OPQ
b.) ABCdef123-+=		b.) -+=098abc123
c.) OPQ098rst-+=Uvx		c.) 98,57.23abcd
d.) abc123-+=ABC		d.) abc-+=OPQ246

Exemplo0418			Exemplo0419
a.) -+=abc!@#OPQ([])		a.) 123-=+abcDEF
b.) -94+=Abc			b.) DEF098.;,opq
c.) .;[asa]$s			c.) -=+.;,/?°
d.) abc123OPQ			d.) a1C[]{}

Exemplo0420
a.) 3   opq123=_=   .dsa;,fa    porsd34
b.) 5   abc1-+=     123ABC      /?°   !@#123    poaç
c.) 2   abc123DEF   123aBc456

Exemplo04E1
a.) 3   opq 123 =_=   .dsa ;, fa    por sd34
b.) 5   abc1 -+=     123 ABC      / ? °   !@#123    po aç
c.) 2   abc123DEF   123aBc456

Exemplo04E2
a.) 3   093ja08   45fgh90    porsd34
b.) 5   abc1      123ABC      abc    !@#123    poaç21
c.) 2   abc123DEF   123aBc456
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         /09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 0.1       01.   ( OK )  14/09  - quantidade de valores reais pares dentro de um intervalo real e fora.
 0.2       01.   ( OK )  14/09  - quantidade de letras maiusculas.
 0.3       01.   ( OK )  14/09  - quantidade de letras maiusculas menores que 'N'. 
 0.4       01.   ( OK )  14/09  - quantidade de letras maiusculas menores que 'N' separadas em outra cadeia.
 0.5       01.   ( OK )  14/09  - quantidade de letras maiores que 'N'||'n'.
 0.6       01.   ( OK )  14/09  - quantidade de letras maiores que 'N'||'n' separadas em outra cadeia.
 0.7       01.   ( OK )  14/09  - quantidade de digitos impares.
 0.8       01.   ( OK )  14/09  - cinco primeiros simbolos nao alfanumericos separados em uma cadeia.
 0.9       01.   ( OK )  14/09  - cinco primeiros simbolos nao alfanumericos separados em uma cadeia.
 1.0       01.   ( OK )  15/09  - quantidade de simbolos nao alfanumericos e o total em todas as palavras.
 E.1       01.   ( OK )  18/09  - quantidade de simbolos nao alfanumericos e o total contando os espacos .
 E.2       01.   ( OK )  18/09  - cadeia com menor quantidade de digitos.

*/