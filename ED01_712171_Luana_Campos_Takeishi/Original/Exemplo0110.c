/*
    Exemplo0110 - Versao 0.1 - 21/08/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0110      exemplo0110.c
    Windows:    gcc -o exemplo0110.exe  exemplo0110.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0110
    Windows:    exemplo0110
*/

//dependencias
//para definicoes proprias (na mesma pasta)
#include "io.h"

/*
    funcao principal
    @return codigo de encerramento
    @param argc - quantidade de parametros na linha de comandos
    @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main (int argc, char* argv [ ])
{
    //definir dados
    //definir variavel com valor inicial
    int x = 5;                        
    double y = 3.5; 
    char z = 'A';   
    bool w = TRUE;  
    //definir variavel com tamanho inicial
    chars a = IO_new_chars(STR_SIZE); 
    chars b = IO_new_chars(STR_SIZE); 
    chars c = IO_new_chars(STR_SIZE); 

    //identificar
    printf("\n%s\n", "Exemplo0110 - Programa = Versao0.1");

    //concatenar (juntar) cadeias de caracteres
    //atribuir a variavel (a) o valor constante ("abc")
    strcpy ( a, "abc" ); 
    //obs: a atribuicao de cadeias de caracteres NAO usa (=)
    strcpy ( b, "def" );

    //melhor que a funcao nativa strcat (a,b)
    c = IO_concat(a, b); 
    IO_printf("\nc = [%s]+[%s] = [%s]\n", a, b, c);

    strcpy(a, "c = ");
    //limpar a cadeia de caracteres
    strcpy(c, STR_EMPTY); 

    IO_printf("%s\n", IO_concat(a, IO_toString_c(z)));

    IO_println(IO_concat(a, IO_toString_d(x)));

    IO_println(IO_concat(a, IO_toString_b(w)));

    strcpy(b, STR_EMPTY);
    IO_print(a);
    IO_print(IO_concat(b, IO_toString_f(y)));
    IO_print("\n");

    z = IO_readchar("caractere = ");
    IO_println(IO_concat(a, IO_toString_c(z)));

    y = IO_readdouble("double = ");
    IO_println(IO_concat(a, IO_toString_f(y)));

    x = IO_readint("int = ");
    IO_println(IO_concat(a, IO_toString_d(x)));

    w = IO_readbool("bool = ");
    IO_println(IO_concat(a, IO_toString_b(w)));

    b = IO_readstring("chars = ");
    IO_println(IO_concat(a, b));

    b = IO_readln("line = ");
    IO_println(IO_concat(a, b));

    //encerrar
    IO_pause ("Apertar <enter> para terminar");
    //chamar metodo para pausar
    getchar( );
    //voltar ao SO (sem erros)
    return(0);
}//end main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
programa funcionou como o esperado, mostra os valores e e possivel testar
a exibicao dos diferentes tipos com os valores estipuladios na previsao de testes.
observacao:
---------------------------------------------- previsao de testes
a.) a
b.) 4.2
c.) 10
d.) 1
e.) abc def
f.) abc def
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
1.0 01. ( OK ) leitura e exibicao com procedimento alternativo
*/