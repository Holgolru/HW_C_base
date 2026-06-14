#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 2; i < 10; i++)
    {
        int counter = 0;
        for (int j = 2; j <= n; j++) {
            if (j%i==0) counter++;
        }
        printf("%d %d\n", i, counter);
    }
    return 0;
}