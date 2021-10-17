/*
    Exemplo0211 - Versao 0.3 - 26/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0211      exemplo0211.c
    Windows:    gcc -o exemplo0211.exe  exemplo0211.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0211
    Windows:    exemplo0211
*/

// dependencias
#include "io.h"     //para definicoes proprias

/*
    valueIoP - funcao paraa testar se um valor par ou impar
    @param ip - valor a ser testado e exibido
*/
void valueIoP ( int ip )
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
}//end valueIoP( )

/*
    Funcao principal.
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main( )
{
    //definir dado
    int ip = 0;       //definir variavel com valor inicial
    
    //identificar
    IO_id("EXEMPLO0211 - Programa - v0.3");
    
    //ler do teclado
    ip = IO_readint ("Entrar com um valor inteiro: ");
    
    //testar valor e mostrar resultado
    valueIoP( ip );
    
    
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler um valor inteiro do teclado e
- dizer se e' par ou impar
---------------------------------------------- notas / observacoes / comentarios
0.1 
erro: numeros impares negativos nao sai identificados com switch-case
0.2
modificacoes: mudanca de switch-case para if-else afim de obter melhor resultado
com o numero zero, que nao e' nenhuma das opcoes
transformar o numero negativo lido em positivo para evitar erros
0.3 criacao de uma funcao fora da main
---------------------------------------------- previsao de testes
a.) 0
b.) -2
c.) 2
d.) -5
e.) 5
---------------------------------------------- historico
Versao   Data    Modificacao
 0.1     26/08     esboco
 0.2     26/08     esboco
 0.3     26/08     esboco
---------------------------------------------- testes
Versao Teste
1.1 03. ( OK ) exercicio 1 - teste valor impar ou par
*/