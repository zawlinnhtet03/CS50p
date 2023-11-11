#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    //Getting input from the user
    string name = get_string("What's your name?\n");
    //Print out that name with hello
    printf("Hello, %s\n", name);
}