/*
myarray.hpp - v0.0. - 02 / 11 / 2020
Author: Luana Campos Takeishi
*/

// ----------------------------------------------- definicoes globais
#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_
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
class Array
{
private: // area reservada
    int length;
    T *data;

public: // area aberta
    Array(int n)
    {
        // definir valor inicial
        length = 0;
        data = NULL;
        // reservar area
        if (n > 0)
        {
            length = n;
            data = new T[length];
        }
    } // end constructor
    void free()
    {
        if (data != NULL)
        {
            delete (data);
            data = NULL;
        } // end if
    }     // end free ( )
    void set(int position, T value)
    {
        if (0 <= position && position < length)
        {
            data[position] = value;
        } // end if
    }     // end set ( )
    T get(int position)
    {
        T value = 0; // return value has type dependency
        if (0 <= position && position < length)
        {
            value = data[position];
        } // end if
        return (value);
    } // end get ( )
    void print()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : "
                 << setw(9) << data[x]
                 << endl;
        } // end for
        cout << endl;
    } // end print ( )
    void read()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : ";
            cin >> data[x];
        } // end for
        cout << endl;
    } // end read ( )
    void fprint(string fileName)
    {
        ofstream afile; // output file
        afile.open(fileName);
        afile << length << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            afile << data[x] << endl;
        } // end for
        afile.close();
    } // end fprint ( )
    void fread ( string fileName )
    {
        ifstream afile; // input file
        int n = 0;
        afile.open(fileName);
        afile >> n;
        if (n <= 0)
        {
            cout << "\nERROR: Invalid length.\n"
                 << endl;
        }
        else
        {
            // guardar a quantidade de dados
            length = n;
            // reservar area
            data = new T[n];
            // ler dados
            for (int x = 0; x < length; x = x + 1)
            {
                afile >> data[x];
            } // end for
        }     // end if
        afile.close();
    } // end fread ( )

    Array() // construtor padrao
    {
        // definir valor inicial
        length = 0;
        // reservar area
        data = NULL;
    } // end constructor
    // contrutor baseado em copia
    Array(int length, int other[])
    {
        if (length == 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            // criar copia
            this->length = length;
            // reservar area
            data = new T[this->length];
            // ler dados
            for (int x = 0; x < this->length; x = x + 1)
            {
                data[x] = other[x];
            } // end for
        }     // end if
    }         // end constructor ( )
    Array(const Array &other)
    {
        if (other.length == 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            // criar copia
            length = other.length;
            // reservar area
            data = new T[other.length];
            // ler dados
            for (int x = 0; x < length; x = x + 1)
            {
                data[x] = other.data[x];
            } // end for
        }     // end if
    }         // end constructor ( )
    Array &operator=(const Array<T> other)
    {
        if (other.length == 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            this->length = other.length;
            this->data = new T[other.length];
            for (int x = 0; x < this->length; x = x + 1)
            {
                data[x] = other.data[x];
            } // end for
        }     // end if
        return (*this);
    } // end operator= ( )

    bool operator==(const Array<T> other)
    {
        bool result = true;
        int x = 0;
        if (other.length == 0 || length != other.length)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            x = 0;
            while (x < this->length && result)
            {
                result = result && (data[x] == other.data[x]);
                x = x + 1;
            } // end for
        }     // end if
        return (result);
    } // end operator== ( )
    Array &operator+(const Array<T> other)
    {
        static Array<T> result(other);
        if (other.length == 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            for (int x = 0; x < this->length; x = x + 1)
            {
                result.data[x] = result.data[x] + this->data[x];
            } // end for
        }     // end if
        return (result);
    } // end operator+ ( )
    const int getLength()
    {
        return (length);
    } // end getLength ( )
    T &operator[](const int position)
    {
        static T value = 0; // return value has type dependency
        if (position < 0 || length <= position)
        {
            cout << endl
                 << "\nERROR: Invalid position.\n"
                 << endl;
            return (value);
        }
        else
        {
            value = data[position];
            return (value);
        } // end if
    }     // end operator[]

    //------------------------------------------------------ ESTUDO DIRIGIDO 11
    bool operator!=(const Array<T> other)
    {
        bool result = false;
        int x = 0;
        if (other.length == 0 || length != other.length)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
             x = 0;
            while (x < this->length && !result)
            {
                result = (data[x] != other.data[x]);
                x = x + 1;
            } // end for
        }//end if
        return (result);
    } // end operator!= ( )

    Array &operator-(const Array<T> other)
    {
        static Array<T> result(other);
        if (other.length == 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            for (int x = 0; x < this->length; x = x + 1)
            {
                result.data[x] = this->data[x] - other.data[x];
            } // end for
        }     // end if
        return (result);
    } // end operator- ( )

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
            aleatorio = rand()%100;
        } while (aleatorio < inferior || aleatorio > superior);
        //retornar valor
        return(aleatorio);
    }//end geraInt

    /**
     * procurar maior numero par em arranjo inteiro.
    */
    int maiorIntPar( )
    {
        //variavel
        int auxiliar = 0;
        int maior = 0;
        if (data[0] % 2 == 0)
        {
            maior = data[0];
        }//end if
        //varrer array
        for (int i = 1; i < this->length; i++)
        {
            //verificar se par
            if (data[i] % 2 == 0)
            {
                auxiliar = data[i];
                if ((auxiliar > maior))
                {
                    maior = auxiliar;
                }//end if 
            }//end if
        }//end for
        //retornar valor
        return(maior);
    }//end maiorIntPar

    /**
     * prucura menor multiplo de 'n'.
    */
    int menorMultiploN(int n)
    {
        //variavel
        int menor = 0;
        if (data[0] % n == 0)
            menor = data[0];
        int aux = 0;
        //varrer array
        for (int i = 1; i < this->length; i++)
        {
            //se multiplo de 3
            if(data[i] % n == 0)
            {
                aux = data[i];
                if ((aux < menor) && menor != 0)
                {
                    menor = aux;
                }//end if
            }//end if
        }//end for
        //retornar valor
        return(menor);
    }

    /**
     * somar valores impares de arranjo.
    */
    int somaImpares( )
    {
        //variavel
        int soma = 0;
        //varrer array
        for (int i = 0; i < this->length; i++)
        {
            //se impar
            if(data[i] % 2 != 0)
            {
                soma = soma + data[i];
            }//end if
        }//end for
        //retornar valor
        return(soma);
    }//end somaImpares

    /**
     * calcular a media dos valores pares de arranjo.
    */
    double mediaPares( )
    {
        //variavel
        int soma = 0;
        int q = 0;
        double media = 0;
        //varrer array
        for (int i = 0; i < this->length; i++)
        {
            //se impar
            if(data[i] % 2 == 0)
            {
                soma = soma + data[i];
                q++;
            }//end if
        }//end for
        //calcular media
        media = (double) soma / q;
        //retornar valor
        return(media);
    }//end mediaPares

    /**
     * verificar se todos os valores sao nao nulos.
     * retorna true - todos nao nulos
     * false - pelo menos um nulo
    */
    bool saoZeros( )
    {
        //variavel
        bool nulo = true;
        //varrer array
        for (int i = 0; i < this->length; i++)
        {
            //se zero
            if(data[i] == 0)
            {
                nulo = false;
            }//end if
        }//end for
        //retornar resultado
        return(nulo);
    }//end saoZeros

    /**
     * verificar se esta ordenado de forma decrescente.
     * retorna true - ordem decrescente
     * false - nao ordem decrescente
    */
    bool decrescente( )
    {
        //variavel
        bool decres = true;
        //varrer array
        for (int i = 1; i < this->length; i++)
        {
            //se desordenado decrescente
            if(data[i] > data[i-1])
            {
                decres = false;
            }//end if
        }//end for
        //retornar resultado
        return(decres);
    }//end decrescente

    /**
     * procurar valor entre duas posicoes.
     * retorna true - encontrado
     * false - nao encontrado
    */
    bool achaValor(int procurado, int p1, int p2)
    {
        //variavel
        bool eValor = false;
        //varrer array
        for (int i = p1; i <= p2; i++)
        {
            //se igual a valor
            if (data[i] == procurado)
            {
                eValor = true;
            }//end if
        }//end for
        //retornar resultado
        return(eValor);
    }//end achaValor

    /**
     * escalonar um arranjo por uma constante
    */
    void escalar( int cte )
    {
        //varrer array
        for (int i = 0; i < this->length; i++)
        {
            data[i] = data[i] * cte;
        }//end for
    }//end escalar

    /**
     * ordenar um arranjo de maneira decrescente.
    */
    void ordenarDecrescente( )
    {
        //variaveis
        int auxiliar = 0;
        //varrer array
        for (int j = 0; j < this->length; j++)
        {
            for (int i = 1; i < this->length; i++)
            {
                if (data[i] > data[i-1])
                {
                    auxiliar  = data[i];
                    data[i]   = data[i-1];
                    data[i-1] = auxiliar;
                }//end if
            }//end for
        }//end for
    }//end ordenarDecrescente
    
};    // end class
#endif