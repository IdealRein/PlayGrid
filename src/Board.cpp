// Board.cpp - 棋盘类实现
#include "Board.h"

Board::Board() {
    grid.resize(BOARD_SIZE, std::vector<char>(BOARD_SIZE, EMPTY));
}

void Board::display() const {
    std::cout << "   ";
    for (int i = 0; i < BOARD_SIZE; ++i)
        std::cout << i % 10 << ' ';
    std::cout << '\n';
    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << i % 10 << "  ";
        for (int j = 0; j < BOARD_SIZE; ++j)
            std::cout << grid[i][j] << ' ';
        std::cout << '\n';
    }
}

bool Board::place(int x, int y, char piece) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || grid[x][y] != EMPTY)
        return false;
    grid[x][y] = piece;
    return true;
}

bool Board::check_win(int x, int y, char piece) const {
    const int dirs[4][2] = {{1,0},{0,1},{1,1},{1,-1}};
    for (auto& d : dirs) {
        int count = 1;
        for (int dir = -1; dir <= 1; dir += 2) {
            int nx = x, ny = y;
            while (true) {
                nx += d[0] * dir;
                ny += d[1] * dir;
                if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || grid[nx][ny] != piece)
                    break;
                count++;
            }
        }
        if (count >= 5) return true;
    }
    return false;
}

bool Board::is_full() const {
    for (const auto& row : grid)
        for (char cell : row)
            if (cell == EMPTY) return false;
    return true;
}

char Board::get(int x, int y) const {
    return grid[x][y];
}
