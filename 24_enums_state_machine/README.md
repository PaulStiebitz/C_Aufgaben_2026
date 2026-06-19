# Exercise 24 – Enums: State Machine

## Topic
Enums

## Objective
Use an `enum` to model the states of a simple Finite State Machine (FSM) for a traffic light.

## Instructions

1. Create `state_machine.c`.

2. Define the states:
   ```c
   typedef enum { RED, RED_YELLOW, GREEN, YELLOW } TrafficLight;
   ```

3. Implement:
   - `TrafficLight next_state(TrafficLight current);`
     Returns the next state in the cycle: RED → RED_YELLOW → GREEN → YELLOW → RED → ...
   - `const char* state_name(TrafficLight s);`
     Returns the human-readable name.
   - `int state_duration(TrafficLight s);`
     Returns duration in seconds: RED=30, RED_YELLOW=3, GREEN=25, YELLOW=4.

4. In `main`:
   - Start at `RED`.
   - Simulate 8 state transitions, printing the current state name, duration, and transition arrow.

## Expected Output
```
[1] RED        (30s) ->
[2] RED_YELLOW ( 3s) ->
[3] GREEN      (25s) ->
[4] YELLOW     ( 4s) ->
[5] RED        (30s) ->
[6] RED_YELLOW ( 3s) ->
[7] GREEN      (25s) ->
[8] YELLOW     ( 4s)
```

## Hints
- A `switch` statement on the enum value is the cleanest approach for `next_state`.
- Add a `default` case to `switch` statements to catch unexpected values.
- Enums are integers at runtime — you could also use `(current + 1) % 4` with sequential values.
