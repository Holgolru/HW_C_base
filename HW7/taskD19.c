#include <stdio.h>

int acounter(void) {
    char c = getchar();

    if (c == '.') {
        return 0;
    }

    int count = acounter();

    if (c == 'a') {
        return count + 1;
    }

    return count;
}

int main() {
    printf("%d\n", acounter());
    return 0;
}