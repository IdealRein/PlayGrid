#include "BossKey.h"
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#endif
#include <iostream>

bool BossKey::toggle(Board& board) {
#ifdef _WIN32
    if (_kbhit()) {
        char c = _getch();
        if (c == 'b' || c == 'B') {
            active = !active;
            system("cls");
            if (active) {
                std::cout << "[INFO] Running batch job...\n";
                std::cout << "[OK] Output written to report.csv\n";
            } else {
                board.display();
            }
            return true;
        }
    }
#endif
    return false;
}

bool BossKey::is_active() const {
    return active;
}
