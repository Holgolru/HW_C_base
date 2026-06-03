#include <stdio.h>

int isItCorrect(char text[]) {
    int count = 0;
    int i = 0;

    while (text[i] != '.') {
        if (text[i] == '(') {
            count++;
        }
        else if (text[i] == ')') {
            count--;
            if (count < 0) {
                return 0;
            }
        }
        i++;
    }
    return (count == 0);
}

int main() {
    char text[1000];
    fgets(text, sizeof(text), stdin);

    if (isItCorrect(text)) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}