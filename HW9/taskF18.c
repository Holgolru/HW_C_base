#include <stdio.h>
#include <string.h>

const int SIZE = 10;

int findMax(int row, int arr[][SIZE]) {
    int max = arr[row][0];
    
    for (int j = 1; j < SIZE; j++) {
        if (arr[row][j] > max) max = arr[row][j];
    }
    
    return max;
}

int main() {
    int arr[SIZE][SIZE];
    int i, j, sum = 0;
    

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
        
    for (i = 0; i < SIZE; i++) {
        sum += findMax(i, arr);
    }
    
    printf("%d", sum);
    
    return 0;
}