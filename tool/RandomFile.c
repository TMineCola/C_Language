#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Amount
    int num;
    // Setting range
    int max, less;
    // I = int, F = float
    char type;
    // File selection
    FILE *output_file;
    output_file = fopen("data.txt", "w");
    if(output_file == NULL) {
        printf("File error!");
        return 0;
    }
    // more random for random
    srand(time(NULL));

    printf("Input random type (I = int, F = float): ");
    scanf("%c", &type);
    printf("\nInput the range (less to max): ");
    scanf("%d %d", &less, &max);
    printf("\nInput the amount: ");
    scanf("%d", &num);
    if(less > max) {
        int temp = less;
        less = max;
        max = temp;
    }

    //依據類型產生亂數, 並將第一位數填入數量, 如果整數要包含 0 請輸入 -1
    fprintf(output_file, "%d ", num);
    for(int i = 0; i < num; i++) {
        if(type == 'I') {
            fprintf(output_file, "%d ", (rand() % (max - less)) + less + 1);
        } else if(type == 'F') {
            fprintf(output_file, "%f ", ((float)rand()/(float)(RAND_MAX)) * (max - less) + less);
        }
    }
}