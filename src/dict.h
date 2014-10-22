
// dict.h

#ifndef _DICT_H
#define _DICT_H

#define _DICT_LIMIT 10000

typedef struct dict {
    char key[_DICT_LIMIT], value[_DICT_LIMIT];
    struct dict *next;
} dict;

static int streq (char *a, char *b);
static void copy (char *dst, char *src);

dict *dict_new ();
void dict_get (dict *d, void *dst, char *key);
void dict_set (dict *d, char *key, void *value);
int dict_len (dict *d);
void dict_keys (dict *d, char **keys);
void dict_values (dict *d, char **values);

#endif
