#include <stdio.h>
#include <string.h>

char* is_palindrom(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if ((str[i] != str[len - i - 1]))
        {
            return ("NO");
        }
    }
    return ("YES");
}

int main()
{
    FILE *f;
    f = fopen("input.txt", "r");
    char text[1000];
    // fscanf(f, "%s", text);
    char c;
    int pos = 0;
    while ((c = fgetc(f)) != EOF && c != '\n')
    {
        text[pos++] = c;
    }
    text[pos] = '\0';

    fclose(f);

    f = fopen("output.txt", "w");

    
    fprintf(f, "%s", is_palindrom(text));
    //printf("%s", is_palindrom(text));

    fclose(f);
    return 0;
}