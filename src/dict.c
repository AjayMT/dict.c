
// dict.c

#include <stdarg.h>

#include "dict.h"

// Check whether two strings are equal
static int dict_streq (char *a, char *b)
{
    while (*a == *b && (*a != '\0' || *b != '\0'))
        a++, b++;

    if (*a == '\0' && *b == '\0') return 1; // equal

    return 0; // not equal
}

// One-line memcpy that detects the size of the source string
static void dict_copy (char *dst, char *src)
{
    for (char *a = dst, *b = src; (b - src) < sizeof(src); *a = *b, a++, b++);
}

// Create a new dictionary
// npairs is the number of key-value pairs
// each key-value pair is just an array of two strings
dict dict_new (int npairs, ...)
{
    va_list args;
    va_start(args, npairs);

    dict *p, *d;

    for (int i = 0; i < npairs; i++) {
        dict_pair pair = va_arg(args, dict_pair);

        dict a;
        dict_copy(a.key, pair[0]);
        dict_copy(a.value, pair[1]);

        if (p)
            p->next = &a;
        else
            d = &a;

        p = &a;
    }

    return *d;
}

// Get a value for a specific key
void dict_get (dict d, char *dst, char *key)
{
    while (1) {
        if (dict_streq(d.key, key)) {
            dict_copy(dst, d.value);
            break;
        }

        if (d.next) d = *d.next;
        else break;
    }
}

// Set a value for a specific key
void dict_set (dict *d, char *key, char *value)
{
    while (1) {
        if (dict_streq(d->key, key)) {
            dict_copy(d->value, value);
            break;
        }

        if (d->next) d = d->next;
        else {
            dict a;
            dict_copy(a.key, key);
            dict_copy(a.value, value);

            d->next = &a;
            break;
        }
    }
}
