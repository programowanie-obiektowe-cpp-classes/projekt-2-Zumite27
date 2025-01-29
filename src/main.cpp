#include <iostream>
#include <vector>
#include "BoardRenderer.hpp"

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void play() {
        int moves = 0;
        while (true) {
            BoardRenderer::drawBoard(board);
            if (moves >= 9 || checkWin()) {
                displayOutcome();
                break;
            }
            if (currentPlayer == 'X') {
                playerMove();
            } else {
                computerMove();
            }
            moves++;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    void playerMove() {
        int row, col;
        while (true) {
            std::cout << "Podaj wiersz i kolumne (0-2): ";
            std::cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = 'X';
                break;
            }
            std::cout << "Nieprawidlowy ruch, sprobuj ponownie.\n";
        }
    }

    void computerMove() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    return;
                }
            }
        }
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    void displayOutcome() {
        BoardRenderer::drawBoard(board);
        if (checkWin()) {
            if (currentPlayer == 'X') {
                BoardRenderer::showMessage("Gratulacje! Wygrales!");
            } else {
                BoardRenderer::showMessage("Przegrales! Sprobuj ponownie.");
            }
        } else {
            BoardRenderer::showMessage("Remis!");
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
