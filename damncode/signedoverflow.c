#include <stdio.h>

extern int info[256];

int signed_overflow(int id) {
    short s; // signed short s
    unsigned sz; // unsigned sz

    s = id; // int -> short could be signed negative value(-1 ...)

    if (s > 256)
        return 0;

    sz = s; // big signed value saved.

    return info[sz]; // focus variable area pointer returned. (trigger)
}
