
#include <stdio.h>

#include "BallisticCalc.h"

int main() {
    printf("16""/50 Mark 7\n ");
    printf("Angle   |   Range\n");
    printf("Degrees |   Meters      |   Yards\n");
    double temp = 0;
    for(int i = 10; i<=45;i=i+5) {
        temp = calculateRangeMetric((16 * 0.0254), i, 762, 1225 );
        printf("   %i   |   %5.2f    |   %5.2f \n",i, temp,(temp*1.09361));
    }
    printf("\nAlaska Class 12 inch Gun \n");
    printf("Angle   |   Range\n");
    printf("Degrees |   Meters      |   Yards\n");
    temp = 0;
    for(int i = 10; i<=45;i=i+5) {
        temp = calculateRangeMetric((12 * 0.0254), i, 762, 517.093);
        printf("   %i   |   %5.2f    |   %5.2f \n",i, temp,(temp*1.09361));
    }
    return 0;
}
