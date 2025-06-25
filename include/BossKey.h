// BossKey.h - 老板键模块
#ifndef BOSSKEY_H
#define BOSSKEY_H

#include "Board.h"
#include <vector>
#include <string>

class BossKey {
private:
    bool active = false;

public:
    bool toggle(Board& board);                      // 切换老板键状态
    bool is_active() const { return active; }       // 是否处于老板键模式
    void display_fake_output();                     // 显示伪装输出
    bool get_input_with_bosskey(int& x, int& y, Board& board);  // 带老板键监听的输入
};

#endif // BOSSKEY_H
