#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char* string;

static inline int GetInt(void) {
    int n;
    scanf("%d", &n);
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
