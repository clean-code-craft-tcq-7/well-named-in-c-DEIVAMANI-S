#ifndef REF_COLOR_FORMATTER_H
#define REF_COLOR_FORMATTER_H

typedef struct {
    void (*header)(char* buffer, int size);
    void (*line)(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor);
} Formatter;

void md_header(char* buffer, int size);
void md_line_format(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor);
void csv_header(char* buffer, int size);
void csv_line_format(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor);
void printReferenceManual();

void printReferenceManual(const Formatter* fmt);

#endif
