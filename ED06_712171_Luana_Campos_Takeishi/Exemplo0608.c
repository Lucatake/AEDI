/**
 * Exemplo0608 - Versao 0.1 - 28/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//lista de dependencias
//para definicoes proprias
#include "io.h"
#include "Luana.h"

/**
 * Method01a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method01a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);
        // passar ao proximo
        method01a(x - 1); // motor da recursividade
    }                     // fim se
} // fim method01a( )

/**
 * Method01 - Mostrar certa quantidade de valores.
*/
void method01( )
{
    // definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    // identificar
    IO_id("EXEMPLO0601 - Method01 - v0.1");
    // executar o metodo auxiliar
    method01a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
 * Method02a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method02a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // passar ao proximo
        method02a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);
    } // fim se
} // fim method02a( )

/**
 * Method02.
*/
void method02()
{
    // identificar
    IO_id("EXEMPLO0602 - Method02 - v0.1");
    // executar o metodo auxiliar
    method02a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method02 ( )

/**
 * Method03a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method03a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        method03a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%s\n", "Valor = 1");
    } // fim se
} // fim method03a( )

/**
 * Method03.
*/
void method03( )
{
    // identificar
    IO_id("EXEMPLO0603 - Method03 - v0.1");
    // executar o metodo auxiliar
    method03a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method03 ( )

/**
 * Method04a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method04a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        method04a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", 2 * (x - 1));
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%s\n", "Valor = 1");
    } // fim se
} // fim method04a( )

/**
 * Method04.
*/
void method04()
{
    // identificar
    IO_id("EXEMPLO0604 - Method04 - v0.0");
    // executar o metodo auxiliar
    method04a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method04 ( )

/**
 * Method05a - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
*/
void method05a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        method05a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%d: %d/%d\n", x, (2 * (x - 1)), (2 * (x - 1) + 1));
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%d: %d\n", x, 1);
    } // fim se
} // fim method05a( )

/**
 * Method05.
*/
void method05()
{
    // identificar
    IO_id("EXEMPLO0605 - Method05 - v0.0");
    // executar o metodo auxiliar
    method05a(5); // motor da recursividade
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method05 ( )

/**
 * somarFracoes - Somar certa quantidade de fracoes recursivamente.
 * @return soma de valores
 * @param x - quantidade de valores a serem mostrados
*/
double somarFracoes(int x)
{
    // definir dado local
    double soma = 0.0;
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // separar um valor e passar ao proximo (motor da recursividade)
        soma = (2.0 * (x - 1)) / (2.0 * (x - 1) + 1) + somarFracoes(x - 1);
        // mostrar valor
        IO_printf("%d: %lf/%lf\n", x, (2.0 * (x - 1)), (2.0 * (x - 1) + 1));
    }
    else
    {
        // base da recursividade
        soma = 1.0;
        // mostrar o ultimo
        IO_printf("%d: %lf\n", x, 1.0);
    } // fim se
    // retornar resultado
    return (soma);
} // fim somarFracoes ( )

/**
 * Method06.
*/
void method06()
{
    // definir dado
    double soma = 0.0;
    // identificar
    IO_id("EXEMPLO0606 - Method06 - v0.0");
    // chamar a funcao e receber o resultado
    soma = somarFracoes(5);
    // mostrar resultado
    IO_printf("soma = %lf\n", soma);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
 * somarFracoes2b - Somar certa quantidade de fracoes recursivamente.
 * @return soma de valores
 * @param x - quantidade de valores a serem mostrados (controle)
 * @param soma - valor atual da soma (historia = memoria)
 * @param numerador - numerador da parcela a ser somada
 * @param denominador - denominador da parcela a ser somada
*/
double somarFracoes2b(int x, double soma, double numerador, double denominador)
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar valores atuais
        IO_printf("%d: %lf/%lf\n", x, numerador, denominador);
        // somar o termo atual e passar ao proximo (motor da recursividade)
        soma = somarFracoes2b(x - 1,                                    // proximo
                              soma + ((1.0 * numerador) / denominador), // atualizar
                              numerador + 2.0,                          // proximo
                              denominador + 2.0);                       // proximo
    }
    // retornar resultado
    return (soma);
} // fim somarFracoes2b ( )

