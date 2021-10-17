/**
 * IO_lib - v0.1 - 23/09/2020
 * CoAuthor: Luana Campos Takeishi
 * Matricula: 712171
*/

//lista de dependencias
//para definicoes proprias
#include "io.h"

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
void SprintIntArray(int_Array array)
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
int_Array SIO_readintArray()
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
void SfprintIntArray(chars fileName, int_Array array)
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
int SfreadArraySize(chars fileName)
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
int_Array SfIO_readintArray(chars fileName)
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
int_Array ScopyIntArray(int_Array array)
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
void SprintIntMatrix(ref_int_Matrix matrix)
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
ref_int_Matrix SIO_readintMatrix()
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
void SfprintIntMatrix(chars fileName, ref_int_Matrix matrix)
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
ref_int_Matrix SfreadintMatrix(chars fileName)
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
ref_int_Matrix ScopyIntMatrix(ref_int_Matrix matrix)
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