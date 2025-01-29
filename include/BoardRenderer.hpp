#ifndef BOARD_RENDERER_HPP
#define BOARD_RENDERER_HPP
#include <iostream>
#include <vector>

class BoardRenderer {
public:
    static void drawBoard(const std::vector<std::vector<char>>& board) {
        std::cout << "\nAktualna plansza:\n";
        for (const auto& row : board) {
            for (const auto& cell : row) {
                std::cout << (cell == ' ' ? '.' : cell) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    static void showMessage(const std::string& message) {
        std::cout << message << "\n";
    }
};

#endif // BOARD_RENDERER_HPP
