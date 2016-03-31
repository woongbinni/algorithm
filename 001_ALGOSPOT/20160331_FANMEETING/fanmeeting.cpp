#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int test_case;

    scanf("%d", &test_case);

    for(int i=0; i<test_case; ++i){
        char members[200001];
        char fans[200001];
        scanf("%s", members);
        scanf("%s", fans);

        int len_members = strlen(members);
        for(int j=0; j<len_members; ++j){
            if(members[j] == 'M')
                members[j] -= 'L';
            else
                members[j] -= 'F';
        }

        int len_fans = strlen(fans);
        for(int j=0; j<len_fans; ++j){
            if(fans[j] == 'M')
                fans[j] -= 'L';
            else
                fans[j] -= 'F';
        }

        int len_until = len_fans - len_members + 1;
        int hug_cnt = 0;
        for(int j=0; j<len_until; ++j){
            int k;
            for(k=0; k<len_members; ++k){
                if(members[k] && fans[j+k])
                    break;
            }
            if(k == len_members)
                hug_cnt += 1;
        }

        printf("%d\n", hug_cnt);
    }

    return 0;
}