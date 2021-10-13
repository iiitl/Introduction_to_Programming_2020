#include<stdio.h>
#ifndef _CLEAR_BUFFER
#define _CLEAR_BUFFER
/*
 * To know what this code does, read this link:
 * https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
 * We will discuss non-library functions in Week 7
 */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
#endif
