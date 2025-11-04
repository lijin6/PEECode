#ifndef STRLIB_H
#define STRLIB_H

void build_next(const char *pattern, int *next);
int kmp_search(const char *text, const char *pattern);
void test_kmp(void);

#endif
