/*
Guia0313 - v0.2. - 20 / 08 / 2020
Author: Luana Campos Takeishi
Matr'icula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux :      g++ -o Guia0313         ./Guia0313.cpp
No Windows:     g++ -o Guia0313.exe     Guia0313.cpp
Para executar em uma janela de comandos (terminal):
No Linux :      ./Guia0313.cpp
No Windows:     Guia0313
*/

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"

//--------definicoes de metodos--------

/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar marcadores no mundo
    world->set ( 6, 7, BEEPER ); //1
    world->set ( 5, 7, BEEPER ); //2
    world->set ( 5, 7, BEEPER );
    world->set ( 4, 7, BEEPER ); //3
    world->set ( 4, 7, BEEPER );
    world->set ( 4, 7, BEEPER );
    
//verticais (da esquerda para direita)
    world->set ( 1, 3, VWALL);
    world->set ( 1, 4, VWALL);
    world->set ( 1, 5, VWALL);
    world->set ( 1, 6, VWALL);
    world->set ( 1, 7, VWALL);
    world->set ( 1, 8, VWALL);

    world->set ( 2, 4, VWALL);
    world->set ( 2, 5, VWALL);
    world->set ( 2, 6, VWALL);
    world->set ( 2, 7, VWALL);

    world->set ( 3, 5, VWALL);
    world->set ( 3, 6, VWALL);

    world->set ( 4, 7, VWALL);
    world->set ( 5, 7, VWALL);

    world->set ( 6, 5, VWALL);
    world->set ( 6, 6, VWALL);

    world->set ( 7, 3, VWALL);
    world->set ( 7, 4, VWALL);
    world->set ( 7, 5, VWALL);
    world->set ( 7, 6, VWALL);
    world->set ( 7, 7, VWALL);

//horizontais (de baixo para cima)
    world->set ( 2, 2, HWALL);
    world->set ( 3, 2, HWALL);
    world->set ( 4, 2, HWALL);
    world->set ( 5, 2, HWALL);
    world->set ( 6, 2, HWALL);
    world->set ( 7, 2, HWALL);

    world->set ( 5, 4, HWALL);
    world->set ( 6, 4, HWALL);
    world->set ( 4, 6, HWALL);
    world->set ( 6, 6, HWALL);
    world->set ( 3, 7, HWALL);
    world->set ( 4, 7, HWALL);
    world->set ( 5, 7, HWALL);
    world->set ( 6, 7, HWALL);
    world->set ( 7, 7, HWALL);

    world->set ( 2, 8, HWALL);
    world->set ( 3, 8, HWALL);
    world->set ( 4, 8, HWALL);
    world->set ( 5, 8, HWALL);
    world->set ( 6, 8, HWALL);
    world->set ( 7, 8, HWALL);

/**Obs: paredes verticais são formadas do lado direito
    e paredes horizontais em cima*/   

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
 @param action - comando a ser executado
  Lista de comandos disponiveis:
  0 - turnOff    | 1 - turnNorth    | 2 - turnSouth 
  3 - turnEast   | 4 - turnWest     | 5 - move 
  6 - pickBeeper | 7 - putBeeper    
  8 - rightWall  | 9 - leftWall    
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
                coordBeepers("Coordenadas0313.txt");
            }//end if
            break;
            case 7: //colocar marcador
            if ( beepersInBag( ) )
            {
                putBeeper( );
            }//end if
            break;

            case 8: //parede direita
                rightWall( );
            break;
            case 9: //parede esquerda
                leftWall( );
            break;

            default: //nenhuma das alternativas anteriores
            //comando invalido
            show_Error ( "ERROR: Invalid command." );
        }//end switch
    }//end execute( )

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
 coordBeepers - Metodo para arquivar posicoes dos marcadores carregados
 @param fileName - nome do arquivo
