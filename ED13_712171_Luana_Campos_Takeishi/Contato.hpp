/**
 * Contato.hpp - v0.0. - 16 / 11 / 2020
 * Author: Luana Campos Takeishi
*/
// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_
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
// outras dependencias
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )
#include "Erro.hpp"

// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar contatos, derivada da classe Erro.
*/
class Contato : public Erro
{
    /**
 * atributos privados.
*/
private:
    string nome;
    string fone;
    string tel;
    string endResid;
    string endProf;
    int n;
    /**
 * definicoes publicas.
*/
public:
    /**
     * Destrutor.
    */
    ~Contato()
    {
    }
    /**
     * Construtor padrao.
    */
    Contato()
    {
        // atribuir valores iniciais vazios
        nome = "";
        fone = "";
        tel = "";
        endResid = "";
        endProf = "";
        n = 0;
    } // fim construtor padrao
    
    /**
    * Construtor alternativo.
    * @param nome_inicial a ser atribuido
    * @param fone_inicial a ser atribuido
    
    Contato ( std::string nome_inicial, std::string fone_inicial )
    {
    // atribuir valores iniciais
    nome = nome_inicial;
    fone = fone_inicial;
    } // fim construtor alternativo
    */
    /**
    * Construtor padrao.
    
    Contato ( )
    {
    setErro ( 0 ); // nenhum erro, ainda
    // atribuir valores iniciais vazios
    nome = "";
    fone = "";
    } // fim construtor padrao
    */
    /**
    * Construtor alternativo.
    * @param nome_inicial a ser atribuido
    * @param fone_inicial a ser atribuido
    */
    Contato ( std::string nome_inicial, std::string fone_inicial, std::string tel_inicial, std::string endResid_inicial, std::string endProf_inicial )
    {
    setErro ( 0 ); // nenhum erro, ainda
    // atribuir valores iniciais
    setNome ( nome_inicial ); // nome = nome_inicial;
    setFone ( fone_inicial ); // fone = fone_inicial;
    setTel ( tel_inicial ); // tel = tel_inicial;
    setEndResid ( endResid_inicial ); // endResid = endResid_inicial;
    setEndProf ( endProf_inicial ); // endProf = endProf_inicial;
    } // fim construtor alternativo

    
    /**
    * Construtor alternativo baseado em copia.
    
    Contato ( Contato const & another )
    {
    // atribuir valores iniciais por copia
    setErro ( 0 ); // copiar erro
    setNome ( another.nome ); // copiar nome
    setFone ( another.fone ); // copiar fone
    } // fim construtor alternativo

    // ----------------------------------- metodos para acesso
    /**
    * Metodo para atribuir nome.
    * @param nome a ser atribuido
    
        void setNome(std::string nome)
        {
            this->nome = nome;
        } // fim setNome ( )
    */
    /**
    * Metodo para atribuir nome.
    * @param nome a ser atribuido
    */
    void setNome ( std::string nome )
    {
    if ( nome.empty ( ) )
    setErro ( 1 ); // nome invalido
    else
    this->nome = nome;
    } // fim setNome ( )

    /**
    * Metodo para atribuir telefone.
    * @param fone a ser atribuido
    
        void setFone(std::string fone)
        {
            this->fone = fone;
        } // fim setFone ( )
    */
    /**
    * Metodo para atribuir telefone.
    * @param fone a ser atribuido
    */
    void setFone ( std::string fone )
    {
    if ( fone.empty ( ) )
    setErro ( 2 ); // fone invalido
    else
    this->fone = fone;
    } // fim setFone ( )
    

    /**
    * Funcao para obter nome.
    * @return nome armazenado
    */
        std::string getNome()
        {
            return (this->nome);
        } // fim getNome ( )

    /**
    * Funcao para obter fone.
    * @return fone armazenado
    */
        std::string getFone()
        {
            return (this->fone);
        } // fim getFone ( )

    /**
    * Funcao para obter tel.
    * @return tel armazenado
    */
        std::string getTel()
        {
            return (this->tel);
        } // fim getTel ( )

         std::string getEndResid()
        {
            return (this->endResid);
        } // fim getEndResid ( )

         std::string getEndProf()
        {
            return (this->endProf);
        } // fim getEndProf ( )

    /**
    * Funcao para obter dados de uma pessoa.
    * @return dados de uma pessoa
    */
    std::string toString ( )
    {
    return ( "{ "+getNome( )+", "+getFone( )+", "+getTel( )+", "+getEndResid( )+", "+getEndProf( )+" }" );
    } // fim toString ( )
  

    /**
    * indicar a existencia de erro.
    */
    bool hasErro ( )
    {
    return ( getErro( ) != 0 );
    } // end hasErro ( )

