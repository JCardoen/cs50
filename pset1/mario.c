#include <stdio.h>
#include <cs50.h>
#include <math.h>

 int GetPositiveInt(void){
 int n;
 do{
  printf("Height?\n");
      n = GetInt();
        }

       while (n < 0 || n >= 24); 
       return n; 
  
 }
       

int main(void){
 int spaces = 0;
 int hashes = 0;

       printf("Input:\n");
    int c = GetPositiveInt();
             for (int i = 1; i<=c; i++) {
             hashes = i + 1;
             spaces = c-hashes+1;
             printf("%.*s", spaces, "                                          ");
             printf("%.*s", hashes, "########################################");
             printf("\n");
             
             }
 

}