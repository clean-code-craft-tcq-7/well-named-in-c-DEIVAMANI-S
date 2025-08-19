#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

void testPrintReferenceManual() {
    printf("Printing Reference Manual:\n");
    char buff[200];
    md_header(buff, sizeof(buff));
    assert(strcmp(buff, "| Pair Number | Major Color | Minor Color |\n|---|---|---|\n") == 0);
    md_line_format(buff, sizeof(buff), 1, WHITE, BLUE);
    assert(strcmp(buff, "| 1 | White | Blue |\n") == 0);
    printReferenceManual(&MarkdownFormatter);
}

void testPrintReferenceManualCSV() {
    printf("Printing Reference Manual in CSV format:\n");
    char buff[200];
    csv_header(buff, sizeof(buff));
    assert(strcmp(buff, "Pair Number,Major Color,Minor Color\n") == 0);
    csv_line_format(buff, sizeof(buff), 1, WHITE, BLUE);
    assert(strcmp(buff, "1,White,Blue\n") == 0);
    printReferenceManual(&CsvFormatter);
}

void testPrintReferenceManualJSON() {
    printf("Printing Reference Manual JSON format:\n");
    char buff[200];
    json_header(buff, sizeof(buff));
    assert(strcmp(buff, "[\n") == 0);
    json_line_format(buff, sizeof(buff), 1, WHITE, BLUE);
    assert(strcmp(buff, "  { \"PairNumber\": 1, \"MajorColor\": \"White\", \"MinorColor\": \"Blue\" },\n") == 0);

    printReferenceManual(&JsonFormatter);
}

void run_formatter_tests() {
    testPrintReferenceManual();
    testPrintReferenceManualCSV();
    testPrintReferenceManualJSON();
}
