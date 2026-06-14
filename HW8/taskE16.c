#include <stdio.h>
#include <limits.h>

void readElem(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}


int  maxMatchingInArray(int *arr, int size)
{
      
    int maxMatching = 0;
    int result = 0;

    for (int i = 0; i < size; i++)
    {
        int counter = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) counter++;
        }
        if (counter > maxMatching) {
            result = arr[i];
            maxMatching = counter;
        }
    }

    return result;
}

int main()
{
    int size = 10;

    int arr[size];

    readElem(arr, size);
    printf("%d ", maxMatchingInArray(arr, size));

    return 0;
}