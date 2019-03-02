#include <stdio.h>

int mem_size = 20;

int my_rand(int seed)
{
    for(int i=1; i<mem_size; i++)
    {
        int rand = ((((seed*2971215073) + (837659))*i)/65536);
        printf("number = %d\n",rand);
    }
}

int main()
{
    my_rand(21);
}