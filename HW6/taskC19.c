#include <stdio.h>

int digit_to_num(char c) {
    return (c - '0');
}

int main() {
    char text[1000];
    int summ = 0;
    int i = 0;

    fgets(text, sizeof(text), stdin);

    while (text[i] != '.') {
        if ((text[i] >= '0') && (text[i] <= '9')) {
            summ += digit_to_num(text[i]);
        }
        i++;
    }

    printf("%d", summ);
    return 0;
}