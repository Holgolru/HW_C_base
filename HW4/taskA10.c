#include <stdio.h>

int main() {

    int n1,n2,n3,n4,n5,res;

    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

    res = (n1<n2)?n1:n2;
    if (res>n3) {res = n3;};
    if (res>n4) {res = n4;};
    if (res>n5) {res = n5;};
    
    printf ("%d",res);

    return 0;
}