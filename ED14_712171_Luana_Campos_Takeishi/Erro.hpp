/**
 * Classe para tratar erro.
*/
// dependencias
#include <string>
#ifndef _ERRO_H_
#define _ERRO_H_
class Erro
{
/**
 * tratamento de erro.
 * Codigos de erro:
 * 0. Nao ha' erro.
*/

/**
 * atributos privados.
*/
private:
    int erro;

/**
 * definicoes publicas.
*/
public:
    /**
     * Destrutor.
    */
    ~Erro()
    {
    }
    /**
     * Construtor padrao.
     * */
    Erro()
    {
        // atribuir valor inicial
        erro = 0;
    } // fim construtor padrao
    /**
    * Constante da classe.
    */
    static const std::string NO_ERROR;
    // ------------------------------------------- metodos para acesso
    /**
     * Funcao para obter o codigo de erro.
     * @return codigo de erro guardado
    */
    int getErro()
    {
        return (erro);
    } // end getErro ( )
    /**
    * Funcao para testar se ha' erro.
    * @return true, se houver;
    * false, caso contrario
    */
    bool hasError ( );
    /**
    * Funcao para obter mensagem
    * relativa ao código de erro.
    * @return mensagem sobre o erro
    */
    virtual std::string getErroMsg ( )
    {
    return ( "ERRO" );
    } // end getErroMsg ( )




protected:
    // ------------------------------------------- metodos para acesso restrito
    /**
     *  Metodo para estabelecer novo codigo de erro.
     * @param codigo de erro a ser guardado
    */
    void setErro(int codigo)
    {
        erro = codigo;
    } // end setErro ( )
};    // fim da classe Erro

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro."; // definir o valor da constante

#endif