#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letter = 0;
    int word = 1;
    int snt = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letter++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            snt++;
        }

        if (text[i] == ' ')
        {
            word++;
        }
    }

    float L = ((float) letter * 100) / (float) word;
    float S = ((float) snt * 100) / (float) word;

    float index = 0;

    index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}