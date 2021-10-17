/*
    Exemplo0109 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0109      exemplo0109.c
    Windows:    gcc -o exemplo0109.exe  exemplo0109.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0109
    Windows:    exemplo0109
*/

//dependencias
//para entradas e saidas
#include <stdio.h>
//para valores logicos
#include <stdbool.h>
//para cadeias de caracteres
#include <string.h>
//para funcoes matematicas
#include <math.h>

/*
    funcao principal
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main (int argc, char* argv [ ])
{
    //definir dados singulares
    //definir variaveis com valor inicial para guardar inteiro
    int x = 0;
    //definir variaveis com valor inicial para guardar real
    double y = 3.5;
    //definir variavel com valor inicial para guardar caractere (simbolo)
    char z = 'A';
    //definir variavel com valor inicial para guardar falso ou verdadeiro
    bool w = false;

    //definir dados com mais de um valor
    //definir espaco de armazenamento para ate' 80 caracteres (simbolos)
    char s[80];

    //identificar
    printf("\n%s\n", "Exemplo0109 - Programa = Versao0.1");
    printf("%s\n", "Autor: Luana Campos Takeishi");
    printf("\n");   //mudar de linha

    //mostrar valores iniciais
    printf("01. %s%d\n", "x = ", x);
    printf("02. %s%lf\n", "y = ", y);
    printf("03. %s%c\n", "z = ", z);

    //converter entre tipos de dados (type casting)
    x = (int)z;                     //codigo inteiro equivalente ao caractere
    printf("04. %s%d -> %c\n", "x = ", x, z);

    x = (int)y;                     //parte inteira de real
    printf("05. %s%d -> %lf\n", "x = ", x, y);

    x = 97;
    z = (char)x;                    //caractere equivalente ao codigo inteiro
    printf("06. %s%c -> %d\n", "z = ", z, x);

    x = (int)'0';                   //codigo inteiro equivalente ao caractere
    z = (char)x;                    //caractere equivalente ao codigo inteiro
    printf("07. %s%c -> %d\n", "z = ", z, x);

    x = w;                          //codigo inteiro equivalente ao logico
    printf("08. %s%d -> %d\n", "x = ", x, w);

    w = true;
    x = w;                          //codigo inteiro equivalente ao logico
    printf("09. %s%d -> %d\n", "x = ", x, w);

    x = (w == false);               //equivalente 'a comparacao de igualdade (true igual a false)
    printf("10. %s%d -> %d\n", "x = ", x, w);

    x = !(w == false);              //equivalente ao contrario da comparacao de valores (true igual a false)
    printf("11. %s%d -> %d\n", "x = ", x, w);

    x = (w != false);               //equivalente 'a comparacao de diferenca (true diferente de false)
    printf("12. %s%d -> %d\n", "x = ", x, w);

    w = (x < y);                    //equivalente 'a comparacao entre (x) e (y)
    printf("13. %s%d < %lf = %d\n", "w = ", x, y, w);

    w = (x <= y);                   //equivalente 'a comparacao entre (x) e (y)
    printf("14. %s%d <= %lf = %d\n", "w = ", x, y, w);

    w = (y > x);                    //equivalente 'a comparacao entre (x) e (y)
    printf("15. %s%lf > %d = %d\n", "w = ", y, x, w);

    w = (y >= x);                   //equivalente 'a comparacao entre (x) e (y)
    printf("16. %s%lf >= %d = %d\n", "w = ", y, x, w);
    x = 4;
    w = (x % 2 == 0);               //equivalente a testar se é par ou
                                    //resto inteiro (%) da divisao por 2 igual a zero
    printf("17. %s%(%d) ? %d\n", "e' par ", x, w);

    x = 4;
    w = (x % 2 != 0);               //equivalente a testar se é ímpar ou
                                    //resto inteiro (%) da divisao por 2 diferente de zero
    printf("18. %s%(%d) ? %d\n", "e' impar ", x, w);

    z = 'x';
    w = ('a' <= z && z <= 'z');     //equivalente a testar se e' letra minuscula,
                                    //pertence a [‘a’:’z’] (é igual ou esta’ entre ‘a’ e ‘z’)
    printf("19. %s%(%c) ? %d\n", "e' minuscula ", z, w);

    z = 'X';
    w = (!('a' <= z && z <= 'z'));       //equivalente a testar se NAO (!) e' letra minuscula
    printf("19. %s%(%c) ? %d\n", "nao e' minuscula ", z, w);

    z = 'x';
    w = ('A' <= z && z <= 'Z');          //equivalente a testar se e' letra maiuscula
    printf("20. %s%(%c) ? %d\n", "e' maiuscula ", z, w);

    z = 'X';
    w = ((z < 'A') || ('Z' < z));        //equivalente a testar se NAO e' letra maiuscula,
                                         //esta’ fora do intervalo [’a’:’z’], ou e’ menor que ‘a’ ou e’ maior que ‘z’
    printf("19. %s%(%c) ? %d\n", "nao e' maiuscula ", z, w);

    z = '0';
    w = ('0' == z || '1' == z);          //equivalente a testar se e' igual a '0' ou a '1'
    printf("21. %s%(%c) ? %d\n", "e' 0 ou 1 ", z, w);

    strcpy(s, "palavra");                //copiar para (s) <- "palavra" (NAO usar '=' com caracteres);
    printf("22. palavra = %s\n", s);

    w = (strcmp("zero", s) != 0);        //comparar se caracteres iguais (NAO usar '==' com caracteres);
    printf("23. palavra == %s ? %d\n", s, w);

    strcpy(s, "um dois");                //copiar para (s) <- "outra palavra" (NAO usar '=' com caracteres);
    printf("24. palavras = %s\n", s);

    w = (strcmp("zero", s) != 0);        //comparar se caracteres diferentes (NAO usar '!=' com caracteres);
    printf("25. palavra == %s ? %d\n", s, w);

    //encerrar
    printf("\n\nAperte <enter> para terminar.");
    //limpar entrada de dados
    fflush(stdin);
    //aguardar por enter
    getchar( );
    //voltar ao SO (sem erros)
    return(0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
programa funcionou como o esperado mostrando os valores manipulados.
observacao:
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao  Data     Modificacao
0.1     21/08     esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) leitura e exibicao de inteiro
0.2 02. ( OK ) leitura e exibicao de real
0.3 01. ( OK ) leitura e exibicao de caractere
0.4 01. ( OK ) leitura e exibicao de logica
0.5 01. ( OK ) leitura e exibicao de cadeia de caracteres
0.6 01. ( OK ) leitura e exibicao do produto de dois inteiros
0.7 01. ( OK ) leitura e exibicao da potencia 
0.8 01. ( OK ) leitura e exibicao concatenacao de dois caracteres
0.9 01. ( OK ) leitura e exibicao de procedimentos logicos
*/