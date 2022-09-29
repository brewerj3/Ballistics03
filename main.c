
#include <stdio.h>

#include "BallisticCalc.h"

int main() {
    //calculateRangeMetric((16 * 0.0254), 25, 762, 1225 );
    printf("test\n");
    for(int i = 10; i<=45;i = i+5) {
        printf("Range in Meters    = %5.2f \n",calculateRangeMetric((16 * 0.0254), i, 762, 1225 ));
    }
    return 0;
}
