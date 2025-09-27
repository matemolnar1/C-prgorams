#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

typedef struct {
    char name[50];
    int score;
} Player;

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '-';
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n  ");
    for (int j = 0; j < SIZE; j++)
        printf("%d ", j);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    Player player;
    int treasureRow, treasureCol;
    int guessRow, guessCol;
    int tries = 5;

    printf("Jatekos neve: ");
    scanf_s("%49[^\n]", player.name, (unsigned)50);
    player.score = 0;

    srand((unsigned)time(NULL));
    treasureRow = rand() % SIZE;
    treasureCol = rand() % SIZE;

    initBoard(board);

    printf("\n--- Treasure Hunt ---\n");
    printf("Talald meg a kincset egy %dx%d-es racsban!\n", SIZE, SIZE);

    while (tries > 0) {
        printBoard(board);
        printf("\nMelyik sorban van a kincs? (0-%d): ", SIZE - 1);
        scanf_s("%d", &guessRow);
        printf("Melyik oszlopban van a kincs? (0-%d): ", SIZE - 1);
        scanf_s("%d", &guessCol);

        if (guessRow == treasureRow && guessCol == treasureCol) {
            printf("Gratulalok, talaltad a kincset!\n");
            board[guessRow][guessCol] = 'X';
            player.score++;
            break;
        }
        else {
            printf("Sajat tipp: nem a kincs. Probald ujra!\n");
            board[guessRow][guessCol] = 'O';
            tries--;
        }
    }

    if (tries == 0)
        printf("Sajnos kifogytal a tippekbol. A kincs helye: (%d,%d)\n", treasureRow, treasureCol);

    printf("\nJatekos: %s, Pontszam: %d\n", player.name, player.score);

    return 0;
}
