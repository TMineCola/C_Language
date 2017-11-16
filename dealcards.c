#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int card[52];
    char num[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char color[4] = {'C', 'D', 'H', 'S'};
    srand(time(NULL));
    //填入牌的邊號
    for(int i = 0; i < 52; i++) {
        card[i] = i;
    }
    //隨機選兩張卡交換牌的邊號
    for(int i = 0; i < 1000; i++) {
        int x = rand() % 52;
        int y = rand() % 52;
        int temp = card[x];
        card[x] = card[y];
        card[y] = temp;
    }

    //發牌
    for(int i = 0; i < 4; i++) {
        printf("Player[%d]'s card: \n", i + 1);
        for(int j = 0; j < 13; j++) {
            //印出每張牌的花色及數字
            printf("%c%c ", color[card[i * 13 + j]/13], num[card[i * 13 + j] % 13]);
        }
        printf("\n");
    }
}