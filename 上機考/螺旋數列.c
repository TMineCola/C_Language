#include <stdio.h>
#include <math.h>

int main() {
    int n;
    char r, d;
    scanf("%d %c %c", &n, &r, &d);
    // 幫數字們找個家
    int matrix[n][n];
    // 紀錄目前是跑幾乘幾的圈圈, 順便先算出中央點
    int run_cycle = 1, x = n / 2, y = n / 2;

    for(int i = 1; i <= n * n; i++) {
        matrix[y][x] = i;
        // 當印出基數平方後要換圈
        if(i % 2 != 0 && i == pow(run_cycle, 2)) {
            // 換圈, 從哪邊開始就會從哪邊出去
            switch(d) {
                case 'u':
                    y -= 1;
                    break;
                case 'd':
                    y += 1;
                    break;
                case 'r':
                    x += 1;
                    break;
                case 'l':
                    x -= 1;
                    break;
            }
            // 圈數增加
            run_cycle += 2;
            continue;
        }
        // 計算每圈邊界
        int l_u = n / 2 - (run_cycle / 2), r_d = n / 2 + (run_cycle / 2);
        switch(r) {
            // 判斷順或逆時針旋轉
            case 'c':
                // 判斷位置並順時針旋轉
                if(x < r_d && y == l_u) {
                    x += 1;
                } else if(y < r_d && x == r_d) {
                    y += 1;
                } else if(x > l_u && y == r_d) {
                    x -= 1;
                } else if(y > l_u && x == l_u) {
                    y -= 1;
                }
                break;
            case 'a':
                // 判斷位置並逆時針旋轉
                if(x > l_u && y == l_u) {
                    x -= 1;
                } else if(y < r_d && x == l_u) {
                    y += 1;
                } else if(x < r_d && y == r_d) {
                    x += 1;
                } else if(y > l_u && x == r_d) {
                    y -= 1;
                }
                break;
        }
    }
    // 印出所有的數字
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}