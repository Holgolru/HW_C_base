#include <stdio.h>

int main() {

    int n,n1,n2,n3,res;

    scanf("%d", &n);

    n1 = n%10;
    n2 = (n/10)%10;
    n3 = n/100;

    res = (n1>n2)?n1:n2;
    if (res<n3) {res = n3;};
    
    printf ("%d",res);

    return 0;
}