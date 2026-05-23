#include <stdio.h>

int main() {

    int n1,n2,n3;

    scanf("%d %d %d", &n1, &n2, &n3);
    printf ("%s",((n1<n2)&&(n2<n3))?"YES":"NO");

    return 0;
}