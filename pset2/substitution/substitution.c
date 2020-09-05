#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc,string argv[])
{
    int letter;
    

    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    
    string s = argv[1];
    
    for (int k = 0; k < strlen(s); k++)
    {
        
        if (((char) s[k] < 65) || ((char) s[k] > 90 && (char) s[k] < 97) || (char) s[k] > 122)
        {
            printf("Usage: ./substitution key");
            return 1;
        }
        
        for(int j = k+1; j < strlen(s); j++) 
        {  
            if(s[k] == s[j]) 
            {  
                printf("No repeated characters");
                return 1;
            }  
        }  
    }
    
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int k = 0; k < strlen(text); k++)
    {
        if ((char) text[k] >= 65 && (char) text[k] <= 90)
        {
            letter = text[k]-65;
            printf("%c", toupper(s[letter]));
        }
        else if ((char) text[k] >= 97 && (char) text[k] <= 122)
        {
            letter = text[k]-97;
            printf("%c", tolower(s[letter]));
        }
        else
        {
            printf("%c", text[k]);
        }
    }
    printf("\n");
    return 0;
}