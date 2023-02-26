// Program ini adalah game sederhana yang menggunakan objek-objek berupa kapal player dan kapal musuh.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Kelas Ship merepresentasikan kapal dan memiliki beberapa method untuk memanipulasi kapal seperti attack, move, getHealth, dll.
class Ship {
public:
    Ship() {
        x = 0;
        y = 0;
        health = 100;
        max_range = 2;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int new_x) {
        x = new_x;
    }

    void setY(int new_y) {
        y = new_y;
    }

    int getHealth() {
        return health;
    }

    void setHealth(int new_health) {
        health = new_health;
    }

    int getMaxRange() {
        return max_range;
    }

    void attack(Ship& enemy) {
        int distance = calculateDistance(enemy);
        if (distance > max_range) {
            cout << "Error: Enemy ship is out of range." << endl;
        } else {
            enemy.setHealth(enemy.getHealth() - 10);
            cout << "Ship attacked enemy ship! Enemy health is now " << enemy.getHealth() << endl;
        }
    }

    void printLocation() {
        cout << "Ship is at (" << x << "," << y << ")" << endl;
    }

    void move(char direction) {
        int new_x = x;
        int new_y = y;

        if (direction == 'U') {
            new_x--;
        } else if (direction == 'D') {
            new_x++;
        } else if (direction == 'L') {
            new_y--;
        } else if (direction == 'R') {
            new_y++;
        }

        if (new_x < 0 || new_x > 4 || new_y < 0 || new_y > 4) {
            cout << "Error: Cannot move outside the map." << endl;
        } else {
            x = new_x;
            y = new_y;
            cout << "Ship moved to (" << x << "," << y << ")" << endl;
        }
    }

    int calculateDistance(Ship& enemy) {
        int x_diff = abs(x - enemy.getX());
        int y_diff = abs(y - enemy.getY());
        return max(x_diff, y_diff);
    }

    char getSymbol() {
        return symbol;
    }

protected:
    int x;
    int y;
    int health;
    int max_range;
    char symbol;
};

// Kelas PlayerShip dan EnemyShip adalah turunan dari Ship dan memiliki beberapa method tambahan, seperti konstruktor untuk mengatur symbol kapal.
class PlayerShip : public Ship {
public:
    PlayerShip() {
        symbol = 'T';
    }
};

class EnemyShip : public Ship {
public:
    EnemyShip() {
        symbol = 'M';
        x = rand() % 5;
        y = rand() % 5;
        health = 50;
        max_range = 1;
    }
};

// Pada main program, map diinisialisasi dan dimulai game loop.
// Pada setiap iterasi game loop, map diprint, input player diterima, dan aksi yang sesuai dilakukan.
int main() {
    srand(time(NULL));
    PlayerShip player;
    EnemyShip enemy;

    char map[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = '~';
        }
    }
    map[player.getX()][player.getY()] = player.getSymbol();
    map[enemy.getX()][enemy.getY()] = enemy.getSymbol();

    int enemy_count = 1;
    while (player.getHealth() > 0) {
    // Print map
    cout << "Map:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    char input;
    cout << "Enter command (A for attack, M for move, S for stay): ";
    cin >> input;

    // Jika player memilih untuk attack, akan dilakukan pengecekan range, jika dalam range, musuh akan diserang dan map diupdate.
    if (input == 'A') {
        player.attack(enemy);
        if (enemy.getHealth() <= 0) {
            map[enemy.getX()][enemy.getY()] = 'X';
            enemy_count++;
            enemy = EnemyShip();
            map[enemy.getX()][enemy.getY()] = enemy.getSymbol();
        }
    // Jika player memilih untuk move, player dipindahkan sesuai input, dan map diupdate.
    } else if (input == 'M') {
        char direction;
        cout << "Enter direction (U for up, D for down, L for left, R for right): ";
        cin >> direction;
        player.move(direction);
        // Update map
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == player.getX() && j == player.getY()) {
                    map[i][j] = player.getSymbol();
                } else if (i == enemy.getX() && j == enemy.getY()) {
                    map[i][j] = enemy.getSymbol();
                } else {
                    map[i][j] = '~';
                }
            }
        }
    // Jika player memilih untuk stay, tidak terjadi apa-apa.
    } else if (input == 'S') {
        // Do nothing
    // Jika player memasukkan input yang tidak valid, akan muncul pesan error.
    } else {
        cout << "Error: Invalid command." << endl;
    }
}
// Game akan berakhir ketika health player mencapai 0. Jumlah musuh yang berhasil dihancurkan akan ditampilkan.
cout << "Game over. You destroyed " << enemy_count << " enemy ships." << endl;

return 0;
}