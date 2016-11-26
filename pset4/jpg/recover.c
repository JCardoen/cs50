/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{   
    // open card.raw and store it as variable 'file'
    FILE* file = fopen("card.raw", "r");
    
    // check if file exist
    if (file == NULL)
    {
        fclose(file); 
        printf("Unable to find card.raw.\n");
        return 1;
    }

    // initialize our counter
    int counter = 0; 
   
    // initialize our buffer of 512 bytes
    BYTE buffer[512];
   
    // initialize our array for filename
    char lname[10]; 
   
    // initialize temporary file equal to NULL value
    FILE* temp = NULL; 
    
    
    
    // loop over the code if the end of the file is not reached
    while (!feof(file))
    {
       
        // check if the first sequence of 4 bytes is one of the 2 possible sequence that specify .jpg format
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // if the file 'temp' already exists close the temp file
            if (temp != NULL)
            {
                fclose(temp);
                
            }
            
            // give each jpg a filename consisting of 3 digits, incrementing with each file always formatted as 3 digits
            sprintf(lname, "%03d.jpg", counter);
            
            // next file
            temp = fopen(lname, "w");
            
            // increment our counter
            counter++;
            
            // new file with buffer
            fwrite(buffer, sizeof(buffer), 1, temp);
        }
        else if (counter > 0)
        {
            // write jpg to our temp file
            fwrite(buffer, sizeof(buffer), 1, temp);            
            
        }
      
        fread(buffer, sizeof(buffer), 1, file);
        
    }
  
    // close the file
    fclose(file);

    return 0;
}