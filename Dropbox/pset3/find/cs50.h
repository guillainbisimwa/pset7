#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/types.h>

typedef char* string;

static inline int GetInt(void) {
    int n;
    if (scanf("%d", &n) != 1) return INT_MAX;
    return n;
}

static inline float GetFloat(void) {
    float f;
    scanf("%f", &f);
    return f;
}

static inline string GetString(void) {
    char* buf = NULL;
    size_t len = 0;
    ssize_t read = getline(&buf, &len, stdin);
    if (read > 0 && buf[read - 1] == '\n')
        buf[read - 1] = '\0';
    return buf;
}
