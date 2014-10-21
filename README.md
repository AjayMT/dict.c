
# dict.c
dict.c is a simple implementation of a dictionary in C. It's basically just a linked list of key-value pairs.

Here's a usage example:

```c
#include "dict.h"

int main (int argc, char *argv[])
{
    int n = 12;
    char *pair1[2] = { "hello", "world" };
	char *pair2[2] = { "foo", &n };
    dict my_dict = dict_new(2, pair1, pair2);

    char world[100];
	dict_get(my_dict, world, "hello");
    printf("hello: %s\n", world); // => "hello: world"

    char bar[100];
	dict_get(my_dict, bar, "foo");
	printf("foo: %d\n", *((int *)bar)); // => "foo: 12"

    dict_set(&my_dict, "hello", "people"); // now 'hello' is mapped to 'people'
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
### dict_new(int npairs, ...)
Create a new dictionary. `npairs` is the number of key-value pairs the dictionary is being initialized with, followed by a series of key-value pairs in the form of arrays of 2 strings each. Note that you can add more key-value pairs to your dictionary via `dict_set`; `npairs` is **not** limiting the actual number of key-value pairs. This function returns the dictionary that was created.

### dict_get(dict d, char *dst, char *key)
Get the value of `key` in `d` and copy it to `dst`.

### dict_set(dict *d, char *key, char *value)
Set `key` to `value` in `d`. This function will create a new key-value pair if necessary.

## Running tests
Clone the thing, `cd` into it and then do this:
```sh
$ make test
```

## License
MIT License. See `./LICENSE` for details.
