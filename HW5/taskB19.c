#include <stdio.h>

int main() {
    int num, accum = 0;
    
    scanf("%d", &num);
    
    while ((num > 0)&&(accum<=10)) {
        accum += num % 10;
        num /= 10;
    }
    
    if (accum == 10) {
        printf("YES");
    } else {
        printf("NO");
    }
    
    return 0;
}