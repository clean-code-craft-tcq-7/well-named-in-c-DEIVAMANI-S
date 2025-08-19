
#include <stdio.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

void md_header(char* buffer, int size) {
    snprintf(buffer, size, "| Pair Number | Major Color | Minor Color |\n|---|---|---|\n");
}

void md_line_format(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor) {
    snprintf(buffer, size, "| %d | %s | %s |\n", pairNumber,
             MajorColorNames[major], MinorColorNames[minor]);
}

void csv_header(char* buffer, int size) {
    snprintf(buffer, size, "Pair Number,Major Color,Minor Color\n");
}

void csv_line_format(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor) {
    snprintf(buffer, size, "%d,%s,%s\n", pairNumber,
             MajorColorNames[major], MinorColorNames[minor]);
}

enum {MARKDOWN, CSV};

void printReferenceManual(char* (*header_formatter)(char*, int), 
                          char* (*line_formatter)(char*, int, int, enum MajorColor, enum MinorColor)) {
    printf("Reference Manual:\n");
    char buffer[100];
    header_formatter(buffer, 100);
    printf("%s", buffer);
    for (int i=0; i< 25; ++i) {
        ColorPair colorPair = GetColorFromPairNumber(i + 1);
        line_formatter(buffer, 100, i + 1, colorPair.majorColor, colorPair.minorColor);
        printf("%s", buffer);
    }
}
