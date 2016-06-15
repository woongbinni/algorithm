#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _result {
    char filename[101];
} result;

result results[51];
int result_cnt;
int cache[101][101];

int cmp(const void *a, const void *b) {
    return strcmp(((result*)a)->filename, ((result*)b)->filename);
}

int match(char* word, char* filename) {
    // printf("%s | %s\n", word, filename);
    int idx = 0;
    int wildcard_idx;
    int len_word = strlen(word);
    int len_filename = strlen(filename);

    if (cache[len_word][len_filename] != -1) {
        return cache[len_word][len_filename];
    }

    while (idx < len_word && idx < len_filename) {
        if (word[idx] == '?' || word[idx] == filename[idx]) {
            idx += 1;
            continue;
        }
        break;
    }

    if (idx == len_word) {
        if (idx == len_filename) {
            cache[len_word][len_filename] = 1;
        }
        else {
            cache[len_word][len_filename] = 0;
        }
        return cache[len_word][len_filename];
    }

    if (word[idx] == '*') {
        for (wildcard_idx = 0; wildcard_idx + idx <= len_filename; ++wildcard_idx) {
            if (match(&(word[idx + 1]), &(filename[idx + wildcard_idx])) == 1) {
                cache[len_word][len_filename] = 1;
                return cache[len_word][len_filename];
            }
        }
    }

    cache[len_word][len_filename] = 0;
    return 0;
}

int main(void) {
    int Case;
    char W[101];
    int  N;
    char filename[101];

    scanf("%d", &Case);

    for (int i = 0; i < Case; ++i) {
        memset(W, 0x00, sizeof(W));
        scanf("%s", W);
        scanf("%d", &N);

        memset(results, 0x00, sizeof(results));
        result_cnt = 0;

        for (int j = 0; j < N; ++j) {
            memset(filename, 0x00, sizeof(filename));
            memset(cache, -1, sizeof(cache));

            scanf("%s", filename);

            if (match(W, filename) == 1) {
                sprintf(results[result_cnt].filename, "%s", filename);
                result_cnt += 1;
            }
        }

        qsort(results, result_cnt, sizeof(result), cmp);

        for (int j = 0; j < result_cnt; ++j) {
            printf("%s\n", results[j].filename);
        }
    }

    return 0;
}