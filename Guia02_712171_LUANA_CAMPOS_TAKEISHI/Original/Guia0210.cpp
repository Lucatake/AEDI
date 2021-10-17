/*
Guia_0210 -v0.1. - 13 / 08 / 2020
Author: Luana Campos Takeishi
Matri'cula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux:     gcc -o Guia0210      ./Guia0210.cpp
No Windows:   gcc -o Guia0210.exe    Guia0210.cpp
Para executar em uma janela de comandos (terminal):
No Linux:     ./Guia0210.cpp
No Windows:     Guia0210
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
// colocar um marcador no mundo
    world->set ( 4, 4, BEEPER );
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
 moveN - Metodo para mover certa quantidade de passos.
 @param steps - passosa serem dados.
*/
    void moveN( int steps )
    {
        //definir dado local
        int step = 0;

        //testar se a quantidade de passos e maior que zero
        for ( step=steps; step>0 ; step=step-1 )
        {
            //dar um passo
            move( );
        }//end for
    }//end moveN( )

/**
 doPartialTask - Metodo para especificar parte de uma tarefa
*/
    void doPartialTask( )
    {
        //especificar acoes dessa parte da tarefa
        moveN( 3 );
        turnLeft( );
    }//end doPartialTask( )

/**
 doTask - Relação de acoes para o robo executar
*/
    void doTask( )
    {
        //definir dado local
        int step = 4;

        //especificar acoes da tarefa
        while( step>0 )
        {
            //realizar parte da tarefa
            doPartialTask( );
            //tentar passar para a proxima
            step = step - 1;
        }//end while

        //encerrar
        turnOff( );
    }//end doTask( )

/**
 pickBeepers - Metodo para coletar marcadores (todos)
*/
    int pickBeepers( )
    {
        //definir dado local
        int n = 0;
        //repetir (com teste no inicio)
        //enquanto houver marcador proximo
        while( nextToABeeper( ) )
        {
            //coletar um carcador
            pickBeeper( );
            //contar mais um marcador coletado
            n = n + 1;
        }//end while
        //retornar quantidade de marcadores coletados
        return( n );
    }//end pickBeepers( )


/**
 doSquare - Metodo para especificar outro percurso.
*/
    void doSquare( )
    {
        //definir dado local
        int step = 1;
        int n = 0;

        //especificar acoes da tarefa
        while( step<=4 )
        {
            //realizar uma parte da tarefa
            moveN( 3 );
            n = pickBeepers( );

            //testar se a quantidade e maior que zero
            if( n>0 )
            {
                //montar mensagem pra saida
                sprintf( msg_txt, "Recolhidos = %d", n );
                //agendar exibicao
                has_Text = true;
            }//end if

            turnRight( );
            //tentar passar a proxima
            step = step + 1;
        }//end while

        turnOff( );
    }//end doSquare( )

/**
 execute - Metodo para executar um comando.
 @param acrion - comando a ser executado
*/
    void execute( int option )
    {
        //executar acao de comando
        switch( option )
        {
            case 0: //terminar
            //nao fazer nada
            break;
            case 1: //virar para a esquerda
            if ( leftIsClear( ) )
            {
                turnLeft( );
            }//end if
            break;
            case 2: //virar para o sul
            while ( ! facingSouth( ) )
            {
                turnLeft( );
            }//end while
            break;
            case 3: //virar para a direita
            if ( rightIsClear( ) )
            {
                turnRight( );
            }//end if
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
            case 6: //virar para o leste
            while ( ! facingEast( ) )
            {
                turnLeft( );
            }//end while
            break;
            case 7: //pegar marcador
            if ( nextToABeeper( ) )
            {
                pickBeeper( );
            }//end if
            break;
            case 8: //virar para o norte
            while ( ! facingNorth( ) )
            {
                turnLeft( );
            }//end while
            break;
            case 9: //colocar marcador
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
 movel - Metodo para mover o robot iterativamente
 Lista de comandos disponiveis:
  0 - turnOff           
  1 - turnLeft          2-  to South          
  3 - turnRight         4 - to West           
  5 - move              
  6 - to East           7 - pickBeeper        
  8 - to North          9 - putBeeper
*/
    void movel( )
    {
        //definir dados 
        int action;

        //repetir com testes no fim
        //enquanto opcao diferente de zero
        do
        {
            //ler opcao
            action = IO_readint( "Command?" );
            //executar acao dependente da opcao
            execute ( action );
        } while ( action !=0 );
    }//end movel( )

/**
 recordActions - Metodo para mover o robot interativamente
 e aguardar a descricao da tarefa em arquivo.
 @param fileName - nome do arquivo
*/
    void recordActions( const char *fileName )
    {
        //definir dados
        int action;
        //definir arqui onden gravar comandos
        std::ofstream archive ( fileName );

        //ler opcao
            action = IO_readint( "Command?" );
        //repetir enquanto for maior ou igual a zero
        while( action!=0 )
        {
            //testar se opcao e valida
            if ( 0 <= action&&action <=9 )
            {
                //executar comando
                execute( action );
                
                //guardar o comando earquivo
                archive<<action<<"\n";
            }//end if
            //ler opcao
            action = IO_readint( "Command?" );
        }//end while
        
        //fechar arquivo
        //INDISPENSAVEL para a gravacao
        archive.close( );        
    }//end recordActions( )

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
            //execar mais um comando
            execute( action );
            //tentar ler a proxima linha
            archive>>action;            //tentar ler a primeira linha
        }//end while

        //fechar o arquivo
        //RECOMENDAVEL para a leitura
        archive.close( );
    }//end playActions( )

