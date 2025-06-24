// Game.h - 抽象棋类接口
#ifndef GAME_H
#define GAME_H

class Game {
public:
    virtual ~Game() = default;
    virtual void start() = 0;  // 游戏开始的主入口
};

#endif // GAME_H
