#include <stdio.h>

int main()
{
    FILE *f;
    char text[100];
    char c;
    int pos=0;
    f = fopen("input.txt", "r");
    while ((c = fgetc(f)) != EOF && c != '\n')
    {
        text[pos++]=c;
    }
    text[pos] = '\0';
    fclose(f);
    f = fopen("output.txt", "w");
    fprintf(f, "%s, %s, %s %d", text, text, text, pos);
    fclose(f);
    return 0;
}