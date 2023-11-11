#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n;
    do
    {
        //Prompt number from the user
        n = get_long("Number: ");
    }
    while (n < 0);


    //Get some digit for checksum
    int digit1 = (n / 1000000000000000) * 2;
    int digit2 = ((n / 10000000000000) % 10) * 2;
    int digit3 = ((n / 100000000000) % 10) * 2;
    int digit4 = ((n / 1000000000) % 10) * 2;
    int digit5 = ((n / 10000000) % 10) * 2;
    int digit6 = ((n / 100000) % 10) * 2;
    int digit7 = ((n / 1000) % 10) * 2;
    int digit8 = ((n / 10) % 10) * 2;

    //Split and add the digits which are greater or equal than 10
    digit1 = (digit1 / 10) + (digit1 % 10);
    digit2 = (digit2 / 10) + (digit2 % 10);
    digit3 = (digit3 / 10) + (digit3 % 10);
    digit4 = (digit4 / 10) + (digit4 % 10);
    digit5 = (digit5 / 10) + (digit5 % 10);
    digit6 = (digit6 / 10) + (digit6 % 10);
    digit7 = (digit7 / 10) + (digit7 % 10);
    digit8 = (digit8 / 10) + (digit8 % 10);

    int a = digit1 + digit2 + digit4 + digit3 + digit5 + digit6 + digit7 + digit8;

    //Get the remaining digits
    int digit1a = n / 100000000000000 % 10;
    int digit2a = n / 1000000000000 % 10;
    int digit3a = n / 10000000000 % 10;
    int digit4a = n / 100000000 % 10;
    int digit5a = n / 1000000 % 10;
    int digit6a = n / 10000 % 10;
    int digit7a = n / 100 % 10;
    int digit8a = n % 10;

    int v = a + digit1a + digit2a + digit4a + digit3a + digit5a + digit6a + digit7a + digit8a;


    long long vs = n / 1000000000000000;
    long long vs1 = n / 1000000000000;
    long long amax = n / 10000000000000;
    long long ms = n / 100000000000000;

    //Count the amount of digits
    int num = 0;
    while (n > 0)
    {
        n = n / 10;
        num++;
    }
    //Grab last digit
    v = v % 10;

    if (num < 13)
    {
        printf("INVALID\n");
        return 0;
    }



    if (num != 13 && num != 15 && num != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    if (v == 0)
    {
        if (num == 16)
        {
            if (vs == 4)
            {
                printf("VISA\n");
            }
            if (ms == 51 || ms == 52 || ms == 53 || ms == 54 || ms == 55)
            {
                printf("MASTERCARD\n");
            }
            if (ms != 51 && ms != 52 && ms != 53 && ms != 54 && ms != 55 && vs != 4)
            {
                printf("INVALID\n");
            }
        }
        if (num == 13)
        {
            if (vs1 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        if (num == 15)
        {
            if (amax == 34 || amax == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }

}