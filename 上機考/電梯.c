#include <stdio.h>

// 資料陣列, 總人數, 單趟上限
void routePlan(int input[], int num, int max) {
    int sum = 0, count = num;
    // 搭滿的情況
    for(int i = num - 1; i > 0; i-=max) {
        if(num < max) {
            break;
        }
        sum += (input[i] - 1) * 2;
    }
    // 非搭滿的情況
    if(count / max == 0 && count % max != 0 && max > num) {
        sum += (input[count - 1] - 1) * 2;
    }
    printf("%d", sum);
}

// 資料陣列, 總人數, 單趟上限
void insertionSort(int input[], int num, int max) {
    int temp;
    for(int i = 1; i < num; i++) {
        temp = input[i];
        for(int j = i - 1; j >= 0; j--) {
            if(j < 0) {
                break;
            }
            if(temp < input[j]) {
                input[j + 1] = input[j];
                input[j] = temp;
            }
        }
    }
    routePlan(input, num, max);
}

int main() {
    // n = 單趟上限, m = 總人數
    int n, m;
    scanf("%d %d", &n, &m);
    //Person to floor
    int pf[m];
    for(int i = 0; i < m; i++) {
        scanf("%d", &pf[i]);
    }
    insertionSort(pf, m, n);
}