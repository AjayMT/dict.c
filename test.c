
// test.c

#include <stdio.h>

#include "dict.h"

int main (int argc, char *argv[])
{
    printf("\n\nbegin tests\n");

    int n = 4;
    dict *d = dict_new();
    dict_set(d, "hello", "world");
    dict_set(d, "foo", &n);

    printf("\n  getting things...\n");

    char world[100];
    dict_get(d, world, "hello");
    printf("    getting 'hello': %s\n", world);

    char bar[100];
    dict_get(d, bar, "foo");
    printf("    getting 'foo': %d\n", *bar);

    printf("\n  setting things...\n");

    dict_set(d, "hello", "people");
    char people[100];
    dict_get(d, people, "hello");
    printf("    setting 'hello': %s\n", people);

    dict_set(d, "baz", "quux");
    char quux[100];
    dict_get(d, quux, "baz");
    printf("    setting 'baz': %s\n", quux);

    printf("\n  dict length: %i\n", dict_len(d));

    printf("\n  keys & values...\n");

    char keys[dict_len(d)][100];
    dict_keys(d, keys);
    printf("    keys:");
    /* for (int i = 0; i < dict_len(d); i++) */
    /*     printf(" %s", keys[i]); */
    printf("\n");

    printf("\nend tests\n\n");

    return 0;
}
