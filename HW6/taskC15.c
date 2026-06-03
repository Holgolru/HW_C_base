#include <stdio.h>

int grow_up(int n) {
    int num = n % 10;
    n /= 10;

    while (n > 0) {
        if (num <= n % 10) return 0;
        num = n % 10;
        n /= 10;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    if (grow_up(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}