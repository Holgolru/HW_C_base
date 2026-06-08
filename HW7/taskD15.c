#include <stdio.h>
#include <limits.h>

int max_find(int max) {
    int current;
    scanf("%d", &current);

    if (current == 0) {
        return max;
    }

    if (current > max) {
        max = current;
    }

    return max_find(max);
}

int main() {
    int max = INT_MIN;
    printf("%d\n", max_find(max));
    return 0;
}