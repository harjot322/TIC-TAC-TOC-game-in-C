#include <stdio.h>
#include <stdbool.h>

void displayBoard(char board[3][3]) {
    printf("\nTic Tac Toe\n");

    for (int i = 0; i < 3; ++i) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

bool isGameOver(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void makeMove(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char currentPlayer = 'X';

    while (!isGameOver(board, 'X') && !isGameOver(board, 'O') && !isBoardFull(board)) {
        displayBoard(board);

        printf("Player %c, enter row (0-2) and column (0-2) separated by space: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isValidMove(board, row, col)) {
            makeMove(board, row, col, currentPlayer);
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    displayBoard(board);

    if (isGameOver(board, 'X')) {
        printf("Player X wins!\n");
    } else if (isGameOver(board, 'O')) {
        printf("Player O wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}