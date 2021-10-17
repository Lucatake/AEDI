/**
    Estudo Dirigido 10 - Versao 0.1 - 26/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//dependencias
//para definicoes proprias
#include "io.h"
#include "Luana.h"
//lista de funcoes
int menu(void);
void Parar();

// ----------------------------------------------- definicoes globais arranjos

/**
 * Definicao de tipo arranjo com inteiros
 * baseado em estrutura
*/
typedef struct s_int_Array
{
    int length;
    ints data;
    int ix;
} int_Array;

/**
 * Definicao de referencia para arranjo com inteiros
 * baseado em estrutura
*/
typedef int_Array *ref_int_Array;

/**
 * new_int_Array - Reservar espaco para arranjo com inteiros
 * @return referencia para arranjo com inteiros
 * @param n - quantidade de datos
*/
ref_int_Array new_int_Array(int n)
{
    // reserva de espaco
    ref_int_Array tmpArray = (ref_int_Array)malloc(sizeof(int_Array));
    // estabelecer valores padroes
    if (tmpArray == NULL)
    {
        IO_printf("\nERRO: Falta espaco.\n");
    }
    else
    {
        tmpArray->length = 0;
        tmpArray->data = NULL;
        tmpArray->ix = -1;
        if (n > 0)
        {
            // guardar a quantidade de dados
            tmpArray->length = n;
            // reservar espaco para os dados
            tmpArray->data = (ints)malloc(n * sizeof(int));
            // definir indicador do primeiro elemento
            tmpArray->ix = 0;
        } // fim se
    }     // fim se
    // retornar referencia para espaco reservado
    return (tmpArray);
} // fim

/**
 * free_int_Array - Dispensar espaco para arranjo com inteiros
 * @param tmpArray - referencia para grupo de valores inteiros
*/
void free_int_Array(ref_int_Array tmpArray)
{
    // testar se ha' dados
    if (tmpArray != NULL)
    {
        free(tmpArray->data);
        free(tmpArray);
    } // fim se
} // fim free_int_Array ( )

// ----------------------------------------------- definicoes globais matrix

/**
 * Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura
*/
typedef struct s_int_Matrix
{
    int lines;
    int columns;
    ints *data;
    int ix, iy;
} int_Matrix;

/**
 * Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
*/
typedef int_Matrix *ref_int_Matrix;

/**
 * new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
 * @return referencia para arranjo com inteiros
 * @param lines - quantidade de dados
 * @param columns - quantidade de dados
*/
ref_int_Matrix new_int_Matrix(int lines, int columns)
{
    // reserva de espaco
    ref_int_Matrix tmpMatrix = (ref_int_Matrix)malloc(sizeof(int_Matrix));
    // estabelecer valores padroes
    if (tmpMatrix != NULL)
    {
        tmpMatrix->lines = 0;
        tmpMatrix->columns = 0;
        tmpMatrix->data = NULL;
        // reservar espaco
        if (lines > 0 && columns > 0)
        {
            tmpMatrix->lines = lines;
            tmpMatrix->columns = columns;
            tmpMatrix->data = malloc(lines * sizeof(ints));
            for (tmpMatrix->ix = 0;
                 tmpMatrix->ix < tmpMatrix->lines;
                 tmpMatrix->ix = tmpMatrix->ix + 1)
            {
                tmpMatrix->data[tmpMatrix->ix] = (ints)malloc(columns * sizeof(int));
            } // fim repetir
        }     // fim se
        tmpMatrix->ix = 0;
        tmpMatrix->iy = 0;
    } // fim se
    return (tmpMatrix);
} // fim new_int_Matrix ( )

/**
 * free_int_Matrix - Dispensar espaco para arranjo com inteiros
 * @param tmpMatrix - referencia para grupo de valores inteiros
*/
void free_int_Matrix(ref_int_Matrix tmpMatrix)
{
    // testar se ha' dados
    if (tmpMatrix != NULL)
    {
        for (tmpMatrix->ix = 0;
             tmpMatrix->ix < tmpMatrix->lines;
             tmpMatrix->ix = tmpMatrix->ix + 1)
        {
            free(tmpMatrix->data[tmpMatrix->ix]);
        } // fim repetir
        free(tmpMatrix->data);
        free(tmpMatrix);
    } // fim se
} // fim free_int_Matrix ( )

// ----------------------------------------------- metodos arranjos

