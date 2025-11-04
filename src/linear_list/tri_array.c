#include <stdio.h>

// 下三角矩阵压缩存储示例
void tri_array(void) {
    int n = 4;
    int a[4][4] = {
        {1, 0, 0, 0},
        {2, 3, 0, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 10}
    };

    int b[10]; // 压缩后
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            b[k++] = a[i][j];

    printf("Triangular stored array: ");
    for (int i = 0; i < k; i++)
        printf("%d ", b[i]);
    printf("\n");
}