    //---------------------------------------------estudo dirigido 13
    /**
    * Metodo para atribuir outro telefone.
    * @param tel a ser atribuido
    */
    void setTel ( std::string tel )
    {
    if ( tel.empty ( ) )
    setErro ( 2 ); // tel invalido
    else
    this->tel = tel;
    } // fim setTel ( )

    void setEndResid ( std::string endResid )
    {
    if ( endResid.empty ( ) )
    setErro ( 2 ); // tel invalido
    else
    this->endResid = endResid;
    } // fim setEndResid  ( )
    
    void setEndProf ( std::string endProf )
    {
    if ( endProf.empty ( ) )
    setErro ( 2 ); // tel invalido
    else
    this->endProf = endProf;
    } // fim setEndProf  ( )

    /**
     * metodo para ler e atribuir um nome do teclado
     * @param texto - texto a ser mostrado
    */
    void readNome (string texto)
    {
        std::string nome;
        cout << texto; cin >> nome; cout << endl;
        if ( nome.empty ( ) )
        setErro ( 1 ); // nome invalido
        else
        this->nome = nome;
    }//end readNome

    /**
     * metodo para ler e atribuir um fone do teclado
     * @param texto - texto a ser mostrado
    */
    void readFone (string texto)
    {
        std::string fone;
        cout << texto; cin >> fone; cout << endl;
        if ( fone.empty ( ) )
        setErro ( 2 ); // fone invalido
        else
        this->fone = fone;
    }//end readFone

    /**
     * metodo para ler e atribuir um fone do teclado
     * @param texto - texto a ser mostrado
    */
    void readTel (string texto)
    {
        std::string tel;
        cout << texto; cin >> tel; cout << endl;
        if ( tel.empty ( ) )
        setErro ( 2 ); // tel invalido
        else
        this->tel = tel;
    }//end readTel

    void readEndResid (string texto)
    {
        std::string endResid;
        cout << texto; cin >> endResid; cout << endl;
        if ( endResid.empty ( ) )
        setErro ( 2 ); // endResid invalido
        else
        this->endResid = endResid;
    }//end readEndResid 

    void readEndProf (string texto)
    {
        std::string endProf;
        cout << texto; cin >> endProf; cout << endl;
        if ( endProf.empty ( ) )
        setErro ( 2 ); // tel invalido
        else
        this->endProf = endProf;
    }//end readEndProf 

    /**
     * metodo para testar se fone e' valido
     * @return 1- valido 0 - invalido
    */
    int validoFone( )
    {
        bool valido = false;
        if ( this->fone.empty() || this->fone.length() != 9 )
        setErro ( 2 );
        else 
        {
            int i = 0;
            do
            {
                if (i == 4)
                {
                    valido = this->fone[i] == '-';
                }
                if ( this->fone[i] >= '0' && this->fone[i] <= '9' )
                {
                    valido = true; 
                }
                i++;
            }while (i < this->fone.length() && valido);
        }
        if(valido)
        return(1);
        else
        return(0);
    }//end validoFone

    /**
     * metodo para ler objeto de arquivo
     * @param fileName nome do arquivo
    */
    void fromFile ( string fileName )
    {
        ifstream afile; // input file
        int n = 0;
        afile.open(fileName);
        afile >> n;
        if (n <= 0)
        {
            cout << "\nERROR: Invalid.\n"
                 << endl;
        }
        else
        {
            // ler dados
            for (int i = 0; i < n; i++)
            {
                afile >> this->nome;
                afile >> this->fone;
            }// end for
        }// end if
        afile.close();
    }//end fromFile

    /**
     * metodo para gravar objeto em arquivo
     * @param fileName nome do arquivo
    */
    void toFile ( string fileName )
    {
        ofstream afile; // output file
        afile.open(fileName);
        int n = 1;
        afile << n << endl;
        if (n <= 0)
        {
            cout << "\nERROR: Invalid.\n"
                 << endl;
        }
        else
        {
            // ler dados
            for (int i = 0; i < n; i++)
            {
                afile << this->nome << endl;
                afile << this->fone << endl;
            }// end for
        }// end if
        afile.close();
    }//end toFile

    /**
     * metodo para contare quantos telefones uma pessoa possui cadastrados
     * @return quantidade de telefones encontrados
    */
    int telefones()
    {
        int q = 0;
        if ( this->fone.empty() && this->tel.empty())
        {
            q = 0;
            setErro(3);
        }
        else if ( this->fone.empty() || this->tel.empty() )
        q = 1;
        else q = 2;
        return(q);
    }//end telefones
};    // fim da classe Contato

using ref_Contato = Contato *; // similar a typedef Contato* ref_Contato;
#endif