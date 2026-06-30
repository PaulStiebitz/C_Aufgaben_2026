# File Handling in C – Intuitive Übersicht

Kompakte Referenz der wichtigsten File-I/O-Funktionen aus `<stdio.h>`, mit lauffähigem Demo-Code in [`file_handling_overview.c`](file_handling_overview.c).

---

## Kompilieren & Ausführen

```bash
gcc -Wall -Wextra -o file_handling_overview file_handling_overview.c
./file_handling_overview        # Linux / macOS
file_handling_overview.exe      # Windows
```

Der Demo-Code erstellt automatisch drei temporäre Dateien: `demo.txt`, `zahlen.txt`, `binaer.bin`.

---

## Inhaltsübersicht

| # | Funktion(en) | Thema |
|---|---|---|
| [1](#1-datei-öffnen--schließen--fopen--fclose) | `fopen` / `fclose` | Datei öffnen & schließen |
| [2](#2-zeile-lesen--fgets) | `fgets` | Zeile lesen (sicherste Methode) |
| [3](#3-zahlen-lesen--fscanf) | `fscanf` | Zahlen & Text lesen |
| [4](#4-text-schreiben--fprintf) | `fprintf` | Formatiert in Datei schreiben |

---

## 1. Datei öffnen & schließen — `fopen` / `fclose`

```c
FILE *fp = fopen("datei.txt", "w");  // Datei öffnen
if (fp == NULL) { perror("fopen"); return; }  // IMMER prüfen!
// ... lesen / schreiben ...
fclose(fp);  // IMMER schließen – sonst gehen Daten verloren!
```

### Öffnungsmodi

| Modus | Bedeutung |
|---|---|
| `"r"` | Lesen — Datei **muss** existieren |
| `"w"` | Schreiben — Datei wird **neu erstellt** oder **geleert** |
| `"a"` | Anhängen — Datei wird **nicht geleert** |
| `"r+"` | Lesen + Schreiben — Datei muss existieren |

> **Faustregel:** Rückgabe von `fopen` immer auf `NULL` prüfen. `fclose` immer aufrufen — erst dann wird der interne Puffer auf die Festplatte geschrieben.

---

## 2. Zeile lesen — `fgets`

```c
char *fgets(char *puffer, int maxBytes, FILE *fp);
```

- Liest bis zu `maxBytes - 1` Zeichen **oder** bis zum `'\n'`
- Das `'\n'` wird **mit eingelesen** (falls vorhanden)
- Hängt automatisch `'\0'` ans Ende → Buffer-Overflow unmöglich
- Rückgabe `NULL` → Dateiende oder Fehler

```c
char zeile[128];
while (fgets(zeile, sizeof(zeile), fp) != NULL) {
    zeile[strcspn(zeile, "\n")] = '\0';  // '\n' am Ende entfernen
    printf("%s\n", zeile);
}
```

> **Faustregel:** Für Textdateien immer `fgets` statt `scanf("%s", ...)` verwenden — `scanf` stoppt beim ersten Leerzeichen und bietet keinen Schutz vor Buffer-Overflows.

---

## 3. Zahlen lesen — `fscanf`

```c
int fscanf(FILE *fp, const char *format, ...);
```

- Funktioniert genau wie `scanf`, liest aber aus einer Datei
- Rückgabe: Anzahl erfolgreich gelesener Felder; `EOF` bei Dateiende
- Überspringt Whitespace (Leerzeichen, Tabs, Newlines) automatisch

```c
int a, b;
float x;
fscanf(fp, "%d %d", &a, &b);   // zwei Integer lesen
fscanf(fp, "%f",    &x);        // einen Float lesen
```

---

## 4. Text schreiben — `fprintf`

```c
int fprintf(FILE *fp, const char *format, ...);
```

- Funktioniert genau wie `printf`, schreibt aber in eine Datei
- Unterstützt alle bekannten Formatzeichen (`%d`, `%f`, `%s`, …)
- Rückgabe: Anzahl geschriebener Zeichen; negativer Wert bei Fehler

```c
fprintf(fp, "Name: %s\n",       "Alice");       // String schreiben
fprintf(fp, "Alter: %d\n",      30);             // Integer schreiben
fprintf(fp, "Note:  %.2f\n",    1.3f);           // Float schreiben
```

> **Faustregel:** `fprintf` ist das Gegenstück zu `fscanf` — was `fscanf` liest, kann `fprintf` schreiben.

---

## Kurzreferenz aller Funktionen

| Funktion | Signatur | Rückgabe |
|---|---|---|
| `fopen` | `FILE *fopen(const char *pfad, const char *modus)` | `FILE*` oder `NULL` |
| `fclose` | `int fclose(FILE *fp)` | `0` oder `EOF` |
| `fgets` | `char *fgets(char *buf, int n, FILE *fp)` | `buf` oder `NULL` |
| `fscanf` | `int fscanf(FILE *fp, const char *fmt, ...)` | Anzahl gelesener Felder |
| `fprintf` | `int fprintf(FILE *fp, const char *fmt, ...)` | Geschriebene Zeichen |

---

## Die goldenen Regeln

1. **`fopen` immer auf `NULL` prüfen** — sonst Absturz beim ersten Zugriff.
2. **`fclose` immer aufrufen** — erst dann wird der interne I/O-Puffer geleert.
3. **Für Textzeilen `fgets` verwenden** — nicht `scanf("%s")`, kein Buffer-Overflow möglich.
