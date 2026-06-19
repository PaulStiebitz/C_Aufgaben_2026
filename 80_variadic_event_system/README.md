# Exercise 80 – Variadic Functions: Event System

## Topic
Variadic Functions + Function Pointers + Structs

## Objective
Build a simple publish/subscribe event system where event handlers are registered with a name and called with variadic payloads.

---

## Instructions

1. Create `events.c`.

2. Define:
   ```c
   typedef void (*EventHandler)(const char *event_name, va_list args);

   typedef struct {
       char         name[32];
       EventHandler handlers[8];
       int          handler_count;
   } Event;

   typedef struct {
       Event events[16];
       int   event_count;
   } EventBus;
   ```

3. Implement:
   ```c
   void bus_init(EventBus *bus);
   int  bus_register(EventBus *bus, const char *event_name, EventHandler handler);
   /* Register a handler for an event. Creates event if first handler. Returns 0 ok, -1 full. */

   void bus_emit(EventBus *bus, const char *event_name, ...);
   /* Finds all handlers for event_name and calls each with (event_name, va_list). */
   ```

4. Define three event handler functions:
   - `void on_user_login(const char *event, va_list args);`
     Expects: `(char *username, int user_id)`.
   - `void on_data_received(const char *event, va_list args);`
     Expects: `(char *data, int length)`.
   - `void on_error(const char *event, va_list args);`
     Expects: `(int error_code, char *message)`.
   Also register a **logger handler** for all three events that simply prints the event name.

5. In `main`:
   ```c
   bus_register(&bus, "user.login",     on_user_login);
   bus_register(&bus, "user.login",     logger_handler);
   bus_register(&bus, "data.received",  on_data_received);
   bus_register(&bus, "error",          on_error);

   bus_emit(&bus, "user.login",    "alice", 42);
   bus_emit(&bus, "data.received", "hello world", 11);
   bus_emit(&bus, "error",         404, "Not Found");
   ```

---

## Expected Output
```
[LOG] event: user.login
[user.login] alice (id=42) logged in.
[LOG] event: data.received
[data.received] 11 bytes: "hello world"
[LOG] event: error
[error] Code 404: Not Found
```

---

## Hints
- Inside `bus_emit`: call `va_start(args, event_name)`, then for each handler call `va_copy(copy, args)`, invoke `handler(event_name, copy)`, then `va_end(copy)`. Finally `va_end(args)`.
- `va_copy` is essential because each handler call consumes the `va_list` state.
- Inside a handler, extract args with `va_arg(args, type)`.
