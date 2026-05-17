#include <stdio.h>
#include <windows.h>

void printHex(int n) {
    if (n == 0) return;
    
    printHex(n/16);
    
    int rem = n%16;
    if (rem < 10)
        printf("%d", rem);
    else
        printf("%c", 'A'+(rem-10));
}

int main() {

    // Преобразование из 10 СИ в 16 СИ

    SetConsoleOutputCP(CP_UTF8);    
    
    int n = 12345678;
    //int n = 1000000;

    printf("Исходное число в 10 СИ: %d \n",n);
    printf("Преобразованное число в 16 СИ: ");

    if (n == 0) {
        printf("0\n");
    } else {
        printHex(n);
        printf("\n");
    }
    printf("Исходный код программы смотри на Github");
    return 0;
}