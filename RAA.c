#include <stdio.h>

//反轉數值的魔法(函式) input為輸入的數字
int reverse(int input) {
    int answer = 0; //儲存答案
    // 前情提要： 105 % 10 = 5 (105 / 10 = 10 ... 5) 取餘數的意思, 而 "int" 只會取整數部分 5/2 = 2.5 取 2
    // 當數字還沒被除完( ex: 9/10 = 0.9, int 取整數部分為 0 )，就將原本答案乘以10後在加上取input的尾數
    // example: 輸入123
    // input = 123, answer = 0
    // 第一次迴圈 0 * 0, 然後 0 = 0 + 123 % 10, 所以現在 answer = 3, 再將 input / 10, 現在 input = 12
    // 第二次迴圈 3 * 10, 然後 30 = 30 + 2, 所以現在 answer = 32, 再將 input / 10, 現在 input = 1
    // 第三次迴圈 32 * 10, 然後 320 = 320 + 1, 所以現在answer = 321, 再將 input / 10, 現在 input = 0
    // 最後 input = 0 故不進入迴圈, 回傳最終答案 answer = 321
    while(input != 0) {
        answer = answer * 10;
        answer = answer + input % 10;
        input = input / 10;
    }
    return answer;
}

int main() {
    int rev, count = 0;
    scanf("%d", &rev);
    while(rev != reverse(rev) || count == 0) {
        rev += reverse(rev);
        count ++;
    }
    printf("%d %d\n", count, rev);
    return 0;
}