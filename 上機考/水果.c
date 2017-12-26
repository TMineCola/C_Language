#include <stdio.h>
#include <string.h>

#define fruit_type 3
int fruit[fruit_type] = {10, 20, 30};
char fruit_name[fruit_type][20] = { "香蕉", "草莓", "蘋果"};

void happy_fruit(int bucket, int money, int which, int now_select, int inbucket[]) {
    if(money < 0) {
        return;
    }
    if(now_select == bucket) {
        for(int i = 0; i < fruit_type; i++) {
            printf("%s:%d ", fruit_name[i], inbucket[i]);
        }
        printf("\n");
        return;
    }
    for(int i = which; i < fruit_type; i++) {
        if(fruit[i] <= money) {
            inbucket[i] += 1;
            money -= fruit[i];
            happy_fruit(bucket, money, i, now_select + 1, inbucket);
            inbucket[i] -= 1;
            money += fruit[i];
        }
    }
    return;
}

int main() {
    int money, bksp;
    scanf("%d %d", &money, &bksp);
    int mybucket[fruit_type];
    for(int i = 0; i < fruit_type; i++) {
        mybucket[i] = 0;
    }
    // 錢 與 籃子大小
    happy_fruit(bksp, money, 0, 0, mybucket);
}