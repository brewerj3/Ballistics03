#include <stdio.h>

#include "BallisticCalc.h"

int main() {
    printf("Angle   |  Range\n");
    printf("Degrees |    Meters     |   Yards\n");
    double temp = 0;
    for (int i = 10; i <= 45; i = i + 5) {
        temp = calculateRangeMetric((16 * 0.0254), i, 762, 1225);
        printf("   %i   |   %5.2f    |   %5.2f \n", i, temp, (temp * 1.09361));
    }
    return 0;
}
