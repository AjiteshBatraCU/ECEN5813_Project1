#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "help.h"
#include "alloc.h"
#include "free.h"
#include "modify.h"
#include "display.h"
#include "invert.h"
#include "set_pattern.h"
#include "verify_pattern.h"

char *ptr;
int32_t mem_size;

typedef void (*function_ptr)(void);

struct functionlist {
  char *string;
  function_ptr function;
};

const struct functionlist functions[] = {
	{"help", &help},
	{"alloc", &alloc},
	{"free", &mem_free},
	{"read", &read},
   	{"write", &write},
	{"invert", &invert},
	{"exit", &exit},
   	{"pattern", &set_pattern},
	{"verify", &verify_pattern}
};

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
        for (int j=0; j<=8; j++)
        {
            if (strcmp(user_input, functions[j].string) == 0)
            {
               functions[j].function();
            }
        }

		/*
        while ((c = getchar()) != '\n' && c != EOF)
        {
            user_input[i] = c;
            i++;
        }
        user_input[i] = 0;
        if (strcmp(user_input, "help") == 0)
        {
           help();
        }
        else if (strcmp(user_input, "alloc") == 0)
        {
            printf("Enter number of words of memory to allocate:");
            scanf("%d", &mem_size);
            alloc(mem_size);
        }
        else if (strcmp(user_input, "free") == 0)
        {
            mem_free();
        }
        else if (strcmp(user_input, "read") == 0)
        {
            int location, size;
            printf("Which of the %d memory words would you like to start at : ", mem_size);
            scanf("%x", &location);
            printf("Enter the number of words to read: ");
            scanf("%x", &size);
            Read(location, size);

        }
        else if (strcmp(user_input, "write") == 0)
        {
            int location, value, size;
            printf("Which of the %d memory words would you like to start at : ", mem_size);
            scanf("%x", &location);
            printf("Enter the data to be entered: ");
            scanf("%x", &value);
            printf("Enter the number of words to write: ");
            scanf("%x", &size);
            Write(location, value, size);
        }
        else if (strcmp(user_input, "invert") == 0)
        {
            invert();
        }
        else if (strcmp(user_input, "exit") == 0)
        {
	    mem_free();
            exit(0);
        }
        // else
        // {
        //     printf("Invalid input. Enter help for available commands.\n>>");
        // }*/
    }
}
