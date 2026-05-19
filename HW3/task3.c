#include <stdio.h>
//#include <windows.h>

int main() {

    //SetConsoleOutputCP(CP_UTF8); 

    int a,b,c;

    //printf ("Введите три числа\n");
    scanf("%d %d %d", &a, &b, &c);

    printf ("%.2f",(a+b+c)/3.0);


    return 0;
}