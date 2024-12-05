#include <stdio.h>

#define PI 3.14159

double calculateCircleArea(double radius);

int main()
{
    printf("%lf", calculateCircleArea(1.5));
    return 0;
}

double calculateCircleArea(double radius)
{
    return PI * radius * radius;
}