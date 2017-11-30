#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // 打亂時間參數
    srand(time(NULL));
    // 載入資料及輸出書檔案
    FILE *input_file, *output_file;
    input_file = fopen("input.txt","r");
    output_file = fopen("output.txt","a+");
    // 讀取檔案
    printf("讀取資料中...\n");
    // 教室數量
    int class_num;
    fscanf(input_file, "%d", &class_num);
    printf("教室數: %d\n", class_num);
    // 教室名稱及最大人數上限
    char class_name[class_num][20];
    int class_max[class_num];
    for(int i = 0; i < class_num; i++) {
        fscanf(input_file, "%s", class_name[i]);
        fscanf(input_file, "%d", &class_max[i]);
        printf("教室名稱: %s, 教室人數上限: %d\n", class_name[i], class_max[i]);
    }
    // 分類方式 A: 平均, B: 比例平均, C:前者優先填滿
    char tp[1];
    fscanf(input_file, "%s", tp);
    printf("分配方式: %s\n", tp);
    // 讀取學生數, 學生id及姓名
    int n;
    fscanf(input_file, "%d", &n);
    printf("總學生數: %d\n", n);
    int stdid[n];
    char name[n][20];
    for(int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &stdid[i]);
        fscanf(input_file, "%s", name[i]);
    }
    // 將學生資料打亂
    for(int i = 0; i < 1000; i++) {
        int swap_A = rand() % n;
        int swap_B = rand() % n;
        int tempid;
        char tempname[20];
        tempid = stdid[swap_A];
        stdid[swap_A] = stdid[swap_B];
        stdid[swap_B] = tempid;
        for(int j = 0; j < 20; j++) {
            char temp;
            temp = name[swap_A][j];
            name[swap_A][j] = name[swap_B][j];
            name[swap_B][j] = temp;
        }
    }
    //分配
    int max, total = 0, count = 0;
    switch(tp[0]) {
        case 'A':
            // 平均分配
            max = n / class_num;
            for(int i = 0; i < class_num; i++) {
                fprintf(output_file, "教室名稱：%s\n", class_name[i]);
                for(int j = max * i; j < max * (i + 1); j++) {
                    fprintf(output_file, "%d %s\n", stdid[j], name[j]);
                }
                // 餘數補進最後一個班級
                if(n % class_num != 0 && i == class_num - 1) {
                    for(int j = max * (i + 1); j < max * (i + 1) + n % class_num; j++) {
                        fprintf(output_file, "%d %s\n", stdid[j], name[j]);
                    }
                }
                fprintf(output_file, "\n");
            }
            break;
        case 'B':
            // 比例分配
            // 先算總容納人數
            for(int i = 0; i < class_num; i++) {
                total += class_max[i];
            }
            for(int i = 0; i < class_num; i++) {
                // 計算比例
                max = (float)n * ((float)class_max[i] / (float)total);
                fprintf(output_file, "教室名稱：%s\n", class_name[i]);
                for(int j = count; j < count + max; j++) {
                    fprintf(output_file, "%d %s\n", stdid[j], name[j]);
                }
                // 紀錄分配中斷點
                count += max;
                // 補印
                if(count < n && i == class_num - 1) {
                    for(int j = count; j < n; j++) {
                        fprintf(output_file, "%d %s\n", stdid[j], name[j]);
                    }
                }
            }
            break;
        case 'C':
            // 順序優先
            for(int i = 0; i < class_num; i++) {
                fprintf(output_file, "教室名稱：%s\n", class_name[i]);
                max = count + class_max[i];
                if(max > n) {
                    max = n;
                }
                for(int j = count; j < max; j++) {
                    fprintf(output_file, "%d %s\n", stdid[j], name[j]);
                }
                count += class_max[i];
            }
            break;
        default:
            printf("Type error!");
            break;
    }
}