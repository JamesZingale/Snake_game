#ifndef SNAKE GAME_HPP
#define SNAKE GAME_HPP
#include <iostream>
#include<stdlib.h>

struct snakenode
{
    snakenode* next = nullptr;
    snakenode* prev = nullptr;
    char data;
    int x_pos, y_pos;
};

class snakegame
{
    public:
        int score = 0;
        bool gameover = 0;
        bool doPopTail = 1;
        snakegame();
        ~snakegame();
        void push_snakehead(int direct);
        void pop_snaketail();
        void displayframe();
        void addapple();
        void removeapple();
        void debug_displayheadtailpos();


    private:

        int currentHeadDir;
        int snakeLenght;
        const static int row = 15;
        const static int col = 30;
        snakenode gamearr[row][col];
        snakenode* head;
        snakenode* tail;
        snakenode* apple;



};

#endif // SNAKE GAME_HPP
