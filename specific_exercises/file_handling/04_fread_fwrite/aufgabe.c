// =============================================================================
//  AUFGABE 4 – fprintf
// =============================================================================
//
//  Theorie: README.md  →  Abschnitt 4 "Text schreiben — fprintf"
//
//  Aufgabenstellung:
//    a) Erstelle eine Datei "kontakte.txt" und schreibe mit fprintf
//       die folgenden drei Kontakte hinein, je einen pro Zeile
//       im Format:  Name, Alter, Note
//         Alice, 22, 1.30
//         Bob, 25, 2.70
//         Charlie, 23, 1.70
//
//    b) Öffne "kontakte.txt" zum Lesen und gib alle Zeilen
//       mit fgets zeilenweise auf der Konsole aus:
//         Alice, 22, 1.30
//         Bob, 25, 2.70
//         Charlie, 23, 1.70
//
//    c) Öffne "kontakte.txt" mit dem Modus "a" (Anhängen) und
//       füge einen vierten Kontakt hinzu:
//         Diana, 21, 1.00
//
//    d) Lies die Datei erneut mit fgets komplett aus und gib sie aus —
//       diesmal sollen alle 4 Einträge erscheinen.
//
//  Hinweis: Modus "a" öffnet die Datei ohne sie zu leeren —
//           der neue Eintrag wird ans Ende angehängt.
//
// =============================================================================

#include <stdio.h>
#include <string.h>

int main(void) {

    // --- a) Drei Kontakte schreiben ---
    // TODO: "kontakte.txt" öffnen ("w"), NULL prüfen
    //       fprintf für jeden Kontakt aufrufen
    //       fclose aufrufen
    FILE *fwrite = fopen("./kontakte.txt.", "w");
    if(fwrite == NULL) {
        return 1;
    }

    fprintf(fwrite, "%s\n","Alice, 22, 1.30");
    fprintf(fwrite, "%s\n","Bob, 25, 2.70");
    fprintf(fwrite, "%s\n","Charlie, 23, 1.70");
    fclose(fwrite);
    // --- b) Datei lesen & ausgeben ---
    // TODO: "kontakte.txt" öffnen ("r"), fgets-Schleife, printf
    //       fclose aufrufen
    FILE *fread = fopen("./kontakte.txt.", "r");
    if(fread == NULL) {
        return 1;
    }

    char buffer[256];
    while(fgets(buffer, sizeof(buffer), fread) != NULL) {
        printf("%s\n", buffer);
    }
    fclose(fread);


    // --- c) Vierten Kontakt anhängen ---
    // TODO: "kontakte.txt" öffnen ("a"), fprintf für Diana
    //       fclose aufrufen
    FILE *fappend = fopen("./kontakte.txt", "a");
    if(fappend == NULL) {
        return 1;
    }

    fprintf(fappend, "%s", "Diana, 21, 1.00");
    fclose(fappend);
    // --- d) Datei komplett ausgeben (alle 4 Einträge) ---
    // TODO: "kontakte.txt" öffnen ("r"), fgets-Schleife, printf
    //       fclose aufrufen
    FILE *fread2 = fopen("./kontakte.txt", "r");
    char buffer2[256];
    
    while(fgets(buffer2, sizeof(buffer2), fread2) != NULL) {
        printf("%s\n", buffer2);
    }
    fclose(fread2);

    return 0;
}
