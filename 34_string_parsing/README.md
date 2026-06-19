# Exercise 34 – String Parsing and Number Conversion

## Topic
Strings – Parsing & Conversion

## Objective
Convert between strings and numeric types, and parse simple structured string data.

## Instructions

1. Create `string_parsing.c`. Use `<stdlib.h>` and `<string.h>`.

2. **Part A – String to Number**:
   - Use `atoi`, `atof`, `strtol`, `strtod` to parse these strings: `"42"`, `"3.14"`, `"-100"`, `"0xFF"` (hex), `"99abc"` (partial).
   - Print each result and, for `strtol`/`strtod`, print the unconverted remainder.

3. **Part B – Number to String**:
   - Use `sprintf` to convert `int`, `float`, `double` values to strings.
   - Print the resulting strings.

4. **Part C – CSV Parser**:
   - Given the string: `"Alice,30,Berlin,3.8"`.
   - Use `strtok` to split by `','`.
   - Store tokens into:  
     `char name[50]; int age; char city[50]; float gpa;`
   - Convert `age` and `gpa` using `atoi`/`atof`.
   - Print all extracted fields.

## Expected Output (example)
```
atoi("42")       = 42
atof("3.14")     = 3.140000
strtol("0xFF",16)= 255
strtol("99abc")  = 99, remainder: "abc"
sprintf int:     "age=25"
CSV parse: name=Alice age=30 city=Berlin gpa=3.80
```

## Hints
- `strtol(str, &end, base)` — set base to 0 for auto-detection (0x = hex, 0 = octal).
- Prefer `strtol`/`strtod` over `atoi`/`atof` for production code — they report errors.
- `sprintf(buf, "%d", value)` writes to a char buffer.
