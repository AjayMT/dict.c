
// dict.c

#include <stdlib.h>

#include "dict.h"

// Check whether two strings are equal
static int streq (char *a, char *b)
{
    while (*a == *b && *a != '\0' && *b != '\0')
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
char *dict_get (dict *d, char *key)
{
    if (streq(d->key, key)) {
        char *val = malloc(sizeof(d->value));
        copy(val, d->value);

        return val;
    } else
        if ((int)(d->next) != 0)
            return dict_get(d->next, key);

    return 0;
}

// Set a value for a specific key
void dict_set (dict *d, char *key, void *value)
{
    if (streq(key, "")) return;

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

// Get the number of key-value pairs in a dictionary
int dict_len (dict *d)
{
    int i;

    for (i = 1; (int)(d->next) != 0; i++)
        d = d->next;

    return i;
}

// Get all the keys in a dictionary
char **dict_keys (dict *d)
{
    int len = dict_len(d);
    char **keys = malloc(len * sizeof(char *));

    for (int i = 0; i < len; i++) {
        keys[i] = malloc(_DICT_LIMIT);
        copy(keys[i], d->key);
        d = d->next;
    }

    return keys;
}

// Get all the values in a dictionary
char **dict_values (dict *d)
{
    int len = dict_len(d);
    char **values = malloc(len * sizeof(char *));

    for (int i = 0; i < len; i++) {
        values[i] = malloc(_DICT_LIMIT);
        copy(values[i], d->value);
        d = d->next;
    }

    return values;
}
