/*
Guia0302 - v0.2. - 19 / 08 / 2020
Author: Luana Campos Takeishi
Matr'icula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux :      g++ -o Guia0302         ./Guia0302.cpp
No Windows:     g++ -o Guia0302.exe     Guia0302.cpp
Para executar em uma janela de comandos (terminal):
No Linux :      ./Guia0302.cpp
No Windows:     Guia0302
*/

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"

// --------------------------- definicoes de metodos

/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
    // colocar um marcador no mundo
    world->set ( 4, 4, BEEPER );
    // salvar a configuracao atual do mundo
    world->save( fileName );
} // decorateWorld ( )

/**
Classe para definir robo particular (MyRobot),
a partir do modelo generico (Robot)
Nota: Todas as definicoes irao valer para qualquer outro robo
criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
    public:
/**
turnRight - Procedimento para virar 'a direita.
*/
    void turnRight ( )
    {
    // definir dado local
        int step = 0;
    // testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
        // o agente que executar esse metodo
        // devera' virar tres vezes 'a esquerda
            for ( step = 1; step <= 3; step = step + 1 )
            {
                turnLeft( );
            } // end for
        } // end if
    } // end turnRight ( )

/**
moveN - Metodo para mover certa quantidade de passos.
@param steps - passos a serem dados.
*/
    void moveN( int steps )
    {
    // definir dado local
        int step = 0;
    // testar se a quantidade de passos e' maior que zero
        for ( step = steps; step > 0; step = step - 1 )
        {
        // dar um passo
            move( );
        } // end if
    } // end moveN( )

/**
  countCommands - Funcao para contar comandos de arquivo.
  @return quantidade de comandos
  @param fileName - nome do arquivo
*/
    int countCommands( const char *fileName )
    {
    // definir dados
        int x = 0;
        int length = 0;
        msg_txt [0] = '\0';
        std::ifstream archive ( fileName );

    // repetir enquanto houver dados
        archive >> x;
        while ( ! archive.eof ( ) )
        {
        // contar mais um comando
            length = length + 1;
        // tentar ler a proxima linha
            archive >> x;
        } // end while

    // fechar o arquivo
        archive.close( );
        
    // retornar resultado
        return( length );
        
    } // end countCommands( )

}; // end class MyRobot

// --------------------------- acao principal
/**
Acao principal: executar a tarefa descrita acima.
*/

int main ( )
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create ( "" ); // criar o mundo
    decorateWorld ( "Guia0302.txt" );
    world->show ( );

    // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0302.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 1 ); // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot( );
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, NORTH, 0, "Karel" );

    // executar tarefa de contar comando
    sprintf( msg_txt, "Commands = %d",
            robot->countCommands ( "Tarefa0301.txt" ) );
    show_Text( msg_txt );
    
    // encerrar operacoes no ambiente
    world->close ( );
    // encerrar programa
    getchar ( );
    return ( 0 );
} // end main ( )

// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
instrucoes:
- programa para contar a quantidade de comandos em um arquivo e mostrar na tela
novo metodo
---------------------------------------------- notas / observacoes / comentarios
Versao 0.1
uso do "message" em vez do msg_txt devido aos problemas apresentados anteriormente
Versao 0.2
mudanca de karel e uso do msg_txt
---------------------------------------------- previsao de testes
conta a quantidades de comandos no arquivo Tarefa0302.txt
e mostra na tela a quantidade encontrada
---------------------------------------------- historico
Versao Data Modificacao
0.1 18/08 esboco
0.2 19/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 05. ( OK ) identificacao de programa
0.2 02. ( OK ) teste contagem de comandos novo metodo
*/