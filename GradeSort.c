#include <stdio.h>

void insertionSort(int grade[], int num) {
    int temp;
    for(int i = 1; i < num; i++) {
        temp = grade[i];
        for(int j = i - 1; j >= 0; j--) {
            if(j < 0) {
                break;
            }
            if(temp < grade[j]) {
                grade[j + 1] = grade[j];
                grade[j] = temp;
            }
        }
    }
}

void bestFail(int grade[], int num) {
    int best = -1;
    for(int i = 0; i < num; i++) {
        if(grade[i] < 60 && grade[i] > best) {
            best = grade[i];
        }
    }
    if(best != -1) {
        printf("\n最高分被當分數： %d", best);
    } else {
        printf("\n沒有人被當");
    }
}

void worstPass(int grade[], int num) {
    int worst = 101;
    for(int i = 0; i < num; i++) {
        if(grade[i] >= 60 && grade[i] < worst) {
            worst = grade[i];
        }
    }
    if(worst != 101) {
        printf("\n最低分通過分數： %d", worst);
    } else {
        printf("\n沒有人通過");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int grade[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &grade[i]);
    }
    insertionSort(grade, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", grade[i]);
    }
    worstPass(grade, n);
    bestFail(grade, n);
    printf("\n");
    return 0;
}