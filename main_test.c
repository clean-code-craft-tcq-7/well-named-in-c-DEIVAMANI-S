#include <stdio.h>

// Declarations from other test files
void run_colorcode_tests();
void run_formatter_tests();

int main() {
    run_colorcode_tests();
    run_formatter_tests();
    printf("✅ All tests passed!\n");
    return 0;
}
