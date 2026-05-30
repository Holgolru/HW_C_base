#include <stdio.h>

int main() {
    int num,sum,mult,rem;
    
    scanf("%d", &num);
    
    for (int i = 10; i <= num; i++) {
        sum = 0;
        mult = 1;
        rem = i;
        
        while (rem > 0) {
            sum += rem%10;
            mult *= rem%10;
            rem /= 10;
        }
        
        if (mult == sum) {
            printf("%d ", i);
        }
    }
    
    return 0;
}