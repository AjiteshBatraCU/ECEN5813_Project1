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

void Write(int location, int value, int size)
{

    void *value_ptr = &value; //pointer to user value to write
    void *malloc_step = ptr + (sizeof(uint32_t)*(location-1)); //step @ starting location passsed into function
    void *final_location = malloc_step + (sizeof(uint32_t)*size); //final location = step + size of the passed in value

    /* Copy value of passed value to the passed location
    * value of memory pointer + (# of 32-bit words * 4), step malloc_step by 4 bits, until size of passed int
    * Copy 8 bits into malloc_step from value*/
    for (malloc_step; malloc_step < final_location; (malloc_step += sizeof(int32_t)))
    {
        memcpy(malloc_step, value_ptr, 4);
            printf("address: %x ", malloc_step);
            printf("Memory copied = %x\n", *((int32_t *)(malloc_step)));
    }
}
