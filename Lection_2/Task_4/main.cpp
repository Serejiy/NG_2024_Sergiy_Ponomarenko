#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct position {
    int x;
    int y;
};

const int ROW_SIZE = 10;
const int COL_SIZE = 20;

void drawLine(int size) {
    for (int elemNumber = 0; elemNumber < size; elemNumber++)
        cout << "=";
    cout << endl;
}

void drawMap(char map[ROW_SIZE][COL_SIZE], position player, position enemy) {
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            if (row == player.y && col == player.x)
                cout << "@";
            else if (row == enemy.y && col == enemy.x)
                cout << "E";
            else
                cout << map[row][col];
        }
        cout << endl;
    }
}

void mapInit(char map[ROW_SIZE][COL_SIZE], char playerMap[ROW_SIZE][COL_SIZE]) {
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            if (row == 0 || col == 0 || row == ROW_SIZE - 1 || col == COL_SIZE - 1)
                map[row][col] = '*';
            else {
                int chance = rand() % 10;
                switch(chance) {
                case 1: map[row][col] = 's'; break;
                case 2: map[row][col] = 't'; break;
                default: map[row][col] = ' ';
                }
            }
            playerMap[row][col] = '*';
        }
    }
}

bool checkPosition(char map[ROW_SIZE][COL_SIZE], position pos) {
    char item = map[pos.y][pos.x];
    return item == ' ';
}

bool updatePlayerPosition(char map[ROW_SIZE][COL_SIZE], char direction, position *player) {
    position tempPosition;
    tempPosition = *player;
    switch (direction) {
    case 'w': tempPosition.y--; break;
    case 's': tempPosition.y++; break;
    case 'a': tempPosition.x--; break;
    case 'd': tempPosition.x++; break;
    }
    if (checkPosition(map, tempPosition)) {
        *player = tempPosition;
        return true;
    }
    return false;
}

bool updateEnemyPosition(position player, position *enemy) {
    position tempPosition;
    tempPosition = *enemy;
    if (player.x > enemy->x)
        tempPosition.x++;
    else if (player.x < enemy->x)
        tempPosition.x--;
    if (player.y > enemy->y)
        tempPosition.y++;
    else if (player.y < enemy->y)
        tempPosition.y--;

    *enemy = tempPosition;
    return true;
}

void updatePlayerMap(char map[ROW_SIZE][COL_SIZE], char playerMap[ROW_SIZE][COL_SIZE], position player) {
    for (int row = player.y - 1; row <= player.y + 1; row++) {
        for (int col = player.x - 1; col <= player.x + 1; col++) {
            playerMap[row][col] = map[row][col];
        }
    }
}

int main() {
    srand(time(NULL));

    char map[ROW_SIZE][COL_SIZE];
    char playerMap[ROW_SIZE][COL_SIZE];

    position player;
    player.x = COL_SIZE / 2;
    player.y = ROW_SIZE / 2;

    position enemy;
    enemy.x = rand() % COL_SIZE;
    enemy.y = rand() % ROW_SIZE;

    char direction = ' ';
    int playerHealth = 100; // Initial player health

    mapInit(map, playerMap);

    while (playerHealth > 0) {
        drawMap(playerMap, player, enemy);
        drawLine(COL_SIZE);

        cout << "Player Health: " << playerHealth << endl;
        cout << "Enter direction: ";
        cin >> direction;
        if (updatePlayerPosition(map, direction, &player))
            updatePlayerMap(map, playerMap, player);

        updateEnemyPosition(player, &enemy);

        // Check if enemy reached the player
        if (enemy.x == player.x && enemy.y == player.y) {
            // Decrease player health when enemy reaches the player
            playerHealth -= 10; // Example: Decrease health by 10
            // Display player and enemy together when they are in the same position
            drawMap(playerMap, player, enemy);
            drawLine(COL_SIZE);
            cout << "Player Health: " << playerHealth << endl;
            // You can add additional logic here if needed
        }

        system("clear");
    }

    cout << "Game Over - Player Health depleted!" << endl;

    return 0;
}
