#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        for (int l = 0; l < 2; l++)
        {
            printf(" ");
        }
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}