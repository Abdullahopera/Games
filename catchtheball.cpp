#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include<windows.h>


using namespace std;

const int board_size = 15;
const char empty = ' ';
const char ball = 'o';
const char player = '_';
void clear_screen() {
    COORD cursor = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

int main(){
    srand(time(0));
char board [board_size][board_size];
int player_row = board_size - 1;
int player_column = board_size / 2;
int ball_row = 0;
int ball_column = rand() % board_size;

for (int row = 0; row < board_size; ++row)
{
    for ( int column = 0; column < board_size ; ++column)
    {
        board[row][column] = empty;
    }
    
}
 board[player_row][player_column] = player;
 board[ball_row][ball_column] = ball;
    
bool gamerunning = true;
int score = 0;
 
while (gamerunning)
{
    clear_screen ();
    
 for (int row = 0; row < board_size; ++row) {
            for (int col = 0; col < board_size; ++col) {
                cout << board[row][col] << " ";
            }
            cout << endl;
        }

    


cout<<endl;
cout<<"press a for character to move left press d to move character right";


board[player_row][player_column]= empty;
 if (_kbhit()) {
            char move = _getch();
            if (move == 'a' && player_column > 0)
                --player_column;
            else if (move == 'd' && player_column < board_size - 1)
                ++player_column;
        }


board[player_row][player_column] = player;
board[ball_row][ball_column] = empty;
if (ball_row<player_row)
{
    ++ball_row;
}else{
    int direction = rand() % 2;
    if (direction == 0 && ball_column>0)
    {
        --ball_column;
    }
    else if (direction == 1 && ball_column<board_size-1)
    {
++ball_column;
    }
    ++ball_row;
}

if (ball_row == player_row && ball_column == player_column)
{
    ++score;
    ball_row = 0;
    ball_column = rand()%board_size;
}
board[ball_row][ball_column]= ball;
if (ball_row == board_size - 1)
{
    gamerunning = false;
}
Sleep(100);
}
cout<<"game over"<<score<< endl;

return 0;

}
