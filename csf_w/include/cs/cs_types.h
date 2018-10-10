#ifndef CS_TYPES_H
#define CS_TYPES_H

#include <inttypes.h>

#ifdef _WIN32
typedef unsigned int csptr_t;
#else
typedef uintptr_t csptr_t;
#endif

typedef struct {
    char value[120];
} SHORT_STRING ;

typedef struct {
    char value[260];
} LONG_STRING ;

typedef struct {
    float x, y, z;
} vec3 ;

typedef struct {
    int x, y;
} vec2i ;

typedef float matrix3x4_t[3][4];

#endif /* CS_TYPES_H */

