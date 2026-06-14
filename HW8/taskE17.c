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

int findUniqueElem(int *arr, int *arrUniqueElem, int size)
{
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        int counter = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) counter++;
        }
        if (counter==1) {
            arrUniqueElem[j++]=arr[i];
        }
    }

    return j;
}

int main()
{
    int size = 10;
    int sizeResultArray = 0;

    int arr[size], arrUniqueElem[size];

    readElem(arr, size);
    sizeResultArray = findUniqueElem(arr, arrUniqueElem, size);
    writeElem(arrUniqueElem, sizeResultArray);

    return 0;
}