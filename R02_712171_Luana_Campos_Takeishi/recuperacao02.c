/**
    Lista de exercicios de recuperacao02 - Versao 0.1 - 20/11/2020
    Author: Luana Campos Takeishi
    Matricula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o recuperacao02      recuperacao02.c
    Windows:    gcc -o recuperacao02.exe  recuperacao02.c
    Para executar em terminal (janela de comandos):
    Linux:      ./recuperacao02
    Windows:    recuperacao02
*/

//--------------------------------------------dependencias

//para definicoes proprias
#include "io.h"

//para metodos proprios
#include "Luana.h"
#include "Array.h"
#include "Struct.h"

//lista de funcoes
int menu(void);
int divisores ( int valor );
void maiorMenor( int n, int array[], int m, int div[], chars fileName);
int somaDivInt( int valor );
int numPerfeito( int valor );
int mdc ( int M, int N );
int mmc ( int M, int N );
int binary (int_Array binarios);
int BparaDecimal( int_Array binarios );
int_Array arrayNoSize(chars fileName, int N);
int_Array inverter(chars fileName, int_Array array1);
int_Array filtra(chars fileName, int_Array dados1, int_Array dados2);
bool matrizQuadrados( ref_int_Matrix matriz );
int compararMatriz(ref_int_Matrix matriz1, ref_int_Matrix matriz2);

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
    IO_id("\nRecuperacao 02 - Programa - v0.1");
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
 * definir e usar uma funcao inteira para calcular
 * quantos sao os divisores de um numero inteiro;
 * ler valores inteiros do arquivo DADOS.TXT,
 * o ultimo sera zero, e nao devera ser processado;
 * calcular e gravar em RESULTADOS.TXT, dentre os numeros lidos,
 * os que tiverem a maior e a menor quantidade de divisores.
