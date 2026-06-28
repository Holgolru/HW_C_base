#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *input, *output;
    char c, last;

    int pos = 0;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    fseek(input, -1, SEEK_END);

    while (!isalnum(last = fgetc(input)))
    {
        fseek(input, -2, SEEK_CUR);
    }

    //printf("%c ", last);
    fseek(input, 0, SEEK_SET);

    while ((c = fgetc(input)) != '\n')
    {
        if (last == c)
        {
            int curPos = ftell(input);
            char nextSym;
            if (isalnum(nextSym = fgetc(input)))
            {
                fprintf(output, "%d ", pos);
                //printf("%d ", pos);
            }
            fseek(input, curPos, SEEK_SET);
        }
        pos++;
    }

    fclose(input);
    fclose(output);

    return 0;
}