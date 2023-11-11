#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float c;
    do
    {
        //Prompt user for the positive input
        c = get_float("Changed owed: \n");
    }
    while (c < 0);

    //Change dollar to cent
    c = round(c * 100);

    int coins = 0;

    //Calculate the number of coins
    while (c >= 25)
    {
        c = c - 25;
        coins++;
    }
    while (c >= 10)
    {
        c = c - 10;
        coins++;
    }
    while (c >= 5)
    {
        c = c - 5;
        coins++;
    }
    while (c >= 1)
    {
        c = c - 1;
        coins++;
    }
    //Print out the amount of coins
    printf("%i\n", coins);
}