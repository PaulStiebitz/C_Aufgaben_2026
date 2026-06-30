/**
 * ============================================================
 *  C FILE HANDLING – ÜBERSICHT
 * ============================================================
 *
 *  Kompilieren:  gcc filehandling_cheatsheet.c -o cheatsheet
 *  Ausführen:    ./cheatsheet
 *
 *  Alle Beispiele schreiben/lesen "demo.txt" bzw. "demo.bin".
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
 *  1.  DATEI ÖFFNEN & SCHLIESSEN
 *
 *  FILE *fopen(const char *pfad, const char *modus);
 *
 *  Wichtige Modi:
 *   "r"   – lesen         (Datei muss existieren)
 *   "w"   – schreiben     (erstellt / überschreibt)
 *   "a"   – anhängen      (erstellt falls nicht vorhanden)
 *   "rb"  – binär lesen
 *   "wb"  – binär schreiben
 *
 *  Immer auf NULL prüfen, immer fclose() aufrufen!
 * ============================================================ */
static void demo_open_close(void)
{
    printf("\n--- 1. fopen / fclose ---\n");

    FILE *fp = fopen("demo.txt", "w");
    if (fp == NULL) {          /* Fehlerbehandlung */
        perror("fopen");
        return;
    }
    fprintf(fp, "Hallo Welt\n");
    fclose(fp);               /* Datei schließen */

    printf("demo.txt wurde erstellt.\n");
}


/* ============================================================
 *  2.  ZEILEN SCHREIBEN mit fprintf
 *
 *  fprintf(fp, format, ...);   – wie printf, aber in Datei
 * ============================================================ */
static void demo_write_lines(void)
{
    printf("\n--- 2. fprintf: Zeilen schreiben ---\n");

    FILE *fp = fopen("demo.txt", "w");
    if (!fp) { perror("fopen"); return; }

    fprintf(fp, "Zeile 1: Apfel\n");
    fprintf(fp, "Zeile 2: Banane\n");
    fprintf(fp, "Zeile 3: Kirsche\n");
    fprintf(fp, "Zeile 4: %d Stueck\n", 42);   /* mit Wert */

    fclose(fp);
    printf("4 Zeilen in demo.txt geschrieben.\n");
}


/* ============================================================
 *  3.  ZEILENWEISE LESEN mit fgets
 *
 *  char *fgets(char *puffer, int groesse, FILE *fp);
 *
 *  – Liest bis '\n' ODER groesse-1 Zeichen
 *  – Gibt NULL zurück wenn EOF oder Fehler
 *  – Sicherste Methode für zeilenweises Lesen
 * ============================================================ */
static void demo_read_lines(void)
{
    printf("\n--- 3. fgets: Zeilenweise lesen ---\n");

    FILE *fp = fopen("demo.txt", "r");
    if (!fp) { perror("fopen"); return; }

    char zeile[128];          /* Puffer für eine Zeile */
    int  nr = 0;

    while (fgets(zeile, sizeof(zeile), fp) != NULL) {
        nr++;
        printf("  [%d] %s", nr, zeile);   /* \n steckt schon im Puffer */
    }
    printf("Gesamt: %d Zeilen\n", nr);

    fclose(fp);
}


/* ============================================================
 *  4.  ZAHLEN LESEN mit fscanf
 *
 *  int fscanf(FILE *fp, format, ...);
 *
 *  – Liest whitespace-getrennte Token / Zahlen
 *  – Gibt Anzahl erfolgreich gelesener Werte zurück
 * ============================================================ */
static void demo_read_numbers(void)
{
    printf("\n--- 4. fscanf: Zahlen lesen ---\n");

    /* Erst Zahlen-Datei anlegen */
    FILE *fp = fopen("numbers.txt", "w");
    if (!fp) { perror("fopen"); return; }
    fprintf(fp, "10 20 30\n40 50\n");
    fclose(fp);

    /* Jetzt lesen */
    fp = fopen("numbers.txt", "r");
    if (!fp) { perror("fopen"); return; }

    int  zahl;
    long summe = 0;
    int  anzahl = 0;

    while (fscanf(fp, "%d", &zahl) == 1) {   /* solange 1 Wert gelesen */
        printf("  Zahl: %d\n", zahl);
        summe += zahl;
        anzahl++;
    }
    printf("Summe: %ld  Anzahl: %d\n", summe, anzahl);

    fclose(fp);
}


