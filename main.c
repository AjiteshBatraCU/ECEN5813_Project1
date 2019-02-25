#include <stdio.h>
#include "help.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        //printf("%s\n",user_input);
        if (strcmp(user_input, "help") == 0)
        {
            printf("Help Menu:\n");
            printf("alloc : Allocate memory - Enter the number of words of memory to allocate. Enter the number of words followed by the command\n");
            printf("free : Free memory - Frees the previously allocated memory block.\n");
            printf("read : Display memory words - Displays contents of the memory in 32-bit hex format.\n");
            printf("write : Write memory words - Enter the address and 32-bit value to write to the address.\n");
            printf("invert : Invert block - Invert all memory bits in a specified memory area. It also reports the time taken by the operation.\n>>");
        }
        else if (strcmp(user_input, "alloc") == 0)
        {
            int num;
            printf("Enter number of words of memory to allocate:");
            scanf("%d", &num);
            printf("Number of words: %d\n", num);
            printf("allocating\n>>");
        }
        else if (strcmp(user_input, "free") == 0)
        {

            printf("free\n>>");
            //free();
        }
        else if (strcmp(user_input, "read") == 0)
        {
            //printf("Enter the memory location between %x and %x: ",add1,add2);
            //printf("Number of memory words to read: ");
            printf("reading\n>>");
            //read();
        }
        else if (strcmp(user_input, "write") == 0)
        {
            //printf("Enter the memory location between %x and %x: ",add1,add2);
            //printf("Enter the data to be entered: ");
            //printf("")

            printf("writing\n>>");
            //write();
        }
        else if (strcmp(user_input, "invert") == 0)
        {
            printf("inverting\n>>");
            //invert();
        }
        else if (strcmp(user_input, "exit") == 0)
        {
            printf("exiting");
            exit(0);
        }
        // else
        // {
        //     printf("Invalid input. Enter help for available commands.\n>>");
        // }
    }
}
