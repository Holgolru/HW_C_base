#include <stdio.h>

int main() {

    int n;

    scanf("%d", &n);

    if ((n<=2)||(n==12)) (printf ("%s","winter")); 
    else if ((n<=5)) (printf ("%s","spring"));
    else if ((n<=8)) (printf ("%s","summer"));
    else (printf ("%s","autumn"));

    return 0;
}