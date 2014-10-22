
// dict.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "dict.h"

// Check whether two strings are equal
static int streq (char *a, char *b)
{
    while (*a == *b && (*a != '\0' || *b != '\0'))
        a++, b++;

    if (*a == '\0' && *b == '\0') return 1; // equal

    return 0; // not equal
}

// memcpy that detects the size of the source
static void copy (char *dst, char *src)
{
    char *a = dst;
    char *b = src;
    for (; (b - src) < sizeof(src); *a = *b, a++, b++);
}

// Create a new dictionary
dict *dict_new ()
{
    dict *d = malloc(sizeof(dict));
    copy(d->key, "");
    d->next = 0;

    return d;
}

// Get a value for a specific key
void dict_get (dict *d, void *dst, char *key)
{
    if (streq(d->key, key))
        copy(dst, d->value);
    else
        if ((int)(d->next) != 0)
            dict_get(d->next, dst, key);
}

// Set a value for a specific key
void dict_set (dict *d, char *key, void *value)
{
    if (streq(d->key, key) || streq(d->key, "")) {
        if (streq(d->key, ""))
            copy(d->key, key);

        copy(d->value, value);
    } else {
        if ((int)(d->next) == 0)
            d->next = dict_new();

        dict_set(d->next, key, value);
    }
}

int dict_len (dict *d)
{
    int i;

    for (i = 1; (int)(d->next) != 0; i++)
        d = d->next;

    return i;
}

void dict_keys (dict *d, char **keys)
{
    int len = dict_len(d);

    for (int i = 0; i < len; i++) {
        copy(keys[i], d->key);
        d = d->next;
    }
}

void dict_values (dict *d, char **values)
{
    int len = dict_len(d);

    for (int i = 0; i < len; i++) {
        copy(values[i], d->value);
        d = d->next;
    }
}
