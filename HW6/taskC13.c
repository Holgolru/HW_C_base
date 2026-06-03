#include <stdio.h>

float absMy(float x) {
    if (x < 0)
        return -x;
    return x;
}

// x - в радианах!!!!
float cosinus(float x) {
    float cos = 1.0;
    float cosOld = 0.0;
    float numer = -x * x;
    float denom = 2.0;
    int i = 2;

    while (absMy(cos - cosOld) > 0.001) {
        cosOld = cos;
        cos += numer / denom;

        numer *= -x * x;
        denom *= (2 * i) * (2 * i - 1);
        i++;
    }

    return cos;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%.3f", cosinus(n*3.14152/180));

    return 0;
}