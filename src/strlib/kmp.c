#include "strlib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void build_next(const char *pattern, int *next) {
    int m = (int)strlen(pattern);
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        next[i] = j;
    }
}

int kmp_search(const char *text, const char *pattern) {
    int n = (int)strlen(text);
    int m = (int)strlen(pattern);
    if (m == 0) return 0;

    int *next = (int *)malloc(sizeof(int) * m);
    build_next(pattern, next);

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == m) {
            free(next);
            return i - m + 1;
        }
    }

    free(next);
    return -1;
}

void test_kmp(void) {
    const char *text = "ababcabcacbab";
    const char *pattern = "abcac";

    int pos = kmp_search(text, pattern);
    if (pos != -1)
        printf("Pattern found at position %d\n", pos);
    else
        printf("Pattern not found\n");
}
