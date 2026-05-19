#include <stdio.h>
//#include <windows.h>

int main() {

    //SetConsoleOutputCP(CP_UTF8); 

    int a,b,c,sum;

    //printf ("Введите три числа\n");
    scanf("%d %d %d", &a, &b, &c);

    sum = a+b+c;

    printf ("%d+%d+%d=%d",a,b,c,sum);


    return 0;
}