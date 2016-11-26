#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){
        
        //valid argc 
        if (argc != 2)
        {
            printf("Invalid.");
            return 1;
        }
        
        // key for caesar cipher encryption
        int k = atoi(argv[1]);
        
        if(k == 0)
        {
            printf("Key is invalid.");
        }
        
        // get user input and store in string variable
        string crypt = GetString();
        
        // make a loop that goes over each letter of your string
        for(int i = 0, n = strlen(crypt); i < n; i++)
        {
            
            int c = 0;
            char charstring = crypt[i];
            
            // store the character of string at i'th index as a character
            if(isalpha(charstring) == false)
            {
                printf("%c", (char)charstring);
            }
            
            // cipher algorithm + conversion from alphabetical to ASCII distinguish upper- from lowercase
            
            if(islower(charstring))
            {
                c = (((int)charstring - 97) + k) % 26;
                c = c + 97;
                printf("%c", (char)c);
            }
            
            if(isupper(charstring))
            {
                c = (((int)charstring - 65)+ k) % 26;
                c = c + 65;
                printf("%c", (char)c);
            }
        }
        
    printf("\n");
}
    

    
    
    