// =============================================================================
//  AUFGABE 2 – fgets
// =============================================================================
//
//  Theorie: README.md  →  Abschnitt 2 "Zeile lesen — fgets"
//
//  Aufgabenstellung:
//    Eine Datei "gedicht.txt" mit folgendem Inhalt ist bereits vorhanden
//    (wird vom Programm automatisch erstellt – nicht ändern!).
//
//    a) Lies die Datei zeilenweise mit fgets ein.
//       Entferne das '\n' am Ende jeder Zeile mit strcspn.
//       Gib jede Zeile nummeriert aus:
//         1: Roses are red
//         2: Violets are blue
//         3: C is the best
//         4: And so are you
//
//    b) Zähle dabei, wie viele Zeilen die Datei hat, und gib
//       die Gesamtzahl am Ende aus:
//         Zeilen gesamt: 4
//
//  Hinweis: fgets liest maximal (sizeof(puffer) - 1) Zeichen pro Aufruf.
//           Was passiert, wenn eine Zeile länger als der Puffer ist?
//           (Nur nachdenken, nicht implementieren.)
//
// =============================================================================

#include <stdio.h>
#include <string.h>

// Hilfsfunktion – Testdatei erstellen (nicht verändern!)
static void erstelle_testdatei(void) {
    FILE *fp = fopen("gedicht.txt", "w");
    if (!fp) { perror("erstelle_testdatei"); return; }
    fprintf(fp, "Roses are red\nViolets are blue\nC is the best\nAnd so are you\n");
    fclose(fp);
}

int main(void) {
    erstelle_testdatei();

    FILE *fp = fopen("gedicht.txt", "r");
    if (fp == NULL) { perror("fopen"); return 1; }

    // TODO: a) Zeilenweise lesen, '\n' entfernen, nummeriert ausgeben
    char buffer[256];
    int counter = 0;
    while(fgets(buffer, sizeof(buffer), fp)) {
        counter++;
        printf("%d. %s", counter, buffer);
    }

    // TODO: b) Zeilenzähler hochzählen und am Ende ausgeben
    printf("\nZeilenanzahl: %d", counter);

    fclose(fp);
    return 0;
}
