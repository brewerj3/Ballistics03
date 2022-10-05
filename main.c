
#include <stdio.h>

#include "BallisticCalc.h"

int main() {
    printf("16""/50 Mark 7\n");
    printf("Angle   |   Range\n");
    printf("Degrees |   Meters      |   Yards\n");
    double temp = 0;
    for(int i = 10; i<=45;i=i+5) {
        temp = calculateRangeMetric((16 * 0.0254), i, 762, 1225 );
        printf("   %i   |   %5.2f    |   %5.2f \n",i, temp,(temp*1.09361));
    }
    printf("\n12""/50 Mark 18 \n");
    printf("Angle   |   Range\n");
    printf("Degrees |   Meters      |   Yards\n");
    temp = 0;
    for(int i = 10; i<=45;i=i+5) {
        temp = calculateRangeMetric((12 * 0.0254), i, 762, 517.093);
        printf("   %i   |   %5.2f    |   %5.2f \n",i, temp,(temp*1.09361));
    }
    printf("\n8/55 Mark 16 \n");
    printf("Angle   |   Range\n");
    printf("Degrees |   Meters      |   Yards\n");
    temp = 0;
    for(int i = 10; i<=41;i=i+5) {
        temp = calculateRangeMetric((8 * 0.0254), i, 762, 152);
        printf("   %i   |   %5.2f    |   %5.2f \n",i, temp,(temp*1.09361));
    }
    printf("\n5/38 Mark 12 \n");
    printf("Angle   |   Range\n");
    printf("Degrees |   Meters      |   Yards\n");
    temp = 0;
    for(int i = 10; i<=41;i=i+5) {
        temp = calculateRangeMetric((5 * 0.0254), i, 762, 25);
        printf("   %i   |   %5.2f    |   %5.2f \n",i, temp,(temp*1.09361));
    }
    return 0;
}
