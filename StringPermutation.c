#include <stdio.h>
#include <string.h>

void print(char data[], int n) {
    // 印出字元陣列的前n個資料
    for(int i = 0; i < n; i++) {
        printf("%c", data[i]);
    }
    printf("\n");
}

void insert(char data[], int from, int to) {
    int dir = 1;
    if(from > to) {
        dir = -1;
    }

    int tmp = data[from];

    for(int i = from; i != to; i +=dir) {
        data[i] = data[i + dir];
    }
    data[to] = tmp;
}

void perm(char data[], int n, int from) {
    // n 為 要排的長度, from 為 排好的長度
    // 要選的數量及已經選好的數量相同即結束並印出
    if(n == from) {
        print(data, n);
        return;
    }
    //將被選的數字交換後丟入遞迴, 去產生下一個排列
    for(int i = from; i < n; i++) {
        insert(data, i, from);
        perm(data, n, from + 1);
        insert(data, from, i);
    }
}

void permutation(char data[], int n) {
    // 給予初始資料, n = 要排列的長度,
    perm(data, n, 0);
}

int main() {
    int num = 0;
    char *input;
    printf("String: ");
    scanf("%s", input);
    //計算字串長度
    for(int i = 0; input[i] != '\0'; i++) {
        num++;
    }
    //將字串以字元的方式進行排列
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num - 1; j++) {
            if(input[j] > input[j + 1]) {
                char temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
    permutation(input, num);
    return 0;
}