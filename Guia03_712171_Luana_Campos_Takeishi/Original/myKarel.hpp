#include "karel.hpp"
class MyRobot : public Robot
{
  public:

/**
 turnRight - Metodo para virar a direita
*/
 void turnRight ( ) //turnRight - Procedimento para virar 'a direita.
 {
 // testar se o robo esta' ativo
  if ( checkStatus ( ) )
  {
 // o agente que executar esse metodo
 // devera' virar tres vezes 'a esquerda
    turnLeft ( );
    turnLeft ( );
    turnLeft ( );
  } // end if
 } // end turnRight ( )

 /**
  moveN - Metodo para andar N passos
  @param steps - passos a serem dados.
 */
  void moveN( int steps )
 {
  // testar se a quantidade de passos e' maior que zero
  while ( steps > 0 ) // forma alternativa
  {
  // dar um passo
     move( );
  // tentar fazer de novo, com menos um passo
    steps = steps - 1;
  } // end while
 } // end moveN( ) 

/**
 pickBeepers - Metodo para carregar marcadores
*/
    void pickBeepers ( int n ) //carregar N marcadores
    {
        for ( int b = 0; b != n; b++)
        {
            if ( nextToABeeper( ) )
            {
            // ... de tentar carrega-lo
            pickBeeper( );            
            } //end if
        }//end for
    }//end pickBeepers( )

/**
 putBeepers - Metodo para descarregar marcadores
*/
     void putBeepers ( int n ) //descarregar N marcadores no local
    {
        for ( int b = 0; b != n; b++)
        {
                if ( beepersInBag( ) )
                {
                    // ... de tentar descarrega-lo
                    putBeeper( );
                }//end if
        }//end for
    }//end putBeepers ( )

/**
 moveLeft - Metodo para virar a esquerda e andar N passos
*/
    void moveLeft( int p )
    {
        if ( leftIsClear( ) )
        {
            turnLeft( );
            moveN( p );
        }//end if
    }//end moveLeft( )
/**
 moveRight - Metodo para virar a direita e andar N passos
*/
    void moveRight( int p )
    {
        if ( rightIsClear( ) )
        {
            turnRight( );
            moveN( p );
        }//end if
    }//end moveRight( )

/**
 coordBeepers - Metodo para arquivar posicoes dos marcadores carregados
 @param fileName - nome do arquivo
*/
    void coordBeepers( const char *fileName )
    {
        //definir dados
        int x, y;
        //definir arquivo onde gravar comandos
        FILE *archive;
        archive = fopen ("Tarefa0214.txt", "a" );
        //leitura da posicao
        x= xAvenue( );      //obter posicao atual (avenue)
        y= yStreet( );      //obter posicao atual (street)
        //arquivar a posicao
        fprintf( archive, "\n%d\n", x );
        fprintf( archive, "%d\n", y );
        //fechar arquivo
        //INDISPENSAVEL para a gravacao
        fclose( archive );   
    }//end coordBeepers

//------------------------------------------------- parametros de ccrtole por numeros ou intereativo

/**
 execute - Metodo para executar um comando.
 @param action - comando a ser executado
  Lista de comandos disponiveis:
  0 - turnOff    | 1 - turnNorth    | 2 - turnSouth 
  3 - turnEast   | 4 - turnWest     | 5 - move 
  6 - pickBeeper | 7 - putBeeper    
  8 - turnLeft   | 9 - turnRight
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

            case 8: //virar a esquerda
            if ( leftIsClear( ) )
            {
                turnLeft( );
            }//end if
            break;

            case 9: //virar para a direita
            if ( rightIsClear( ) )
            {
                turnRight( );
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

/**
 movel - Metodo para mover o robot iterativamente
 Lista de comandos disponiveis:
 0 - turnOff     | 1 - turnNorth  | 2 - turnSouth 
 3 - turnEast    | 4 - turnWest   | 5 - move 
 6 - pickBeeper  | 7 - putBeeper 
 8 - turnLeft    | 9 - turnRight
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

        //repetir enquanto o comando
        //for diferente de zero
        do
        {
            //ler opcao
            action = IO_readint( "Command?" );

            //testar se opcao e valida
            if ( 0 <= action&& action <=9 )
            {
                //executar comando
                execute( action );
                
                //guardar o comando earquivo
                archive<<action<<"\n";
            }//end if
        } while ( action !=0 );

        //fechar arquivo
        //INDISPENSAVEL para a gravacao
        archive.close( );        
    }//end recordActions( )

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
                 strcpy( word, "turnNorth( ); ");
                break;
            case 2:         //virar para sul
                 strcpy( word, "turnSouth( ); ");
                break;
            case 3:         //virar para direita
                  strcpy( word, "turnEast( ); ");
                 break;
            case 4:         //virar para oeste
                  strcpy( word, "turnWest( ); ");
                 break;
            case 5:         //mover
                  strcpy( word, "move( ); ");
                 break;
            case 6:         //virar para leste
                  strcpy( word, "pickBeeper( ); ");
                 break;
            case 7:         //pegar marcador
                  strcpy( word, "putBeeper( ); ");
                 break;
            case 8:         //virar para norte
                  strcpy( word, "turnLeft( ); ");
                 break;
            case 9:         //colocar marcador
                  strcpy( word, "turnRight( ); ");
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

};

