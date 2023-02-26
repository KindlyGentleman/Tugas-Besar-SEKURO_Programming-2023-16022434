#include <iostream>

#include <cstdlib>

#include <ctime>

#include <cmath>

using namespace std;

class Ship {
  public: Ship(int x, int y, int health, int damage, int range): x(x),
  y(y),
  health(health),
  damage(damage),
  range(range) {}

  int getX() const {
    return x;
  }
  int getY() const {
    return y;
  }
  int getHealth() const {
    return health;
  }
  int getDamage() const {
    return damage;
  }
  int getRange() const {
    return range;
  }

  void move(char direction) {
    switch (direction) {
    case 'u':
      y++;
      break;
    case 'd':
      y--;
      break;
    case 'r':
      x++;
      break;
    case 'l':
      x--;
      break;
    default:
      cout << "Invalid move" << endl;
    }
  }

  double distanceTo(const Ship & other) const {
    int dx = x - other.x;
    int dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
  }

  void attack(Ship & other) {
    double dist = distanceTo(other);
    if (dist > range) {
      cout << "Target is out of range" << endl;
      return;
    }
    other.health -= damage;
    cout << "Attack successful. Target's health is now " << other.health << endl;
  }

  private: int x;
  int y;
  int health;
  int damage;
  int range;
};

int main() {
  srand(time(NULL)); // untuk menghasilkan seed acak

  // Inisialisasi kapal pemain
  Ship player(0, 0, 100, 10, 5);

  // Inisialisasi armada musuh
  int numEnemies = 3;
  Ship * enemies = new Ship[numEnemies];
  for (int i = 0; i < numEnemies; i++) {
    int x = rand() % 10 + 1; // menghasilkan koordinat x acak antara 1 dan 10
    int y = rand() % 10 + 1; // menghasilkan koordinat y acak antara 1 dan 10
    enemies[i] = Ship(x, y, 50, 5, 3); // kapal musuh memiliki atribut yang lebih kecil dari kapal pemain
  }

  // Loop permainan
  while (player.getHealth() > 0) {
    // Tampilkan peta
    cout << "Pemain: (" << player.getX() << "," << player.getY() << "), health: " << player.getHealth() << endl;
    for (int i = 0; i < numEnemies; i++) {
      cout << "Musuh " << i + 1 << ": (" << enemies[i].getX() << "," << enemies[i].getY() << "), health: " << enemies[i].getHealth() << endl;
    }

    // Tampilkan opsi untuk pemain
    cout << "Pilih opsi (1 untuk menembak, 2 untuk bergerak, 3 untuk diam): ";
    int choice;
    cin >> choice;

    if (choice == 1) { // Tembak musuh
      int enemyIndex;
      cout << "Pilih musuh untuk ditembak (1-" << numEnemies << "): ";
      cin >> enemyIndex;

      if (enemyIndex < 1) {
        cout << "Invalid choice" << endl;
      } else {
        Ship & target = enemies[enemyIndex - 1];
        player.attack(target);
        if (target.getHealth() <= 0) {
          cout << "Musuh berhasil dikalahkan" << endl;
        }
      }
    } else if (choice == 2) { // Gerakkan kapal
      char direction;
      cout << "Pilih arah (u untuk ke atas, d untuk ke bawah, r untuk ke kanan, l untuk ke kiri): ";
      cin >> direction;
      int newX = player.getX();
      int newY = player.getY();
      switch (direction) {
      case 'u':
        newY++;
        break;
      case 'd':
        newY--;
        break;
      case 'r':
        newX++;
        break;
      case 'l':
        newX--;
        break;
      default:
        cout << "Invalid direction" << endl;
      }

      bool collision = false;
      for (int i = 0; i < numEnemies; i++) {
        if (enemies[i].getX() == newX && enemies[i].getY() == newY) {
          collision = true;
          break;
        }
      }

      if (newX < 0 || newX > 10 || newY < 0 || newY > 10) {
        cout << "Kapal keluar dari peta" << endl;
      } else if (collision) {
        cout << "Kapal menabrak musuh" << endl;
      } else {
        player.move(direction);
      }
    } else if (choice == 3) { // Diam di tempat
      // Do nothing
    } else {
      cout << "Invalid choice" << endl;
    }

    // Musuh bergerak acak
    for (int i = 0; i < numEnemies; i++) {
      int dx = rand() % 3 - 1; // menghasilkan angka acak antara -1, 0, dan 1
      int dy = rand() % 3 - 1; // menghasilkan angka acak antara -1, 0, dan 1
      int newX = enemies[i].getX() + dx;
      int newY = enemies[i].getY() + dy;
      if (newX >= 0 && newX <= 10 && newY >= 0 && newY <= 10) {
        enemies[i].move(dx, dy);
      }
    }
  }

  // Akhir permainan
  int numKills = 0;
  for (int i = 0; i < numEnemies; i++) {
    if (enemies[i].getHealth() <= 0) {
      numKills++;
    }
  }
  cout << "Permainan berakhir. Jumlah musuh yang berhasil dikalahkan: " << numKills << endl;

  delete[] enemies; // dealokasi memori yang dialokasikan secara dinamis
  return 0;
}