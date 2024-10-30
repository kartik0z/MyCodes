#include <stdio.h>

#define PI 3.14159

float calculateArea(float radius);
float calculateCircumference(float radius);

int main() {
    float radius, area, circumference;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    if (radius > 25) {
        circumference = calculateCircumference(radius);
        printf("Radius is greater than 25, calculating circumference.\n");
        printf("Circumference of the circle: %.2f\n", circumference);
    } else {
        area = calculateArea(radius);
        printf("Radius is 25 or less, calculating area.\n");
        printf("Area of the circle: %.2f\n", area);
    }

    return 0;
}
float calculateArea(float radius) {
    return PI * radius * radius;
}
float calculateCircumference(float radius) {
    return 2 * PI * radius;
}