#include <stdio.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"
enum {MARKDOWN, CSV, JSON};
Formatter MarkdownFormatter = { md_header, md_line_format };
Formatter CsvFormatter      = { csv_header, csv_line_format };
Formatter JsonFormatter = { json_header, json_line_format };
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
void json_header(char* buffer, int size) {
    snprintf(buffer, size, "[\n");
}
void json_line_format(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor) {
    snprintf(buffer, size,
             "  { \"PairNumber\": %d, \"MajorColor\": \"%s\", \"MinorColor\": \"%s\" },\n",
             pairNumber, MajorColorNames[major], MinorColorNames[minor]);
}

void printReferenceManual(const Formatter* format) {
    printf("Reference Manual:\n");
    char buffer[200];
    format->header(buffer, sizeof(buffer));
    printf("%s", buffer);
    for (int i=0; i< 25; ++i) {
        ColorPair colorPair = GetColorFromPairNumber(i + 1);
        format->line(buffer, sizeof(buffer), i + 1, colorPair.majorColor, colorPair.minorColor);
        if (format == &JsonFormatter && i == 24) {         // For JSON: avoid comma after the last element
            buffer[strlen(buffer) - 2] = '\0'; // remove ","
            snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "\n");
        }
        printf("%s", buffer);
    }
    if (format == &JsonFormatter) {
        printf("]\n");
    }
}
