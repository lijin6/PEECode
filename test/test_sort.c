#include <stdio.h>
#include "sort.h"

void test_sort(void) {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insert_sort(arr, n);

    printf("insert_sort result: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
