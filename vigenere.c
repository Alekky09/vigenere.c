#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int alpha_check = 0; //A counter for key digit checking
int shift(char c);


int main(int argc, string argv[])
{
    if(argc != 2 || argv[1] == '\0')   //Checks if the command is correct
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int key_length = strlen(argv[1]);
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)   //Iterate over every char in the key
    {
            
        if(isalpha(argv[1][i]))  //Check if the char is a letter
        {    
            alpha_check++;
        }
        else                    //Return error if the key is not a alphabetic
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    }
    if(alpha_check == key_length)    //Executes cipher if the key is valid
    {
        string msg = get_string("plaintext: ");
        int kpos = 0;   //Counter for the position of the current char in the key
        printf("ciphertext: ");
        for(int j = 0, m = strlen(msg); j < m; j++)   //Executes the cypher
        {
            int key = shift(argv[1][kpos]);           //Calls for the current shift integer
            if(isupper(msg[j]))                       //Deals with the rollover in capital letters
            {
                char c = (msg[j] + key) % 91;         
                if(c < 'A')
                    printf("%c", c + 'A');
                else
                {
                    printf("%c", c);
                }
            }
            else if(islower(msg[j]))           //Deals with the rollover in small letters
            {
                char c = (msg[j] + key) % 123;       
                if(c < 'a')
                {
                    printf("%c", c + 'a');
                }
                else
                {
                    printf("%c", c);
                }
            }
            else
            {
                printf("%c", msg[j]);
            }
            
            kpos++;                     //Moves on to the next key char
            if(kpos > key_length - 1)   //Repeats the counter of the key char position when the key runs out of chars
            {
                kpos = 0;
            }
        }
        printf("\n");
        return 0;
    }
        
    
}

int shift(char c)
{
    if(isupper(c))
    {
        c = c - 65;
    }
    else
    {
        c = c - 97;
    }
    return c;
}
