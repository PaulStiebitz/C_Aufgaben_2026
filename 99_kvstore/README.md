# Exercise 99 – All-Topics: In-Memory Key-Value Store

## Topic
All Topics – Applied Capstone

## Objective
Build a persistent in-memory key-value store (like a minimal Redis) that supports multiple value types, TTL expiry, file persistence, and a CLI interface.

---

## Instructions

1. Create `kvstore.c`.

2. **Value types**:
   ```c
   typedef enum { KV_STRING, KV_INT, KV_FLOAT, KV_LIST } KVType;
   typedef struct ListItem { char val[64]; struct ListItem *next; } ListItem;
   typedef union {
       char       str[128];
       int        i;
       float      f;
       ListItem  *list;
   } KVData;
   typedef struct {
       char   key[64];
       KVType type;
       KVData data;
       int    ttl;    /* -1 = no expiry, >0 = decremented each operation */
   } KVEntry;
   ```

3. **Store**:
   ```c
   #define STORE_CAP 64
   typedef struct { KVEntry entries[STORE_CAP]; int count; } KVStore;
   ```

4. **Supported commands** (parse from `argv` or REPL):
   | Command | Example | Effect |
   |---------|---------|--------|
   | `SET key value` | `SET name Alice` | Store string |
   | `SETI key int` | `SETI count 42` | Store int |
   | `SETF key float` | `SETF pi 3.14` | Store float |
   | `GET key` | `GET name` | Retrieve value |
   | `DEL key` | `DEL name` | Delete entry |
   | `EXISTS key` | `EXISTS name` | 1 or 0 |
   | `TTL key n` | `TTL count 5` | Set expiry to n ops |
   | `LPUSH key val` | `LPUSH fruits apple` | Prepend to list |
   | `LRANGE key` | `LRANGE fruits` | Print all list items |
   | `KEYS` | `KEYS` | List all keys |
   | `SAVE file` | `SAVE db.kv` | Write store to binary file |
   | `LOAD file` | `LOAD db.kv` | Load store from file |

5. **TTL**: on each `GET`, decrement TTL; at 0, auto-delete.

6. In `main`: implement a simple REPL that reads commands from `stdin`.

---

## Example Session
```
> SET name Alice
OK

> SETI age 30
OK

> GET name
"Alice"

> GET age
(int) 30

> TTL name 3
TTL set to 3 for "name"

> GET name   <- TTL: 2
"Alice"
> GET name   <- TTL: 1
"Alice"
> GET name   <- TTL: 0 -> deleted
(nil)

> LPUSH fruits apple
> LPUSH fruits banana
> LRANGE fruits
0) banana
1) apple

> KEYS
age  fruits

> SAVE store.kv
Saved 2 entries.

> exit
```

---

## Hints
- Linear scan for key lookup is fine for ≤64 entries.
- `SAVE`/`LOAD`: write the count + each `KVEntry` struct (for `KV_LIST`, write the count of items + each string).
- TTL decrement: add a `kv_tick(KVStore*)` function called on every `GET`.
- For the REPL: split the input line into tokens with `strtok`, dispatch on the first token.
