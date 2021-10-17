/*
Guia0315 - v0.3. - 25 / 08 / 2020
Author: Luana Campos Takeishi
Matr'icula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux :      g++ -o Guia0315         ./Guia0315.cpp
No Windows:     g++ -o Guia0315.exe     Guia0315.cpp
Para executar em uma janela de comandos (terminal):
No Linux :      ./Guia0315.cpp
No Windows:     Guia0315
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
    world->set ( 2, 5, BEEPER ); 
    
//verticais
    world->set ( 1, 5, VWALL);
    world->set ( 1, 6, VWALL);
    world->set ( 8, 5, VWALL);
    world->set ( 8, 6, VWALL);
//horizontais
    world->set ( 2, 4, HWALL);
    world->set ( 3, 4, HWALL);
    world->set ( 4, 4, HWALL);
    world->set ( 5, 4, HWALL);
    world->set ( 6, 4, HWALL);
    world->set ( 7, 4, HWALL);
    world->set ( 8, 4, HWALL);

    world->set ( 2, 5, HWALL);
    world->set ( 3, 5, HWALL);
    world->set ( 4, 5, HWALL);
    world->set ( 6, 5, HWALL);
    world->set ( 7, 5, HWALL);
    world->set ( 8, 5, HWALL);

    world->set ( 2, 6, HWALL);
    world->set ( 3, 6, HWALL);
    world->set ( 4, 6, HWALL);
    world->set ( 5, 6, HWALL);
    world->set ( 6, 6, HWALL);
    world->set ( 7, 6, HWALL);
    world->set ( 8, 6, HWALL);

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
 execute - Metodo para executar um comando.
 @param action - comando a ser executado
  Lista de comandos disponiveis:
  0 - turnOff         | 1 - turnNorth    | 2 - turnSouth 
  5 - move            | 3 - putBeeper 2 
  6 - pickBeeper      | 7 - putBeeper 1   
  8 - halfPathRight   | 9 - halfPathLeft  
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

            case 3: //colocar marcador (robo 2)
            if ( nbeepers( )>0 )
            {
                putBeeper( );
            }
            break;

            case 5: //mover
            if ( frontIsClear( ) )
            {
                move( );
            }//end if
            break;
            
            case 6: //pegar marcador (robo 2)
            if ( nextToABeeper( ) )
            {
                pickBeeper( );
            }//end if
            break;
            case 7: //colocar marcador (robo 1)
            if ( nextToARobot( ) && beepersInBag( ) )
            {
                putBeeper( );
            }
            else
            {
                turnLeft( );
                move( );
                halfPathLeft( );
            }
            //end if
            break;

            case 8: //andar metade do caminho direita
                halfPathRight( );
            break;
            case 9: //andar metade do caminho esquerda
                halfPathLeft( );
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

/*
 halfPathRight - Metodo para andar metade do caminho para a direita
*/
    void halfPathRight( )
    {
        while ( ! facingEast( ) )
        {
                turnLeft( );
        }//end while
        moveN(3);
    }//end HalfPathRight

/*
 halfPathLeft - Metodo para andar metade do caminho para a direita
*/
    void halfPathLeft( )
    {
        while ( ! facingWest( ) )
        {
                turnLeft( );
        }//end while
        moveN(3);
    }//end HalfPathLeft

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
    decorateWorld( "Guia0315.txt");
    world->show( );

    //preparar o ambiente para uso
    world->reset( );                //limpar configurações
    world->read ("Guia0315.txt");   //ler configuracao atual para o ambiente
    world->show( );                 //mostrar a configuracao atual

    //definir velocidade padrao
    set_Speed( 1 );  

    //criar robo
    MyRobot*robot1 = new MyRobot( );
    MyRobot*robot2 = new MyRobot( );

    //posicionar robo no ambiente (situacao inicial):
    //posicao (x=1,y=1), voltada para cima, com zero marcadores, nome escolhido
    robot1->create ( 2 , 6 , EAST , 0 , "Luana" );
    robot2->create ( 8 , 6 , EAST , 0 , "Karel" );

    //executar tarefa
    robot1->playActions("Robo10315.txt");
    robot2->playActions("Robo220315.txt");
    robot1->playActions("Robo110315.txt");
    robot2->playActions("Robo20315.txt");

    //encerrar programa
    getchar( );
    return( 0 );
    
}//end main

//--------testes--------
/*
---------------------------------------------- documentacao complementar
instrucoes:
o robo L devera buscar o marcador (1), mover-se ate a passagem; 
ir a parte de acima, aguardar a aproximacao de K, e entregar o marcador; 
depois, o robo K levara o marcador ate posicao final indicada
e ambos retornarão as suas respectivas posições iniciais;
- dois metodos adicionais deverão ser criados:
halfPathRight( ) - andar metade do caminho para a direita
halfPathLeft( ) - andar metade do caminho para a esquerda
- outros metodos envolvendo sensores deverão ser usados
para a percepcao de um robo em relacao ao outro,
antes da transferência do marcador: (dentro do execute)
a.) testar se proximo a outro robo
b.) testar se proximo a um marcador
---------------------------------------------- notas / observacoes / comentarios
Versao 0.1
construcao do mundo, alocamento dos marcadores e criacao das funcoes
Versao 0.2
construcao dos comandos no arquivo txt (Tarefa0315.txt)
observacao: erro no robot2->playActions("Robo20315.txt"); nao identificado
apos descarregar o marcador, o proximo comando e tido como invalido
por motivo desconhecido, caso ele nao descarregue o marcador
o programa segue normalmente
Versao 0.3
falvava um break; apos o case3
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 22/08 esboco
0.2 22/08 esboco
0.3 25/08 esboco
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
1.4 02. ( OK ) exercicio 4 - labirinto roteiro
1.5 02. ( OK ) exercicio 5 - labirinto 2 robos
*/