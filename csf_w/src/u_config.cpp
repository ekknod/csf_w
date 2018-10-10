#define _CRT_SECURE_NO_WARNINGS
#include "../include/u_config.h"
#include <inttypes.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>

u_config::u_config(const char *path) : _path(path) {}
u_config::~u_config(void) {}

bool u_config::exists(void)
{
    return _access(_path, 0) != -1;
}

void u_config::open_config(const char *mode)
{
    _fd = fopen(_path, mode);
}

void u_config::close_config(void)
{
    fclose(_fd);
}

void u_config::write_config(void *buffer, size_t length)
{
    fwrite(buffer, length, 1, _fd);
}

int u_config::GetInt(const char *name)
{
    char b[32];
    GetVal(name, b);
    return atoi(b);
}

float u_config::GetFloat(const char *name)
{
    char b[32];
    GetVal(name, b);
    return (float)atof(b);
}

bool u_config::SetPos(const char *name)
{
    const char *n;
    char c;

    n = name;
    while ( 1 )
    {
        if (fread(&c, sizeof(c), 1, _fd) == 0)
            break;
        if (*n != c) {
            n = name;
            continue;
        }
        if (*(char*)(n + 1) == '\0') {
            fseek(_fd, 1, SEEK_CUR);
            return true;
        }
        n++;
    }
    return false;
}

bool u_config::GetVal(const char *name, char buffer[32])
{
    long c;
    bool s;
    int  i;


    c = fseek(_fd, 0, SEEK_CUR);
    if ((s = SetPos(name)) == false) {
        goto end;
    }
    i = 0;
    while ( i < 32 ) {
        if (fread(&buffer[i], 1, 1, _fd) == 0)
            break;
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            s = true;
            break;
        }
        i++;
    }
end:
    fseek(_fd, c, SEEK_SET);
    return s;
}
