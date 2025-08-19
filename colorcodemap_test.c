#include <stdio.h>
#include <assert.h>
#include "colorcode.h"

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair = { major, minor };
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void testPrintReferenceManual() {
    printf("Printing Reference Manual:\n");
    char buff[100];
    md_header(buff, 100);
    assert(strcmp(buff, "| Pair Number | Major Color | Minor Color |\n|---|---|---|\n") == 0);
    md_line_format(buff, 100, 1, WHITE, BLUE);
    assert(strcmp(buff, "| 1 | White | Blue |\n") == 0);
    printReferenceManual(md_header, md_line_format);
}

void testPrintReferenceManualCSV() {
    printf("Printing Reference Manual in CSV format:\n");
    char buff[100];
    csv_header(buff, 100);
    assert(strcmp(buff, "Pair Number,Major Color,Minor Color\n") == 0);
    csv_line_format(buff, 100, 1, WHITE, BLUE);
    assert(strcmp(buff, "1,White,Blue\n") == 0);
    printReferenceManual(csv_header, csv_line_format);
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    testPrintReferenceManual();
    testPrintReferenceManualCSV();
    return 0;
}
