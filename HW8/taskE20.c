#include <stdio.h>

const int MAXSIZE = 16;

int main()
{
    int n;
    scanf("%d", &n);
        
    int size = 0;
    int arr[MAXSIZE];
    
    while (n > 0)
    {
        arr[size++] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}