*/
    void coordBeepers( const char *fileName )
    {
        //definir dados
        int x, y;
        //definir arquivo onde gravar coordenadas
        FILE *archive;
        archive = fopen ("Coordenadas0313.txt", "a" );
        fprintf( archive, "\0" );
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

/**
 quantBeepers - Metodo para arquivar a quantidade de marcadores recolhidos
 @param fileName - nome do arquivo
*/
    void quantBeepers( const char *fileName )
    {
        //definir dados
        int c=0;
        //definir arquivo onde gravar quantidades
        FILE *archive;
        archive = fopen ("Quantidade0313.txt", "w" );
        fprintf( archive, "\0" );
        //leitura da quantidade
        while ( beepersInBag( ) )
        {
            putBeeper( );
            c=c+1;
        }
        //arquivar a quantidade
        fprintf( archive, "%d\n", c );
        //fechar arquivo
        //INDISPENSAVEL para a gravacao
        fclose( archive );  
    }//end quantBeepers( )

/**
 rightWall - metodo para seguir a parede e virar a direita
*/
    void rightWall( )
    {
        //virar para direita quando não tiver parede
        if ( rightIsClear( ) )
        {
            turnRight( );
            move( );
        }
        //seguir 
        while ( frontIsClear( ) && !rightIsClear( ) )
        {
            move( );
        }
    } //end rightWall( )
/**
 leftWall - metodo para seguir a parede e virar a esquerda
*/
    void leftWall( )
    {
        //virar para esquerda quando encontrar uma parede
        if (!frontIsClear() && !rightIsClear())
        {
            turnLeft( );
        }
        //seguir
        while ( frontIsClear( ) && !rightIsClear( ) )
        {
            move( );
        }
    } //end leftWall( )

};//end class MyRobot


//--------acao principal--------
/**
 acao principal: executar a tarefa descrita acima
*/
int main( )
{
    //definir contexto

    //criar o ambiente e decorar com objetos
    //obs: executar pelo menos uma vez,
    //antes de qualquer coisa
    //(depois de criado, podera ser comentado)
    world->create("");              //criar mundo
    decorateWorld( "Guia0313.txt");
    world->show( );

    //preparar o ambiente para uso
    world->reset( );                //limpar configurações
    world->read ("Guia0313.txt");   //ler configuracao atual para o ambiente
    world->show( );                 //mostrar a configuracao atual

    //definir velocidade padrao
    set_Speed( 0.7 );  

    //criar robo
    MyRobot*robot = new MyRobot( );

    //posicionar robo no ambiente (situacao inicial):
    //posicao (x=1,y=1), voltada para cima, com zero marcadores, nome escolhido
    robot->create ( 1 , 1 , EAST , 0 , "Luana" );

    //executar tarefa
    robot->playActions( "Tarefa0313.txt" );
    robot->quantBeepers("Quantidade0313.txt");

    //encerrar programa
    getchar( );
    return( 0 );
    
}//end main

//--------testes--------
/*
---------------------------------------------- documentacao complementar
instrucoes:
- definir um robo na posicao (1,1), voltado para leste, sem marcadores;
- dispor blocos em uma configuracao semelhante a dada abaixo:
- definir um labirinto com os marcadores indicados,
segundo o modelo acima;
- tarefa:
o robo devera buscar os marcadores, na ordem indicada,
e traze-los a posicao inicial;
guardar em tabelas separadas as coordenadas (x, y) e
a quantidade de marcadores recolhidos.
---------------------------------------------- notas / observacoes / comentarios
Versao 0.1
construcao do mundo, alocamento dos marcadores e criacao das funcoes
Versao 0.2
construcao dos comandos no arquivo txt (Tarefa0313.txt)
novos metodos adicionados como funcoes e ao execute
funcoes leftWall e rightWall para seguir as paredes
Karel le os comandos do arquivo Tarefa0313.txt,
guarda as coordenadas dos marcadores em Coordenadas0313.txt
e a quantidade em Quantidade0313.txt
obs: as funcoes leftWall e rightWall podem ser melhoradas.
problema de não limpar o arquivo toda vez que executa o programa.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 20/08 esboco
0.2 20/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 04. ( OK ) identificacao de programa
0.2 01. ( OK ) teste contagem de comandos novo metodo
0.3 01. ( OK ) teste receber comandos de arquivo
0.4 03. ( OK ) teste executar comandos de um arquivo
0.5 01. ( OK ) teste funcao doTask
0.6 01. ( OK ) teste mostrar o tamanho do mundo
0.7 02. ( OK ) teste varredura do mundo
0.8 01. ( OK ) teste explorar o mundo e amarzenar matriz do mapa
0.9 01. ( OK ) teste salvar matriz do mapa em arquivo
1.0 01. ( OK ) teste salva e le o mapa
1.1 02. ( OK ) exercicio 1 - dois quadrados
1.2 02. ( OK ) exercicio 2 - labirinto e funcoes 180 e U
1.3 02. ( OK ) exercicio 3 - labirinto, coordenadas e quantidade
*/