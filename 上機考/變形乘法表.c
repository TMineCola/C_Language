#include <stdio.h>

void row(int start, int end) {
    //印出從 start 到 end的乘法組
    for(int i = 1; i <= 9; i++) {
        for(int j = start; j <= end; j++) {
            printf("%d * %d = %d\t", j, i, j * i);
        }
        printf("\n");
    }
}

int main() {
    //n為一列的組數, m為總數量
    int n, m, i;
    scanf("%d %d", &n, &m);
    //要印幾列
    for(i = 0; i < m / n; i++) {
        //每列印出的區間
        row(2 + i * n, n * (i + 1) + 1);
        printf("\n");
    }
    //若未達滿一列, 補印
    if(i * n < m || m / n == 0) {
        row(2 + i * n, m + 1);
    }
}