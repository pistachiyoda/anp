#include "anp.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <sys/ioctl.h>
#include <unistd.h>
#include <algorithm>
using namespace std;

int getScreenWidth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_col;
}

int getScreenHeight() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row; 
}

void changeYPosition(int y) {
    for (int i = 0; i < y; i++) {
        cout << endl;
    }
}

int main() {
    const int windowWidth = getScreenWidth();
    const int windowHeight = getScreenHeight();
    const int height = 8;
    const char* anpImage[2][8] = {{ANP1_1, ANP2_1, ANP3_1, ANP4_1, ANP5_1, ANP6_1, ANP7_1, ANP8_1}, {ANP1_2, ANP2_2, ANP3_2, ANP4_2, ANP5_2, ANP6_2, ANP7_2, ANP8_2}};
    int moveCnt = 0;
    int prev = 0;

    for (int i = windowWidth - IMAGE_LENGTH; i > 0; i--) {
        system("clear");

        if (moveCnt == 0) {
            changeYPosition(windowHeight / 2 - moveCnt);
            moveCnt = 1;
            prev = 0;
        } else if (moveCnt == 1) {
            changeYPosition(windowHeight / 2 - moveCnt);
            moveCnt = prev == 0 ? 2 : 0;
            prev = 1;
        } else if (moveCnt == 2) {
            changeYPosition(windowHeight / 2 - moveCnt);
            moveCnt = prev == 1 ? 3 : 1;
            prev = 2;
        } else {
            changeYPosition(windowHeight / 2 - moveCnt);
            moveCnt = 2;
            prev = 3;
        }

        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < i; k++) {
                cout << " ";
            }
        string imageLine = i % 2 == 0 ? anpImage[1][j] : anpImage[0][j];
        cout << imageLine << endl;
        } 

        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}
