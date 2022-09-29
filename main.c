
#include <stdio.h>
#include <math.h>

#include "BallisticCalc.h"

int main() {
    //calculateRangeMetric((16 * 0.0254), 25, 762, 1225 );

    for(int i = 20; i<=45;i = i+5) {
        printf("Angle of Gun in degree %i\n",i);
        printf("Range in Meters    = %5.2f \n",calculateRangeMetric((16 * 0.0254), i, 762, 1225 ));
    }
    return 0;
}
