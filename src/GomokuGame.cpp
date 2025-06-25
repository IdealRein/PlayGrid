// GomokuGame.cpp - 五子棋游戏逻辑
#include "GomokuGame.h"
#include <iostream>
#include "BossKey.h"

void GomokuGame::start() {
    std::cout << "Start!\n";
    while (true) {
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

    // 👇 用老板键模块处理输入（支持随时按 b）
    if (!boss.get_input_with_bosskey(x, y, board)) {
        std::cout << "Invalid input\n";
        player_turn(); // 递归重试
        return;
    }

    if (!board.place(x, y, player_piece)) {
        std::cout << "Invalid move\n";
        player_turn();
        return;
    }

    if (check_end(x, y, player_piece)) {
        board.display();
        std::cout << "You win!\n";
        exit(0);
    }
}

void GomokuGame::ai_turn() {
    std::cout << "AI is thinking...\n";
    Move m = ai.choose_move(board, ai_piece, player_piece);
    board.place(m.x, m.y, ai_piece);
    std::cout << "AI Position: (" << m.x << ", " << m.y << ")\n";

    if (check_end(m.x, m.y, ai_piece)) {
        board.display();
        std::cout << "You lose!\n";
        exit(0);
    }
}

bool GomokuGame::check_end(int x, int y, char piece) {
    return board.check_win(x, y, piece);
}
