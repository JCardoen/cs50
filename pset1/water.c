#include <stdio.h>
#include <cs50.h>
#include <math.h>

int GetPositiveInt(void)
{
 int n;
    do
    {
        printf("How many minutes did you shower?\n");
       n = GetInt();
    }
   while (n < 0);
    return n;
}

int main(void)
{
    int bottles = 0;
    printf("Input: \n");
    int time = GetPositiveInt();
    
    // 1.5 gallons of water per minute and 1 gallon is 128 ounces, 1 bottle of water = 16 ounces
    
    bottles = ((time * 1.5) * 128) / 16;
    printf("%i\n", bottles);
}