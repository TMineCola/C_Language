#include <stdio.h>
// 萬 1~9
// 筒 1~9
// 條 1~9
// 字牌 東南西北中發白
// 兩個一樣的稱為 "將"
// 三個一樣 "刻"
// 萬筒條連續三張的 稱為 "順"
// 廣東排13張, 台灣牌16張
// 11123445678999
// 以上用array表達後長甚麼樣子?
// 用14個元素的陣列
// {0,0,0,1,2,3,3,4,5,6,7,8,8,8}?
// 有沒有其它的表示法?
// how about 不管有幾張牌, 都用 34個整數來表達
// {3,1,1,2,1,1,1,1,3,0,0,0,0,0,0.....}
// 胡牌: 一個 "將" 其它 為 "順" or "刻"
// 問題: 給你n張牌, 請問有 "胡" 嗎?
// Q1: data type : int
// 值呢?
// 1~9萬: 0 ~8
// 1~9筒: 9 ~ 17
// 1~9條: 18 ~ 26
// 東南西北中發白: 27~ 33
// @return 1 if can hu, 0 otherwise
// card: 每種牌的個數
// remain: 剩下幾張牌
// jun: 是否拿過將, 1有過, 0沒有
int canHu(int card[], int remain, int jun) {
    // 何時知道能胡?
    if (remain == 0 && jun == 1) {
        return 1;
    }
    // 如何化簡 (湊牌) ?
    for (int i = 0; i < 34; i++) {
        // 將,兩個一樣
        if (jun == 0 && card[i] >= 2) {
            card[i] -= 2;
            int result = canHu(card, remain-2, 1);
            card[i] += 2;
            if (result == 1) {
                return 1;
            }
        }
        // 刻,三個一樣
        if (card[i] >= 3) {
            card[i] -= 3;
            int result = canHu(card, remain-3, jun);
            card[i] += 3;
            if (result == 1) {
                return 1;
            }
        }
        // 順,萬筒條連續三張
        // 萬筒條 and <7 and 連續都有
        if (i < 27 && i % 9 <7 && card[i] >= 1 && card[i + 1] >= 1 && card[i + 2] >= 1) {
            card[i] -= 1;
            card[i+1] -= 1;
            card[i+2] -= 1;
            int result = canHu(card, remain - 3, jun);
            card[i] += 1;
            card[i+1] += 1;
            card[i+2] += 1;
            if (result == 1) {
                return 1;
            }
        }
    }
    return 0;
}

void DataTypeChange(int card) {
    if(card < 9) {
        printf("A%d ", card % 9 + 1);
    } else if(card < 18) {
        printf("B%d ", card % 9 + 1);
    } else if(card < 27) {
        printf("C%d ", card % 9 + 1);
    } else {
        printf("D%d ", card % 9 + 1);
    }
}

void huWhich(int card[], int remain) {
    int temp = 0;
    for (int i = 0; i < 34; i++) {
        temp = 1;
        if (card[i] >=4) {
            continue;
        }
        card[i]++;
        if (canHu(card, remain+1, 0)) {
            DataTypeChange(i);
        }
        card[i]--;
    }
    printf("\n");
    if(temp == 0) {
        printf("尚未聽牌\n");
    }
}

int main() {
    int card[34] = {0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0};
    char c;
    int n;
    for(int i = 0; i < 13; i ++) {
        scanf("%c%d", &c, &n);
        switch(c){
            case 'A':
                card[n - 1]++;
                break;
            case 'B':
                card[n + 8]++;
                break;
            case 'C':
                card[n + 17]++;
                break;
            case 'D':
                card[n + 26]++;
                break;
        }
    }
    huWhich(card, 13);
}