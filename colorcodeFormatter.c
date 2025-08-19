
#include <stdio.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

Formatter MarkdownFormatter = { md_header, md_line_format };
Formatter CsvFormatter      = { csv_header, csv_line_format };

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

void printReferenceManual(const Formatter* format) {
    printf("Reference Manual:\n");
    char buffer[100];
    format->header(buffer, 100);
    printf("%s", buffer);

    for (int i=0; i< 25; ++i) {
        ColorPair colorPair = GetColorFromPairNumber(i + 1);
        format->line(buffer, 100, i + 1, colorPair.majorColor, colorPair.minorColor);
        printf("%s", buffer);
    }
}
