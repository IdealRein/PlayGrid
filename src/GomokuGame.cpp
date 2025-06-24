// GomokuGame.cpp - 五子棋游戏逻辑
#include "GomokuGame.h"
#include <iostream>
#include "BossKey.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include <limits>


void GomokuGame::start() {
    std::cout << "Start!\n";
    while (true) {
        // BossKey 检测
        if (boss.toggle(board)) continue;
        if (boss.is_active()) {
#ifdef _WIN32
            Sleep(100);  // 降低 CPU 占用
#endif
            continue;
        }

        board.display();

        if (board.is_full()) {
            std::cout << "Draw\n";
            break;
        }

        if (player_turn_flag) {
            player_turn();
        } else {
            ai_turn();
        }

        player_turn_flag = !player_turn_flag;
    }
}

void GomokuGame::player_turn() {
    int x, y;
    std::cout << "(" << player_piece << ") Your turn, Please select the next position x y: ";
    if (!(std::cin >> x >> y)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
        return;
    }

    if (!board.place(x, y, player_piece)) {
        std::cout << "Invalid\n";
        return;
    } else if (check_end(x, y, player_piece)) {
        board.display();
        std::cout << "Win\n";
        exit(0);
    }
}

void GomokuGame::ai_turn() {
    std::cout << "AI is thinking\n";
    Move m = ai.choose_move(board, ai_piece, player_piece);
    board.place(m.x, m.y, ai_piece);
    std::cout << "AI Position: (" << m.x << ", " << m.y << ")\n";
    if (check_end(m.x, m.y, ai_piece)) {
        board.display();
        std::cout << "Lose\n";
        exit(0);
    }
}

bool GomokuGame::check_end(int x, int y, char piece) {
    return board.check_win(x, y, piece);
}
