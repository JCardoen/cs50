#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){
    int index = 0;
    
    //valid argc 
    if (argc != 2)
    {
        printf("Invalid.");
        return 1;
    }
        
    // key for caesar cipher encryption
    string k = argv[1];
    int count = strlen(k);
    
    for(int i = 0; i < count; i++){
        if(!(isalpha(k[i]))){
            printf("Key is invalid.");
            
            return 1;
        }
    }
    
    // initialize array with integers in them, those integers will function as the key
    int key[count];
        
    // get value of key ignoring case from A: 0 to Z:25 as an integer and store them into another array
    for(int i = 0; i < count; i++)
    {   
        if(islower(k[i]))
        {
            key[i] = k[i] - 97;
        }
        if(isupper(k[i]))
        {
            key[i] = k[i] - 65;
        }
    }

    // get user input and store in string variable
    string crypt = GetString();
    
    // store stringlength as an integer variable
    int cryptlen = strlen(crypt);
        
    // make a loop that goes over each letter of your string
    for(int i = 0; i < cryptlen; i++)
    {
        int c = 0;
        char charstring = crypt[i];
            
        // store the character of string at i'th index as a character
        if(isalpha(charstring) == false)
        {
            printf("%c", (char)charstring);
        }
        
        else {
            // cipher algorithm + conversion from alphabetical to ASCII distinguish upper- from lowercase
                    
            if(islower(charstring))
            {
                c = (((int)charstring - 97)+ key[index]) % 26;
                c = c + 97;
                printf("%c", (char)c);
            }
                    
            if(isupper(charstring))
            {
                c = (((int)charstring - 65)+ key[index]) % 26;
                c = c + 65;
                printf("%c", (char)c);
            }
        
            index++;
            if(index == count)
            {
                index = 0;
            }
        }
    }
    
    printf("\n");
    return 0;
}

    

    

    
    
    