#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char boggle[5][5];
int dir_x[8] = { -1, 0, 1, 1, 1, 0, -1, -1};
int dir_y[8] = { -1, -1, -1, 0, 1, 1, 1, 0};

bool boggle_find_text(char* search_text, int search_idx, int cur_x, int cur_y)
{
    //printf("%s|%d|%d|%d\n", search_text, search_idx, cur_x, cur_y);
    if (cur_x < 0 || cur_x >= 5)
        return false;
    if (cur_y < 0 || cur_y >= 5)
        return false;
    if (search_text[search_idx] != boggle[cur_x][cur_y]) {
        return false;
    }
    if (strlen(&(search_text[search_idx])) == 1) {
        //printf("FOUND!!\n");
        return true;
    }
    for (int i = 0; i < 8; i++) {
        int next_x = cur_x + dir_x[i];
        int next_y = cur_y + dir_y[i];

        if (boggle_find_text(search_text, search_idx + 1, next_x, next_y) == true) {
            //printf("FWD FOUND!!\n");
            return true;
        }
    }
    return false;
}

int main(void)
{
    int test_case = 0;
    char sample_str[11];
    int idx_i;

    scanf("%d", &test_case);

    for (idx_i = 0; idx_i < test_case; ++idx_i)
    {
        scanf("%s", &(boggle[0][0]));
        scanf("%s", &(boggle[1][0]));
        scanf("%s", &(boggle[2][0]));
        scanf("%s", &(boggle[3][0]));
        scanf("%s", &(boggle[4][0]));

        int sample_case;
        bool result;
        scanf("%d", &sample_case);

        for (int i = 0; i < sample_case; i++) {
            scanf("%s", sample_str);
            printf("%s ", sample_str);

            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    result = boggle_find_text(sample_str, 0, j, k);
                    if (result == true) {
                        break;
                    }
                }
                if(result == true) {
                    break;
                }
            }

            if (result == true) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }

        }
    }
    return 0;
}