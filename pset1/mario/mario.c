#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int Height = get_int("Height: ");
    
    while (Height < 1 || Height > 8)
    {
        Height = get_int("Height: ");
    }
    
    for (int k = 1; k <= Height; k++)
    {
        for (int space = Height - k; space > 0; space--)
        {
            printf(" ");
        }
        
        for (int hash = 1; hash <= k; hash++)
        {
            printf("#");
        }
        
        printf("  ");
        
        for (int hash = 1; hash <= k; hash++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}