
#include <math.h>
#include <stdio.h>

#include "BallisticCalc.h"

const double gravitationalAcceleration = 9.8;
const double passesPerSecond = 1000;
const double airDensity = 1.225;
const double dragCoefficiant = 0.1774;

double calculateRangeMetric(double shellDiameterInMeters, double angleOfGunDegree, double muzzleVelocityMeterPerSecond, double massOfShellKilograms){
    // Calculate Constants
    const double forceOfGravity = gravitationalAcceleration*massOfShellKilograms;
    const double shellArea = (3.14159265358979323846)*((shellDiameterInMeters/2)*(shellDiameterInMeters/2));

    double currentVelocity = muzzleVelocityMeterPerSecond;
    double forceOfAirOnShell = 0;
    double currentShellAngleRadians = angleOfGunDegree*(3.14159265358979323846/180);
    unsigned currentTimeMilliseconds = 0;

    // Current Position of Shell
    double currentXAxisPosition = 0;
    double currentYAxisPostion = 0;

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

    // Loop to find range
    while(currentYAxisPostion > 0) {
        // Find force of air on shell
        forceOfAirOnShell = -( ( (0.5)*dragCoefficiant*airDensity*shellArea*((currentVelocity)*(currentVelocity))) / passesPerSecond );

        // Find force in both axis
        xAxisForce = ( cos(currentShellAngleRadians) * forceOfAirOnShell);
        yAxisForce = ( sin(currentShellAngleRadians) * forceOfAirOnShell) + (forceOfGravity/passesPerSecond);

        // Find velocity in both axis
        xAxisVelocity = ( (cos(currentShellAngleRadians)*currentVelocity) + xAxisAcceleration );
        yAxisVelocity = ( (sin(currentShellAngleRadians)*currentVelocity) + yAxisAcceleration );

        // Find change in velocity for both axis
        deltaX = ( (cos(currentShellAngleRadians)*currentVelocity)/passesPerSecond + xAxisAcceleration );
        deltaY = ( (sin(currentShellAngleRadians)*currentVelocity)/passesPerSecond + yAxisAcceleration );

        // Update the position
        currentXAxisPosition = currentXAxisPosition + deltaX;
        currentYAxisPostion = currentYAxisPostion + deltaY;

        // Update current velocity
        currentVelocity = fabs( sqrt( ( ( xAxisVelocity)*(xAxisVelocity) + (yAxisVelocity)*(yAxisVelocity)) ) );

        // Update current shell angle
        currentShellAngleRadians = atan((yAxisVelocity/xAxisVelocity));

        // Update current time in milliseconds
        currentTimeMilliseconds++;
    }
    printf("Range in Meters    = %5.2f \n",currentXAxisPosition);
    printf("Final Velocity m/s = %5.2f \n",currentVelocity);

    return currentXAxisPosition;

}