/**
 * somarFracoes2a - Somar certa quantidade de fracoes.
 * Funcao de servico para preparar e
 * disparar o mecanismo recursivo.
 * @return soma de valores
 * @param x - quantidade de valores a serem mostrados
*/
double somarFracoes2a(int x)
{
    // definir dado local
    double soma = 0.0;
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar o ultimo
        IO_printf("%d: %lf\n", x, 1.0);
        // preparar a soma do valor atual e o proximo
        soma = somarFracoes2b(x - 1, 1.0, 2.0, 3.0);
    } // fim se
    // retornar resultado
    return (soma);
} // fim somarFracoes2a ( )

/**
 * Method07.
*/
void method07()
{
    // definir dado
    double soma = 0.0;
    // identificar
    IO_id("EXEMPLO0607 - Method07 - v0.0");
    // chamar a funcao e receber o resultado
    soma = somarFracoes2a(5);
    // mostrar resultado
    IO_printf("soma = %lf\n", soma);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method07 ( )

/**
 * contarDigitos - Contar digitos recursivamente.
 * @return quantidade de digitos
 * @param x - numero cuja quantidade de digitos sera' calculada
*/
int contarDigitos(int x)
{
    // definir dado
    int resposta = 1; // base
    // testar se contador valido
    if (x >= 10)
    {
        // tentar fazer de novo com valor menor
        resposta = 1 + contarDigitos(x / 10); // motor 1
    }
    else
    {
        if (x < 0)
        {
            // fazer de novo com valor absoluto
            resposta = contarDigitos(-x); // motor 2
        }                                 // fim se
    }                                     // fim se
    // retornar resposta
    return (resposta);
} // fim contarDigitos ( )

/**
 * Method08.
*/
void method08()
{
    // identificar
    IO_id("EXEMPLO0608 - Method08 - v0.0");
    // mostrar resultado
    IO_printf("digitos (%3d) = %d\n", 123, contarDigitos(123));
    IO_printf("digitos (%3d) = %d\n", 1, contarDigitos(1));
    IO_printf("digitos (%3d) = %d\n", -10, contarDigitos(-10));
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method08 ( )

/**
 * Funcao principal
 * @return codigo de encerramento
*/
int main( )
{
    //definir variaveis com valor inicial
    int x = 0;

    //identificar
    IO_id("\nESTUDO DIRIGIDO 06 - Programa - v0.1");

    do
    {
        // ler do teclado
        IO_println("Opcoes:");
        IO_println(" 0 - parar");
        IO_println(" 1 - certa quantidade de valores decrescente (recursividade)");
        IO_println(" 2 - certa quantidade de valores (recursividade alternativo)");
        IO_println(" 3 - certa quantidade de valores (recursividade com base)");
        IO_println(" 4 - certa quantidade de valores pares (recursividade base 1)");
        IO_println(" 5 - certa quantidade de valores inversos (recursividade base 1)");
        IO_println(" 6 - soma de certa quantidade de valores inversos (recursividade)");
        IO_println(" 7 - somatorio de certa quantidade de fracoes (recursividade)");
        IO_println(" 8 - contar quantidade de digitos no numero (recursividade)");
        IO_println(" 9 - ");
        IO_println("10 - ");
        x = IO_readint("\nEntrar com uma opcao: ");
        IO_println(" ");

        //testar valor
        switch (x)
        {
        case 0:
            Parar();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();       
            break;
        case 8:
            method08();
            break;
        case 9:
        
            break;
        case 10:
        
            break;
        default:
            IO_println("ERRO: Valor invalido.");
        }//end switch-case
    } while (x != 0);
    
    //encerrar
    IO_pause("\nApertar ENTER para terminar");
    return (0);
}//end main

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
digitos (123) = 3
digitos (  1) = 1
digitos (-10) = 2
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         28/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 0.1       01.   ( OK )  28/09  - certa quantidade de valores decrescente (recursividade)
 0.2       01.   ( OK )  28/09  - certa quantidade de valores crescente (recursividade alternativa)
 0.3       01.   ( OK )  28/09  - certa quantidade de valores crescente (recursividade com base)
 0.4       01.   ( OK )  28/09  - certa quantidade de valores pares (recursividade base 1)
 0.5       01.   ( OK )  28/09  - certa quantidade de valores inversos (recursividade base 1)
 0.6       01.   ( OK )  28/09  - soma de certa quantidade de valores inversos (recursividade crescente)
 0.7       01.   ( OK )  28/09  - somatorio de certa quantidade de fracoes (recursividade decrescente)
 0.8       01.   ( OK )  28/09  - contar quantidade de digitos no numero (recursividade)
 
*/