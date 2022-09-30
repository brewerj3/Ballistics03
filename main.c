
#include <stdio.h>
#include <math.h>

#include "BallisticCalc.h"

int main() {
    //printf("Range in Meters    = %5.2f \n",calculateRangeMetric((16 * 0.0254), 40, 762, 1225 ));
    printf("Angle  |  Range\n");
    for(int i = 10; i<=45;i=i+5) {
        printf("   %i  |   %5.2f \n",i, calculateRangeMetric((16 * 0.0254), i, 762, 1225 ));
    }
    return 0;
}
