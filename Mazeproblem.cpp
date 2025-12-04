// Mazeproblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include <iostream>
#include "stack.cpp"
using namespace std;
struct pairs
{
    int x;
    int y;
};
bool iscorrectpath(int maze[5][5], int row, int col, int n, int m) {
    return (row >= 0 && row < n && col >= 0 && col < m && maze[row][col] == 0);
}
void printmaze(int maze[5][5], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void solvemaze(int maze[5][5], pairs s, pairs d, int row, int col)
{
    stack<pairs> st(row * col);
    st.push(s);
    while (!st.isempty())
    {
        pairs p = st.pop();
        int r = p.x;
        int c = p.y;
        if (r == d.x && c == d.y)
        {   
            maze[r][c] = 3;
            printmaze(maze, row, col);
            cout << "path found" << endl;
            return;
        }
        if (maze[r][c] == 0)
        {
            maze[r][c] = 3;

        }
        if (iscorrectpath(maze, r + 1, c, row, col)) st.push({ r + 1, c });
        if (iscorrectpath(maze, r, c + 1, row, col)) st.push({ r, c + 1 });
        if (iscorrectpath(maze, r - 1, c, row, col)) st.push({ r - 1, c });
        if (iscorrectpath(maze, r, c - 1, row, col)) st.push({ r, c - 1 });
    }
    cout << "path not found" << endl;
}
int main() {
    int maze[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    pairs start = { 0, 0 };
    pairs  end = { 4, 4 };
    solvemaze(maze, start, end, 5, 5);

    return 0;
}
*/
#include<iostream>
#include<array>
#include<string>
#include "Stack.cpp"

using namespace std;

struct pair1
{
	int x; //coordinate of row
	int y; //coordinate of column
};

void solve_maze(char maze[6][6], pair1 s, pair1 d, int row, int col)
{
	Stack<pair1> st(100);
	st.push(s);      //pushing the beginning index in stack
	maze[s.x][s.y] = '3';  //marking a value for the alr visited cells

	while (s.x != d.x || s.y != d.y)  //only terminates when both are equal
	{
		if (s.y + 1 < col && maze[s.x][s.y + 1] != '*' && maze[s.x][s.y + 1] != '3')  //moves right
		{
			s.y++;
			maze[s.x][s.y] = '3';
			st.push(s);
		}

		if (s.x + 1 < row && maze[s.x + 1][s.y] != '*' && maze[s.x + 1][s.y] != '3') //moves above
		{
			s.x++;
			maze[s.x][s.y] = '3';
			st.push(s);
		}

		else if (s.y - 1 < col && maze[s.x][s.y - 1] != '*' && maze[s.x][s.y - 1] != '3') //moves left
		{
			s.y--;
			maze[s.x][s.y] = '3';
			st.push(s);
		}

		else if (s.x - 1 < row && maze[s.x - 1][s.y] != '*' && maze[s.x - 1][s.y] != '3') //moves down
		{
			s.x--;
			maze[s.x][s.y] = '3';
			st.push(s);
		}

		else
		{
			pair1 p = st.pop();  //backtracking
			s.x = p.x;
			s.y = p.y;
		}


	}

	if (s.x == d.x && s.y == d.y)
	{
		cout << "MAZE HAS BEEN SOLVED!"<<endl;
			if (st.isempty() || st.getStack().x != d.x || st.getStack().y != d.y)  //seeing if dest is there,if not push to complete path
			{
				st.push(d);
			}

		while (!st.isempty())  //printing the addresses in the stack(path)
		{
			pair1 cd = st.pop();

			cout << "(" << cd.x << "," << cd.y << ")";

		}
	}

	else
	{
		cout << "Path does not exist." << endl;
	}
}
int main() {
	char maze1[6][6] = {
	{' ', '*', ' ', '*', ' ', ' '},
	{' ', '*', ' ', '*', ' ', ' '},
	{'P', ' ', ' ', ' ', '*', ' '},
	{'*', ' ', '*', '*', '*', ' '},
	{' ', ' ', ' ', ' ', '*', 'T'},
	{'*', ' ', ' ', ' ', ' ', ' '}
	};
	pair1 start = { 2,0 };
	pair1 dest = { 4,5 };
	solve_maze(maze1, start, dest, 6, 6);
	/*char maze2[6][6] = {

	{' ', '*', ' ', '*', ' ', ' '},
	{' ', '*', ' ', '*', ' ', ' '},
	{'P', ' ', ' ', ' ', '*', ' '},
	{'*', '*', '*', '*', '*', ' '},
	{' ', ' ', ' ', ' ', '*', 'T'},
	{'*', ' ', ' ', ' ', ' ', ' '}
	};
	solve_maze(maze2, start, dest, 6, 6);*/
	return 0;
}