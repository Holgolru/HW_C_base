#include <stdio.h>

int main() {

    int n1,n2,n3,n4,n5,max,min;

    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

    max = (n1>n2)?n1:n2;
    if (max<n3) {max = n3;};
    if (max<n4) {max = n4;};
    if (max<n5) {max = n5;};

    min = (n1>n2)?n2:n1;
    if (min>n3) {min = n3;};
    if (min>n4) {min = n4;};
    if (min>n5) {min = n5;};
    
    printf ("%d",max+min);

    return 0;
}