/**
 * printIntArray - Mostrar arranjo com valores inteiros.
 * @param array - grupo de valores inteiros
*/
void printIntArray(int_Array array)
{
    // mostrar valores no arranjo
    for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
    {
        // mostrar valor
        printf("%2d: %d\n", array.ix, array.data[array.ix]);
    } // fim repetir
} // printIntArray ( )

/**
 * IO_readintArray - Ler arranjo com valores inteiros.
 * @return arranjo com valores lidos
*/
int_Array IO_readintArray()
{
    // definir dados locais
    chars text = IO_new_chars(STR_SIZE);
    static int_Array array;
    // ler a quantidade de dados
    do
    {
        array.length = IO_readint("\nlength = ");
    } while (array.length <= 0);
    // reservar espaco para armazenar
    array.data = IO_new_ints(array.length);
    // testar se ha' espaco
    if (array.data == NULL)
    {
        array.length = 0; // nao ha' espaco
    }
    else
    {
        // ler e guardar valores em arranjo
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            // ler valor
            strcpy(text, STR_EMPTY);
            array.data[array.ix] = IO_readint(IO_concat(
                IO_concat(text, IO_toString_d(array.ix)), " : "));
        } // fim repetir
    }     // fim se
    // retornar arranjo
    return (array);
} // IO_readintArray ( )

/**
 * fprintIntArray - Gravar arranjo com valores inteiros.
 * @param fileName - nome do arquivo
 * @param array - grupo de valores inteiros
*/
void fprintIntArray(chars fileName, int_Array array)
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    // gravar quantidade de dados
    fprintf(arquivo, "%d\n", array.length);
    // gravar valores no arquivo
    for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
    {
        // gravar valor
        fprintf(arquivo, "%d\n", array.data[array.ix]);
    } // fim repetir
    // fechar arquivo
    fclose(arquivo);
} // fprintIntArray ( )

/**
 * freadArraySize - Ler tamanho do arranjo com valores inteiros.
 * @return quantidade de valores lidos
 * @param fileName - nome do arquivo
*/
int freadArraySize(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    fscanf(arquivo, "%d", &n);
    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
        n = 0;
    } // fim se
    // retornar dados lidos
    return (n);
} // freadArraySize ( )

/**
 * fIO_readintArray - Ler arranjo com valores inteiros.
 * @return arranjo com os valores lidos
 * @param fileName - nome do arquivo
 * @param array - grupo de valores inteiros
*/
int_Array fIO_readintArray(chars fileName)
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *arquivo = fopen(fileName, "rt");
    static int_Array array;
    // ler a quantidade de dados
    fscanf(arquivo, "%d", &array.length);
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
} // fIO_readintArray ( )

/**
 * copyIntArray - Copiar arranjo com valores inteiros.
 * @return oopia do arranjo
 * @param fileName - nome do arquivo
 * @param array - grupo de valores inteiros
*/
int_Array copyIntArray(int_Array array)
{
    // definir dados locais
    int x = 0;
    int y = 0;
    static int_Array copy;
    if (array.length <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
        array.length = 0;
    }
    else
    {
        // reservar area
        copy.length = array.length;
        copy.data = IO_new_ints(copy.length);
        // testar se ha' espaco e dados
        if (copy.data == NULL || array.data == NULL)
        {
            printf("\nERRO: Falta espaco ou dados.");
        }
        else
        {
            // ler e copiar valores
            for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
            {
                // copiar valor
                copy.data[array.ix] = array.data[array.ix];
            } // fim repetir
        }     // fim se
    }         // fim se
    // retornar dados lidos
    return (copy);
} // copyIntArray ( )

// ----------------------------------------------- metodos matrix

/**
 * printIntMatrix - Mostrar matrix com valores inteiros
 * @param array - grupo de valores inteiros
*/
void printIntMatrix(ref_int_Matrix matrix)
{
    // mostrar valores na matriz
    for (matrix->ix = 0; matrix->ix < matrix->lines; matrix->ix = matrix->ix + 1)
    {
        for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
        {
            // mostrar valor
            printf("%3d\t", matrix->data[matrix->ix][matrix->iy]);
        } // fim repetir
        printf("\n");
    } // fim repetir
} // printIntArray ( )

