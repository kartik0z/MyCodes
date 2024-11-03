#include <stdio.h>

#define PI 3.14159

// Function prototypes
float calculateArea(float radius);
float calculateCircumference(float radius);

int main() {
    float radius, area, circumference;

    // Input from user
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Function calls
    area = calculateArea(radius);
    circumference = calculateCircumference(radius);

    // Output results
    printf("Area of the circle: %.2f\n", area);
    printf("Circumference of the circle: %.2f\n", circumference);

    return 0;
}

// Function to calculate the area of the circle
float calculateArea(float radius) {
    return PI * radius * radius;
}

// Function to calculate the circumference of the circle
float calculateCircumference(float radius) {
    return 2 * PI * radius;
}