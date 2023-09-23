#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    int a0 =  (*reg) & 1;
    int a2 =  ((*reg)>>2) & 1;
    int a3 =  ((*reg)>>3) & 1;
    int a5 =  ((*reg)>>5) & 1;
    int m = ((a0^a2)^a3)^a5 ;
    //printf("%d",a2);
    (*reg) = (*reg) >> 1 | m << 15;    
}