/**
 * IO_readintMatrix - Ler arranjo bidimensional com valores inteiros.
 * @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix IO_readintMatrix()
{
    // definir dados locais
    int lines = 0;
    int columns = 0;
    int z = 0;
    chars text = IO_new_chars(STR_SIZE);
    // ler a quantidade de dados
    do
    {
        lines = IO_readint("\nlines = ");
    } while (lines <= 0);
    do
    {
        columns = IO_readint("\ncolumns = ");
    } while (columns <= 0);
    // reservar espaco para armazenar valores
    ref_int_Matrix matrix = new_int_Matrix(lines, columns);
    // testar se ha' espaco
    if (matrix->data == NULL)
    {
        // nao ha' espaco
        matrix->lines = 0;
        matrix->columns = 0;
        matrix->ix = 0;
        matrix->iy = 0;
    }
    else
    {
        // ler e guardar valores na matriz
        for (matrix->ix = 0; matrix->ix < matrix->lines; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
            {
                // ler e guardar valor
                strcpy(text, STR_EMPTY);
                matrix->data[matrix->ix][matrix->iy] = IO_readint(IO_concat(
                    IO_concat(IO_concat(text, IO_toString_d(matrix->ix)), ", "),
                    IO_concat(IO_concat(text, IO_toString_d(matrix->iy)), " : ")));
            } // fim repetir
            printf("\n");
        } // fim repetir
    }     // fim se
    // retornar dados lidos
    return (matrix);
} // IO_readintMatrix ( )

/**
 * fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 * @param fileName - nome do arquivo
 * @param matrix - grupo de valores inteiros
*/
void fprintIntMatrix(chars fileName, ref_int_Matrix matrix)
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    // testar se ha' dados
    if (matrix == NULL)
    {
        printf("\nERRO: Nao ha' dados.");
    }
    else
    {
        // gravar quantidade de dados
        fprintf(arquivo, "%d\n", matrix->lines);
        fprintf(arquivo, "%d\n", matrix->columns);
        // gravar valores no arquivo
        for (matrix->ix = 0; matrix->ix < matrix->lines; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
            {
                // gravar valor
                fprintf(arquivo, "%d\n", matrix->data[matrix->ix][matrix->iy]);
            } // fim repetir
        }     // fim repetir
        // fechar arquivo
        fclose(arquivo);
    } // fim se
} // fprintIntMatrix ( )

/**
 * freadintMatrix - Ler arranjo bidimensional com valores inteiros.
 * @return referencia para o grupo de valores inteiros
 * @param fileName - nome do arquivo
*/
ref_int_Matrix freadintMatrix(chars fileName)
{
    // definir dados locais
    ref_int_Matrix matrix = NULL;
    int lines = 0;
    int columns = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    fscanf(arquivo, "%d", &lines);
    fscanf(arquivo, "%d", &columns);
    if (lines <= 0 || columns <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // reservar espaco para armazenar
        matrix = new_int_Matrix(lines, columns);
        // testar se ha' espaco
        if (matrix->data == NULL)
        {
            // nao ha' espaco
            matrix->lines = 0;
            matrix->columns = 0;
            matrix->ix = 0;
            matrix->iy = 0;
        }
        else
        {
            // ler e guardar valores na matriz
            matrix->ix = 0;
            while (!feof(arquivo) && matrix->ix < matrix->lines)
            {
                matrix->iy = 0;
                while (!feof(arquivo) && matrix->iy < matrix->columns)
                {
                    // guardar valor
                    fscanf(arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy]));
                    // passar ao proximo
                    matrix->iy = matrix->iy + 1;
                } // fim repetir
                // passar ao proximo
                matrix->ix = matrix->ix + 1;
            } // fim repetir
            matrix->ix = 0;
            matrix->iy = 0;
        } // fim se
    }     // fim se
    // retornar matriz lida
    return (matrix);
} // fim freadintMatrix ( )

