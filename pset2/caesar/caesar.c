#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage:./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage:./caesar key\n");
                return 1;
            }
        }
    }
    string s = get_string("plaintext: ");
    int k = atoi(argv[1]);
    printf("ciphertext: ");
    for (int j = 0, n = strlen(s); j < n; j ++)
    {
        char c = s[j];
        char m = 'A';
        if (isalpha(c))
        {
            if (isupper(c))
            {
                printf("%c", (c - m + k) % 26 + m);
            }
            if (islower(c))
            {
                m = 'a';
                printf("%c", (c - m + k) % 26 + m);
            }
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}