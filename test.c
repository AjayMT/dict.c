
// test.c

#include <stdio.h>

#include "dict.h"

int main (int argc, char *argv[])
{
    int n = 12;
    char *pair1[2] = { "hello", "world" };
    char *pair2[2] = { "foo", &n };
    dict d = dict_new(2, pair1, pair2);

    printf("getting things...\n");

    char world[100];
    dict_get(d, world, "hello");
    printf("getting 'hello': %s\n", world);

    char bar[100];
    dict_get(d, bar, "foo");
    printf("getting 'foo': %d\n", *((int *)bar));

    printf("\nsetting things...\n");

    dict_set(&d, "hello", "people");
    char people[100];
    dict_get(d, people, "hello");
    printf("setting 'hello': %s\n", people);

    dict_set(&d, "baz", "quux");
    char quux[100];
    dict_get(d, quux, "baz");
    printf("setting 'baz': %s\n", quux);

    return 0;
}
