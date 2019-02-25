/***************************************************
* main .c
* 
***************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "help.h"
#include "alloc.h"
#include "free.h"
#include "modify.h"
#include "display.h"
#include "invert.h"

char *ptr;
int32_t mem_size;


int main()
{
    char c;
    char user_input[10] = {0};

    printf("Welcome to the Interactive Memory Management Project\nType in help for info about the features, exit to exit\n>>");
    while (1)
    {
        int i = 0;
        while ((c = getchar()) != '\n' && c != EOF)
        {
            user_input[i] = c;
            i++;
        }
        user_input[i] = 0;
        //Help option
        if (strcmp(user_input, "help") == 0)
        {
           help();
        }
        //Memory allocation
        else if (strcmp(user_input, "alloc") == 0)
        {
            printf("Enter number of words of memory to allocate:\n");
            scanf("%d", &mem_size);
            alloc(mem_size);
        }
        //Free memory
        else if (strcmp(user_input, "free") == 0)
        {   
            if(mem_size != 0)
            {
                mem_free();
            }
            else
            {
                printf("No memory allocated\n>>");
            }   
        }
        //Memory read
        else if (strcmp(user_input, "read") == 0)
        {
            if(mem_size != 0)
            {
                int location, size;
                printf("Which of the %d memory words would you like to start at: \n", mem_size);
                scanf("%x", &location);
                printf("Enter the number of words to read: \n");
                scanf("%x", &size);
                read(location, size);
            }
            else
            {
                printf("No memory allocated\n>>");
            }   
        }
        //Memory write
        else if (strcmp(user_input, "write") == 0)
        {
            if(mem_size != 0)
            {
                int location, value, size;
                printf("Which of the %d memory words would you like to start at: \n", mem_size);
                scanf("%x", &location);
                printf("Enter the data to be entered: \n");
                scanf("%x", &value);
                printf("Enter the number of words to write: \n");
                scanf("%x", &size);
                write(location, value, size);
            }    
            else
            {
                printf("No memory allocated\n>>");
            }   
        }
        //Data invert
        else if (strcmp(user_input, "invert") == 0)
        {
            if(mem_size != 0)
            {
                invert();
            }
            else
            {
                printf("No memory allocated\n>>");
            }   
        }
        //Exit with free memory
        else if (strcmp(user_input, "exit") == 0)
        {
	        mem_free();
            printf("Goodbye<<\n");
            exit(0);
        }
    }
}
