// =============================================================================
//  AUFGABE 3 – argc & argv: Argumente validieren
// =============================================================================
//
//  Theorie: README.md  →  Abschnitt 3 "Argumente prüfen"
//
//  Aufgabenstellung:
//    Programme müssen mit falschen Eingaben umgehen können.
//    Das Programm erwartet genau einen Namen als Argument.
//
//    a) Prüfe ob genau 1 Argument übergeben wurde (argc == 2).
//       Falls nicht: Gib eine Fehlermeldung auf stderr aus und beende
//       das Programm mit return 1.
//
//       Fehlermeldung:
//         Verwendung: ./aufgabe <Name>
//
//    b) Prüfe ob das Argument kürzer als 2 Zeichen ist (strlen).
//       Falls ja: Fehlermeldung und return 1.
//
//       Fehlermeldung:
//         Fehler: Name muss mindestens 2 Zeichen lang sein.
//
//    c) Gib bei korrekter Eingabe aus:
//         Hallo, <Name>!
//
//  Aufruf-Beispiele im Terminal:
//    ./aufgabe            →  Verwendung: ./aufgabe <Name>
//    ./aufgabe A          →  Fehler: Name muss mindestens 2 Zeichen lang sein.
//    ./aufgabe Moritz     →  Hallo, Moritz!
//
//  Hinweis: Fehlermeldungen gehören auf stderr:
//           fprintf(stderr, "...");
//
// =============================================================================

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // --- a) Argument-Anzahl prüfen ---
    // TODO: if (argc != 2) → fprintf(stderr, ...), return 1
    if (argc != 2) {
        printf("error: more or less than 2 arguments given");
        return 1;
    }
    // --- b) Länge des Arguments prüfen ---
    // TODO: if (strlen(argv[1]) < 2) → fprintf(stderr, ...), return 1

    if(strlen(argv[1]) < 2) {
        printf("error: argument to short");
        return 1;
    }
    // --- c) Begrüßung ausgeben ---
    // TODO: printf("Hallo, %s!\n", argv[1])
    printf("Hallo, %s!\n", argv[1]);
    
    return 0;
}
