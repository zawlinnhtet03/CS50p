#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Prompt for key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        //Prompt for only alphabatical characters
        if (isdigit(argv[1][i]))
        {
            printf("Key must only contain alphabatic characters\n");
            return 1;
        }
        else if (isalpha(argv[1][i]))
        {
            //Prompt for 26 letters
            if (n != 26)
            {
                printf("Key must only contain 26 characters\n");
                return 1;
            }
        }
        for (int j = 0; j < i; j++)
        {
            //Reprompt if occur repeated letters
            if (argv[1][i] == argv[1][j] || argv[1][i] == argv[1][j] + 32 || argv[1][i] == argv[1][j] - 32)
            {
                printf("Key must not contain repeated character\n");
                return 1;
            }
        }
    }
    //Prompt actual string from the user
    string t = get_string("plaintext: ");
    //Print out ciphertext
    printf("ciphertext: ");
    for (int i = 0, n  = strlen(t); i < n; i++)
    {
        //Assume arrays of characters as aph
        char aph = t[i];
        //Conditions for only alphabatical characters
        if (isalpha(aph))
        {
            //Conditions for uppercase letters
            if (isupper(aph))
            {
                //Conditions for uppercase keys
                if (isupper(argv[1][aph - 'A']))
                {
                    printf("%c", argv[1][aph - 'A']);
                }
                //Conditions for lowercase keys
                else if (islower(argv[1][aph - 'A']))
                {
                    printf("%c", (argv[1][aph - 'A'] - 32));
                }
            }
            //Conditions for lowercase letters
            if (islower(aph))
            {
                //Conditions for uppercase keys
                if (isupper(argv[1][aph - 'a']))
                {
                    printf("%c", (argv[1][aph - 'a'] + 32));
                }
                //Conditions for lowercase keys
                else if (islower(argv[1][aph - 'a']))
                {
                    printf("%c", argv[1][aph - 'a']);
                }
            }
        }
        else
        {
            //For those which isn't alphabat
            printf("%c", aph);
        }

    }
    printf("\n");
}