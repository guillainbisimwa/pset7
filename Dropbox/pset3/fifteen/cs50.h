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
    scanf("%d", &n);
    return n;
}

static inline float GetFloat(void) {
    float f;
    scanf("%f", &f);
    return f;
}

static inline string GetString(void) {
    char buf[1024];
    if (fgets(buf, sizeof(buf), stdin) == NULL) return NULL;
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';
    char* result = malloc(len + 1);
    if (result) memcpy(result, buf, len + 1);
    return result;
}
