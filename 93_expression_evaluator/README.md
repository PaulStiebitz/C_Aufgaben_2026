# Exercise 93 – Expression Evaluator (Stack-Based)

## Topic
Stacks + Strings + Structs + Algorithms

## Objective
Implement a **Reverse Polish Notation (RPN)** evaluator and a **shunting-yard** algorithm to convert infix to RPN, then evaluate.

---

## Instructions

1. Create `expr_eval.c`.

2. **Part A – RPN Evaluator**:
   - Implement a float stack.
   - Write `double eval_rpn(const char *expr)`:
     - Tokenise by spaces.
     - If token is a number: push.
     - If token is an operator (`+`,`-`,`*`,`/`): pop two operands, apply, push result.
   - Test: `"3 4 +"` → 7, `"5 1 2 + 4 * + 3 -"` → 14.

3. **Part B – Infix to RPN (Shunting-Yard)**:
   Implement `int infix_to_rpn(const char *infix, char *rpn_out, size_t out_size)`:
   - Use an operator stack (array-based, char stack).
   - Rules:
     - Number → output immediately.
     - `(` → push onto operator stack.
     - `)` → pop to output until matching `(`.
     - Operator: pop operators of **higher or equal precedence** from stack to output first, then push this operator.
     - Precedence: `*`, `/` = 2; `+`, `-` = 1.
   - Return 0 on success, -1 on error (mismatched parens).

4. **Part C – Full pipeline**:
   - Write `double eval_infix(const char *expr)` that calls `infix_to_rpn` then `eval_rpn`.

5. Test all three expressions:
   - `"3 + 4"`
   - `"3 + 4 * 2"`   (multiplication has higher precedence)
   - `"(3 + 4) * 2"` (parentheses override precedence)
   - `"10 / 2 - 3 * 1 + 5"`

---

## Expected Output
```
=== RPN Evaluation ===
"3 4 +"              = 7.00
"5 1 2 + 4 * + 3 -"  = 14.00

=== Infix to RPN ===
"3 + 4"          -> "3 4 +"
"3 + 4 * 2"      -> "3 4 2 * +"
"( 3 + 4 ) * 2"  -> "3 4 + 2 *"

=== eval_infix ===
"3 + 4"          = 7.00
"3 + 4 * 2"      = 11.00
"( 3 + 4 ) * 2"  = 14.00
"10 / 2 - 3 * 1 + 5" = 7.00
```

---

## Hints
- Tokenise infix expression by spaces (caller must space-separate tokens: `"3 + 4"` not `"3+4"`).
- The operator stack is a `char stack[64]; int top = 0;`
- `precedence('+') = 1`, `precedence('*') = 2` — implement as a switch or if-chain.
- Division by zero check: if divisor is `0.0`, print error and return `NaN` or `0.0`.
