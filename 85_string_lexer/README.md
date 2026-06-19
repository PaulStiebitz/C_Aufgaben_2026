# Exercise 85 – String Tokenizer / Lexer

## Topic
Strings + Pointers + Structs + Enums

## Objective
Build a simple lexer/tokenizer that breaks a mathematical expression string into typed tokens — the foundation of any interpreter or compiler.

---

## Instructions

1. Create `lexer.c`.

2. Define token types:
   ```c
   typedef enum {
       TOK_NUMBER,    /* integer or float literal */
       TOK_PLUS,      /* + */
       TOK_MINUS,     /* - */
       TOK_STAR,      /* * */
       TOK_SLASH,     /* / */
       TOK_LPAREN,    /* ( */
       TOK_RPAREN,    /* ) */
       TOK_IDENT,     /* variable name: [a-zA-Z][a-zA-Z0-9_]* */
       TOK_EOF,       /* end of input */
       TOK_UNKNOWN    /* unrecognised character */
   } TokenType;

   typedef struct {
       TokenType   type;
       char        lexeme[32];  /* raw text of the token */
       double      number;      /* numeric value if TOK_NUMBER */
   } Token;
   ```

3. Implement:
   ```c
   /* Tokenise the input string; fill tokens[] array; return count */
   int tokenise(const char *input, Token *tokens, int max_tokens);

   /* Print a token */
   void token_print(const Token *t);

   /* Return the name of a token type as a string */
   const char* token_type_name(TokenType t);
   ```

4. Tokenizer rules:
   - Skip whitespace.
   - On a digit or `.`: accumulate a number, convert with `strtod`.
   - On a letter: accumulate an identifier (letters/digits/underscore).
   - On `+`,`-`,`*`,`/`,`(`,`)`: emit single-char token.
   - On `\0`: emit `TOK_EOF`.
   - Anything else: emit `TOK_UNKNOWN`.

5. In `main`, tokenise these strings and print the token stream:
   - `"3 + 4 * (2 - 1)"`
   - `"x * 3.14 + y / 2"`
   - `"hello + world"`

---

## Expected Output
```
Input: "3 + 4 * (2 - 1)"
[NUMBER  "3"     3.00]
[PLUS    "+"         ]
[NUMBER  "4"     4.00]
[STAR    "*"         ]
[LPAREN  "("         ]
[NUMBER  "2"     2.00]
[MINUS   "-"         ]
[NUMBER  "1"     1.00]
[RPAREN  ")"         ]
[EOF                 ]

Input: "x * 3.14 + y / 2"
[IDENT   "x"         ]
[STAR    "*"         ]
[NUMBER  "3.14"  3.14]
...
```

---

## Hints
- Use a `const char *pos` pointer that advances through the input.
- A `while (*pos == ' ') pos++;` loop skips whitespace.
- `isdigit(*pos)` or `*pos == '.'` detects the start of a number.
- `isalpha(*pos)` detects the start of an identifier.
