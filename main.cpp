#include <iostream>
#include <conio.h>
#include <windows.h>
#include "snake game.hpp"

using namespace std;
// to do
//
//fix when you hit wall then go up or down and it shaves of a piece
//
//fix output smoothness
//
//add score

int main()
{
    snakegame gameobj;

    gameobj.addapple();
    int movedir = 2;

    // Infinite loop for continuously checking input
    while (true)
    {
        // Check if a key is pressed
        if (_kbhit())
        {
            // If a key is pressed, get the key without waiting
            char key = _getch();
            // Convert the key to the desired direction
            switch (key)
            {
                case 'w':
                    if(movedir != 3)
                    movedir = 1; // Up
                    break;
                case 's':
                    if(movedir != 1)
                    movedir = 3; // Down
                    break;
                case 'a':
                    if(movedir != 2)
                    movedir = 4; // Left
                    break;
                case 'd':
                    if(movedir != 4)
                    movedir = 2; // Right
                    break;
                default:
                    // Handle other keys as needed
                    break;
            }
        }


        gameobj.push_snakehead(movedir);

        if(gameobj.doPopTail)
        {
            gameobj.pop_snaketail();

        }else{
        gameobj.removeapple();
        gameobj.addapple();
        gameobj.doPopTail = 1;
        }

        gameobj.displayframe();

        // Add some delay if needed
         Sleep(200); // for Windows

    }

    return 0;
}
