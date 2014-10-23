
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
void dict_free (dict *d);
char *dict_get (dict *d, char *key);
void dict_set (dict *d, char *key, void *value);
void dict_del (dict *d, char *key);
int dict_has (dict *d, char *key);
int dict_len (dict *d);
char **dict_keys (dict *d);
char **dict_values (dict *d);

#endif
