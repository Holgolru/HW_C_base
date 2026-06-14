#include <stdio.h>
#include <limits.h>

void readElem(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void writeElem(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int sortPlusMinus(int *arr, int *arrPlusMinus, int size)
{
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            arrPlusMinus[j++] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            arrPlusMinus[j++] = arr[i];
    }

    return j;
}

int main()
{
    int size = 10;
    int sizePlusMinus = 0;

    int arr[size], arrPlusMinus[size];

    readElem(arr, size);
    sizePlusMinus = sortPlusMinus(arr, arrPlusMinus, size);
    writeElem(arrPlusMinus, sizePlusMinus);

    return 0;
}