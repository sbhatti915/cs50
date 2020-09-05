#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    char Result;
    int countword = 1;
    int countletter = 0;
    int countsentence = 0;

    string s = get_string("Text: ");

    for (int k = 0; k < strlen(s); k++)
    {
        Result = s[k];
        if ((Result >= 97 && Result <= 122) || (Result >= 65 && Result <= 90))
        {
            countletter++;
        }
        else if (Result == 32)
        {
            countword++;
        }
        else if ((Result == 33) || (Result == 46) || (Result == 63))
        {
            countsentence++;
        }
    }
    printf("%i\n", countletter);
    printf("%i\n", countword);
    printf("%i\n", countsentence);

    float index = (0.0588 * ((float) countletter / (float) countword * 100) - 0.296 * ((float) countsentence / (float) countword * 100) - 15.8);
    index = round(index);
    
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
}
