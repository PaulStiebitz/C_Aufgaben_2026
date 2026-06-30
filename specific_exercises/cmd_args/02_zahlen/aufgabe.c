// =============================================================================
//  AUFGABE 2 – argc & argv: Argumente als Zahlen lesen
// =============================================================================
//
//  Theorie: README.md  →  Abschnitt 2 "Argumente umwandeln — atoi & atof"
//
//  Aufgabenstellung:
//    Das Programm erwartet genau zwei Zahlen als Argumente.
//    Es soll deren Summe, Differenz und Produkt berechnen und ausgeben.
//
//    a) Lies argv[1] und argv[2] mit atoi() als ganze Zahlen ein.
//
//    b) Berechne:
//         - Summe
//         - Differenz (argv[1] - argv[2])
//         - Produkt
//
//    c) Gib die Ergebnisse auf der Konsole aus.
//
//  Aufruf-Beispiel im Terminal:
//    ./aufgabe 8 3
//
//  Erwartete Konsolenausgabe:
//    Summe:      11
//    Differenz:   5
//    Produkt:    24
//
//  Hinweis: argv-Einträge sind immer Strings (char *).
//           atoi() wandelt einen String in einen int um:  int x = atoi(argv[1]);
//           atof() wandelt einen String in einen double um: double x = atof(argv[1]);
//
// =============================================================================

#include <stdio.h>
#include <stdlib.h>   // atoi, atof

int main(int argc, char *argv[]) {

    // --- a) Zwei Argumente einlesen ---
    // TODO: atoi(argv[1]) und atoi(argv[2]) in int-Variablen speichern
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    // --- b) Berechnungen ---
    // TODO: Summe, Differenz, Produkt berechnen
    int sum = a + b;
    int dif = a - b;
    int prod = a * b;

    // --- c) Ergebnisse ausgeben ---
    // TODO: printf für alle drei Werte
    printf("Summe: %d\n", sum);
    printf("Differenz: %d\n", dif);
    printf("Produkt: %d\n", prod);

    return 0;
}
