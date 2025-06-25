// BossKey.cpp - 老板键实现
#include "BossKey.h"
#include <conio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <cstdlib>
#include <cctype>

// 假装编译输出的模板（可以自己扩展）
static const std::vector<std::string> fake_outputs = {
    "[Compiling] Building module core.cpp...",
    "[Compiling] Optimizing AI interface...",
    "[Compiling] Linking Engine subsystem...",
    "[Finished] All targets built successfully.",
};

// 输出老板键界面
void BossKey::display_fake_output() {
    system("cls");
    std::cout << "PlayGrid [Safe Mode - Productivity Log]\n\n";
    for (const auto& line : fake_outputs) {
        std::cout << line << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

bool BossKey::toggle(Board& board) {
    active = !active;
    if (active) {
        display_fake_output();
    } else {
        system("cls");
        board.display();
    }
    return active;
}

bool BossKey::get_input_with_bosskey(int& x, int& y, Board& board) {
    std::string buffer;
    std::cout.flush();
    while (true) {
        if (_kbhit()) {
            char c = _getch();
            if (c == 'b' || c == 'B') {
                toggle(board);
                continue;
            }
            if (c == '\r') {
                std::cout << "\n";
                break;
            }
            if (std::isdigit(c) || std::isspace(c)) {
                std::cout << c;
                buffer += c;
            } else if (c == '\b' && !buffer.empty()) {
                buffer.pop_back();
                std::cout << "\b \b";
            }
        }
        if (is_active()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    std::istringstream iss(buffer);
    return (iss >> x >> y) ? true : false;
}