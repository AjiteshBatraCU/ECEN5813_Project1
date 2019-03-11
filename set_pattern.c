#include <stdio.h>

extern char *ptr;
extern int32_t mem_size;

void my_rand(int seed)
{
   
    for(int i=1; i<=mem_size; i++)
    {
        int rand = ((((seed*2971215073) + (837659))*i)/65536);
        printf("number = %d\n",rand);
    }
}

void set_pattern(void)
{
    my_rand(21);
}