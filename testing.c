#include "testing.h"
#include <stdio.h>

static int _failure_count;

void print_test(const char* mensaje, bool ok)
{
    _failure_count += !ok;
    printf("%s... %s\n", mensaje, ok ? "OK" : "ERROR");
}

int failure_count() {
    return _failure_count;
}
