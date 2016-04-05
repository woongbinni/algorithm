#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int result_cnt;
int shape[4][3][2] = {
    {{0, 0}, {1, 0}, {1, -1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 0}}
};

bool findempty(int board[21][21], int height, int width)
{
    bool retVal = false;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            retVal |= board[i][j];
        }
    }
    return retVal;
}

void nextpos(int board[21][21], int height, int width, int cur_x, int cur_y, int* next_x, int *next_y) {
    for (int i = cur_x; i < height; ++i) {
        for (int j = cur_y; i < width; ++j) {
            if (board[i][j] == 1) {
                *next_x = i;
                *next_y = j;
                return;
            }
        }
    }
}

void printboard(int board[21][21], int height, int width){
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

void boardcover(int board[21][21], int height, int width, int cur_x, int cur_y) {
    // printboard(board, height, width);

    int next_x, next_y;
    if (findempty(board, height, width) == false) {
        // printf("full!!\n");
        result_cnt += 1;
        return;
    }
    if (board[cur_x][cur_y] == false) {
        nextpos(board, height, width, cur_x, cur_y, &next_x, &next_y);
        // printf("next pos : %d %d\n", next_x, next_y);
        boardcover(board, height, width, next_x, next_y);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int board_copy[21][21];
        memcpy(board_copy, board, sizeof(board_copy));
        if (board_copy[cur_x + shape[i][0][0]][cur_y + shape[i][0][1]] && board_copy[cur_x + shape[i][1][0]][cur_y + shape[i][1][1]] && board_copy[cur_x + shape[i][2][0]][cur_y + shape[i][2][1]]) {
            board_copy[cur_x + shape[i][0][0]][cur_y + shape[i][0][1]] = board_copy[cur_x + shape[i][1][0]][cur_y + shape[i][1][1]] = board_copy[cur_x + shape[i][2][0]][cur_y + shape[i][2][1]] = 0;
            nextpos(board_copy, height, width, cur_x, cur_y, &next_x, &next_y);
            boardcover(board_copy, height, width, next_x, next_y);
        }
    }
}

int main(void) {

    int test_case;
    char temp_str[21];

    scanf("%d", &test_case);

    for (int idx = 0; idx < test_case; idx++) {
        int height, width;
        int empty_cnt = 0;
        int board[21][21];
        memset(board, 0, sizeof(board));
        scanf("%d%d", &height, &width);
        // printf("%d %d", height, width);
        for (int i = 0; i < height; ++i) {
            scanf("%s", temp_str);
            // printf("%s", temp_str);
            for (int j = 0; j < width; ++j) {
                if (temp_str[j] == '.') {
                    board[i][j] = 1;
                    empty_cnt += 1;
                }
            }
        }
        // printf("empty : %d\n", empty_cnt);

        if ((empty_cnt % 3) != 0) {
            printf("0\n");
        }
        else {
            result_cnt = 0;
            boardcover(board, height, width, 0, 0);
            printf("%d\n", result_cnt);
        }
    }

    return 0;
}