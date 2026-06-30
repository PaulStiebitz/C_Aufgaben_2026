// =============================================================================
//  AUFGABE 3 – fscanf / fprintf
// =============================================================================
//
//  Theorie: README.md  →  Abschnitt 3 "Zahlen lesen — fscanf"
//                         Abschnitt 4 "Text schreiben — fprintf"
//
//  Aufgabenstellung:
//    a) Erstelle eine Datei "temperatur.txt" und schreibe mit fprintf
//       die folgenden Messwerte (Grad Celsius) hinein, je einen pro Zeile:
//         12.5
//         17.3
//         9.8
//         22.1
//         15.0
//
//    b) Öffne "temperatur.txt" zum Lesen.
//       Lies alle Werte mit fscanf ein (Schleife bis fscanf EOF liefert).
//       Berechne dabei:
//         - die Summe aller Werte
//         - den Durchschnitt
//
//    c) Schreibe Summe und Durchschnitt mit fprintf in eine neue Datei
//       "auswertung.txt":
//         Summe:        76.70
//         Durchschnitt: 15.34
//
//    d) Gib den Inhalt von "auswertung.txt" zeilenweise auf der Konsole aus.
//
// =============================================================================

#include <stdio.h>
#include <string.h>

int main(void) {

    // --- a) Messwerte schreiben ---
    // TODO: "temperatur.txt" öffnen ("w"), 5 Werte mit fprintf schreiben
    FILE *fwrite = fopen("./temperatur.txt", "w");
    if(fwrite == NULL) {
        return 1;
    }

    for(double i = 0.0; i < 5; i++) {
        fprintf(fwrite, "%.2f\n", i);  
    }

    fclose(fwrite);
    // --- b) Werte lesen & auswerten ---
    // TODO: "temperatur.txt" öffnen ("r"), fscanf-Schleife
    //       Summe und Anzahl berechnen, Durchschnitt ermitteln
    double value = 0.0;
    double sum = 0.0;
    int anzahl = 0;
    double average = 0.0;

    FILE *fread = fopen("./temperatur.txt", "r");
    if(fread == NULL) {
        return 1;
    }

    while(fscanf(fread, "%lf", &value) == 1) {
        sum += value;
        anzahl++;
    }
    fclose(fread);
    // --- c) Auswertung in Datei schreiben ---
    // TODO: "auswertung.txt" öffnen ("w"), Summe & Durchschnitt schreiben
    FILE *fausw = fopen("./auswertung.txt", "w");
    if(fausw == NULL) {
        return 1;
    }

    average = sum / anzahl;
    fprintf(fausw, "Summe: %.2f\nAnzahl: %d\nDurchschnitt: %.2f", sum, anzahl, average);
    fclose(fausw);
    // --- d) Auswertung ausgeben ---
    // TODO: "auswertung.txt" öffnen ("r"), fgets-Schleife & printf

    return 0;
}
