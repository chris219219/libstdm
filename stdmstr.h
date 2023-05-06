#ifndef STDMSTR_H
#define STDMSTR_H

#include "stdm.h"
#include <string.h>

char* strltrim(char* buf);
char* strrtrim(char* buf);
static inline char* strtrim(char* buf) { strrtrim(buf); strltrim(buf); return buf; }

typedef struct string
{
    i32 length;
    char* data;
} string;



#endif