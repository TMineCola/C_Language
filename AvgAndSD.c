#include <stdio.h>

double power(double input, int times) {
    for(int i = 1; i < times; i++) {
        input *= input;
    }
    return input;
}

double sqrt(double v) {
    double l, r;
    double mid;
    if(v >= 1) {
        l = 1;
        r = v;
    } else {
        l = v;
        r = 1;
    }
    mid = (l + r) / 2;
    while(l < mid && r > mid) {
        if(mid * mid > v) {
            r = mid;
        } else {
            l = mid;
        }
        mid = (l + r) / 2;
	}
	return mid;
}

double Calc_avg(double data[], int n) {
    double avg = 0;
    for(int i = 0; i < n; i++) {
        avg += data[i];
    }
    return avg / n;
}

double Calc_sd(double data[], int n) {
    double avg = Calc_avg(data, n);
    double sd = 0;
    for(int i = 0; i < n; i++) {
        //sd += power(data[i] - avg, 2);
        sd += (data[i]-avg)*(data[i]-avg);
    }
    return sqrt(sd / n);
}

int main() {
    int n;
    scanf("%d", &n);
    double data[n];
    for(int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }
    printf("%f\n", Calc_avg(data, n));
    printf("%f\n", Calc_sd(data, n));
}