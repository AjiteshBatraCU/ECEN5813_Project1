/***************************************************
* File to write data to memory
* write function takes in which memory word to start
* at (location), how many words to write (size)
* and what data (value)
***************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

extern char *ptr;

void write(int location, int32_t value, int size)
{

    void *value_ptr = &value; //pointer to user value to write
    void *malloc_step = ptr + 32*(location-1); //step @ starting location passed into function
    void *final_location = malloc_step + 32*size - 8; //final location = step + number of words requested
    
    /*printf("Value size = %x\n", value);
    printf("Step Address = %x\n", malloc_step);
    printf("Final location = %x\n", final_location);*/
    

    /* Copy value of passed value to the passed location
    * value of memory pointer + (# of 32-bit words * 4), step malloc_step by 4 bits, until size of passed int
    * Copy 8 bits into malloc_step from value*/
    for (malloc_step; malloc_step <= final_location; (malloc_step += sizeof(char)))
    {
        memcpy(malloc_step, value_ptr, 1);
        value_ptr += sizeof(char);
        if (count++ == 3) 
        {
            value_ptr = &value;
            count = 0;
        }
    }
}
