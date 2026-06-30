# cmd_args – Kommandozeilenargumente in C

## Grundkonzept

Jedes C-Programm kann beim Aufruf Argumente aus dem Terminal empfangen.
Dazu muss `main` mit zwei Parametern deklariert werden:

```c
int main(int argc, char *argv[])
```

| Parameter | Bedeutung |
|---|---|
| `argc` | **Arg**ument **C**ount — Anzahl der Argumente (inklusive Programmname) |
| `argv` | **Arg**ument **V**ector — Array von Strings mit den einzelnen Argumenten |

---

## Abschnitt 1 — Was sind argc und argv?

```
./programm Hallo Welt
```

| Index | Wert |
|---|---|
| `argv[0]` | `"./programm"` — immer der Programmname |
| `argv[1]` | `"Hallo"` |
| `argv[2]` | `"Welt"` |
| `argc` | `3` |

> `argc` ist immer mindestens 1, weil `argv[0]` (der Programmname) immer vorhanden ist.

---

## Abschnitt 2 — Argumente umwandeln — atoi & atof

`argv`-Einträge sind **immer Strings** (`char *`), auch wenn eine Zahl übergeben wird.
Für Berechnungen müssen sie erst umgewandelt werden:

```c
#include <stdlib.h>

int    x = atoi(argv[1]);   // String → int    ("42"   → 42)
double y = atof(argv[1]);   // String → double ("3.14" → 3.14)
```

---

## Abschnitt 3 — Argumente prüfen

Immer prüfen ob die erwartete Anzahl an Argumenten übergeben wurde:

```c
if (argc != 3) {
    fprintf(stderr, "Verwendung: %s <Zahl1> <Zahl2>\n", argv[0]);
    return 1;
}
```

- Fehlermeldungen gehören auf `stderr` (nicht `stdout`)
- `argv[0]` im Fehlertext verwenden — zeigt den tatsächlichen Programmnamen
- Mit `return 1` (Exit-Code ≠ 0) signalisiert das Programm einen Fehler

---

## Abschnitt 4 — Operator als char lesen

Ein einzelnes Zeichen aus einem Argument liest man so:

```c
char op = argv[2][0];   // erstes Zeichen des dritten Arguments
```

Dann kann man mit `switch` darauf reagieren:

```c
switch (op) {
    case '+': ergebnis = a + b; break;
    case '-': ergebnis = a - b; break;
    default:
        fprintf(stderr, "Unbekannter Operator '%c'\n", op);
        return 1;
}
```

---

## Aufgaben

| Aufgabe | Thema |
|---|---|
| `01_grundlagen` | argc/argv ausgeben |
| `02_zahlen` | atoi/atof — Zahlen aus Argumenten lesen |
| `03_validierung` | Argumente prüfen, stderr, return 1 |
| `04_taschenrechner` | Kombination aller Konzepte |