/* ============================================================
 *  5.  BESTIMMTE PUFFERGRÖSSE lesen mit fread
 *
 *  size_t fread(void *puffer, size_t elementgroesse,
 *               size_t anzahl, FILE *fp);
 *
 *  – Liest exakt N Bytes (rohe Bytes, kein Text-Parsing)
 *  – Gibt Anzahl gelesener Elemente zurück
 *  – Typisch für Binär-Daten ODER wenn du die Anzahl
 *    Bytes selbst kontrollieren willst
 * ============================================================ */
static void demo_read_buffer(void)
{
    printf("\n--- 5. fread: Bestimmte Puffergröße ---\n");

    /* Datei mit Inhalt vorbereiten */
    FILE *fp = fopen("demo.txt", "r");
    if (!fp) { perror("fopen"); return; }

    char  puffer[16];         /* lese maximal 15 Zeichen auf einmal */
    size_t gelesen;

    while ((gelesen = fread(puffer, 1, sizeof(puffer) - 1, fp)) > 0) {
        puffer[gelesen] = '\0';   /* manuell null-terminieren */
        printf("  [%u Bytes] \"%s\"\n", (unsigned)gelesen, puffer);
    }

    fclose(fp);
}


/* ============================================================
 *  6.  EINE GANZE DATEI auf einmal lesen
 *
 *  Trick: fseek(SEEK_END) + ftell() → Dateigröße,
 *         dann fread mit genau dieser Größe
 * ============================================================ */
static void demo_read_whole_file(void)
{
    printf("\n--- 6. Ganze Datei lesen ---\n");

    FILE *fp = fopen("demo.txt", "r");
    if (!fp) { perror("fopen"); return; }

    /* Dateigröße bestimmen */
    fseek(fp, 0, SEEK_END);       /* ans Ende springen */
    long groesse = ftell(fp);     /* Position = Größe */
    rewind(fp);                   /* zurück zum Anfang */

    char *inhalt = malloc(groesse + 1);
    if (!inhalt) { fclose(fp); return; }

    fread(inhalt, 1, groesse, fp);
    inhalt[groesse] = '\0';

    printf("Dateiinhalt (%ld Bytes):\n%s\n", groesse, inhalt);

    free(inhalt);
    fclose(fp);
}


/* ============================================================
 *  7.  BINÄRDATEN schreiben und lesen mit fwrite / fread
 *
 *  size_t fwrite(const void *ptr, size_t groesse,
 *                size_t anzahl, FILE *fp);
 * ============================================================ */
typedef struct {
    int   id;
    float wert;
    char  name[16];
} Eintrag;

static void demo_binary(void)
{
    printf("\n--- 7. fwrite / fread: Binäre Structs ---\n");

    Eintrag eintraege[3] = {
        {1, 3.14f, "Alpha"},
        {2, 2.71f, "Beta"},
        {3, 1.41f, "Gamma"},
    };

    /* Schreiben */
    FILE *fp = fopen("demo.bin", "wb");
    if (!fp) { perror("fopen"); return; }
    fwrite(eintraege, sizeof(Eintrag), 3, fp);
    fclose(fp);

    /* Lesen */
    fp = fopen("demo.bin", "rb");
    if (!fp) { perror("fopen"); return; }

    Eintrag e;
    while (fread(&e, sizeof(Eintrag), 1, fp) == 1) {
        printf("  ID:%d  Wert:%.2f  Name:%s\n", e.id, e.wert, e.name);
    }

    fclose(fp);
}


/* ============================================================
 *  KURZREFERENZ
 * -------------------------------------------------------
 *  fopen(pfad, modus)          Datei öffnen → FILE*
 *  fclose(fp)                  Datei schließen
 *  fprintf(fp, fmt, ...)       Formatiert schreiben
 *  fscanf(fp, fmt, ...)        Formatiert lesen (Zahlen/Token)
 *  fgets(buf, n, fp)           Eine Zeile lesen (sicher)
 *  fread(buf, size, n, fp)     N Elemente binär lesen
 *  fwrite(buf, size, n, fp)    N Elemente binär schreiben
 *  fseek(fp, offset, SEEK_*)   Cursor setzen
 *  ftell(fp)                   Aktuelle Position
 *  rewind(fp)                  Zurück zum Anfang
 *  feof(fp)                    != 0 wenn Dateiende
 *  ferror(fp)                  != 0 bei Fehler
 * ============================================================ */

int main(void)
{
    demo_open_close();
    demo_write_lines();
    demo_read_lines();
    demo_read_numbers();
    demo_read_buffer();
    demo_read_whole_file();
    demo_binary();

    printf("\nFertig.\n");
    return 0;
}
