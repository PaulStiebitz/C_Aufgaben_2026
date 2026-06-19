# Exercise 03 – Create a Geometry Library

## Topic
Custom Libraries (`.h` / `.c`)

## Objective
Practice separating interface from implementation by building a geometry library that handles circles, rectangles, and triangles.

## Instructions

1. Create `geometry.h` with include guards and declare:
   - `double circle_area(double radius);`
   - `double circle_circumference(double radius);`
   - `double rect_area(double width, double height);`
   - `double rect_perimeter(double width, double height);`
   - `double triangle_area(double base, double height);`
   - `double triangle_hypotenuse(double a, double b);`

2. Define the constant `PI` as a macro in the header: `#define PI 3.14159265358979`

3. Implement all functions in `geometry.c`.

4. Write a `main.c` that calls each function and displays the results formatted to 2 decimal places.

5. Compile separately and link.

## Expected Output (example)
```
Circle   r=5.00 : area=78.54, circumference=31.42
Rect     4x6    : area=24.00, perimeter=20.00
Triangle b=3,h=4: area=6.00,  hypotenuse=5.00
```

## Hints
- `<math.h>` provides `sqrt()`. Link with `-lm`: `gcc ... -lm`.
- Keep `PI` only in the header so both files share the same value.
