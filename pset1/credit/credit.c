#include <stdio.h>
#include <cs50.h>

int main()
{
    long Number = get_long_long("Number: ");
    long cc = Number;
    int k = 0;

    while (cc > 0)
    {
        cc = cc/10;
        k++;
    }
    
    if (k < 13 || k == 14 || k > 16)
    {
        printf("INVALID\n");
        return 0;
    }
    
    int digit1 = (Number % 10);
    int digit2 = (Number/10) % 10 *2;
    int digit3 = (Number/100) % 10;
    int digit4 = (Number/1000) % 10 *2;
    int digit5 = (Number/10000) % 10;
    int digit6 = (Number/100000) % 10 *2;
    int digit7 = (Number/1000000) % 10;
    int digit8 = (Number/10000000) % 10 *2;
    int digit9 = (Number/100000000) % 10;
    int digit10 =(Number/1000000000) % 10 *2;
    int digit11 =(Number/10000000000) % 10;
    int digit12 =(Number/100000000000) % 10 *2;
    int digit13 =(Number/1000000000000) % 10;
    int digit14 =(Number/10000000000000) % 10 *2;
    int digit15 =(Number/100000000000000) % 10;
    int digit16 =(Number/1000000000000000) % 10 *2;
    
    int check1  =   ((digit2 % 10) + ((digit2 % 100) / 10));
    check1 = (check1 + ((digit4 % 10) + ((digit4 % 100) / 10)));
    check1 = (check1 + ((digit6 % 10) + ((digit6 % 100) / 10)));
    check1 = (check1 + ((digit8 % 10) + ((digit8 % 100) / 10)));
    check1 = (check1 + ((digit10 % 10) + ((digit10 % 100) / 10)));
    check1 = (check1 + ((digit12 % 10) + ((digit12 % 100) / 10)));
    check1 = (check1 + ((digit14 % 10) + ((digit14 % 100) / 10)));
    check1 = (check1 + ((digit16 % 10) + ((digit16 % 100) / 10)));
    
    int checksum = check1+digit1+digit3+digit5+digit7+digit9+digit11+digit13+digit15;
    
    printf("%i\n",digit15*10 + digit14/2);
    
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    if (k == 13)
    {
        if (digit16/2 == 4)
        {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    
    if (k == 15)
    {
        if (digit15*10 + digit14/2 == 35 || digit15*10 + digit14/2 == 37)
        {
            printf("AMEX\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    
    if (k == 16)
    {
        if (digit16/2 == 4)
        {
            printf("VISA\n");
        }
        
        if (digit16/2 == 5)
        {
            if (digit16/2*10 + digit15 == 51 || digit16/2*10 + digit15 == 52 || digit16/2*10 + digit15 == 53 || digit16/22*10 + digit15 == 54 || digit16/2*10 + digit15 == 55)
            {
                printf("MASTERCARD\n");
            }
            else {
                printf("INVALID\n");
            }
        }
    }
}