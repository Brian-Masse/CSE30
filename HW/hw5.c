#include <stdio.h>

unsigned int fp_convert(unsigned int fp) {
    unsigned int converted_fp = ~0;
    
    
    printf( "original: %.8x\n", fp );
    
    return converted_fp;
}

int main() {

    unsigned int fp = 0xa6;
    
    unsigned int exp = fp & 0b01110000;
    unsigned int sign = fp & 0b10000000;
    unsigned int mantissa = fp & 0b00001111;

    exp = exp >> 4;
    if (exp == 0) {
        exp = 1;
        while ((mantissa & 0b10000) == 0) {
            mantissa = mantissa << 1;
            exp -= 1;
        }
        
        mantissa = mantissa & 0b00001111;
    }
    
    exp += 124;   

    exp = exp << 23;
    sign = sign << 24;
    mantissa = mantissa << 19;    

    unsigned int converted_fp = sign + exp + mantissa;

    printf( "%.8x\n", converted_fp );
    
    return converted_fp;
}