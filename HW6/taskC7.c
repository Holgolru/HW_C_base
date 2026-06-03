#include <stdio.h>

int convertNum(int original, int base) {
    // Original > 0
    // 1 < Base < 10
    int remainder, digit = 1, accum = 0;
    while (original > 0) {
        remainder = original % base;
        original /= base;
        accum = accum + remainder * digit;
        digit *= 10;
    }
    return accum;
}

int main() {
    int num, base;
    scanf("%d %d", &num, &base);
    printf("%d", convertNum(num, base));
    return 0;
}