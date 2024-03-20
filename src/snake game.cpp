#include "snake game.hpp"

void snakegame::debug_displayheadtailpos()
{
    std::cout << "head y, x: " << this->head->x_pos << " " << this->head->y_pos << std::endl;
    std::cout << "tail y, x: " << this->tail->x_pos << " " << this->tail->y_pos << std::endl;
}

snakegame::snakegame()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
         gamearr[i][j].data = '#';
        }
    }
    snakeLenght = 1;
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
    //maybe instead of all the if staments, have switch statment calculate new cords based on dir
    // then have (maybe) 2 other functions one to validate and one to create the new head at the new cords
    if(direct == 1)
    {

        if (head->y_pos - 1 > -1)
        {
            if(gamearr[head->y_pos - 1][head->x_pos ].data == 'A')
            {
                doPopTail = 0;
                this->score += 3 * snakeLenght;
            }
            if(gamearr[head->y_pos - 1][head->x_pos ].data == 'O')
            {
                this->gameover = 1;
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


        }else{
        this->gameover = 1;
        }

    }
    if(direct == 2)
    {
        if (head->x_pos + 1 < col )
        {
            if(gamearr[head->y_pos][head->x_pos + 1].data == 'A')
            {
                doPopTail = 0;
                this->score += 3 * snakeLenght;
            }
            if(gamearr[head->y_pos][head->x_pos + 1].data == 'O')
            {
                this->gameover = 1;
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


        }else{
        this->gameover = 1;
        }
    }
    if(direct == 3)
    {
        if (head->y_pos + 1 < row  )
        {
            if(gamearr[head->y_pos + 1][head->x_pos].data == 'A')
            {
                doPopTail = 0;
                this->score += 3 * snakeLenght;
            }
            if(gamearr[head->y_pos + 1][head->x_pos].data == 'O')
            {
                this->gameover = 1;
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

        }else{
        this->gameover = 1;
        }

    }
    if(direct == 4)
    {
        if (head->x_pos - 1 > -1 )
        {
            if(gamearr[head->y_pos][head->x_pos - 1].data == 'A')
            {
                doPopTail = 0;
                this->score += 3 * snakeLenght;
            }
            if(gamearr[head->y_pos][head->x_pos - 1].data == 'O')
            {
                this->gameover = 1;
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
        }else{
        this->gameover = 1;
        }
    }
}
void snakegame::pop_snaketail()
{
    if( this->gameover == 0 ) // so if not over
    {
        tail->data = '#';
        tail = tail->prev;
        tail->next = nullptr;
    }

}
void snakegame::displayframe()
{
    for(int t = 0; t < row; t++)
    {
        std::cout << "\n";
    }

    std::cout << "|";
    for(int t = 0; t < col ; t++)
    {
        std::cout << "-";
    }
    std::cout << "|";
    std::cout << "\n";

    std::cout << "|";
    std::cout << "  Score: " << this->score;;
    int outputwidth = 10;
    switch(score)
    {
        case 0 ... 9:
            outputwidth = 10;
            break;
        case 10 ... 99:
        outputwidth = 11;
            break;
        case 100 ... 999:
            outputwidth = 12;
            break;
        case 1000 ... 9999:
        outputwidth = 13;
            break;
        case 10000 ... 99999:
            outputwidth = 14;
            break;
        case 100000 ... 999999:
        outputwidth = 15;
            break;
    }
    for(int t = 0; t < col - outputwidth ; t++)
    {
        std::cout << ' ';
    }
    std::cout << "|";
    std::cout << "\n";

    std::cout << "|";
    for(int t = 0; t < col ; t++)
    {
        std::cout << "-";
    }
    std::cout << "|";
    std::cout << "\n";

    for(int i = 0; i < row; i++)
    {
        std::cout << "|";
        for(int j = 0; j < col; j++)
        {
         std::cout << gamearr[i][j].data;
        }
        std::cout << "|";
        std::cout << "\n";
    }
    std::cout << "|";
    for(int t = 0; t < col ; t++)
    {
        std::cout << "-";
    }
    std::cout << "|";
    std::cout << "\n";
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
