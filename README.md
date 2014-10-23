
# dict.c
[![Build Status](https://travis-ci.org/AjayMT/dict.c.svg)](https://travis-ci.org/AjayMT/dict.c)

dict.c is a simple implementation of a dictionary in C. It's basically just a linked list of key-value pairs.

Here's a usage example:

```c
#include <stdio.h>
#include "dict.h"

int main (int argc, char *argv[])
{
    int n = 12;
    dict *my_dict = dict_new();
    dict_set(my_dict, "hello", "world");
    dict_set(my_dict, "foo", &n);

    char *world = dict_get(my_dict, "hello");
    printf("hello: %s\n", world); // => "hello: world"

    char *bar = dict_get(my_dict, "foo");
    printf("foo: %d\n", *bar); // => "foo: 12"

    dict_set(my_dict, "hello", "people"); // now 'hello' is mapped to 'people'
    n = 5; // we don't need to dict_set since 'foo' points to n
}
```

Take a look at `./test.c` for a longer example.

## Installation
Installing with [clib](http://github.com/clibs/clib) is recommended:

```sh
$ clib install AjayMT/dict.c
```

But you *can* `make` it and use the `dict.o` file:

```sh
$ git clone http://github.com/AjayMT/dict.c.git
$ cd dict.c
$ make
```

## API
### dict *dict_new()
Allocate and initialize a new dictionary. This function returns a pointer to the dictionary that was created.

### char *dict_get(dict *d, char *key)
Get the value of `key` in `d` and return it.

### void dict_set(dict *d, char *key, char *value)
Set `key` to `value` in `d`. This function will create a new key-value pair if necessary.

### void dict_del(dict *d, char *key)
Delete `key` in `d`.

### int dict_has(dict *d, char *key)
Return 1 if `key` is in `d`, 0 otherwise.

### int dict_len(dict *d)
Return the number of key-value pairs in `d`.

### char **keys(dict *d)
Return an array containing all the keys in `d`.

### char **values(dict *d)
Return an array containing all the values in `d`.

### void dict_free(dict *d)
Properly free `d`.

## Running tests
Clone the thing, `cd` into it and then do this:
```sh
$ make test
```

## License
MIT License. See `./LICENSE` for details.
