using namespace std;
#include <iostream>
#include <Windows.h>
#include <conio.h>


//#define KEY_UP 72
//
//#define KEY_DOWN 80
//
//#define KEY_LEFT 75
//
//#define KEY_RIGHT 77


const int MAX_SNAKE_SIZE = 100;


void gotoxy(short x, short y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void showcursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}


class Point {

    int x, y;

public:

    Point(int i=0, int j=0) : x(i) ,y(j){ }

    void display() const { cout << "(" << x << "," << y << ")" << endl; }

    void up() { y++; }
    void down() { y--; }
    void right() { x = x + 2; }
    void left() { x = x - 2; }


    void print()
    { 
        gotoxy(x, y);
        cout << "O";
    }

    void copy_point(const Point& obj)
    {
        x = obj.x;
        y = obj.y;
    }


};


class Snake {
    
public:
    int size = 4;
    // representing snake by 100 points
    Point body[MAX_SNAKE_SIZE];

    Snake()
    {
        // head pos
        body[0] = { 20,20 };
    }
    

    void move()
    {       

        

    }
    





};


void play()
{
    char c = 'a';
    Snake s;

    hidecursor();

    do
    {
        if (_kbhit())
        {
            c = _getch();
        }

        switch(c)
        {

           case 's':
            {
               s.body[0].up();
                break;
            }
            case 'w':
            {
                s.body[0].down();
                break;
            }
            case 'a':
            {
                s.body[0].left();
                break;
            }
            case 'd':
            {
                s.body[0].right();
                break;
            }
        }

        
        for ( int i=0 ;i<s.size; i++)
        {
            s.body[i].print();
        }


        for (int i = s.size; i > 0; i--)
        {
            s.body[i].copy_point(s.body[i - 1]);
        }


        system("cls");
        //Sleep(10);

    } while (c != 'e');
    



}


int main()
{
    play();  
    return 0;
}
    
 



    




   


