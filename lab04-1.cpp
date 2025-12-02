// lab04-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Stack.cpp"
using namespace std;
struct Cell
{
    int x;
    int y;
};

bool helper(char maze[6][6], Cell start, Cell end, int r, int c)
{
    if (r < 0 || r >= 6 || c < 0 || c >= 6 || maze[r][c] == '*' || maze[r][c] == 'P')
    {
        return false;
    }
    if (r==end.x&& c==end.y && maze[r][c])
    {
        cout << "(" << r << "," << c << ")" << endl;
        return true;
    }
   
    maze[r][c] ='P';
    if (helper(maze, start, end, r + 1, c))//down
    { 
        cout << "(" << r << "," << c << ")" << endl;
        return true;
    }
    if (helper(maze, start, end, r , c+1))//right
    { 
        cout << "(" << r << "," << c << ")" << endl;
        return true;
    }
    if (helper(maze, start, end, r , c-1))//left
    {
        cout << "(" << r << "," << c << ")" << endl;
        return true;
    }
    if (helper(maze, start, end, r - 1, c))//up
    {
        cout << "(" << r << "," << c << ")" << endl;
        return true;
    }
    maze[r][c] = ' ';
    return false;
}
void solvemaze(char maze[6][6], Cell start, Cell end, int r, int c)
{  
    cout << "Path is  : " << endl;
    if (!helper(maze, start, end, r, c))
    {
        cout << "Path not found" << endl;
        return;
    }
    helper(maze, start, end, r, c);
  

}
int main()
{
    char maze1[6][6] = {
 {' ', '*', ' ', '*', ' ', ' '},
 {' ', '*', ' ', '*', ' ', ' '},
 {'P', ' ', ' ', ' ', '*', ' '},
 {'*', ' ', '*', '*', '*', ' '},
 {' ', ' ', ' ', ' ', '*', 'T'},
 {'*', ' ', ' ', ' ', ' ', ' '}
    };
    Cell start = { 2,0 };
    Cell dest = { 4,5 };
    solvemaze(maze1, start, dest, 6, 6);
    char maze2[6][6] = {

    {' ', '*', ' ', '*', ' ', ' '},
    {' ', '*', ' ', '*', ' ', ' '},
    {'P', ' ', ' ', ' ', '*', ' '},
    {'*', '*', '*', '*', '*', ' '},
    {' ', ' ', ' ', ' ', '*', 'T'},
    {'*', ' ', ' ', ' ', ' ', ' '}
    };
    solvemaze(maze2, start, dest, 6, 6);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
