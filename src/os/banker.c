#include "os.h"
#include <stdio.h>

#define P 5 // 进程数
#define R 3 // 资源种类

// 简单示例：安全性检查
void banker(void) {
    int available[R] = {3, 3, 2};          // 可用资源
    int max[P][R] = {                     // 各进程最大需求
        {7,5,3}, {3,2,2}, {9,0,2}, {2,2,2}, {4,3,3}
    };
    int allocation[P][R] = {               // 已分配资源
        {0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2}
    };
    int need[P][R];                        // 还需要资源
    for(int i=0;i<P;i++)
        for(int j=0;j<R;j++)
            need[i][j] = max[i][j] - allocation[i][j];

    int finish[P] = {0};
    int safeSeq[P];
    int count = 0;

    while(count < P) {
        int found = 0;
        for(int p = 0; p < P; p++) {
            if(!finish[p]) {
                int j;
                for(j=0;j<R;j++)
                    if(need[p][j] > available[j])
                        break;
                if(j==R) {
                    for(int k=0;k<R;k++)
                        available[k] += allocation[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if(!found) {
            printf("os is not safety !\n");
            return;
        }
    }

    printf("os is safety ! and the safe sequence is: \n ");
    for(int i=0;i<P;i++)
        printf("%d ", safeSeq[i]);
    printf("\n");
}
