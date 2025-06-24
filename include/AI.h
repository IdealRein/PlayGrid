// AI.h - 五子棋AI逻辑
#ifndef AI_H
#define AI_H

#include "Board.h"

struct Move {
    int x, y;
};

class AI {
public:
    Move choose_move(const Board& board, char ai_piece, char player_piece);

private:
    int evaluate(const Board& board, int x, int y, char self, char opponent) const;
    int line_score(const Board& board, int x, int y, char piece) const;
};

#endif // AI_H