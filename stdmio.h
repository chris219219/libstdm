#ifndef STDMIO_H
#define STDMIO_H

#include "stdm.h"
#include "stdmstr.h"
#include <stdio.h>

typedef struct _iobuf filebuf;

static inline char* ngets(char* buf, i32 n)
{
    fgets(buf, n, stdin);
    if (!strchr(buf, '\n'))
    {
        scanf("%*[^\n]");
        scanf("%*c");
    }
    buf[strcspn(buf, "\n")] = '\0';
    return buf;
}

#endif