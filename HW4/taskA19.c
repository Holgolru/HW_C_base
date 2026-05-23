#include <stdio.h>
//#include <windows.h>

int main() {

    //SetConsoleOutputCP(CP_UTF8); 

    int a,b,c;

    scanf("%d %d %d", &a, &b, &c);

    printf ("%s",(((a+b)>c)&&((a+c)>b)&&((b+c)>a))?("YES"):"NO");
    
    return 0;
}