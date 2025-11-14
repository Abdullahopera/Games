#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[3];
int enemyX[3];
int enemyFlag[3];

char car[4][4] = {' ', '_', '_', ' ',
                  '0', '|', '|', '0',
                  ' ', '|', '|', ' ',
                  '0', '|', '|', '0'};

int carPos = WIN_WIDTH / 2;
int score = 0;

void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
void drawBorder()
{
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            gotoxy(0 + j, i);
            cout << "|";
            gotoxy(WIN_WIDTH - j, i);
            cout << "|";
        }
    }
}

void updateScore()
{
    gotoxy(WIN_WIDTH + 7, 5);
    cout << "Score: " << score << endl;
}

void genEnemy(int ind)
{
    enemyX[ind] = 17 + rand() % (33);
}

void drawCar()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + carPos, i + 22);
            cout << car[i][j];
        }
    }
}

void drawEnemy(int ind, int card)
{

    if (card == 0)
    {
        if (enemyFlag[ind] == true)
        {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "0**0";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << " ** ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "0**0";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " 00 ";
        }
    }
    else if (card == 1)
    {
        if (enemyFlag[ind] == true)
        {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "0**0";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << " ** ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "0**0";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " -- ";
        }
    }
    else if (card == 2)
    {
        if (enemyFlag[ind] == true)
        {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "****";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << " ** ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "****";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " ** ";
        }
    }
    else if (card == 3)
    {
        if (enemyFlag[ind] == true)
        {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "0..0";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << " .. ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "0..0";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " -- ";
        }
    }
}
int collision()
{
    if (enemyY[0] + 4 >= 23)
    {
        if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9)
        {
            return 1;
        }
    }
    return 0;
}

void gameover()
{
    system("cls");
    cout << endl;
    cout << "\t\t--------------------------" << endl;
    cout << "\t\t-------- Game Over -------" << endl;

    cout << "\t\t--------------------------" << endl
         << endl;
    cout << "\t\tPress any key to go back to menu.";
    getch();
}

void eraseCar()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + carPos, i + 22);
            cout << " ";
        }
    }
}

void eraseEnemy(int ind)
{
    if (enemyFlag[ind] == true)
    {
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 1);
        cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 2);
        cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 3);
        cout << "    ";
    }
}

void resetEnemy(int ind)
{
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void play(int card)
{
    carPos = -1 + WIN_WIDTH / 2;
    score = 0;

    string lastname;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    gotoxy(WIN_WIDTH + 7, 2);
    ifstream in("pfproject.txt");
    getline(in, lastname);
    cout << "username = ";
    cout << lastname;
    gotoxy(WIN_WIDTH + 6, 4);
    cout << "----------";
    gotoxy(WIN_WIDTH + 6, 6);
    cout << "----------";
    gotoxy(WIN_WIDTH + 7, 12);
    cout << "Control ";
    gotoxy(WIN_WIDTH + 7, 13);
    cout << "-------- ";
    gotoxy(WIN_WIDTH + 2, 14);
    cout << " A Key - Left";
    gotoxy(WIN_WIDTH + 2, 15);
    cout << " D Key - Right";

    gotoxy(18, 5);
    cout << "Press any key to start";
    getch();
    gotoxy(18, 5);
    cout << "                      ";

    while (true)
    {
        if (kbhit())
        {
            char ch = getch();
            if (ch == 'a' || ch == 'A')
            {
                if (carPos > 18)
                    carPos -= 4;
            }
            if (ch == 'd' || ch == 'D')
            {
                if (carPos < 50)
                    carPos += 4;
            }
            if (ch == 27)
            {
                break;
            }
        }

        drawCar();
        drawEnemy(0, card);
        drawEnemy(1, card);

        if (collision() == 1)
        {
            gameover();
            return;
        }

        Sleep(50);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if (enemyY[0] == 10)
            if (enemyFlag[1] == 0)
                enemyFlag[1] = 1;

        if (enemyFlag[0] == 1)
            enemyY[0] += 1;

        if (enemyFlag[1] == 1)
            enemyY[1] += 1;

        if (enemyY[0] > SCREEN_HEIGHT - 4)
        {
            resetEnemy(0);
            score++;
            updateScore();
        }
        if (enemyY[1] > SCREEN_HEIGHT - 4)
        {
            resetEnemy(1);
            score++;
            updateScore();
        }
    }
}

void setcursor(bool visible, DWORD size)
{

    if (size == 0)
        size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

int cardesign()
{
    int a;
    system("cls");
    gotoxy(10, 6);
    cout << "---------select a design---------";
    gotoxy(10, 8);
    cout << "-------0------" << endl;
    cout << "          0**0" << endl;
    cout << "           ** " << endl;
    cout << "          0**0" << endl;
    cout << "           00 " << endl;
    gotoxy(10, 13);
    cout << "-------1------" << endl;
    cout << "          0**0" << endl;
    cout << "           ** " << endl;
    cout << "          0**0" << endl;
    cout << "           --" << endl;
    gotoxy(10, 19);
    cout << "-------2------" << endl;
    cout << "          ****" << endl;
    cout << "           ** " << endl;
    cout << "          ****" << endl;
    cout << "           **" << endl;
    gotoxy(10, 25);
    cout << "-------3------" << endl;
    cout << "          0..0" << endl;
    cout << "           .. " << endl;
    cout << "          0;;0" << endl;
    cout << "           --" << endl;
    cin >> a;
    return a;
}

void nameenter(string name)
{
    system("cls");

    gotoxy(10, 10);
    cout << "-------enter your name----------";

    ofstream hout("pfproject.txt");
    gotoxy(10, 13);
    getline(cin, name);
    hout << name;
}

void lastnamef(string lastname)
{
    ifstream in("pfproject.txt");
    getline(in, lastname);
    gotoxy(10, 6);
    cout << "---------Last username------------";
    gotoxy(10, 8);
    cout << lastname;
}

int main()
{
    string name, lastname;
    int card = 0;
    int *cardptr = &card;
    setcursor(0, 0);
    srand((unsigned)time(NULL));

    do
    {
        system("cls");
        gotoxy(10, 5);
        cout << " -------------------------- ";
        gotoxy(10, 6);
        cout << " |        Car Game        | ";
        gotoxy(10, 7);
        cout << " --------------------------";

        gotoxy(10, 9);
        cout << "1. Start Game";
        gotoxy(10, 10);
        cout << "2. Instructions";
        gotoxy(10, 11);
        cout << "3. Quit";
        gotoxy(10, 12);
        cout << "4. Change car design";

        gotoxy(10, 13);
        cout << "Select option: ";
        char op = getche();

        if (op == '1')
        {
            nameenter(name);
            system("cls");
            play(card);
        }
        else if (op == '2')
            cout << "'a' for left \n'd' for right ";
        else if (op == '3')
            exit(0);
        else if (op = '4')
            *cardptr = cardesign();

    } while (true);

    return 0;
}
