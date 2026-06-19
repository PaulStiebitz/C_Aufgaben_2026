# Exercise 19 – Structs: Nested Structs & Arrays of Structs

## Topic
Structs (Nested)

## Objective
Use nested structs and arrays of structs to model more complex data.

## Instructions

1. Create `nested_structs.c`.

2. Define:
   ```c
   typedef struct {
       int day;
       int month;
       int year;
   } Date;

   typedef struct {
       char title[100];
       char author[60];
       int pages;
       Date published;
       float price;
   } Book;
   ```

3. Implement:
   - `void print_date(const Date *d);` – prints as `DD.MM.YYYY`.
   - `void print_book(const Book *b);` – prints all fields including the date.
   - `Book most_expensive(const Book *books, int n);` – returns the most expensive book.
   - `void sort_by_pages(Book *books, int n);` – sorts the array by `pages` ascending (use any sort).

4. In `main`, create an array of 4 books, print them, find the most expensive, and print sorted by pages.

## Expected Output (example)
```
[1] "The C Programming Language" by K&R, 272 pages, 01.01.1988, €29.99
[2] "Clean Code" by R. Martin,   464 pages, 01.08.2008, €39.95
...
Most expensive: "Clean Code" (€39.95)
Sorted by pages:
  "The C Programming Language" (272)
  ...
```

## Hints
- Access nested fields with `book.published.year` or `ptr->published.year`.
- You can initialize a `Book` with a compound literal: `Book b = {"Title", "Author", 200, {1,1,2000}, 19.99};`
