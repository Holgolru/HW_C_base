#include <stdio.h>
//#include <windows.h>

int main() {

    //SetConsoleOutputCP(CP_UTF8); 

    int a,b,c;

    //printf ("Введите три числа\n");
    scanf("%d %d %d", &a, &b, &c);

    printf ("%d+%d+%d=%d\n",a,b,c,a+b+c);
    printf ("%d*%d*%d=%d",a,b,c,a*b*c);


    return 0;
}