/******************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char *ptr = NULL;
int32_t mem_size = 8;

void do_malloc(int n);
void Write(int location, int value, int size);
void flippy_bits(void);

int main () {
    do_malloc(2);
    int some_hex = 0x33333333;
    do_malloc(mem_size);
    Write(1, (some_hex), mem_size);
    
    flippy_bits();
    printf("second call\n");
    flippy_bits();
    
    //printf("malloc pointer location %x", ptr);
   
   return(0);
}

void do_malloc(int32_t n)
{
    
    if (ptr != NULL)
    {
        free(ptr);
        printf("Old Malloc destroyed.\n\r");
    }
    

   /* Initial memory allocation */
   ptr = (void *) malloc(n*sizeof(int32_t));
   if (ptr == NULL)
   {
       printf("Malloc failed");
   }
   printf("Address = %x\n", ptr);
}

void Write(int location, int value, int size)
{

    void *value_ptr = &value; //pointer to user value to write
    void *malloc_step = ptr + 32*(location-1); //step @ starting location passsed into function
    void *final_location = malloc_step + 32*size - 8; //final location = step + size of the passed in value
    
    /*printf("Value size = %x\n", value);
    printf("Step Address = %x\n", malloc_step);
    printf("Final location = %x\n", final_location);*/
    

    /* Copy value of passed int to the passed location
    * value of memory pointer + (# of 32-bit words * 4), step malloc_step by 4 bits, until size of passed int
    * Copy 8 bits into malloc_step from value*/
    for (malloc_step; malloc_step <= final_location; (malloc_step += sizeof(char)))
    {
        memcpy(malloc_step, value_ptr, 1);
        //value_ptr += sizeof(char);
    }
    
    //malloc_step = ptr + 32*(location-1);
    
     //printf("value written = %x\n", *((int32_t *)(malloc_step)));
     //printf("write location = %x\n", malloc_step);
    
    
    /*value_ptr = &value;
    malloc_step = ptr + 32*location;
    final_location = malloc_step + 32*size;
    
    for (malloc_step; malloc_step <= (final_location + 4); (malloc_step += 4))
    {
       //printf("%x @ address %x, compared to %x @ %x\n", *((int *)malloc_step), malloc_step, *((int*)value_ptr), value_ptr);
        value_ptr += 4;
    }*/
}

void flippy_bits(void)
{
    int32_t mem_inverse = 0; //dereferencing 32 bits of memory

    void *inverse_ptr = &mem_inverse;
    
    for (int i = 0; (i <= 32*(mem_size-1)); (i = i + 32))
    {
        //printf("value at flip = %x\n", *((int32_t *)(ptr+i)));
        mem_inverse = *((int32_t *)(ptr + i));
        //printf("mem_inverse = %x\n", mem_inverse);
        mem_inverse = ~mem_inverse;
       
        memcpy((ptr+i), inverse_ptr, 4);
       printf("value at flip = %x\n", *((int32_t *)(ptr+i)));
       printf("flip location = %x\n", (ptr+i));
       
    }
}