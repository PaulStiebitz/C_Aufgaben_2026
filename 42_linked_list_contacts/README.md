# Exercise 42 – Linked List of Structs: Contact Book

## Topic
Linked Lists + Structs + Strings

## Objective
Build a contact book stored as a singly linked list of `Contact` structs, with CRUD operations.

## Instructions

1. Create `contacts.c`.

2. Define:
   ```c
   typedef struct Contact {
       char           name[50];
       char           phone[20];
       char           email[60];
       struct Contact *next;
   } Contact;
   ```

3. Implement:
   - `Contact* contact_create(const char *name, const char *phone, const char *email);`
   - `Contact* contact_add(Contact *head, const char *name, const char *phone, const char *email);`
     Inserts in **alphabetical order by name**.
   - `void contact_print_all(const Contact *head);`
   - `Contact* contact_find(Contact *head, const char *name);`
   - `Contact* contact_delete(Contact *head, const char *name);`
   - `void contact_free_all(Contact *head);`

4. In `main`:
   - Add contacts: Bob, Alice, Diana, Charlie.
   - Print (should be alphabetically sorted).
   - Find "Alice" — print her phone number.
   - Delete "Bob".
   - Print again.

## Expected Output
```
--- All Contacts ---
[Alice]   📞 555-0101  ✉ alice@example.com
[Bob]     📞 555-0102  ✉ bob@example.com
[Charlie] 📞 555-0103  ✉ charlie@example.com
[Diana]   📞 555-0104  ✉ diana@example.com

Found Alice: 555-0101
Deleted Bob.

--- All Contacts ---
[Alice]   📞 555-0101  ✉ alice@example.com
[Charlie] 📞 555-0103  ✉ charlie@example.com
[Diana]   📞 555-0104  ✉ diana@example.com
```

## Hints
- `strcmp` for comparison, `strncpy` for copying string fields.
- Sorted insertion: traverse until `strcmp(current->name, new->name) > 0`, then insert before.
