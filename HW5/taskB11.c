#include <stdio.h>

int main() {
    int number, rebmun = 0;
    
    scanf("%d", &number);
    
    while (number > 0) {
        rebmun = rebmun * 10 + number % 10;
        number /= 10;
    }
    
    printf("%d", rebmun);
    
    return 0;
}