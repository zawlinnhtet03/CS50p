#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    string s = get_string("Text: ");

    int letter = 0;
    for (int i = 0, n = strlen(s); i < n; i ++)
    {
        if (islower(n [i]) || isupper(n [i]))
        {
            letter ++;
        }
    }
    int word = 1;
    for (int j = 0, n = strlen(s); j < n; j ++)
    {
        if (isspace(s [j]))
        {
            word ++;
        }
    }
    int sent = 0;
    for (int k = 0, n = strlen(s); k < n; k ++)
    {
        if (s [k] == '.' || s [k] == '!' || s [k] == '?')
        {
            sent ++;
        }
    }

    float L = ((float)letter * 100) / (float)word;
    float S = ((float)sent * 100) / (float)word;
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) index);
    }
    

}