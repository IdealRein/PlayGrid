// AI.cpp - 启发式AI实现
#include "AI.h"
#include <limits>

Move AI::choose_move(const Board& board, char ai_piece, char player_piece) {
    int best_score = std::numeric_limits<int>::min();
    Move best_move = {-1, -1};

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board.get(i, j) == EMPTY) {
                int score = evaluate(board, i, j, ai_piece, player_piece);
                if (score > best_score) {
                    best_score = score;
                    best_move = {i, j};
                }
            }
        }
    }
    return best_move;
}

int AI::evaluate(const Board& board, int x, int y, char self, char opponent) const {
    // 攻守评分：更偏向进攻，适当考虑防守
    int score = 0;
    score += 2 * line_score(board, x, y, self);
    score += 1 * line_score(board, x, y, opponent);
    return score;
}

int AI::line_score(const Board& board, int x, int y, char piece) const {
    const int dirs[4][2] = {{1,0},{0,1},{1,1},{1,-1}};
    int total = 0;
    for (auto& d : dirs) {
        int count = 1;
        for (int dir = -1; dir <= 1; dir += 2) {
            int nx = x, ny = y;
            while (true) {
                nx += d[0] * dir;
                ny += d[1] * dir;
                if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || board.get(nx, ny) != piece)
                    break;
                count++;
            }
        }
        total += count * count; // 连得越多，分越高
    }
    return total;
}
