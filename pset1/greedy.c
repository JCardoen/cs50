#include <stdio.h>
#include <cs50.h>
#include <math.h>

float GetPositiveFloat(void)
{
 float n;
    do
    {
        printf("Please give me a positive float: ");
       n = GetFloat();
    }
   while (n < 0);
    return n;
}

int main(void)
{
    int coins = 0;
  
    
    printf("Howmuch is the change?: \n");
    float c = GetPositiveFloat();
    int change = round(c * 100);
    

    while(change % 25 >= 0 && change >= 25 && change > 0){
        change = change-25;
        coins++;
    }
    
     while(change % 10 >= 0 && change >= 10 && change > 0){
        change = change-10;
        coins++;
    }
    
     while(change % 5 >= 0 && change >= 5 && change > 0){
        change = change-5;
        coins++;
    }
    
    while(change % 1 == 0 && change >= 1 && change > 0){
        change = change -1;
        coins++;
    }
    

printf("%i\n",coins);
    
}
