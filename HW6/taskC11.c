#include <stdio.h>

int nod(int a, int b) {
    int bMemory = b;
    while (b != 0) {
        bMemory = b;
        b = a % b;
        a = bMemory;
    }
    return a;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", nod(a, b));
    return 0;
}