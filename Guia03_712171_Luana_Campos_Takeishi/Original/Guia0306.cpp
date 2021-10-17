/*
Guia0306 - v0.1. - 19 / 08 / 2020
Author: Luana Campos Takeishi
Matr'icula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux :      g++ -o Guia0306         ./Guia0306.cpp
No Windows:     g++ -o Guia0306.exe     Guia0306.cpp
Para executar em uma janela de comandos (terminal):
No Linux :      ./Guia0306.cpp
No Windows:     Guia0306
*/

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"

// --------------------------- definicoes de metodos

/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar um marcador no mundo
    world->set(4, 4, BEEPER);
    // salvar a configuracao atual do mundo
    world->save(fileName);
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
    void turnRight()
    {
        // definir dado local
        int step = 0;
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            for (step = 1; step <= 3; step = step + 1)
            {
                turnLeft();
            } // end for
        }     // end if
    }         // end turnRight ( )

    /**
moveN - Metodo para mover certa quantidade de passos.
@param steps - passos a serem dados.
*/
    void moveN(int steps)
    {
        // definir dado local
        int step = 0;
        // testar se a quantidade de passos e' maior que zero
        for (step = steps; step > 0; step = step - 1)
        {
            // dar um passo
            move();
        } // end if
    }     // end moveN( )

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
  doTask - Metodo para executar comandos de arquivo.
  @param fileName - nome do arquivo
*/
    void doTask(const char *fileName)
    {
        // definir dados locais
        int quantidade = 0;
        int comandos[MAX_COMMANDS];
        // ler quantidade e comandos
        quantidade = readCommands(comandos, "Tarefa0301.txt");
        message[0] = '\0'; // limpar a mensagem
        sprintf(message, "Commands = %d", quantidade);
        show_Text(message);
        // executar comandos
        doCommands(quantidade, comandos);
    } // end doTask( )

/**
  doCommands - Metodo para executar comandos de arquivo.
  @param length - quantidade de comandos
  @param commands - grupo de comandos para executar
*/
    void doCommands(int length, int commands[])
    {
        // definir dados
        int action = 0;
        int x = 0;
        // repetir para a quantidade de comandos
        for (x = 0; x < length; x = x + 1)
        {
            // executar esse comando
            execute(commands[x]);
        } // end for
    }// end doCommands( )

/**
  countCommands - Funcao para contar comandos de arquivo.
  @return quantidade de comandos
  @param fileName - nome do arquivo
*/
    int countCommands(const char *fileName)
    {
        // definir dados
        int x = 0;
        int length = 0;
        msg_txt[0] = '\0';
        std::ifstream archive(fileName);

        // repetir enquanto houver dados
        archive >> x;
        while (!archive.eof())
        {
            // contar mais um comando
            length = length + 1;
            // tentar ler a proxima linha
            archive >> x;
        } // end while

        // fechar o arquivo
        archive.close();

        // retornar resultado
        return (length);

    } // end countCommands( )

/**
  readCommands - Metodo para receber comandos de arquivo.
  @return grupo formado por todos os comandos
  @param filename - nome do arquivo
*/
    int readCommands (int commands[], const char *fileName)
    {
        // definir dados
        int x = 0;
        int action = 0;
        int length = 0;
        std::ifstream archive(fileName);
        // obter a quantidade de comandos
        length = countCommands(fileName);
        // criar um armazenador para os comandos
        if (length < MAX_COMMANDS)
        {
            // repetir para a quantidade de comandos
            for (x = 0; x < length; x = x + 1)
            {
                // tentar ler a proxima linha
                archive >> action;
                // guardar um comando
                // na posicao (x) do armazenador
                commands[x] = action;
            } // end for
            // fechar o arquivo
            // INDISPENSAVEL para a gravacao
            archive.close();
        } // end for
        // retornar quantidade de comandos lidos
        return (length);
    } // end readCommands( )

/**
  mapWorld - Metodo para o robot explorar o mundo.
*/
    void mapWorld( )
    {
        // obter o tamanho do mundo
        if (world != nullptr)
        {
            // informar o tamanho do mundo
            message[0] = '\0'; // limpar a mensagem
            sprintf(message, "World is %dx%d",
                    world->avenues(), world->streets());
            show_Text(message);
        } // end if
    }     // end mapWorld( )

}; // end class MyRobot

// --------------------------- acao principal
/**
Acao principal: executar a tarefa descrita acima.
*/

int main()
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0306.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0306.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(1);                // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, NORTH, 0, "Karel");

    // executar tarefa
    robot->mapWorld( );

    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);
} // end main ( )

// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
instrucoes:
- 
---------------------------------------------- notas / observacoes / comentarios
Versao 0.1
programa funcionou como o esperado
---------------------------------------------- previsao de testes
mostrar o tamanho do mundo 10x10
---------------------------------------------- historico
Versao Data Modificacao
0.1 19/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 04. ( OK ) identificacao de programa
0.2 01. ( OK ) teste contagem de comandos novo metodo
0.3 01. ( OK ) teste receber comandos de arquivo
0.4 03. ( OK ) teste executar comandos de um arquivo
0.5 01. ( OK ) teste funcao doTask
0.6 01. ( OK ) teste mostrar o tamanho do mundo
*/