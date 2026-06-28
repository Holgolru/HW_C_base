#include <stdio.h>

int main()
{
    FILE *f;
    int pos = 0, N;
    char text[27];
    f = fopen("input.txt", "r");
    fscanf(f, "%d", &N);
    fclose(f);

    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            text[pos++] = 'A' + i / 2;
        }
        else
        {
            text[pos++] = '0' + (i % 8) + 1;
        }
    }
    text[pos] = '\0';

    f = fopen("output.txt", "w");
    fprintf(f, "%s", text);
    printf("%s", text);
    fclose(f);
    return 0;
}