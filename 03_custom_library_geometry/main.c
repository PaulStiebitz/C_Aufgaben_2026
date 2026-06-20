#include <stdio.h>
#include "geometry.h"


int main(void) {
    // circle
    double r = 5.0;

    // rectangle
    int width = 4;
    int height = 6;
    
    // triangle
    int b = 3;
    int h = 4;

    printf("Circle  r=%f : area=%f, circumference=%f\n", r, circle_area(r), circle_circumference(r));
    printf("Rect    %dx%d : area=%f, perimeter=%f\n", width, height, rect_area(width, height), rect_perimeter(width, height));
    printf("Triangle  b=%f,h=%d : area=%f\n", b, h, triangle_area(b, h));

    return 0;
}