*/
void exercicio01( )
{
//identificar
    IO_id("exercicio01 - v0.1");
//definir array lido de arquivo
    int n = freadArraySize("DADOS.TXT");
    int array[n];
    freadIntArray("DADOS.TXT", n, array);
    printIntArray(n, array);
//definir dados locais
    int m = n - 1;
    int div[m];
//varrer array e testar dados
    int i = 0;
    while ( i < n && array[i] != 0)
    {
        div[i] = divisores(array[i]);   
        i++;     
    }//end while
//chamar funcao e mostrar resultados
    maiorMenor(n, array, m, div, "RESULTADOS.TXT");
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio01

/**
 * divisores - funcao para calcular quantos divisores
 * um numero inteiro possui.
 * @param valor - valor testado
*/
int divisores ( int valor )
{
    int div = 0;
//divisores
    for (int i = valor; i > 0; i--)
    {
    //testar se valor e' divisivel
        if (valor % i == 0)
        {
            //IO_printf("%d\t", i);
            div++;
        }//end if
    }//end for
//retornar resultado
    return(div);
}//end divisores( )

/**
 * maiorMenor - funcao para ver qual o numero com maior
 * e com menor quantidade de divisores e salvar em arquivo.
 * @param n, m - quantidade de dados
 * @param array, div - arranjo com valores e divisores
 * @param fileName - nome do arquivo
*/
void maiorMenor( int n, int array[], int m, int div[], chars fileName)
{
//definir arquivo
    FILE *arquivo = fopen(fileName, "wt");
//definir dados locais
    int maior = 0;
    int menor = 0;
    int maiorNum = 0;
    int menorNum = 0;
//definir condicao de existencia
    if (n!=0 && m!=0)
    {
    //testar maior e menor
        maior = div[0];
        maiorNum = array[0];
        menor = div[0];
        menorNum = array[0];
        for (int j = 1; j < m; j++)
        {
            //maior
            if (div[j] > maior)
            {
                maiorNum = array[j];
                maior = div[j];
            }//end if
            if (div[j] < menor)
            {
                menorNum = array[j];
                menor = div[j];
            }//end if
        }//end for
    //gravar resultados
        fprintf(arquivo, "%d\n", maiorNum);
        fprintf(arquivo, "%d", menorNum);
        IO_printf("\n num com mais divisores: %d", maiorNum);
        IO_printf("\n num com menos divisores: %d", menorNum);
    } else
    {
        IO_printf("\n dados inexistentes.");
    }//end if
//fechar arquivo
    fclose(arquivo);
}//end maiorMenor( )

/**
 * exercicio02:
 * definir e usar uma funcao inteira para calcular
 * a soma dos divisores de um numero inteiro;
 * definir uma funcao logica para saber se um valor inteiro
 * e' perfeito: se a soma de seus outros divisores e' igual a ele mesmo;
 * calcular e GRAVAR em PERFEITOS.TXT, no intervalo entre 1000 e 9999,
 * quantos e quais sao os numeros perfeitos.
*/
void exercicio02( )
{
//identificar
    IO_id("exercicio02 - v0.1");
// definir dados locais
    int_Array array;
    array.data = (ints)malloc(array.length * sizeof(int));
    int valor = 0;
    int i = 0;
//gravar dados de [1000-9999]
    for (int n = 1000; n <= 9999; n++)
    {
        valor = numPerfeito(n);
        if (valor != 0)
        {
            array.data[i] = valor;
            i++;
        }//end if
        array.length = i;
    }//end for
//mostrar dados
    IO_printf("\n NUMEROS PERFEITOS");
    SprintIntArray(array);
    SfprintIntArray("PERFEITOS.TXT", array);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio02

/**
 * somaDivInt - calcular a soma dos divisores de um numero inteiro.
 * @param valor - numero a ser testado
 * @return soma
*/
int somaDivInt( int valor )
{
//definir variaveis locais
    int soma = 0;
//realizar a soma se for divisor
    for (int i = 1; i < valor; i++)
    {
        if (valor%i == 0)
        {
            soma = soma + i;
        }//end if
    }//end for
//retornar resultado
    return(soma);
}//end somaDivInt( )

/**
 * numPerfeito - verificar se o numero e' perfeito 
 * (possui a soma de seus divisores igual ao seu valor).
 * @param valor - dado a ser testado
 * @return - valor perfeito ou zero, caso nao seja
*/
int numPerfeito( int valor )
{
//definir dados locais
    int perfeito = 0;
//definir dado volar como valor resultado da funcao
    int soma = somaDivInt(valor);
    //IO_printf("valor: %d\t", valor);
    //IO_printf("soma: %d\n", soma);
//verificar se e' perfeito
    if (valor == soma)
    {
        perfeito = valor;
    }//end if
//retornar valor
    return(perfeito);
}//end numPerfeito( )

/**
 * exercicio03:
 * definir e usar uma funcao inteira para calcular
 * o maximo divisor comum entre dois inteiros;
 * ler dois valores inteiros ( M, N ) do arquivo NUMEROS.TXT;
 * calcular e mostrar o maximo divisor comum ( M.D.C. ) entre eles.
*/
void exercicio03( )
{
//identificar
    IO_id("exercicio03 - v0.1");
// definir dados locais
    int M = 0;
    int N = 0;
//definir arquivo
    FILE *arquivo = fopen("NUMEROS.TXT", "rt");
//ler valores de arquivo
// tentar ler o proximo
    fscanf(arquivo, "%d", &M);
    fscanf(arquivo, "%d", &N);
//chamar funcao e armazenar mdc
    int MDC = mdc(M, N);
//mostrar resultado
    IO_printf("\n MDC [%d][%d]= %d", M, N, MDC);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio03

/**
 * mdc - funcao para calcular e retornar o 
 * maximo divisor comum de dois numeros
 * @param M, N - valores
 * @return mdc
*/
int mdc ( int M, int N )
{
//definir variavies locais
    int resto = M % N;
//realizar operacao ate encontrar o valor
    while(resto!=0)
    {
        M = N;
        N = resto;
        resto = M % N;         
    }//end while
//retornar valor
    return (M);
}//end mdc( )

/**
 * exercicio04:
 * definir e usar uma funcao inteira para calcular
 * o minimo multiplo comum entre dois inteiros;
 * ler dois valores inteiros ( M, N ) do arquivo NUMEROS.TXT
 * calcular e mostrar o minimo multiplo comum ( M.M.C. ) entre eles.
*/
void exercicio04( )
{
//identificar
    IO_id("exercicio04 - v0.1");
// definir dados locais
    int M = 0;
    int N = 0;
//definir arquivo
    FILE *arquivo = fopen("NUMEROS.TXT", "rt");
//ler valores de arquivo
// tentar ler o proximo
    fscanf(arquivo, "%d", &M);
    fscanf(arquivo, "%d", &N);
    //fclose(arquivo);
//chamar funcao e armazenar mdc
    int MMC = mmc(M, N);
//mostrar resultado
    IO_printf("\n MMC [%d][%d]= %d", M, N, MMC);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio04

/**
 * mmc - funcao para calcular e retornar o 
 * minimo multiplo comum de dois numeros
 * @param M, N - valores
 * @return mmc
*/
int mmc ( int M, int N )
{
//definir dados locais
    int MMC = 0;
//encontrar mdc
    int MDC =  mdc(M, N);
//encontrar MMC a partir dele
    MMC = (M * N) / MDC;
//retornar valor
    return (MMC);
}//end mmc( )

/**
 * exercicio05:
 * ler valores inteiros do teclado,
 * mas so serao validos os valores iguais a zero ou a um;
 * se algum digito for fornecido errado, devera ser lido novamente;
 * armazena-los em um arranjo de inteiros (int);
 * supondo serem digitos de um numero binario,
 * converte-los para decimal mediante o uso de uma funcao.
 * DICA: Para ler novamente em caso de erro, usar do-while.
 * Exemplo:
 *      //  Arranjo binario = { 1, 0, 1, 1 }
 *          int x = paraDecimal ( binario ); // x = 13
*/
void exercicio05( )
{
//identificar
    IO_id("exercicio05 - v0.1");
// definir dados locais
    int_Array binarios;
    binarios.data = (ints)malloc(binarios.length * sizeof(int));
//chamar funcao para montar arranjo
    binarios.length = binary(binarios);
    SprintIntArray(binarios); 
//chamar funcao para converter binarios para decinal
    int dec = BparaDecimal(binarios);
    IO_printf("convertido para decimal = %d", dec);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio05

/**
 * binary - metodo para montar arranhjo binario do teclado.
 * @param array - onde serao armazenados os dados
 * @return array.lenght
*/
int binary (int_Array binarios)
{
//definir dados locais
    int i = 0;
    int num = 0;
//montar arranjo
//ler quantidade de dados
    int quantidade = quantidades("\n digite a quantidade de dados desejada: ");
    do
    {
    //ler valores do teclado
        num = IO_readint("\n digite um valor (0 ou 1): ");
        if (num == 0 || num == 1)
        {
        //guardar em arranjo e passar para o proximo
            binarios.data[i] = num;
            i++;
        }//end if
        binarios.length = i; 
    } while(i < quantidade);    
    return(i);
}//end binary

/**
 * BparaDecimal - funcao para converter um numero binario
 * em decinal
 * @param binarios - arranjo de valores
 * @return decimal resultado da conversao
*/
int BparaDecimal( int_Array binarios )
{
//definir variaveis locais
    int dec = 0;
//varrer arranjo binario (tras pra frente)
    for (int i = binarios.length -1; i >= 0; i--)
    {
        if (binarios.data[i] == 1)
        {
        //calcular valor decinal
            dec = dec + pow(2,((binarios.length-1)-i));
        }//end if
    }//end for
//retornar valor 
    return(dec);
}//end BparaDecinal( )

/**
 * exercicio06:
 * ler um numero inteiro ( N ) para indicar o tamanho de um arranjo;
 * ler ( N ) valores inteiros do arquivo CRESCENTE.TXT e
 * inserir cada um no arranjo;
 * definir uma funcao para receber o arranjo como
 * parametro e inverter a ordem de seus elementos;
 * gravar o arranjo invertido no arquivo INVERTIDOS.TXT,
 * colocando a quantidade de dados elementos na primeira linha.
 * DICA: Trocar o ultimo com o primeiro e prosseguir ate' a metade.
 * Exemplo:
 *          //  int arranjo1 [ ] = { 1, 2, 3, 4 };
 *              int arranjo2 [4];
 *              inverter ( arranjo2, arranjo1 ); //arranjo2 = [ 4, 3, 2, 1 ]
*/
void exercicio06( )
{
//identificar
    IO_id("exercicio06 - v0.1");
// definir dados locais
    int_Array crescente;
    crescente.data = (ints)malloc(crescente.length * sizeof(int));
    int_Array decrescente;
    decrescente.data = (ints)malloc(decrescente.length * sizeof(int));
//montar arranjo
    int N = quantidades("\n digite o tamanho de um arranjo: ");
    crescente = arrayNoSize("CRESCENTE.TXT", N);
    SprintIntArray(crescente); 
    IO_println("");
//chamar funcao para inverter
    decrescente = inverter("INVERTIDOS.TXT",crescente);
    SprintIntArray(decrescente); 
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio06

/**
 * arrayNoSize - Ler arranjo com valores inteiros.
 * @return arranjo com os valores lidos
 * @param fileName - nome do arquivo
 * @param N - tamanho do array requerido
 * @param array - grupo de valores inteiros
*/
int_Array arrayNoSize(chars fileName, int N)
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *arquivo = fopen(fileName, "rt");
    static int_Array array;
    array.length = N;
    // testar se ha' dados
    if (array.length <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
        array.length = 0; // nao ha' dados
    }
    else
    {
        // reservar espaco
        array.data = IO_new_ints(array.length);
        // ler e guardar valores em arranjo
        array.ix = 0;
        while (!feof(arquivo) &&
               array.ix < array.length)
        {
            // ler valor
            fscanf(arquivo, "%d", &(array.data[array.ix]));
            // passar ao proximo
            array.ix = array.ix + 1;
        } // fim repetir
    }     // fim se
    // retornar dados lidos
    return (array);
} // arrayNoSize ( )

/**
 * inverter - funcao para inverter um arranjo
 * @param fileName - nome do arquivo a gravar arranjo invertido
 * @param array1 - arranjo a ser invertido
 * @return arranjo invertido
*/
int_Array inverter(chars fileName, int_Array array1)
{
//definir dados locais
    FILE *arquivo = fileName;
    int_Array array2;
    int repeticao = 0;
    int i = 0;
//testar existencia de dados
    if (array1.length <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
        array1.length = 0; // nao ha' dados
    }
    else
    {
    //reservar espaco
        array2.length = array1.length;
        array2.data = IO_new_ints(array2.length);
    //inverter posicoes
        repeticao = array1.length/ 2;
        while (repeticao >= 0)
        {
            array2.data[i] = array1.data[array1.length-1-i];
            array2.data[array1.length-1-i] = array1.data[i];
            repeticao--;
            i++;
        }//end while
    }//end if
//gravar em arquivo arranjo invertido
    SfprintIntArray(arquivo, array2);
//retornar dados lidos
    return (array2);
}


/**
 * exercicio07:
 * ler do arquivo DADOS1.TXT um numero inteiro ( N )
 * para indicar o tamanho de um arranjo;
 * ler ( N ) valores inteiros do arquivo DADOS1.TXT e
 * inserir cada dado em um arranjo;
 * ler do arquivo DADOS2.TXT um numero inteiro ( N )
 * para indicar o tamanho de outro arranjo;
 * ler ( N ) valores inteiros do arquivo DADOS2.TXT e
 * inserir cada dado no outro arranjo;
 * filtrar e mostrar os elementos comuns aos dois arranjos,
 * sem repeticoes;
 * gravar o resultado no arquivo FILTRADOS.TXT,
 * colocando a quantidade de dados unicos na primeira linha.
*/
void exercicio07( )
{
//identificar
    IO_id("exercicio07 - v0.1");
// definir dados locais
    int_Array dados1;
    dados1.data = (ints)malloc(dados1.length * sizeof(int));
    dados1.length = SfreadArraySize("DADOS1.TXT");
    dados1 = SfIO_readintArray("DADOS1.TXT");
    IO_println("DADOS1");
    SprintIntArray(dados1); 
    
    int_Array dados2;
    dados2.data = (ints)malloc(dados2.length * sizeof(int));
    dados2.length = SfreadArraySize("DADOS2.TXT");
    dados2 = SfIO_readintArray("DADOS2.TXT");
    IO_println("DADOS2");
    SprintIntArray(dados2); 

    int_Array filtrados;
    filtrados.length = dados2.length;
        if (dados1.length  > dados2.length)
        {
            filtrados.length = dados1.length;
        }//end if
    filtrados.data = (ints)malloc(filtrados.length * sizeof(int));
//chamar funcao
    filtrados = filtra("FILTRADOS.TXT", dados1, dados2);
    IO_println("FILTRADOS");
    SprintIntArray(filtrados); 
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio07

/**
 * filtra - funcao para filtrar dois arranjos
 * @return terceiro arranjo com os valores filtrados
 * @param arranjos 1 e 2 - dados
 * @param fileName - nome do arquivo contendo o filtrado
*/
int_Array filtra(chars fileName, int_Array dados1, int_Array dados2)
{
//definir dados locais
    FILE *arquivo = fileName;
    static int_Array filtrados;
//testar existencia de dados
    if (dados1.length <= 0 || dados2.length <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    } else
    {
        //reservar area e testar se ha espaco ou dados
        filtrados.length = dados2.length;
        if (dados1.length  > dados2.length)
        {
            filtrados.length = dados1.length;
        }//end if
        filtrados.data = IO_new_ints(filtrados.length);
        if (filtrados.data == NULL || dados1.data == NULL || dados2.data == NULL)
        {
            printf("\nERRO: Falta espaco ou dados.");
        }
        else
        {
            //comparar dados
            filtrados.ix = 0;
            dados1.ix = 0; 
            while (dados1.ix < dados1.length)
            {
                dados2.ix = 0;
                while( dados2.ix < dados2.length)
                {
                    if (dados1.data[dados1.ix] == dados2.data[dados2.ix])
                    {
                    //teste para ver se ja existe esse valor no arranjo
                        int valida = 0;
                        int i = 0;
                        int valor  = dados1.data[dados1.ix];
                        do
                        {
                            if (valor != filtrados.data[i])
                            {
                                valida++;
                            }
                            i++;
                        }while(i < filtrados.ix);
                        if (valida >= filtrados.ix)
                        {
                            //armazenar dado
                            filtrados.data[filtrados.ix] = valor;
                            filtrados.ix = filtrados.ix + 1;
                        }
                        //parar comparacao se acha um igual
                        dados2.ix = dados2.length;
                    }//end if
                    dados2.ix = dados2.ix + 1;
                }//end for
            //comparar o proximo
                dados1.ix = dados1.ix + 1;
            }//end while
                filtrados.length = filtrados.ix;
        }//end if
    }//end if
//gravar em arquivo arranjo filtrado
    SfprintIntArray(arquivo, filtrados);
//retornar dados lidos
    return (filtrados);
}//end filtra

/**
 * exercicio08:
 * ler do arquivo MATRIZ1.TXT
 * a quantidade de linhas, colunas e elementos
 * de uma matriz de inteiros;
 * definir uma funcao logica para verificar
 * se a matriz lida apresenta a caracteristica abaixo.
 * OBS.: Não usar break ou continue.
 * 1 1 1 1
 * 1 2 4 8
 * 1 3 9 27
 * 1 4 16 64
*/
void exercicio08( )
{
//identificar
    IO_id("exercicio08 - v0.1");
//definir dados locais
    ref_int_Matrix matriz1 = SfreadintMatrix("MATRIZ1.TXT");
    IO_printf("MATRIZ1\n");
    SprintIntMatrix(matriz1);

    ref_int_Matrix matriz2 = SfreadintMatrix("MATRIZ2.TXT");
    IO_printf("MATRIZ2\n");
    SprintIntMatrix(matriz2);
//chamar funcao para verificar caracteristicas
    bool m1 = matrizQuadrados(matriz1);
    bool m2 = matrizQuadrados(matriz2);
//mostrar resultados
    IO_printf("\n matriz1? %d", m1);
    IO_printf("\n matriz2? %d", m2);
//reciclar espaco
    free_int_Matrix(matriz1);
    free_int_Matrix(matriz2);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio08

/**
 * matrizQuadrados - verifica se matriz possui caracteristicas
 * especificas
 * @param matriz - dados a serem testados
 * @return true ou false
*/
bool matrizQuadrados( ref_int_Matrix matriz )
{
//definir dados locais
    bool verifica = true;
    int pot = 0;
    int value = 1;
//verificar existencia de dados
    if (matriz->lines <= 0 || matriz->columns <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    } else
    {
        matriz->ix = 0;
        while(matriz->ix < matriz->lines && verifica)
        {
            matriz->iy = 0;
            int pot = 0;
            while(matriz->iy < matriz->columns && verifica)
            {
                //se for a primeira linha ou a primeira coluna, ser == 1
                if (matriz->iy == 0 || matriz->ix == 0)
                {
                    verifica = verifica && (matriz->data[matriz->ix][matriz->iy] == 1);
                } else      //para as outras linhas e colunas, verificar a potencia
                {
                    verifica = verifica && (matriz->data[matriz->ix][matriz->iy] == (int)(pow(value,pot)));
                }//end if
            //passar para o proximo
                pot++;
                matriz->iy = matriz->iy + 1;
            }//end while
        //passar para o proximo
            value++;
            matriz->ix = matriz->ix + 1;
        }//end while
    }//end if 
//retornar resultado
    return(verifica);
}//end matrizQuadrados

/**
 * exercicio09:
 * ler do arquivo MATRIZ1.TXT
 * a quantidade de linhas, colunas e elementos
 * de uma matriz de inteiros;
 * ler do arquivo MATRIZ2.TXT
 * a quantidade de linhas, colunas e elementos
 * de outra matriz de inteiros;
 * definir uma funcao (compareTo) para comparar
 * se ambas sao iguais, parando tao logo sejam diferentes
 * e retornar 0, se forem iguais,
 * (+1) se o elemento diferente na primeira for maior, e
 * (- 1) se o elemento diferente na primeira for menor.
 * OBS.: Nao usar break ou continue.
*/
void exercicio09( )
{
//identificar
    IO_id("exercicio09 - v0.1");
//definir dados locais
    ref_int_Matrix matriz1 = SfreadintMatrix("MATRIZ1.TXT");
    IO_printf("MATRIZ1\n");
    SprintIntMatrix(matriz1);

    ref_int_Matrix matriz2 = SfreadintMatrix("MATRIZ2.TXT");
    IO_printf("MATRIZ2\n");
    SprintIntMatrix(matriz2);
//chamar funcao para verificar caracteristicas
    int result = compararMatriz(matriz1, matriz2);
//mostrar resultados
    IO_printf("\n 0-iguais    +1-elem1 > elem2     -1-elem1 < elem2 \n resultado: %d", result);
//reciclar espaco
    free_int_Matrix(matriz1);
    free_int_Matrix(matriz2);
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio09

/**
 * compararMatriz - funcao para comparar duas matrizes
 * @param matriz1 e matriz2 - dados a serem comparados
 * @return 0 - matrizes iguais
 * @return +1 - matrizes diferentes com elemento matriz1 maior
 * @return -1 - matrizes diferentes com elemento matriz1 menor
*/
int compararMatriz(ref_int_Matrix matriz1, ref_int_Matrix matriz2)
{
//definir variaveis locais
    bool teste = true;
    int retorno = 0;
//verificar existencia de dados e se tamanhos sao compativeis
     if (matriz1->lines <= 0 || matriz1->columns <= 0 || 
         matriz2->lines <= 0 || matriz2->columns <= 0 ||
         matriz1->lines != matriz2->lines || matriz1->columns != matriz2->columns)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    } else
    {
    //percorrer matrizes
        matriz1->ix = 0;
        while(matriz1->ix < matriz1->lines && teste)
        {
            matriz1->iy = 0;
            while(matriz1->iy < matriz1->columns && teste)
            {
            //se dados forem diferentes e 1>2
                if (matriz1->data[matriz1->ix][matriz1->iy] > matriz2->data[matriz1->ix][matriz1->iy])
                {
                //sair do loop
                    teste = false;
                    //retornar valor
                    retorno = 1;                  
                } else if (matriz1->data[matriz1->ix][matriz1->iy] < matriz2->data[matriz1->ix][matriz1->iy])
                {
                //sair do loop
                    teste = false;
                    //retornar valor
                    retorno = -1; 
                }//end if
            //passar para o proximo
                matriz1->iy = matriz1->iy + 1;
            }//end while
        //passar para o proximo
            matriz1->ix = matriz1->ix + 1;
        }//end while
    //retornar resultado
        return(retorno);
    }//end if 
}//end compararMatriz

/**
 * Definicao de tipo arranjo para supermercados
 * baseado em estrutura
*/
typedef struct supermercado
{
    chars nome[sizeof (chars)];
    int codigo[sizeof (int)];
    double preco[sizeof (double)];
} supermercado;

/**
 * Definicao de referencia para arranjo
 * baseado em estrutura
*/
typedef supermercado *supers;

/**
 * exercicio10:
 * ler um numero inteiro ( N ) para indicar
 * o numero de supermercados cujos produtos serao avaliados;
 * ler o nome e o codigo de cada supermercado;
 * ler o preco de um produto de cada supermercado;
 * calcular o preco medio desse produto;
 * informar pelo menos dois supermercados com precos
 * inferiores a media.
*/
void exercicio10( )
{
//identificar
    IO_id("exercicio10 - v0.1");
//dados locais
    double soma = 0.0;
    double media = 0.0;
//montar arranjos
    //cadastro supermercados
    int n = quantidades("\n quantidade de supermercados: ");
    supers S;
    int i = 0;
    do
    {
    //preeencher arranjo com os objetos supermercados
        S->nome[i] = IO_readstring("\n nome do supermercado: ");
        S->codigo[i] = IO_readint("\n codigo do supermercado: ");
        S->preco[i] = IO_readdouble("\n valor do produto a ser comparado: ");
    //passar ao proximo
        i++;
    } while (i < n);
//calcular a media dos valores
    for (int i = 0; i < n; i++)
    {
        soma = soma + S->preco[i];
    }//end for
    media = soma / n;
    IO_printf("\n preco medio: %.2lf", media);
//comparar valores
    IO_printf("\n\n supermercados com valores menores:");
    for (int i = 0; i < n; i++)
    {
        if (S->preco[i] < media)
        {
            IO_printf("\n %s \t codigo: %d", S->nome[i], S->codigo[i]);
        }//end if
    }//end for    
//encerrar
    IO_pause("\nApertar ENTER para continuar.");
}//end exercicio10

/**
--------------------------------------------documentacao complementar

--------------------------------------------notas / observacoes / comentarios

--------------------------------------------previsao de testes e testes

- Exercicio 01:
    -Teste 1:  
        0: 10
        1: 100
        2: 32
        3: 13
        4: 27
        5: 12
        6: 94
        7: 66
        8: 32
        9: 0
 num com mais divisores: 100
 num com menos divisores: 13 
    -Teste 2: 
        0: 96
        1: 21
        2: 146
        3: 80
        4: 131
        5: 9
        6: 32
        7: 14
        8: 18
        9: 0
 num com mais divisores: 96
 num com menos divisores: 131

- Exercicio 02:  
    -Teste 1: ERRO: valor: 8128 soma: 8128 - no entanto nao esta entrando dentro
    do if no numPerfeito
            ERRO corrigido (nova variavel para retorno).  
    -Teste 2:  NUMEROS PERFEITOS 0: 8128

-Exercicio 3:
    -Teste 1: MDC [196][64]= 64  
    -Teste 2: MDC [1095][856]= 2
    
-Exercicio 4:
    -Teste 1: MMC [1095][856]= 468660
    -Teste 2: MMC [196][64]= 196
    
-Exercicio 5: 
    -Teste 1: 10100
  convertido para decimal = 20
    -Teste 2: 11111111
  convertido para decimal = 255

-Exercicio 6:
    -Teste 1:  digite o tamanho de um arranjo: 5
                0: 1                0: 5
                1: 2                1: 4
                2: 3                2: 3
                3: 4                3: 2
                4: 5                4: 1
    -Teste 2:  digite o tamanho de um arranjo: 10
                0: 1                0: 10
                1: 2                1: 9
                2: 3                2: 8
                3: 4                3: 7
                4: 5                4: 6
                5: 6                5: 5
                6: 7                6: 4
                7: 8                7: 3
                8: 9                8: 2
                9: 10                9: 1
    
-Exercicio 7:
    -Teste 1:  DADOS1                DADOS2
                0: 3                0: 87
                1: 7                1: 45
                2: 6                2: 3
                3: 2                3: 19
                4: 19                4: 73
                5: 64                5: 56
                6: 24
                7: 6
                8: 9
                9: 2
                        FILTRADOS
                            0: 3
                            1: 19
    -Teste 2:   DADOS1              DADOS2
                0: 3                0: 87
                1: 7                1: 45
                2: 6                2: 3
                3: 2                3: 19
                4: 19               4: 73
                5: 64               5: 56
                6: 24               6: 76
                7: 6                7: 24
                8: 9                8: 575
                9: 2                9: 9
                10: 15              10: 2
                11: 7               11: 15
                                    12: 7
                                    13: 3
                                    14: 88
        FILTRADOS 0: 3
                  1: 7
                  2: 2
                  3: 19
                  4: 24
                  5: 9
                  6: 2
                  7: 15
                  8: 7
        OBS: ele guarda o mesmo valor duas vezes caso exista o valor duas vezes,
        para corrigir isto, foi adicionado um outro teste para eliminar valores 
        iguais apos o novo arranjo ser montado.
    -Teste 3:   DADOS1              DADOS2
                0: 3                0: 87
                1: 7                1: 45
                2: 6                2: 3
                3: 2                3: 19
                4: 19               4: 73
                5: 64               5: 56
                6: 24               6: 76
                7: 6                7: 24
                8: 9                8: 575
                9: 2                9: 9
                10: 15              10: 2
                11: 7               11: 15
                                    12: 7
                                    13: 3
                                    14: 88
    FILTRADOS 0: 3
              1: 7
              2: 2
              3: 19
              4: 24
              5: 9
              6: 15
    -Teste 4:   DADOS1              DADOS2
                0: 3                0: 87
                1: 7                1: 45
                2: 6                2: 3
                3: 2                3: 19
                4: 19               4: 3
                5: 64               5: 3
                6: 24               6: 76
                7: 6                7: 24
                8: 9                8: 57
                9: 2                9: 9
                10: 15             10: 2
                11: 7              11: 31
                12: 31             12: 3
                13: 575            13: 88
                14: 89             14: 89
    FILTRADOS 0: 3
              1: 2
              2: 19
              3: 24
              4: 9
              5: 31
              6: 89

-Exercicio 8: 
    -Teste 1:
    MATRIZ1
  1       1       1       1
  1       2       4       8
  1       3       9      27
  1       4      16      64
MATRIZ2
  1       1       1       1
  1       2       4       8
  1       3       9      27
  1       4      16      65
                        matriz1? 1
                        matriz2? 0

-Exercicio 9:     0-iguais    +1-elem1 > elem2     -1-elem1 < elem2
    -Teste 1:
        MATRIZ1
    1       1       1       1
    1       2       4       8
    1       3       9      27
    1       4      16      64
        MATRIZ2
    1       1       1       1
    1       2       4       8
    1       3       9      27
    1       4      16      65
             resultado: -1
    -Teste 2: 
        MATRIZ1
    1       1       6       1
    1       2       4       8
    1       3       9      27
    1       4      16      64
        MATRIZ2
    1       1       1       1
    1       2       4       8
    1       3       9      27
    1       4      16      65   
             resultado: 1
    -Teste 3:
        MATRIZ1
    1       1       1       1
    1       2       4       8
    1       3       9      27
    1       4      16      64
        MATRIZ2
    1       1       1       1
    1       2       4       8
    1       3       9      27
    1       4      16      64
             resultado: 0

-Exercicio 10:
    -Teste 1: 
 quantidade de supermercados: 4

 nome do supermercado: ABC
 codigo do supermercado: 0009
 valor do produto a ser comparado: 10.45

 nome do supermercado: OBA
 codigo do supermercado: 9985
 valor do produto a ser comparado: 9.01

 nome do supermercado: JS
 codigo do supermercado: 1213
 valor do produto a ser comparado: 13.99

 nome do supermercado: LUPA
 codigo do supermercado: 7777
 valor do produto a ser comparado: 8.56

 preco medio: 10.50

 supermercados com valores menores:
 ABC     codigo: 9
 OBA     codigo: 9985
 LUPA    codigo: 7777

    -Teste 2: 
 quantidade de supermercados: 3

 nome do supermercado: Juliana
 codigo do supermercado: 90909
 valor do produto a ser comparado: 13.56

 nome do supermercado: PauloS
 codigo do supermercado: 86533
 valor do produto a ser comparado: 11.67

 nome do supermercado: PaLe
 codigo do supermercado: 44467
 valor do produto a ser comparado: 10.99

 preco medio: 12.07

 supermercados com valores menores:
 PauloS          codigo: 86533
 PaLe    codigo: 44467

--------------------------------------------historico
Versao       Data         Modificacao
0.1         17/11         esboco
0.1         20/11         versao final

*/