/**
 * copyIntMatrix - Copiar matriz com valores inteiros.
 * @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix copyIntMatrix(ref_int_Matrix matrix)
{
    // definir dados locais
    ref_int_Matrix copy = NULL;
    if (matrix == NULL || matrix->data == NULL)
    {
        IO_printf("\nERRO: Faltam dados.\n");
    }
    else
    {
        if (matrix->lines <= 0 || matrix->columns <= 0)
        {
            IO_printf("\nERRO: Valor invalido.\n");
        }
        else
        {
            // reservar espaco
            copy = new_int_Matrix(matrix->lines, matrix->columns);
            // testar se ha' espaco e dados
            if (copy == NULL || copy->data == NULL)
            {
                printf("\nERRO: Falta espaco.");
            }
            else
            {
                // copiar valores
                for (copy->ix = 0; copy->ix < copy->lines; copy->ix = copy->ix + 1)
                {
                    for (copy->iy = 0; copy->iy < copy->columns; copy->iy = copy->iy + 1)
                    {
                        // copiar valor
                        copy->data[copy->ix][copy->iy] = matrix->data[copy->ix][copy->iy];
                    } // fim repetir
                }     // fim repetir
            }         // fim se
        }             // fim se
    }                 // fim se
    // retornar copia
    return (copy);
} // copyIntMatrix ( )

// ----------------------------------------------- chamada dos metodos

/**
 * Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    // definir dado
    int_Array array;
    // montar arranjo em estrutura
    array.length = 5;
    array.data = (ints)malloc(array.length * sizeof(int));
    array.data[0] = 1;
    array.data[1] = 2;
    array.data[2] = 3;
    array.data[3] = 4;
    array.data[4] = 5;
    // identificar
    IO_id("EXEMPLO1001 - Method01 - v1.0");
    // executar o metodo auxiliar
    printIntArray(array);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
Method02 - ler arranjo com valores inteiros.
*/
void method02()
{
    // definir dados
    int_Array array;
    // identificar
    IO_id("EXEMPLO1002 - Method02 - v1.0");
    // ler dados
    array = IO_readintArray();
    // mostrar dados
    IO_printf("\n");
    printIntArray(array);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method02 ( )

/**
Method03 - Gravar em arquivo um arranjo inteiro.
*/
void method03()
{
    // definir dados
    int_Array array;
    // identificar
    IO_id("EXEMPLO1003 - Method03 - v0.0");
    // ler dados
    array = IO_readintArray();
    // mostrar dados
    IO_printf("\n");
    fprintIntArray("ARRAY1.TXT", array);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method03 ( )

/**
Method04 - Ler de arquivo arranjo inteiro.
*/
void method04()
{
    // definir dados
    int_Array array; // arranjo sem tamanho definido
    // identificar
    IO_id("EXEMPLO1004 - Method04 - v1.0");
    // ler dados
    array = fIO_readintArray("ARRAY1.TXT");
    // mostrar dados
    IO_printf("\n");
    printIntArray(array);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method04 ( )

/**
 * Method05 - Copiar arranjo com valores inteiros.
*/
void method05()
{
    // definir dados
    int_Array array; // arranjo sem tamanho definido
    int_Array other; // arranjo sem tamanho definido
    // identificar
    IO_id("EXEMPLO1005 - Method05 - v1.0");
    // ler dados
    array = fIO_readintArray("ARRAY1.TXT");
    // copiar dados
    other = copyIntArray(array);
    // mostrar dados
    IO_printf("\nOriginal\n");
    printIntArray(array);
    // mostrar dados
    IO_printf("\nCopia\n");
    printIntArray(other);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method05 ( )

/**
Method06 - Mostrar matrix com valores inteiros.
*/
void method06()
{
    // definir dado
    ref_int_Matrix matrix = new_int_Matrix(3, 3);
    matrix->data[0][0] = 1;
    matrix->data[0][1] = 2;
    matrix->data[0][2] = 3;
    matrix->data[1][0] = 3;
    matrix->data[1][1] = 4;
    matrix->data[1][2] = 5;
    matrix->data[2][0] = 6;
    matrix->data[2][1] = 7;
    matrix->data[2][2] = 8;
    // identificar
    IO_id("EXEMPLO1006 - Method06 - v1.0");
    // executar o metodo auxiliar
    printIntMatrix(matrix);
    // reciclar espaco
    free_int_Matrix(matrix);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
Method07 - Ler matrix com valores inteiros.
*/
void method07()
{
    // definir dados
    ref_int_Matrix matrix = NULL;
    // identificar
    IO_id("EXEMPLO1007 - Method07 - v1.0");
    // ler dados
    matrix = IO_readintMatrix();
    // mostrar dados
    IO_printf("\n");
    printIntMatrix(matrix);
    // reciclar espaco
    free_int_Matrix(matrix);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method07 ( )

/**
 * Method08 - Guardar em arquivo matrix inteira.
*/
void method08()
{
    // definir dados
    ref_int_Matrix matrix = NULL;
    // identificar
    IO_id("EXEMPLO1008 - Method08 - v1.0");
    // ler dados
    matrix = IO_readintMatrix();
    // gravar dados
    fprintIntMatrix("MATRIX1.TXT", matrix);
    // reciclar espaco
    free_int_Matrix(matrix);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method08 ( )

/**
Method09 - Ler de arquivo matrix inteira.
*/
void method09()
{
    // identificar
    IO_id("EXEMPLO1009 - Method09 - v1.0");
    // ler dados
    ref_int_Matrix matrix = freadintMatrix("MATRIX1.TXT");
    // mostrar dados
    IO_printf("\n");
    printIntMatrix(matrix);
    // reciclar espaco
    free_int_Matrix(matrix);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method09 ( )

/**
 * Method10 - Copiar matrix inteira.
*/
void method10()
{
    // definir dados
    ref_int_Matrix matrix = NULL;
    ref_int_Matrix other = NULL;
    // identificar
    IO_id("EXEMPLO1010 - Method10 - v0.0");
    // ler dados
    matrix = freadintMatrix("MATRIX1.TXT");
    // copiar dados
    other = copyIntMatrix(matrix);
    // mostrar dados
    IO_printf("\nOriginal\n");
    printIntMatrix(matrix);
    // mostrar dados
    IO_printf("\nCopia\n");
    printIntMatrix(other);
    // reciclar espaco
    free_int_Matrix(matrix);
    free_int_Matrix(other);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method10 ( )

// ----------------------------------------------- funcao principal

/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param e escolha do menu
*/
int main(int e)
{
    //identificar
    IO_id("\nESTUDO DIRIGIDO 10 - Programa - v0.1");
    //definir dado com valor inicial
    int x = 0;
    //repetir ate desejar parar
    do
    {
        //ler do teclado
        x = menu();
        //testar valor
        //escolha do exercicio a ser executado
        switch (x)
        {
        case 0:
            Parar();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02( );
            break;
        case 3:
            method03( );
            break;
        case 4:
            method04( );
            break;
        case 5:
            method05( );
            break;
        case 6:
            method06( );
            break;
        case 7:
            method07( );
            break;
        case 8:
            method08( );
            break;
        case 9:
            method09( );
            break;
        case 10:
            method10( );
            break;
        default:
            IO_println("\nValor diferente das opcoes");
            break;
        }             //end switch-case
    } while (x != 0); //end do-while
    //encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} //end main( )

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
    IO_println(" 0 - Parar.");
    IO_println(" 1 - Mostrar certa quantidade de valores.");
    IO_println(" 2 - Ler arranjo com valores inteiros.");
    IO_println(" 3 - Gravar em arquivo um arranjo inteiro.");
    IO_println(" 4 - Ler de arquivo arranjo inteiro.");
    IO_println(" 5 - Copiar arranjo com valores inteiros.");
    IO_println(" 6 - Mostrar matrix com valores inteiros.");
    IO_println(" 7 - Ler matrix com valores inteiros.");
    IO_println(" 8 - Gravar em arquivo matrix inteira.");
    IO_println(" 9 - Ler de arquivo matrix inteira.");
    IO_println("10 - Copiar matrix com valores inteiros.");
    //ler do teclado
    e = IO_readint("\nEntrar com uma opcao: ");
    //retornat valor lido
    return (e);
} //end menu( )

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas
---------------------------------------------- observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         26/10         esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 0.1       1.0   ( OK )  25/10    - Mostrar certa quantidade de valores.
 0.2       1.0   ( OK )  26/10    - Ler arranjo com valores inteiros.
 0.3       1.0   ( OK )  26/10    - Gravar em arquivo um arranjo inteiro.
 0.4       1.0   ( OK )  26/10    - Ler de arquivo arranjo inteiro.
 0.5       1.0   ( OK )  26/10    - Copiar arranjo com valores inteiros.
 0.6       1.0   ( OK )  26/10    - Mostrar matrix com valores inteiros.
 0.7       1.0   ( OK )  26/10    - Ler matrix com valores inteiros.
 0.8       1.0   ( OK )  26/10    - Gravar em arquivo matrix inteira.
 0.9       1.0   ( OK )  26/10    - Ler de arquivo matrix inteira.
 1.0       1.0   ( OK )  26/10    - Copiar matrix com valores inteiros.
*/