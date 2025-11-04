#include <stdio.h>
void test_strlib(void);
void test_linear_list(void);
void test_tree(void);
void test_stack(void);
void test_sort(void);

int main(void) {
    printf("=== PEECode Test Runner ===\n");
    test_linear_list();
    // test_tree();
    // test_stack();
    // test_sort();
    
    // test_strlib();
    return 0;
}
