#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;
    printf("Data.i: %d\n", data.i);

    data.f = 220.5;
    printf("Data.f: %.2f\n", data.f);

    strcpy(data.str, "Hello, Union!");
    printf("Data.str: %s\n", data.str);

    // Note: Printing data.i or data.f here would give unexpected results
    // since data.str overwrites their memory space.
    return 0;
}