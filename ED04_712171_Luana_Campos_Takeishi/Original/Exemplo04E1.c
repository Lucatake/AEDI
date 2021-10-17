/*
    Exemplo04E1 - Versao 0.1 - 15/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo04E1      exemplo04E1.c
    Windows:    gcc -o exemplo04E1.exe  exemplo04E1.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo04E1
    Windows:    exemplo04E1
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * quantidadeE1( ) - Metodo para testar se quantidade valida
 * @return quantidade - numero de vezes a testar
*/
int quantidadeE1(void)
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

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO04E1 - Programa - v0.1");

    //definir variavel com valor inicial
    chars cadeia = "0";
    int total = 0;

    //ler quantidade e testar se ela e' valida 
    int quantidade = quantidadeE1( );

    //repetir o metodo a quantidade de vezes desejadas
    do
    {
        //ler do teclado
        cadeia = IO_readln("\n\nEntre com uma cadeia de caracteres: ");
        //chamar funcao
        //retornar valor total
        total = cadeiasE1(cadeia, total);
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
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler certa quantidade de cadeias de caracteres do teclado;
- contar a quantidade de simbolos nao alfanumericos, 
incluindo espaços em branco, em cada palavra, e calcular 
o total de todas as palavras, por meio de uma funcao.
OBS.: Para a leitura incluir espaços em branco, 
utilizar IO_readln( ) ou gets( ), por exemplo.
---------------------------------------------- notas / observacoes / comentarios
OBS: ç (cedilha) e' considerado nao alfanumerico
---------------------------------------------- previsao de testes
a.) 3   opq 123 =_=   .dsa ;, fa    por sd34
b.) 5   abc1 -+=     123 ABC      / ? °   !@#123    po aç
c.) 2   abc123DEF   123aBc456
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         15/09          esboco
---------------------------------------------- testes
Exercicio    Versao  Teste
 0.1  14/09 - 01.   ( OK )  - quantidade de valores reais pares dentro de um intervalo real e fora.
 0.2  14/09 - 01.   ( OK )  - quantidade de letras maiusculas. 
 0.3  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N'. 
 0.4  14/09 - 01.   ( OK )  - quantidade de letras maiusculas menores que 'N' separadas em outra cadeia.
 0.5  14/09 - 01.   ( OK )  - quantidade de letras maiores que 'N'/'n'.
 0.6  14/09 - 01.   ( OK )  - quantidade de letras maiores que 'N'/'n' separadas em outra cadeia.
 0.7  14/09 - 01.   ( OK )  - quantidade de digitos impares.
 0.8  14/09 - 01.   ( OK )  - cinco primeiros simbolos nao alfanumericos separados em uma cadeia.
 0.9  14/09 - 01.   ( OK )  - cinco primeiros simbolos alfanumericos separados em uma cadeia.
 1.0  15/09 - 01.   ( OK )  - quantidade de simbolos nao alfanumericos e o total em todas as palavras

*/