#include <stdio.h>

int main() {
    char text[32];
    // scanf ("%s", &text);
    fgets(text, sizeof(text), stdin);
    int i = 0;
    while (text[i] != '.') {
        if ((text[i] >= 'A') && text[i] <= 'Z'){
            text[i] = text[i] + 32;
        }
        i++;
    }
    text[i] = '\0';
    printf("%s", text);
    return 0;
}