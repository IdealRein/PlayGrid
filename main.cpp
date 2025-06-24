// main.cpp - 选择棋类并启动游戏
#include <iostream>
#include <memory>
#include "include/Game.h"
#include "include/GomokuGame.h"

int main() {
    std::cout << "===== PlayGrid =====\n";
    std::cout << "Select the Game: \n";
    std::cout << "1. Gomoku\n";
    std::cout << "Insert the Number: ";

    int choice;
    std::cin >> choice;

    std::unique_ptr<Game> game;

    switch (choice) {
        case 1:
            game = std::make_unique<GomokuGame>();
            break;
        default:
            std::cout << "Invalid Selection\n";
            return 0;
    }

    game->start();
    return 0;
}
