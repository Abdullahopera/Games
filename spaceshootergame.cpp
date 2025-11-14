#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class SpaceShooter {
private:
    int width, height;
    int x, y;
    int score;
    bool gameover;

    struct Coordinate {
        int x, y;
    };

    vector<Coordinate> bullets;
    vector<Coordinate> enemies;

public:
    SpaceShooter(int width, int height)
        : width(width), height(height), x(width / 2), y(height - 2), score(0), gameover(false) {
        srand((unsigned)time(0));
    }

    void drawPlayer() {
        gotoxy(x, y);
        cout << "|^|";
    }

    void erasePlayer() {
        gotoxy(x, y);
        cout << "   ";
    }

    void moveLeft() {
        if (x > 1)
            x--;
    }

    void moveRight() {
        if (x < width - 3) // -3 because player is 3 chars wide
            x++;
    }

    void shoot() {
        bullets.push_back({ x + 1, y - 1 }); // Center bullet
         
         Beep(1000, 10);
    }

    void drawBullets() {
        for (int i = 0; i < bullets.size(); i++) {
            gotoxy(bullets[i].x, bullets[i].y);
            cout << "*";
        }
    }

    void moveBullets() {
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].y--;

            for (int j = 0; j < enemies.size(); j++) {
                if (bullets[i].x >= enemies[j].x && bullets[i].x <= enemies[j].x + 2 &&
                    bullets[i].y == enemies[j].y) {
                    bullets.erase(bullets.begin() + i);
                    enemies.erase(enemies.begin() + j);
                    Beep(1500, 100);
                    score += 10;
                    i--; // Important to avoid skipping next bullet
                    break;
                }
            }

            if (i >= 0 && i < bullets.size() && bullets[i].y <= 1) {
                bullets.erase(bullets.begin() + i);
                i--;
            }
        }
    }

    void drawEnemies() {
        for (auto &e : enemies) {
            gotoxy(e.x, e.y);
            cout << "-V-";
        }
    }

    void moveEnemies() {
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].y++;

            if (enemies[i].x >= x && enemies[i].x <= x + 2 && enemies[i].y == y) {
                gameover = true;
                return;
            }

            if (enemies[i].y >= height - 1) {
                enemies.erase(enemies.begin() + i);
                i--;
            }
        }
    }

    void generateEnemies() {
        if (rand() % 100 < 5) {
            int enemyX = rand() % (width - 4) + 1;
            enemies.push_back({ enemyX, 1 });
        }
    }

    bool isGameOver() const {
        return gameover;
    }

    int getScore() const {
        return score;
    }
};

int main() {
    SpaceShooter game(50, 25);

    while (!game.isGameOver()) {
        system("cls");
        game.drawPlayer();
        game.drawBullets();
        game.drawEnemies();

        game.moveBullets();
        game.moveEnemies();
        game.generateEnemies();

        if (GetAsyncKeyState(VK_LEFT)) game.moveLeft();
        if (GetAsyncKeyState(VK_RIGHT)) game.moveRight();
        if (GetAsyncKeyState(VK_SPACE)) game.shoot();

        gotoxy(0, 0);
        cout << "Score: " << game.getScore();

        Sleep(50);
    }

    gotoxy(20, 12);
    Beep(500, 500);
    cout << "GAME OVER!";
    gotoxy(20, 13);
    cout << "Final Score: " << game.getScore();
    cin.get();
    return 0;
}
