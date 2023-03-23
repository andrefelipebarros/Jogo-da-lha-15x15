#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
const int ROWS = 15;
const int COLS = 15;
int grid[ROWS][COLS] = {0};

// posiciona o personagem 'X' na matriz na posição (7, 7)
int x = 7;
int y = 7;
grid[x][y] = 1;

// Sistemas para o personagem.
int health = 50;

// Player Status
cout << "VIDA: " << health << endl;

// exibe a grid no plano cartesiano
for (int i = 0; i < ROWS; i++) {
	
	cout << " ";
    for (int j = 0; j < COLS; j++) {
        if (grid[i][j] == 0) {
            cout << " +";
        } else if (grid[i][j] == 1) { // 1 == Player
            cout << " X";
        } else if (grid[i][j] == 2) { // 2 == Sla oq
            cout << " =";
        }
    }
    cout << endl;
}

// movimenta o personagem na grid com base na direção escolhida pelo usuário usando switch
char direction;
do {
    cout << "Digite a direcao do movimento (w, a, s, d) ou 'q' para sair do jogo: ";
    cin >> direction;
    switch (direction) {
        case 'w':
            if (x > 0) {
                grid[x][y] = 0;
                x--;
                health--;
                grid[x][y] = 2;
            }
            break;
        case 's':
            if (x < ROWS - 1) {
                grid[x][y] = 0;
                x++;
                health--;
                grid[x][y] = 2;
            }
            break;
        case 'd':
            if (y < COLS - 1) {
                grid[x][y] = 0;
                y++;
                health--;
                grid[x][y] = 2;
            }
            break;
        case 'a':
            if (y > 0) {
                grid[x][y] = 0;
                y--;
                health--;
                grid[x][y] = 2;
            }
            break;
    }
    
    system("clear");
    
    // Player Status
    cout << "VIDA: " << health << endl;
    
    // exibe a grid atualizada após o movimento do personagem
    for (int i = 0; i < ROWS; i++) {
    	cout << " ";
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                cout << " +";
            } else if (grid[i][j] == 1) {
                cout << " =";
            } else if (grid[i][j] == 2) {
                cout << " X";
            }
        }
        cout << endl;
    }

} while (direction != 'q');

return 0;

}

