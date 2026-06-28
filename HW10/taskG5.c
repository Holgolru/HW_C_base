#include <stdio.h>
#include <string.h>

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

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == 'a') || (text[i] == 'A'))
        {
            text[i]++;
        }
        else if ((text[i] == 'b') || (text[i] == 'B'))
        {
            text[i]--;
        };
    }

    fclose(f);

    f = fopen("output.txt", "w");

    fprintf(f, "%s", text);
    //printf("%s", text);

    fclose(f);
    return 0;
}