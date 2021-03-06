#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "help.h"
#include "alloc.h"
#include "free.h"
#include "modify.h"
#include "display.h"
#include "invert.h"
#include "set_pattern.h"
#include "verify_pattern.h"

int32_t *ptr;
int32_t mem_size;

typedef void (*function_ptr)(void);
void functionnotfound(void);
void exitprogram(void);

struct functionlist
{
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
    {"exit", &exitprogram},
    {"pattern", &set_pattern},
    {"verify", &verify_pattern}};

int main()
{
    char c;
    char user_input[15] = {0};

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
        for (int j = 0; j <= 8; j++)
        {
            if (strcmp(user_input, functions[j].string) == 0)
            {
                functions[j].function();
            }
        }
    }
}
    void exitprogram(void)
    {
        exit(0);
    }
