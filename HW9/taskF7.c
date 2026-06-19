#include <stdio.h>


int compression(int a[], int b[], int N) {
    int j = 0;
    int count = 1;
    
    if (a[0] == 1) {
        b[j++] = 0;
    }
    
    for (int i = 1; i < N; i++) {
        if (a[i] == a[i-1]) {
            count++;
        } else {
            b[j++] = count;
            count = 1;
        }
    }
    b[j++] = count;
    
    return j;
}

int main()
{
    int a[]={1,1,0,0,0,1,1,0,0,1,0,0,0,0,0};
    int length = sizeof(a) / sizeof(a[0]);
    int b[length];

    length = compression(a, b, length);
    
    for (int j=0; j<length; j++) {
        printf("%d ", b[j]);
    }
    return 0;
}