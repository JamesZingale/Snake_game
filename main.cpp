#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "snake game.hpp"

using namespace std;

int main()
{
    srand(time(0)); //seed random

    snakegame gameobj; //create game object

    gameobj.addapple(); //add first apple

    while (!gameobj.getGameOver()) //while not over, do game
    {
            if (_kbhit()) // if key hit update direction
            {
                char key = _getch();
                switch (key)
                {
                    case 'w':
                        if(gameobj.getCurrentHeadDir() != 3)
                         gameobj.setCurrentHeadDir(1); // Up
                        break;
                    case 's':
                        if(gameobj.getCurrentHeadDir() != 1)
                        gameobj.setCurrentHeadDir(3); // Down
                        break;
                    case 'a':
                        if(gameobj.getCurrentHeadDir() != 2)
                        gameobj.setCurrentHeadDir(4); // Left
                        break;
                    case 'd':
                        if(gameobj.getCurrentHeadDir() != 4)
                        gameobj.setCurrentHeadDir(2); // Right
                        break;
                    default:
                        break;
                }
            }

            if(!gameobj.getGameOver()) //if not over move head forward
            {
                gameobj.push_snakehead();
            }


            if(gameobj.getDoPopTail()) //controls whether or not to increase snake length
            {
                gameobj.pop_snaketail();

            }else{
            gameobj.removeapple();
            gameobj.addapple();
            gameobj.setDoPopTail(1);
            }

        if(!gameobj.getGameOver()) //controls whether or not to display new frame or end screen
        {
            gameobj.displayframe();
        }else{
            gameobj.displayGameOver();
        }


        //gameobj.debug_displayheadtailpos();

        //delay
         Sleep(250);
    }

    std::cout<< "press Enter to exit";
    std::cin.get();

    return 0;
}
