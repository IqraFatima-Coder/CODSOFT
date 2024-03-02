#include <iostream>
using namespace std;

char array[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

string p1 = " ", p2 = " ";
char turn = 'X';
bool draw = false;
int num, row, col, i, j;

void grid()
{
    cout << "      |      |     " << endl;
    cout << "  " << array[0][0] << "   |  " << array[0][1] << "   |  " << array[0][2] << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |     " << endl;
    cout << "  " << array[1][0] << "   |  " << array[1][1] << "   |  " << array[1][2] << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |     " << endl;
    cout << "  " << array[2][0] << "   |  " << array[2][1] << "   |  " << array[2][2] << endl;
    cout << "      |      |     " << endl;
}


void input()
{
    if (turn == 'X')
    {
        cout << p1 << " (X) Enter your choice:";
    }
    else if (turn == 'O')
    {
        cout << p2 << " (O) Enter your Choice:";
    }
    cin >> num;
    row = (num - 1) / 3;
    col = (num - 1) % 3;

    if (num < 1 || num > 9 || array[row][col] == 'X' || array[row][col] == 'O')
    {
        cout << "Invalid Input or Position already taken! Choose another one." << endl;
        input();
    }
    else
    {
        if (turn == 'X')
            array[row][col] = 'X';
        else
            array[row][col] = 'O';
        
        // Switch turns
        if (turn == 'X')
            turn = 'O';
        else
            turn = 'X';
    }
}


bool game_over()
{
    // checking rows and columns for win
    for (i = 0; i < 3; i++)
    {
        if ((array[i][0] == array[i][1] && array[i][1] == array[i][2]) || (array[0][i] == array[1][i] && array[0][i] == array[2][i]))
            return false;
    }

    // checking diagonals for win
    if ((array[0][0] == array[1][1] && array[1][1] == array[2][2]) || (array[0][2] == array[1][1] && array[1][1] == array[2][0]))
        return false;

    // checking for draw
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (array[i][j] != 'X' && array[i][j] != 'O')
                return true;
        }
    }

    draw = true;
    return false;
}

void winner()
{
    if (turn == 'X' && !draw)
        cout << "\n\nCongratulations! " << p2 << " (O) has won the game!";
    else if (turn == 'O' && !draw)
        cout << "\n\nCongratulations! " << p1 << " (X) has won the game!";
    else
        cout << "\n\nIt's a draw!";
}

int main()
{
    cout << "\tTic   Tac   Toe\n";
    cout << "\t2-players Game\n\n";
    cout << "Player 1-(X): Enter your name:";
    cin >> p1;
    cout << "Player 2-(O): Enter your name:";
    cin >> p2;
    cout << "Hello " << p1 << " and " << p2 << "!!\n";
    grid();

    while (game_over())
    {
        input();
        grid();
        game_over();
    }

    winner();
    return 0;
}
