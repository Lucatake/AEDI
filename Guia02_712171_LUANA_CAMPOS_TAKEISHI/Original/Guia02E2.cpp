/*
Guia_02E2 -v0.1. - 15 / 08 / 2020
Author: Luana Campos Takeishi
Matri'cula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux:     gcc -o Guia02E2      ./Guia02E2.cpp
No Windows:   gcc -o Guia02E2.exe    Guia02E2.cpp
Para executar em uma janela de comandos (terminal):
No Linux:     ./Guia02E2.cpp
No Windows:     Guia02E2
*/

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"

//---------------------------definicoes de metodos

/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar marcadores no mundo
    world->set ( 3, 3, BEEPER );
    world->set ( 3, 3, BEEPER );
    world->set ( 3, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 3, 4, BEEPER );
    world->set ( 3, 4, BEEPER );
    world->set ( 4, 4, BEEPER );
    world->set ( 4, 4, BEEPER );
    world->set ( 3, 5, BEEPER );

//paredes vertical externa esquerda
    world->set ( 2, 3, VWALL);
    world->set ( 2, 4, VWALL);
    world->set ( 2, 5, VWALL);
    world->set ( 2, 6, VWALL);
    world->set ( 2, 7, VWALL);
    world->set ( 2, 8, VWALL);
//paredes vertical externa direita
    world->set ( 5, 3, VWALL);
    world->set ( 5, 4, VWALL);
    world->set ( 5, 5, VWALL);
    world->set ( 5, 6, VWALL);
    world->set ( 5, 7, VWALL);
    world->set ( 5, 8, VWALL);
//paredes verticais interna esquerda
    world->set ( 3, 3, VWALL);
    world->set ( 3, 4, VWALL);
    world->set ( 3, 5, VWALL);
    world->set ( 3, 6, VWALL);
    world->set ( 3, 7, VWALL);
//paredes verticais interna direita
    world->set ( 4, 3, VWALL);
    world->set ( 4, 4, VWALL);
    world->set ( 4, 5, VWALL);
    world->set ( 4, 6, VWALL);
    world->set ( 4, 7, VWALL);
//paredes horizontais 
    world->set ( 3, 2, HWALL);
    world->set ( 4, 2, HWALL);
    world->set ( 5, 2, HWALL);
    world->set ( 3, 8, HWALL);
    world->set ( 5, 8, HWALL);

// salvar a configuracao atual do mundo
    world->save( fileName );
} // decorateWorld ( )

/** Classe para definir robo particular (MyRobot),
  a partir do modelo generico (Robot)
    Nota: Todas as definicoes irao valer para qualquer outro robo
  criado a partir dessa nova descricao de modelo.
 */

class MyRobot : public Robot
{
    public:

 //turnRight - procedimento para virar a direita.
    void turnRight( )
    {
        //definir dado local
        int step = 0;

        //testar se o robo esta ativo
        if (checkStatus( ))
        {
            //o agente devera executar esse metodo
            //virar tres vezes a esquerda
            for ( step=1 ; step<=3 ; step=step+1 )
            {
                turnLeft( );
            }//end for
        }//end if
    }//end turnRight( )

/**
 execute - Metodo para executar um comando.
 @param acrion - comando a ser executado
  Lista de comandos disponiveis:
  0 - turnOff | 1 - turnLeft | 2 - turnRight | 3 - move | 4 - pickBeeper | 5 - putBeeper
*/
    void execute( int option )
    {
        //executar acao de comando
        switch( option )
        {
            case 0: //terminar
            //nao fazer nada
            break;
            case 1: //virar para o norte
            while ( ! facingNorth( ) )
            {
                turnLeft( );
            }//end while
            break;
            case 2: //virar para o sul
            while ( ! facingSouth( ) )
            {
                turnLeft( );
            }//end while
            break;

            case 3: //virar para o leste
            while ( ! facingEast( ) )
            {
                turnLeft( );
            }//end while
            break;
            case 4: //virar para o oeste
            while ( ! facingWest( ) )
            {
                turnLeft( );
            }//end while
            break;

            case 5: //mover
            if ( frontIsClear( ) )
            {
                move( );
            }//end if
            break;
            
            case 6: //pegar marcador
            if ( nextToABeeper( ) )
            {
                pickBeeper( );
            }//end if
            break;
            
            case 7: //colocar marcador
            if ( beepersInBag( ) )
            {
                putBeeper( );
            }//end if
            break;

            default: //nenhuma das alternativas anteriores
            //comando invalido
            show_Error ( "ERROR: Invalid command." );
        }//end switch
    }//end execute ( )

/**
 playActions - Metodo para receber comandos de arquivo.
 @param fileName - nome do arquivo
*/ 
    void playActions( const char *fileName )
    {
        //definir dados 
        int action;
        std::ifstream archive ( fileName );

        //repetir enquanto houver dados 
        archive>>action;                //tentar ler a primeira linha
        while ( ! archive.eof( ) )      //testar se nao encontrado o fim
        {
            //mostrar mais um comando
            IO_print( IO_toString( action ) );
            delay( stepDelay );
            //executar mais um comando
            execute( action );
            //tentar ler a proxima linha
            archive>>action;                 //tentar ler a primeira linha
        }//end while

        //fechar o arquivo
        //RECOMENDAVEL para a leitura
        archive.close( );
    }//end playActions( )

/**
 countLine - Metodo para contar as linhas de um arquivo que contem a descricao de uma tarefa
 @param fileName - nome do arquivo
*/
    void countLine( const char *fileName )
    {
        //definir dados
        int count;
        std::string linha;
        std::ifstream archive ( fileName );

        //repetir enquanto houver dados
        archive>>count;
        for ( count=0; !archive.eof( ); count++ )
        {
            std::getline( archive, linha );
            
        }//end while
        printf( "Nu'mero de linhas: %d", count );
        //fechar o arquivo
        //RECOMENDAVEL para a leitura
        archive.close( );


    }//end countLine( )

};//end class MyRobot


