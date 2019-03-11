#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "set_pattern.h"
#include "verify_pattern.h"

extern int32_t *ptr;
extern int32_t mem_size;

void verify_pattern()
{
    clock_t t; 
    t = clock(); 
    int error = 0;
    
    int32_t *malloc_step = ptr + (sizeof(int32_t)*(location-1)); //step @ starting location passed into function
    int32_t *final_location = malloc_step + (sizeof(int32_t)*size); //final location = step + size of the passed in value

    for (; malloc_step < final_location; (malloc_step += sizeof(int32_t)))
    {
            int32_t value = my_rand(mem_size, (intptr_t)(malloc_step));
            printf("At %x - Value written : %x\tValue read: %x\n", (int32_t)(intptr_t)(malloc_step), value, *((int32_t *)(malloc_step)));
            if (*((int32_t *)(malloc_step)) != value)
            {
                error++;
            }
    }
    printf("Number of errors after verification: %d\n", error);
    t = clock() - t; 		//end time - start time
    double time_taken = ((double)t)/CLOCKS_PER_SEC*1000; // in microseconds
    
    printf("Time taken to verify pattern = %f milliseconds\n>>", time_taken);
}