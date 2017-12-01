#include <stdio.h>

double CalcBMI(double height, double weight) {
    return weight / ((height/100) * (height/100));
}

void CheckBMI(double BMI) {
    if (BMI < 18.5) {
        printf("過輕\n");
    } else if (BMI < 24) {
        printf("正常\n");
    } else {
        printf("過重\n");
    }
}

int main() {
    double h, w;
    scanf("%lf %lf", &h, &w);
    printf("%lf ", CalcBMI(h, w));
    CheckBMI(CalcBMI(h, w));
    return 0;
}