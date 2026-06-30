// =============================================================================
//  AUFGABE 1 – argc & argv: Grundlagen
// =============================================================================
//
//  Theorie: README.md  →  Abschnitt 1 "Was sind argc und argv?"
//
//  Aufgabenstellung:
//    a) Ändere die Signatur von main so, dass sie argc und argv entgegennimmt.
//
//    b) Gib die Anzahl der übergebenen Argumente auf der Konsole aus.
//       Hinweis: argc zählt das Programm selbst mit!
//
//    c) Gib alle Argumente (inklusive Programmname) mit einer Schleife aus,
//       je eines pro Zeile, mit Index davor:
//           [0] ./aufgabe
//           [1] Hallo
//           [2] Welt
//
//  Aufruf-Beispiel im Terminal:
//    ./aufgabe Hallo Welt
//
//  Erwartete Konsolenausgabe:
//    Anzahl Argumente: 3
//    [0] ./aufgabe
//    [1] Hallo
//    [2] Welt
//
// =============================================================================

#include <stdio.h>

int main(int argc, char *argv[]) {

    // --- a) ist bereits erledigt: argc und argv sind Parameter ---

    // --- b) Anzahl der Argumente ausgeben ---
    // TODO: printf für argc
    printf("Anzahl Argumente: %d\n", argc);

    // --- c) Alle Argumente mit Index ausgeben ---
    // TODO: for-Schleife über argc, printf mit Index und argv[i]
    for(int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    return 0;
}
