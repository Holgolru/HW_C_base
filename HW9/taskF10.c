#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 200;

void packText(char text[], char result[])
{
    int i = 0, j = 0;

    while (text[i] != '.')
    {
        char current = text[i];
        int count = 1;

        while (text[i + 1] != '.' && text[i + 1] == current)
        {
            count++;
            i++;
        }

        result[j++] = current;

        char numStr[10];

        sprintf(numStr, "%d", count);
        for (int k = 0; numStr[k] != '\0'; k++)
        {
            result[j++] = numStr[k];
        }

        i++;
    }

    result[j] = '\0';
}

int main()
{
    char text[MAX_SIZE];
    char result[2 * MAX_SIZE + 1];

    char c;
    int i=0;
    while( (c=getchar())!='.' ) text[i++]=c;
    text[i] = '.';
    text[i + 1] = '\0';

    packText(text, result);

    printf("%s\n", result);

    return 0;

}