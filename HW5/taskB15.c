#include <stdio.h>

int main() {
    int num, counter = 0;
    
    scanf("%d", &num);
    
    while (num != 0) {
        if (num % 2 == 0) {
            counter++;
        }
        scanf("%d", &num);
    }
    
    printf("%d", counter);
    
    return 0;
}