
// test.c

#include <stdio.h>
#include <stdlib.h>

#include "dict.h"

int main (int argc, char *argv[])
{
    printf("\n\nbegin tests\n");

    dict *d = dict_new();
    dict_set(d, "hello", "world");
    dict_set(d, "foo", "4");

    printf("\n  getting things...\n");

    char *world = dict_get(d, "hello");
    printf("    getting 'hello': %s\n", world);
    free(world);

    char *bar = dict_get(d, "foo");
    printf("    getting 'foo': %d\n", atoi(bar));
    free(bar);

    printf("\n  setting things...\n");

    dict_set(d, "hello", "people");
    char *people = dict_get(d, "hello");
    printf("    setting 'hello': %s\n", people);
    free(people);

    dict_set(d, "baz", "quux");
    char *quux = dict_get(d, "baz");
    printf("    setting 'baz': %s\n", quux);
    free(quux);

    printf("\n  dict length: %i\n", dict_len(d));

    printf("\n  keys & values...\n");

    char **keys = dict_keys(d);
    printf("    keys:");
    for (int i = 0; i < dict_len(d); i++)
        printf(" %s", keys[i]);
    printf("\n");
    free(keys);

    char **values = dict_values(d);
    printf("    values:");
    for (int i = 0; i < dict_len(d); i++)
        if (i == 1) printf(" %d", atoi(values[i]));
        else printf(" %s", values[i]);
    printf("\n");
    free(values);

    printf("\n  checking for keys...\n");

    printf("    dict has key 'hello': %i\n", dict_has(d, "hello"));

    printf("    dict has key 'asdf': %i\n", dict_has(d, "asdf"));

    printf("\n  deleting keys...\n");

    char **oldkeys = dict_keys(d);
    dict_del(d, "hello");
    char **newkeys = dict_keys(d);
    printf("    deleting key 'hello': %s %s\n", oldkeys[0], newkeys[0]);

    oldkeys = dict_keys(d);
    dict_del(d, "foo");
    newkeys = dict_keys(d);
    printf("    deleting key 'foo': %s %s\n", oldkeys[0], newkeys[0]);
    free(oldkeys);
    free(newkeys);

    printf("\n  freeing dict...\n");
    dict_free(d);

    printf("\nend tests\n\n");

    return 0;
}
