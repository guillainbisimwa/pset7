#pragma once
#include <stdio.h>
#include <stdlib.h>

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
