#include <stdio.h>

const int SIZE = 5;

int is_two_same(int size, int a[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) return 1;
        }
    }
    return 0;
}

int main()
{
    int a[]={1,2,3,5,5};
    int length = sizeof(a) / sizeof(a[0]);

    printf("%d", is_two_same(length, a));

    return 0;
}