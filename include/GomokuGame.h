// GomokuGame.h - 五子棋主类定义
#ifndef GOMOKUGAME_H
#define GOMOKUGAME_H

#include "Game.h"
#include "Board.h"
#include "AI.h"
#include "BossKey.h"


class GomokuGame : public Game {
public:
    void start() override;

private:
    BossKey boss;
    void player_turn();
    void ai_turn();
    bool check_end(int x, int y, char piece);

    Board board;
    AI ai;
    char player_piece = 'X';
    char ai_piece = 'O';
    bool player_turn_flag = true;
};

#endif // GOMOKUGAME_H