#include <stdio.h>

int main() {

    int n1,n2,n3,res;

    scanf("%d %d %d", &n1, &n2, &n3);

    res = (n1>n2)?n1:n2;
    if (res<n3) {res = n3;};
    
    printf ("%d",res);

    return 0;
}