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
int32_t num;


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
           help();
        }
        else if (strcmp(user_input, "alloc") == 0)
        {
            printf("Enter number of words of memory to allocate:");
            scanf("%d", &num);
            alloc(num);
        }
        else if (strcmp(user_input, "free") == 0)
        {
            free();
        }
        else if (strcmp(user_input, "read") == 0)
        {
            int location, size;
            printf("Enter the memory location between : ");
            scanf("%x", &location);
            printf("Enter the number of words to write: ");
            scanf("%x", &size);
            void Read(int location, int size)

        }
        else if (strcmp(user_input, "write") == 0)
        {
            int location, value, size;
            printf("Enter the memory location between : ");
            scanf("%x", &location);
            printf("Enter the data to be entered: ");
            scanf("%x", &value);
            printf("Enter the number of words to write: ");
            scanf("%x", &size);
            void Write(location, value, size);
        }
        else if (strcmp(user_input, "invert") == 0)
        {
            invert();
        }
        else if (strcmp(user_input, "exit") == 0)
        {
            exit(0);
        }
        // else
        // {
        //     printf("Invalid input. Enter help for available commands.\n>>");
        // }
    }
}
