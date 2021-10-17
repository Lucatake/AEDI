/*
mymatrix.hpp - v0.1. - 06 / 11 / 2020
Author: Luana Campos Takeishi
*/
// ----------------------------------------------- definicoes globais
#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_
// dependencias
#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ifstream; // para ler arquivo
using std::ofstream; // para gravar arquivo
template <typename T>
class Matrix
{
private: // area reservada
    int rows;
    int columns;
    T **data;

public: // area aberta
    Matrix()
    {
        // definir valores iniciais
        this->rows = 0;
        this->columns = 0;
        // sem reservar area
        data = NULL;
    } // end constructor
    Matrix(int rows, int columns)
    {
        // definir dado local
        bool OK = true;
        // definir valores iniciais
        this->rows = rows;
        this->columns = columns;
        // reservar area
        data = new T *[rows];
        if (data != NULL)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
                OK = OK && (data[x] != NULL);
            } // end for
            if (!OK)
            {
                data = NULL;
            } // end if
        }     // end if
    }         // end constructor
    ~Matrix()
    {
        if (data != NULL)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                delete (data[x]);
            } // end for
            delete (data);
            data = NULL;
        } // end if
    }     // end destructor ( )
    void set(int row, int column, T value)
    {
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data[row][column] = value;
        } // end if
    }     // end set ( )
    T get(int row, int column)
    {
        T value = 0; // value has type dependency
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            value = data[row][column];
        } // end if
    }     // end get ( )
    void print()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << data[x][y] << "\t";
            } // end for
            cout << endl;
        } // end for
        cout << endl;
    } // end print ( )
    void read()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << setw(2) << x << ", "
                     << setw(2) << y << " : ";
                cin >> data[x][y];
            } // end for
        }     // end for
        cout << endl;
    } // end read ( )
    void fprint(string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        afile << rows << endl;
        afile << columns << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                afile << data[x][y] << endl;
            } // end for
        }     // end for
        afile.close();
    } // end fprint ( )
    void fread(string fileName)
    {
        ifstream afile;
        int m = 0;
        int n = 0;
        afile.open(fileName);
        afile >> m;
        afile >> n;
        if (m <= 0 || n <= 0)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n"
                 << endl;
        }
        else
        {
            // guardar a quantidade de dados
            rows = m;
            columns = n;
            // reservar area
            data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
            } // end for
            // ler dados
            for (int x = 0; x < rows; x = x + 1)
            {
                for (int y = 0; y < columns; y = y + 1)
                {
                    afile >> data[x][y];
                } // end for
            }     // end for
        }         // end if
        afile.close();
    } // end fread ( )
    Matrix &operator=(const Matrix<T> other)
    {
        if (other.rows == 0 || other.columns == 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            this->rows = other.rows;
            this->columns = other.columns;
            this->data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                this->data[x] = new T[columns];
            } // end for
            for (int x = 0; x < this->rows; x = x + 1)
            {
                for (int y = 0; y < this->columns; y = y + 1)
                {
                    data[x][y] = other.data[x][y];
                } // end for
            }     // end for
        }         // end if
        return (*this);
    } // end operator= ( )
    bool isZeros()
    {
        bool result = true;
        int x = 0;
        int y = 0;
        while (x < rows && result)
        {
            y = 0;
            while (y < columns && result)
            {
                result = result && (data[x][y] == 0);
                y = y + 1;
            } // end for
            x = x + 1;
        } // end while
        return (result);
    } // end isZeros ( )
    bool operator!=(const Matrix<T> other)
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            x = 0;
            do
            {
                y = 0;
                do
                {
                    result = (data[x][y] != other.data[x][y]);
                    y = y + 1;
                } while (y < columns && !result);
                x = x + 1;
            } while (x < rows && !result);
        } // end if
        return (result);
    } // end operator!= ( )
    Matrix &operator-(const Matrix<T> other)
    {
        static Matrix<T> result(other);
        int x = 0;
        int y = 0;
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            for (int x = 0; x < result.rows; x = x + 1)
            {
                for (int y = 0; y < result.columns; y = y + 1)
                {
                    result.data[x][y] = data[x][y] - other.data[x][y];
                } // end for
            }     // end for
        }         // end if
        return (result);
    } // end operator- ( )
    Matrix &operator*(const Matrix<T> other)
    {
        static Matrix<T> result(1, 1);
        int x = 0;
        int y = 0;
        int z = 0;
        int sum = 0;
        if (rows <= 0 || columns == 0 ||
            other.rows <= 0 || other.columns == 0 ||
            columns != other.rows)
        {
            cout << endl
                 << "ERROR: Invalid data." << endl;
            result.data[0][0] = 0;
        }
        else
        {
            result.rows = rows;
            result.columns = other.columns;
            result.data = new T *[result.rows];
            for (int x = 0; x < result.rows; x = x + 1)
            {
                result.data[x] = new T[result.columns];
            } // end for
            for (x = 0; x < result.rows; x = x + 1)
            {
                for (y = 0; y < result.columns; y = y + 1)
                {
                    sum = 0;
                    for (z = 0; z < columns; z = z + 1)
                    {
                        sum = sum + (data[x][z] * other.data[z][y]);
                    } // end for
                    result.data[x][y] = sum;
                } // end for
            }     // end for
        }         // end if
        return (result);
    } // end operator* ( )
    const int getRows()
    {
        return (rows);
    } // end getRows ( )
    const int getColumns()
    {
        return (columns);
    } // end getColumns ( )

    //------------------------------------------------------ ESTUDO DIRIGIDO 11
    bool operator==(const Matrix<T> other)
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            x = 0;
            do
            {
                y = 0;
                do
                {
                    result = (data[x][y] == other.data[x][y]);
                    y = y + 1;
                } while (y < columns && result);
                x = x + 1;
            } while (x < rows && result);
        } // end if
        return (result);
    } // end operator== ( )

    Matrix &operator+(const Matrix<T> other)
    {
        static Matrix<T> result(other);
        int x = 0;
        int y = 0;
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            for (int x = 0; x < result.rows; x = x + 1)
            {
                for (int y = 0; y < result.columns; y = y + 1)
                {
                    result.data[x][y] = data[x][y] + other.data[x][y];
                } // end for
            }     // end for
        }         // end if
        return (result);
    } // end operator+ ( )

    /**
     * gerar inteiros aleatoriamente a partir de um intervalo.
    */
    int geraInt(int inferior, int superior)
    {
        //definir dados
        int aleatorio = 0;
        //gerar numeros aleatorios dentro do intervalo e
        do
        {
            aleatorio = rand() % 100;
        } while (aleatorio < inferior || aleatorio > superior);
        //retornar valor
        return (aleatorio);
    } //end geraInt

    /**
     * escalar uma matriz por uma constante.
    */
    void escalar(int cte)
    {
        //varrer matriz
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                data[i][j] = data[i][j] * cte;
            }
        } //end for
    }     //end escalar

    /**
     * testar se matriz e' identidade.
    */
    bool eIdentidade()
    {
        //definir dados locais
        bool result = false;
        int i = 0;
        int j = 0;
        //condicao de existencia
        if (rows <= 0 || columns <= 0 ||
            rows != columns)
        {
            cout << "\nERROR: Invalid.\n"
                 << endl;
        }
        else
        {
            //testar valores na matriz
            i = 0;
            while (i < rows && !result)
            {
                j = 0;
                while (j < columns && !result)
                {
                    //testar valor
                    if (i == j)
                    {
                        result = !result && (data[i][j] == 1);
                    }
                    else
                    {
                        result = !result && (data[i][j] == 0);
                    } //end if
                    //passar ao proximo
                    j++;
                } //end while
                //passar ao proximo
                i++;
            } //end while
        }     //end if
        //retornar resposta
        return (result);
    } //end eIdentidade

    /**
     * adicionar uma linha resultado da soma da primeira com
     * a segunda multiplicada por uma constante.
    */
    void addRows(int rowA, int rowB, int cte)
    {
        //definir dados
        int aux = 0;
        //mover todos os valores uma linha para baixo
        for (int i = rows; i > 0; i--)
        {
            for (int j = columns; j > 0; j--)
            {
                //passar valores
                aux = data[i][j];
                data[i][j] = data[i + 1][j];
                data[i + 1][j] = aux;
            } //end for
        }     //end for
        //adicionar arranjo na matriz
        for (int j = 0; j < columns; j++)
        {
            data[0][j] = (data[rowA + 1][j] + data[rowB + 1][j]) * cte;
        } //end for
    }     //end addRows

    /**
     * metodo para procurar um valor e indicar em qual linha se encontra.
    */
    int searchRows( int valor )
    {
        int linha; 
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (data[i][j] == valor)
                {
                    linha = i;
                }//end if
            }//end for
        }//end for
        return(linha);
    }//end searchRows

    /**
     * metodo para procurar um valor e indicar em qual coluna se encontra.
    */
    int searchColumns( int valor )
    {
        int coluna; 
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (data[i][j] == valor)
                {
                    coluna = j;
                }//end if
            }//end for
        }//end for
        return(coluna);
    }//end searchRows

    Matrix transpose( )
    {
        static Matrix<T> result(columns, rows);
        //percorrer a matriz
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                result.data[j][i] = data[i][j];
            }//end for
        }//end for
        return (result);
    }//end transpose

    /**
     * MatrizCLin - verifica se matrizes quadradas crescentes 
     * possuem tais caracteristicas
    */
    bool MatrizCLin( )
    {
        //definir dados
        int valor = 1;
        bool result = false;
        int  i = 0;
        int j = 0;

        if (rows <= 0 || columns <= 0 ||
            rows != columns)
        {
            cout << "\nERROR: Invalid.\n"
                 << endl;
        } else
        {
            i = 0;
            while (i < rows && !result)
            {
                j = 0;
                while (j < columns && !result)
                {
                    //testar valor
                    if (data[i][j] == valor)
                    {
                        result = !result && (data[i][j] == valor);
                    } //end if
                    //passar ao proximo
                    valor++;
                    j++;
                } //end while
                //passar ao proximo
                i++;
            } //end while
        }//end if
        return(result);
    } //end MatrizCLin

    /**
     * geraMatrizCCol - montar matrizes quadradas crescentes 
     * com tais caracteristicas.
    */
    bool geraMatrizCCol( )
    {
        //definir dados
        int valor = 1;
        int auxiliar = 1;
        bool result = false;
        int  i = 0;
        int j = 0;

        if (rows <= 0 || columns <= 0 ||
            rows != columns)
        {
            cout << "\nERROR: Invalid.\n"
                 << endl;
        } else
        {
            i = 0;
            while (i < rows && !result)
            {
                j = 0;
                while (j < columns && !result)
                {
                    //armazena valor
                    data[i][j] = valor;
                    //proximo valor
                    valor=valor+rows;
                    //passar ao proximo
                    j++;
                } //end while
                //voltar valor
                auxiliar++;
                valor = auxiliar;
                //passar ao proximo
                i++;
            } //end while
        }//end if
        return(result);
    }//end geraMatrizCCol
}; // end class
#endif