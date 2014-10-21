
IN = src/*.c
OUT = dict.o
INCLUDE = src
TEST_IN = test.c
TEST_OUT = tst

all: $(IN) clean
	$(CC) -o $(OUT) -c $(IN) -I $(INCLUDE)

tst: $(TEST_IN) all clean
	$(CC) $(TEST_IN) $(IN) -I $(INCLUDE) -o $(TEST_OUT)

test: tst
	./$(TEST_OUT)
	$(MAKE) clean

clean:
	rm -fr $(TEST_OUT) $(OUT)

.PHONY: clean
