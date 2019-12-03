#include "mbed.h"
#include <math.h>  

AnalogIn ain(A2);
Serial pc(USBTX, USBRX);


float R1 = 1000;
double logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;



int main()
{
    while(1) {
    
        wait(1); // 1 second
        
        float v = ain.read();
        float vd = (3.3f / (v * 3.3f)) - 1;
        float fvd = vd * 10;
        int temperature = -23.87f*log(fvd) + 80.659;
        
        printf("%d\n", temperature);

        R2 = R1 * (1023.0 / (float)v - 1.0);
        
        logR2 = log(R2);
        T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
        T = T - 273.15;
        
    }
}
