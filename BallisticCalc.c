#include <math.h>
#include <stdio.h>

#include "BallisticCalc.h"

const double gravitationalAcceleration = -9.8;
const unsigned passesPerSecond = 1000;
const double airDensity = 1.204;
const double dragCoefficiant = 0.186;

double calculateRangeMetric(double shellDiameterInMeters, double angleOfGunDegree, double muzzleVelocityMeterPerSecond,
                            double massOfShellKilograms) {
    // Calculate Constants
    const double forceOfGravity = gravitationalAcceleration * massOfShellKilograms;
    const double shellArea = (3.14159265358979323846) * ((shellDiameterInMeters / 2) * (shellDiameterInMeters / 2));

    double currentVelocity = muzzleVelocityMeterPerSecond;
    double forceOfAirOnShell = 0;
    double currentShellAngleRadians = angleOfGunDegree * (3.14159265358979323846 / 180);
    unsigned currentTimeMilliseconds = 0;

    // Current Position of Shell
    double currentXAxisPosition = 0;
    double currentYAxisPosition = 0;

    // Next Position of Shell
    double nextXAxisPosition = 0;
    double nextYAxisPosition = 0;

    // Velocity by axis
    double xAxisVelocity = 0;
    double yAxisVelocity = 0;

    // Acceleration by axis
    double xAxisAcceleration = 0;
    double yAxisAcceleration = 0;

    // Force by axis
    double xAxisForce = 0;
    double yAxisForce = 0;

    // Change in Velocity by axis
    double deltaX = 0;
    double deltaY = 0;

    unsigned test = 0;

    // Loop to find range
    while ((currentYAxisPosition >= 0) && (currentTimeMilliseconds < (120 * passesPerSecond))) {
        // Find force of air on shell
        forceOfAirOnShell = -(((0.5) * dragCoefficiant * airDensity * shellArea *
                               ((currentVelocity) * (currentVelocity))));

        // Find force in both axis
        xAxisForce = (cos(currentShellAngleRadians) * forceOfAirOnShell);
        yAxisForce = (sin(currentShellAngleRadians) * forceOfAirOnShell) + (forceOfGravity);

        // Find acceleration in both axis
        xAxisAcceleration = (xAxisForce / massOfShellKilograms) / passesPerSecond;
        yAxisAcceleration = (yAxisForce / massOfShellKilograms) / passesPerSecond;

        // Find velocity in both axis
        xAxisVelocity = ((cos(currentShellAngleRadians) * currentVelocity) + xAxisAcceleration);
        yAxisVelocity = ((sin(currentShellAngleRadians) * currentVelocity) + yAxisAcceleration);

        // Find change in velocity for both axis
        deltaX = ((cos(currentShellAngleRadians) * currentVelocity) / passesPerSecond + xAxisAcceleration);
        deltaY = ((sin(currentShellAngleRadians) * currentVelocity) / passesPerSecond + yAxisAcceleration);

        // Update the position
        currentXAxisPosition = currentXAxisPosition + deltaX;
        currentYAxisPosition = currentYAxisPosition + deltaY;

        // Update current velocity
        currentVelocity = fabs(sqrt(((xAxisVelocity) * (xAxisVelocity) + (yAxisVelocity) * (yAxisVelocity))));

        // Update current shell angle
        currentShellAngleRadians = atan((yAxisVelocity / xAxisVelocity));

        /* Check if 10 seconds have passed
        test = ((currentTimeMilliseconds%passesPerSecond) );
        if((test == 0) && (currentTimeMilliseconds > passesPerSecond)) {
            printf("%5.2f  |  %5.2f    |  %d\n",currentXAxisPosition, currentYAxisPosition, currentTimeMilliseconds/passesPerSecond);
        }
         */
        // Update current time in milliseconds
        currentTimeMilliseconds++;

        //printf("Time: [%5f]  | X: [%5.2f]  | Y:  [%5.2f] | Angle  [%5.2f]  | Drag: [%5.4f]  |X-Axis acceleration: [%5.4f]  | Y-Axis acceleration: [%5.4f]  | Current Velocity [%5.4f]\n",(currentTimeMilliseconds/passesPerSecond),currentXAxisPosition,currentYAxisPosition,currentShellAngleRadians,forceOfAirOnShell,xAxisAcceleration,yAxisAcceleration,currentVelocity);
    }
    return currentXAxisPosition;
}