// BossKey.h - 老板键功能封装
#ifndef BOSSKEY_H
#define BOSSKEY_H

#include "Board.h"

class BossKey {
public:
    bool toggle(Board& board);  // 检测按键并切换老板模式
    bool is_active() const;     // 当前是否在老板模式

private:
    bool active = false;
};

#endif // BOSSKEY_H
