
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "liblwm2m.h"
#include "windows.h"

void * lwm2m_malloc(size_t s)
{
    return malloc(s);
}

void lwm2m_free(void * p)
{
    free(p);
}

char * lwm2m_strdup(const char * str)
{
    return _strdup(str);
}

int lwm2m_strncmp(const char * s1, const char * s2, size_t n)
{
    return strncmp(s1, s2, n);
}

int lwm2m_strcasecmp(const char * s1, const char * s2)
{
    return _stricmp(s1, s2);
}

time_t lwm2m_gettime(void)
{
    return time(NULL);
}

int lwm2m_getline(char** line, size_t* length, FILE* fd)
{
    size_t alloc = 1024;
    int c;
    char* buf = *line = malloc(alloc);
    for (int i = 0; buf; i++)
    {
        c = fgetc(fd);
        if (i == (alloc - 1))
        {
            *line = realloc(buf, alloc * 2);
            if (!*line)
                break;
            memmove(*line, buf, alloc);
            alloc *= 2;
            buf = *line;
        }

        if (c == EOF)
            c = '\n';
        buf[i] = c;

        if (buf[i] == '\n')
        {
            *length = i + 1;
            buf[*length] = 0;
            return 0;
        }
    }
    free(buf);
    *line = NULL;
    *length = 0;
    return -1;
}

void system_setValueChangedHandler(
    lwm2m_context_t * lwm2m,
    void* p
    )
{
    // Do nothing
}

void system_reboot()
{
    exit(1);
}
