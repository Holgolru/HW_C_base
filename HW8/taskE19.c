#include <stdio.h>

void printNum(int n)
{
    if (n < 10)
    {
        printf("%d ", n);
        return;
    }
    printNum(n / 10);
    printf("%d ", n % 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    printNum(n);
    return 0;
}