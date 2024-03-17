#include "snake game.hpp"

snakegame::snakegame()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
         gamearr[i][j].data = '#';
        }
    }
    snakeLenght= 1;
    head = &gamearr[row/2][col/2];

    head->x_pos = col/2;
    head->y_pos = row/2;

    gamearr[head->y_pos][head->x_pos].data = 'O';
    tail = head;
}
snakegame::~snakegame()
{

}
void snakegame::push_snakehead(int direct)
{
    if(direct == 1)
    {

        if (head->y_pos - 1 > -1)
        {
            if(gamearr[head->y_pos - 1][head->x_pos ].data == 'A')
            {
                doPopTail = 0;
            }
            // Create a new head node
            snakenode* new_head = &gamearr[head->y_pos - 1][head->x_pos];
            new_head->data = 'O';

            new_head->y_pos = head->y_pos - 1;
            new_head->x_pos = head->x_pos;

            // Update the new head's next pointer
            head->prev = new_head;
            new_head->next = head;
            new_head->prev = nullptr;

            // Update the head pointer
            head = new_head;

            // Increment the snake length
            snakeLenght++;
        } // add else to end game

    }
    if(direct == 2)
    {
        if (head->x_pos + 1 < col )
        {
            if(gamearr[head->y_pos][head->x_pos + 1].data == 'A')
            {
                doPopTail = 0;
            }
            // Create a new head node
            snakenode* new_head = &gamearr[head->y_pos][head->x_pos + 1];
            new_head->data = 'O';
            new_head->y_pos = head->y_pos;
            new_head->x_pos = head->x_pos + 1;

            // Update the new head's next pointer
            head->prev = new_head;
            new_head->next = head;
            new_head->prev = nullptr;

            // Update the head pointer
            head = new_head;

            // Increment the snake length
            snakeLenght++;
        }

    }
    if(direct == 3)
    {
        if (head->y_pos + 1 < row )
        {
            if(gamearr[head->y_pos + 1][head->x_pos].data == 'A')
            {
                doPopTail = 0;
            }
            // Create a new head node
            snakenode* new_head = &gamearr[head->y_pos + 1][head->x_pos];
            new_head->data = 'O';
            new_head->y_pos = head->y_pos + 1;
            new_head->x_pos = head->x_pos;

            // Update the new head's next pointer
            head->prev = new_head;
            new_head->next = head;
            new_head->prev = nullptr;

            // Update the head pointer
            head = new_head;

            // Increment the snake length
            snakeLenght++;
        }

    }
    if(direct == 4)
    {
        if (head->x_pos - 1 > -1 )
        {
            if(gamearr[head->y_pos][head->x_pos - 1].data == 'A')
            {
                doPopTail = 0;
            }
            // Create a new head node
            snakenode* new_head = &gamearr[head->y_pos][head->x_pos - 1];
            new_head->data = 'O';
            new_head->y_pos = head->y_pos;
            new_head->x_pos = head->x_pos - 1;

            // Update the new head's next pointer
            head->prev = new_head;
            new_head->next = head;
            new_head->prev = nullptr;

            // Update the head pointer
            head = new_head;

            // Increment the snake length
            snakeLenght++;
        }

    }
}
void snakegame::pop_snaketail()
{
    tail->data = '#';
    tail = tail->prev;
    tail->next = nullptr;

}
void snakegame::displayframe()
{
    std::cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
         std::cout << gamearr[i][j].data;
        }
        std::cout << "\n";
    }
}


void snakegame::addapple()
{
    int rand_rownum, rand_colnum;
    do
    {
        rand_rownum  = rand() % row ;
        rand_colnum  = rand() % col ;

    }while(gamearr[rand_rownum][rand_colnum].data != '#');


    apple = &gamearr[rand_rownum][rand_colnum];
    apple->data  = 'A';
    apple->x_pos = rand_colnum;
    apple->y_pos = rand_rownum;


}
void snakegame::removeapple()
{
    apple = nullptr;
}
