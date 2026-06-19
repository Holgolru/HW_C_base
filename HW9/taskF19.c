#include <stdio.h>
#include <string.h>

const int SIZE = 5;

float findMidDiag(int arr[SIZE][SIZE], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][i];
    }
    return (sum / size);
}

int main() {
    int arr[SIZE][SIZE];
    int counter = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    float midDiag = findMidDiag(arr, SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] > midDiag && arr[i][j] > 0) {
                counter++;
            }
        }
    }
    
    printf("%d\n", counter);
    
    return 0;
}