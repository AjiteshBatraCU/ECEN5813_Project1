#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "set_pattern.h"

extern int32_t *ptr;
extern int32_t mem_size;


void set_pattern()
{
    clock_t t; 
    t = clock(); 
    printf("Which of the %d memory words would you like to start at : ", mem_size);
    scanf("%x", &location);
    printf("Enter the number of words to write: ");
    scanf("%x", &size);

    int32_t *malloc_step = ptr + (sizeof(int32_t)*(location-1)); //step @ starting location passed into function
    int32_t *final_location = malloc_step + (sizeof(int32_t)*size); //final location = step + size of the passed in value

    for (; malloc_step < final_location; (malloc_step += sizeof(int32_t)))
    {
            int32_t value = my_rand(mem_size, (intptr_t)(malloc_step));
            void *value_ptr = &value; //pointer to user value to write
            memcpy(malloc_step, value_ptr, 4);
            printf("\naddress: %x ", (int32_t)(intptr_t)(malloc_step));
            printf("Memory copied = %x", *((int32_t *)(malloc_step)));
    }
    t = clock() - t; 		//end time - start time
    double time_taken = ((double)t)/CLOCKS_PER_SEC*1000; // in microseconds
    
    printf("\nTime taken to set pattern = %f milliseconds\n>>", time_taken);
}

int32_t my_rand(int32_t seed, int32_t addr)
{
    int32_t next;
    next = seed;
    for(int i=1; i<=mem_size; i++)
    {
        next = ((((next*(297121507398+addr*addr)) + (837698981293)))/21474836648)%4294967296;
    }
    return next;
}

