// Board.h - 棋盘类定义
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

const int BOARD_SIZE = 15;
const char EMPTY = '.';

class Board {
public:
    Board();
    void display() const;
    bool place(int x, int y, char piece);
    bool check_win(int x, int y, char piece) const;
    bool is_full() const;
    char get(int x, int y) const;

private:
    std::vector<std::vector<char>> grid;
};

#endif // BOARD_H
