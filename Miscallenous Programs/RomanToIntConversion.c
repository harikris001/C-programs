#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int value(char s)
{
    switch(s)
    {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
         case 'C':
            return 100;
            break;
         case 'D':
            return 500;
            break;
         case 'M':
            return 1000;
            break;
    }
}

int romanToInt(char*s)
{
    int a,b,num=0;
    for(int i=0;i<strlen(s);i++)
    {
        a = value(s[i]);
        if(i+1 < strlen(s))
        {
            b = value(s[i+1]);
            if(a>=b)
                num += a;
            else
                num -= a;
        }
        else
            num += a;
    }
    return num;
}

int main()
{
    char*s;
    printf("Enter your Roman Numeral: ");
    scanf("%s",s);
    int total = romanToInt(s);
    printf("\n value: %d", total);
    return 0;
}
