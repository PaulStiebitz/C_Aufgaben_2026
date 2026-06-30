// =============================================================================
//  AUFGABE 1 – fopen / fclose
// =============================================================================
//
//  Theorie: README.md  →  Abschnitt 1 "Datei öffnen & schließen"
//
//  Aufgabenstellung:
//    a) Öffne eine Datei namens "notizen.txt" zum Schreiben.
//       Prüfe, ob fopen erfolgreich war (NULL-Check!).
//
//    b) Schreibe die folgenden drei Zeilen in die Datei:
//         "Erste Notiz"
//         "Zweite Notiz"
//         "Dritte Notiz"
//
//    c) Schließe die Datei.
//
//    d) Öffne dieselbe Datei erneut, diesmal zum Lesen ("r").
//       Lies den Inhalt zeilenweise aus und gib jede Zeile auf der
//       Konsole aus (Tipp: fgets darf hier schon benutzt werden).
//
//    e) Schließe die Datei wieder.
//
//  Erwartete Konsolenausgabe:
//    Erste Notiz
//    Zweite Notiz
//    Dritte Notiz
//
// =============================================================================

#include <stdio.h>
#include <string.h>

int main(void) {

    // --- a) Datei zum Schreiben öffnen ---
    // TODO: fopen aufrufen, NULL prüfen
    FILE *fwrite = fopen("./notes.txt", "w");

    if(fwrite == NULL) {
        return 1;
    }
    // --- b) Drei Zeilen schreiben ---
    // TODO: fprintf verwenden
    fprintf(fwrite, "A\n");
    fprintf(fwrite, "B\n");
    fprintf(fwrite, "C\n");

    // --- c) Datei schließen ---
    // TODO: fclose aufrufen
    fclose(fwrite);

    // --- d) Datei zum Lesen öffnen & Inhalt ausgeben ---
    // TODO: fopen mit "r", fgets-Schleife, Ausgabe
    FILE *fread = fopen("./notes.txt", "r");
    if(fread == NULL) {
        return 1;
    }

    char buffer[256];
    while(fgets(buffer, sizeof(buffer), fread)) {
        printf("%s", buffer);
    }
    // --- e) Datei schließen ---
    // TODO: fclose aufrufen
    fclose(fread);
    return 0;
}
