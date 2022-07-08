#include <stdio.h>

//Set DEBUG to see log
//from this link :
//https://stackoverflow.com/questions/1644868/define-macro-for-debug-printing-in-c
#ifndef DEBUG_TEST
#define DEBUG 0
#else
#define DEBUG 1
#endif


#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, ##__VA_ARGS__); } while (0)