/**
 dictionary - Metodo para traduzir um comando.
 @param action - comando a ser traduzido
*/
    chars dictionary( int action )
    {
        //definir dado
        static char word[80];
        strcpy( word, "" ); //palavra vazia
        //identificar comando

        switch ( action )
        {
            case 1:         //virar para esquerda
                 strcpy( word, "turnLeft( ); ");
                break;
            case 2:         //virar para sul
                 strcpy( word, "faceSouth( ); ");
                break;
            case 3:         //virar para direita
                  strcpy( word, "turnRight( ); ");
                 break;
            case 4:         //virar para oeste
                  strcpy( word, "faceWest( ); ");
                 break;
            case 5:         //mover
                  strcpy( word, "move( ); ");
                 break;
            case 6:         //virar para leste
                  strcpy( word, "faceEast( ); ");
                 break;
            case 7:         //pegar marcador
                  strcpy( word, "pickBeeper( ); ");
                 break;
            case 8:         //virar para norte
                  strcpy( word, "faceNorth( ); ");
                 break;
            case 9:         //colocar marcador
                  strcpy( word, "putBeeper( ); ");
                 break;

            default:
                break;
        }//end switch
        //retornar palavra equivalente
        return ( &( word[0] ) );
    }//end dictionary( )

/**
 translateActions - Metodo para receber comandos de arquivo e traduzi-los.
 @param fileName - nome do arquivo
*/
    void translateActions ( const char *fileName )
    {
        //definir dados
        int action;
        std::ifstream archive( fileName );

        //repetir enquanto houver dados
        archive>>action;            //tentar ler a primeira linha
        while ( !archive.eof( ) )   //testar se nao encontrado o fim
        {
            //tentar traduzir um comando
            IO_print( dictionary( action ) );
            getchar( );
            //guardar mais um comando
            execute( action );
            //tentar ler a proxima linha
            archive>>action;        //tentar ler a primeira linha
        }//end while
        //fechar o arquivo
        //RECOMENDAVEL para a leitura
        archive.close( );
    }//end translateActions( )

/**
 appendActions - Metodo para acrescentar comandos ao arquivo e traduzi-los
 @param fileName - nome do arquivo
*/
    void appendActions ( const char *fileName )
    {
        //definir dados
        int action;
        std::fstream archive (fileName, std::ios::app );

        //repetir enquanto acao diferente de zero
        do
        {
            //ler acao
            action = IO_readint ( "Command?" );
            //testar se opcao valida
            if ( 0 <= action && action <=9 )
            {
                //executar comando
                execute ( action );
                //guardar comando em arquivo
                archive<<action;
            }//end if
        } while ( action!=0 );
        
        //fechar arquivo
        //INDISPENSAVEL para gravacao
        archive.close( );
    }//end appendActions

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
    decorateWorld( "Guia0210.txt");
    world->show( );

    //preparar o ambiente para uso
    world->reset( );                //limpar configurações
    world->read ("Guia0210.txt");   //ler configuracao atual para o ambiente
    world->show( );                 //mostrar a configuracao atual

    //definir velocidade padrao
    set_Speed( 3 );  

    //criar robo
    MyRobot*robot = new MyRobot( );

    //posicionar robo no ambiente (situacao inicial):
    //posicao (x=1,y=1), voltada para cima, com zero marcadores, nome escolhido
    robot->create ( 1 , 1 , NORTH , 0 , "Karel" );

    //executar tarefa
    robot->recordActions( "Tarefa0210.txt" );
    //dar uma pausa na entrada de comandos
    show_Text( "Pause on recording" );
    //mostrar configuracao atual do mundo
    world->show( );
    //retomar a entrada de comandos
    robot->appendActions( "Tarefa0210.txt" );
    //reproduzir todos os comandos
    robot->playActions( "Tarefa0210.txt" );

    //encerrar programa
    getchar( );
    return( 0 );
    
}//end main

// -------------------------------------------testes
/*--------------------------------------------documentacao complementar
----------------------------------------------notas / observacoes / comentarios
Versão 0.1
modificacoes: teste final (do-while) trocado por inicial (while) 
na funcao recordActions( )
erro: não realiza nada após dar entrada no valor 0 
Versao 0.2
modificacoes: while recordActions --- de (action>=0)
para (action!=0), pois senão o while nunca termina
Karel executa os comandos, pausa para leitura, 
necessario enter para continuar, mostra o mundo atual
aceita novos comandos com o appendActions, ao finalizar
repete a primeira leva dos comandos arquivados
----------------------------------------------previsao de testes

----------------------------------------------historico
Versao 1.0
Data Modificacao 0.1 13/08 esboco
Versao 2.0
Data Modificacao 0.1 13/08 esboco
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
*/