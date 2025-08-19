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
void json_header(char* buffer, int size);
void json_line_format(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor);

extern Formatter MarkdownFormatter;
extern Formatter CsvFormatter;
extern Formatter JsonFormatter;

void printReferenceManual(const Formatter* format);

#endif
