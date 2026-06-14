

#include <stdio.h>
#include <limits.h>


void readElem(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void writeElem(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void shiftElem(int* arr, int size, int shift)
{
    if (size == 0) return;

    int temp[size];

    for (int i = 0; i < size; i++) {
        temp[i] = arr[(i - shift + size) % size];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int size = 12;
    int shift = 4;   

    int arr[size];
    
    readElem(arr, size);
    shiftElem(arr, size, shift);
    writeElem(arr, size);

    return 0;
}