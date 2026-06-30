// =============================================================================
//  AUFGABE 4 – argc & argv: Mini-Taschenrechner
// =============================================================================
//
//  Theorie: README.md  →  alle Abschnitte
//
//  Aufgabenstellung:
//    Baue einen Taschenrechner, der über Terminal-Argumente gesteuert wird.
//    Aufruf: ./aufgabe <Zahl1> <Operator> <Zahl2>
//
//    a) Prüfe ob genau 3 Argumente übergeben wurden (argc == 4).
//       Falls nicht:
//         Verwendung: ./aufgabe <Zahl1> <Operator> <Zahl2>
//         Operatoren: + - * /
//
//    b) Lies Zahl1 und Zahl2 mit atof() als double ein.
//       Lies den Operator als char ein: char op = argv[2][0];
//
//    c) Führe anhand des Operators die richtige Rechnung durch (if/else oder switch).
//       Unterstützte Operatoren: +  -  *  /
//
//    d) Bei Division: Prüfe ob Zahl2 == 0.0 ist.
//       Falls ja:
//         Fehler: Division durch Null.
//
//    e) Gib das Ergebnis aus:
//         <Zahl1> <Operator> <Zahl2> = <Ergebnis>
//
//    f) Bei unbekanntem Operator:
//         Fehler: Unbekannter Operator '<op>'
//
//  Aufruf-Beispiele im Terminal:
//    ./aufgabe 10 + 3        →  10.00 + 3.00 = 13.00
//    ./aufgabe 10 / 0        →  Fehler: Division durch Null.
//    ./aufgabe 10 % 3        →  Fehler: Unbekannter Operator '%'
//    ./aufgabe 7 \* 6        →  7.00 * 6.00 = 42.00
//
//  Hinweis: * muss im Terminal mit \* escaped werden (Shell-Sonderzeichen).
//
// =============================================================================

#include <stdio.h>
#include <stdlib.h>   // atof

int main(int argc, char *argv[]) {
    if(argc != 4) {
        return 1;
    }
    
    return 0;
}
