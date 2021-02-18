#include <stdio.h>
#include <iostream>
using namespace std;
#include <algorithm>
#include <string.h>

int T, N;
typedef struct _phone {
    char number[11];
} phone;

phone phonebook[10001];

bool compare(phone phoneA, phone phoneB){
    if(strcmp(phoneA.number, phoneB.number) > 0){
        return false;
    } else {
        return true;
    }
}

bool isSubPhoneNum(phone phoneA, phone phoneB){
    bool retVal = true;
    for(int i=0; i<strlen(phoneA.number); ++i){
        if(phoneA.number[i] != phoneB.number[i]){
            retVal = false;
            break;
        }
    }
    return retVal;
}

int main() {
    scanf("%d", &T);

    for(int idx=0; idx<T; ++idx){
        scanf("%d", &N);
        for(int i=0; i<N; ++i){
            scanf("%s", phonebook[i].number);
        }
        sort(phonebook, phonebook+N, compare);
        bool scanAll = true;
        for(int i=1; i<N; ++i){
            if(isSubPhoneNum(phonebook[i-1], phonebook[i])){
                printf("NO\n");
                scanAll = false;
                break;
            }
        }
        if(scanAll){
            printf("YES\n");
        }
    }

    return 0;
}
