#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    int maxIntVal = INT_MAX;
    float maxFloatVal = FLT_MAX;
    double maxDoubleVal = DBL_MAX;
    printf("Int max value - %d \nFloat max value - %f \nDouble max value - %lf\n", maxIntVal, maxFloatVal, maxDoubleVal);
    printf("Int size - %lu \nFloat size - %lu \nDouble size - %lu", sizeof(maxIntVal), sizeof(maxFloatVal), sizeof(maxDoubleVal));
    return 0;
}