//---------------------------acao principal
/**
 acao principal: executar a tarefa descrita acima
*/

int main( )
{
    //definir contexto

    //criar o ambiente e decorar com objetos
    //obs: executar pelo menos uma vez,
    //     antes de qualquer coisa
    //     (depois de criado, podera ser comentado)
    world->create("");              //criar mundo
    decorateWorld( "Guia02E2.txt");
    world->show( );

    //preparar o ambiente para uso
    world->reset( );                //limpar configurações
    world->read ("Guia02E2.txt");   //ler configuracao atual para o ambiente
    world->show( );                 //mostrar a configuracao atual

    //definir velocidade padrao
    set_Speed( 1 );  

    //criar robo
    MyRobot*robot = new MyRobot( );

    //posicionar robo no ambiente (situacao inicial):
    //posicao (x=1,y=1), voltada para cima, com zero marcadores, nome escolhido
    robot->create ( 1 , 1 , EAST , 0 , "Karel" );

    //contar as linhas do arquivo
    robot->countLine( "Tarefa02E2.txt" ); 
    delay( stepDelay );
    //executar tarefa
    robot->playActions( "Tarefa02E2.txt" ); 
    

    //encerrar programa
    getchar( );
    return( 0 );
    
}//end main

// -------------------------------------------testes
/*--------------------------------------------documentacao complementar
instrucoes gerais:
ler o número de comandos (linhas) em um arquivo que descreva uma tarefa e, 
em seguida, tentar ler e executar cada um desses comandos.
----------------------------------------------notas / observacoes / comentarios
mesmo percurso do Guia0215, primeiro le o numero de comandos no arquivo pela func countLine( )
tra-o na tela e então inicia a tentativa de execucao dos comandos em playActions( )
----------------------------------------------previsao de testes
----------------------------------------------historico
Versao 1.0
Data Modificacao 0.1 14/08 esboco
---------------------------------------------testes
Versao Teste 0.1 01. ( OK ) teste inicial
Versao Teste 0.2 01. ( OK ) teste da repeticao para virar a direita
Versao Teste 0.3 01. ( OK ) teste da repeticao para percorrer um quadrado
Versao Teste 0.4 01. ( OK ) teste para carregar os marcadores
Versao Teste 0.5 02. ( OK ) teste para carregar os marcadores e retornar a quantidade
Versao Teste 0.6 01. ( OK ) teste para comando do Karel interativo
Versao Teste 0.7 01. ( OK ) teste Karel arquivando os comandos 
Versao Teste 0.8 02. ( OK ) teste Karel realizando acoes arquivadas
Versao Teste 0.9 01. ( OK ) teste Karel com comandos arquivados escritos
Versao Teste 0.9 01. ( OK ) teste Karel com comandos escritos
Versao Teste 1.0 02. ( OK ) teste Karel arquiva, traduz, adiciona e realiza os comandos
Versao Teste 1.1 06. ( OK ) teste Exercicio 01 (escada)
Versao Teste 1.2 04. ( OK ) teste Exercicio 02 ("labirinto" X)
Versao Teste 1.3 02. ( OK ) teste Exercicio 03 (comodos e 6 marcadores)
Versao Teste 1.4 06. ( OK ) teste Exercicio 04 (comodos, 14 marcadores e arquivamento 
                                                            de posicoes dos marcadores)
Versao Teste 1.5 03. ( OK ) teste Exercicio 05 (comodos, 14 marcadores, realocar marcadores 
                                                            a partir de acoes arquivadas)
Versao Teste E.1 01. ( OK ) teste Exercicio EXTRA01 (contar numero de linhas/comandos do arquivo)  
Versao Teste E.2 01. ( OK ) teste Exercicio EXTRA02 (ler o numero de comandos/linhas do arquivo e 
                                                            depois tentar executa-los)                                  
*/