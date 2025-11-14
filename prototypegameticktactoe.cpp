#include <iostream>
#include <ctime>
using namespace std;
void board(char *spots)
{
    cout << "      |        |        " << endl;
    cout << "  " << spots[0] << "   |   " << spots[1] << "    |   " << spots[2] << "    " << endl;
    cout << "      |        |        " << endl;
    cout << "________________________" << endl;
    cout << "      |        |        " << endl;
    cout << "  " << spots[3] << "   |   " << spots[4] << "    |   " << spots[5] << "    " << endl;
    cout << "      |        |        " << endl;
    cout << "________________________" << endl;
    cout << "      |        |        " << endl;
    cout << "  " << spots[6] << "   |   " << spots[7] << "    |   " << spots[8] << "    " << endl;
    cout << "      |        |        " << endl;
}
void yourmove(char *spots, char player)
{

    int num;

    do
    {
        cout << "Pic a spot between 1-9" << endl;
        cin >> num;
        num--;
        if (spots[num] == ' ')
        {
            spots[num] = player;
            break;
        }

    } while (!num < 0 || !num > 9);
}
void compmove(char *spots, char computer)
{

    int num;
    srand(time(0));
    while (true)
    {
        num = rand() % 9;
        if (spots[num] == ' ')
        {
            spots[num] = computer;
            board(spots);
            break;
        }
    }
}
bool checkwin(char *spots,char player,char computer){


if (spots[0]!=' ' && spots[0]==spots[1] && spots[1]==spots[2])
{
    if (spots[0]=player)
    {
        cout<<"YOU WIN"<<endl;
    }else if(spots[0]=computer)
    {cout<<"YOU LOSE"<<endl;}
    
}else if (spots[3]!=' ' && spots[3]==spots[4] && spots[4]==spots[5])
{
    
    if (spots[3]=player)
    {
        cout<<"YOU WIN"<<endl;
    }else if(spots[3]=computer)
    {cout<<"YOU LOSE"<<endl;}
}else if (spots[6]!=' ' && spots[6]==spots[7] && spots[7]==spots[8])
{
   
    if (spots[6]=player)
    {
        cout<<"YOU WIN"<<endl;
    }else if(spots[6]=computer)
    {cout<<"YOU LOSE"<<endl;} 
}
else if (spots[0]!=' ' && spots[0]==spots[3] && spots[3]==spots[6])
{
    if (spots[0]=player)
    {
        cout<<"YOU WIN"<<endl;
    }else if(spots[0]=computer)
    {cout<<"YOU LOSE"<<endl;} 
}else if (spots[1]!=' ' && spots[1]==spots[4] && spots[4]==spots[7])
{
    if (spots[1]=player)
    {
        cout<<"YOU WIN"<<endl;
    }else if(spots[1]=computer)
    {cout<<"YOU LOSE"<<endl;} 
}else if (spots[2]!=' ' && spots[2]==spots[5] && spots[5]==spots[8])
{
    if (spots[2]=player)
    {
        cout<<"YOU WIN"<<endl;
    }else if(spots[2]=computer)
    {cout<<"YOU LOSE"<<endl;} 
}else if (spots[0]!=' ' && spots[0]==spots[4] && spots[4]==spots[8])
{
    if (spots[0]=player)
    {
        cout<<"YOU WIN"<<endl;
    }else if(spots[0]=computer)
    {cout<<"YOU LOSE"<<endl;} 
}
else if (spots[2]!=' ' && spots[2]==spots[4] && spots[4]==spots[6])
{
    if (spots[2]=player)
    {
        cout<<"YOu win "<<endl;
    }else if(spots[2]=computer)
    {cout<<"YOU LOSE"<<endl;} 
}else{return false;}
return true;
}
int main()
{
    char spots[9] = {
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
    };
    char player = 'X';
    char computer = 'O';
    bool runing = true;
    board(spots);

    while (runing)
    {

        yourmove(spots, player);
        if (checkwin(spots,player,computer))
        {
        runing = false;
           cout<<"00000  0   0  00000   00000  0   0  0000 "<<endl;
           cout<<"  0    0   0  0       0      00  0  0   0"<<endl;
           cout<<"  0    00000  0000    0000   0 0 0  0   0"<<endl;
           cout<<"  0    0   0  0       0      0  00  0   0"<<endl;
           cout<<"  0    0   0  0000    0000   0   0  0000"<<endl;
        }
        compmove(spots, computer);
        if (checkwin(spots,player,computer))
        {
            runing = false;
           cout<<"00000  0   0  00000   00000  0   0  0000 "<<endl;
           cout<<"  0    0   0  0       0      00  0  0   0"<<endl;
           cout<<"  0    00000  0000    0000   0 0 0  0   0"<<endl;
           cout<<"  0    0   0  0       0      0  00  0   0"<<endl;
           cout<<"  0    0   0  0000    0000   0   0  0000"<<endl;
        }
    }
    int o;
    cin>>o;

    return 0;
}
