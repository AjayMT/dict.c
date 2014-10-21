
// dict.h

#ifndef _DICT_H
#define _DICT_H

#define _DICT_LIMIT 10000

typedef struct dict {
    char key[_DICT_LIMIT], value[_DICT_LIMIT];
    struct dict *next;
} dict;

typedef char **dict_pair;

static int dict_streq (char *a, char *b);
static void dict_copy (char *dst, char *src);

dict dict_new (int npairs, ...);
void dict_get (dict d, char *dst, char *key);
void dict_set (dict *d, char *key, char *value);

#endif
