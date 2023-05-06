#include "../stdmstr.h"
#include <ctype.h>

char* strltrim(char* buf)
{
    char* s = buf;
    char* p = buf;
    while (*p != '\0')
    {
        if (!isspace(*p))
            break;
        ++p;
    }
    if (s == p)
        return buf;
    while (*p != '\0')
    {
        *s = *p;
        ++s;
        ++p;
    }
    *s = '\0';
    return buf;
}

char* strrtrim(char* buf)
{
    i32 i = strlen(buf) - 1;
    while (i > 0)
    {
        if (!isspace(buf[i]))
        {
            ++i;
            break;
        }
        --i;
    }
    buf[i] = '\0';
    return buf;
}