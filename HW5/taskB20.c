#include <stdio.h>

int main() {
    int n, i;
    
    scanf("%d", &n);
    
    if (n < 2) {
        printf("NO");
    } 
    else if (n == 2) {               
        printf("YES");
        return 0;
    }
    else if (n % 2 == 0) {           
        printf("NO");
        return 0;
    }
    else {
        for (i = 3; i*i <= n; i = i + 2) {
            if (n % i == 0) {     
                printf("NO");       
                return 0;           
            }
        }
        printf("YES");
    }
    
    return 0;
}