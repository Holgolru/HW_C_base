#include <stdio.h>
#include <string.h>

int main()
{
    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    char wordFirst[100], wordSecond[100];
    fscanf(input, "%s %s", &wordFirst, &wordSecond);

    for (char c = 'a'; c <= 'z'; c++)
    {
        if ((strchr(wordFirst, c) == strrchr(wordFirst, c)) &&
            (strchr(wordSecond, c) == strrchr(wordSecond, c)) &&
            (strchr(wordFirst, c) != 0) && (strchr(wordSecond, c) != 0))
        {
            fprintf(output, "%c ", c);
        };
    }

    fclose(input);
    fclose(output);
    return 0;
}