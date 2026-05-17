#include <stdio.h>
#include <windows.h>

int main() {

    // Преобразование из 16 СИ в 10 СИ

    SetConsoleOutputCP(CP_UTF8); 

    //char hex[] = "12345678";
    char hex[] = "1000000";
    int n;
    int res = 0;

    printf("Исходное число в 16 СИ: %s\n", hex);
    printf("Преобразованное число в 10 СИ: ");
    
    for (int i = 0; hex[i] != '\0'; i++) {
         
        if (hex[i] >= '0' && hex[i] <= '9') {
            n = hex[i]-'0';
        } else {
            n = hex[i]-'A'+10;
        };
        
        res = res * 16 + n;
    }
    
    printf("%d \n", res);
    printf("Исходный код программы смотри на Github");
    
    return 0;
}