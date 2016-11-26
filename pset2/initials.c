#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    
    // get user's input and use it in a variable
    string name = GetString();
    
    // now we want to print the first letter of the name, which is basically the first character in the string array
    printf("%c", toupper(name[0]));
    
    // since the second initial letter of your name comes after a space we need to find the index of the space in your string
    for(int i = 0, n = strlen(name) ; i< n ;i++)
    {
        if(name[i] == ' '){
            printf("%c", toupper(name[i+1]));
        }
    }
    
    printf("\n");
}