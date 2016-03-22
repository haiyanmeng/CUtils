CC=gcc
C99=c99
CFLAGS=-g3 -Wall -pedantic
VALGRIND_CMD=valgrind --tool=memcheck --leak-check=yes --track-origins=yes

TARGET = type_conv_test hash_table_test search_test stack_test

all: $(TARGET) 

stack_test: stack.o stack_test.c
	$(C99) $(CFLAGS) -o $@ $^

search_test: search.o search_test.c
	$(C99) $(CFLAGS) -o $@ $^

type_conv_test: type_conv.o type_conv_test.c
	$(C99) $(CFLAGS) -o $@ $^

hash_table_test: hash_table.o hash_table_test.c type_conv.o
	$(C99) $(CFLAGS) -o $@ $^

type_conv.o: type_conv.c
	$(C99) $(CFLAGS) -c -o $@ $^

# hash_table.c uses strdup, which is not part of ANSI C.
hash_table.o: hash_table.c
	$(CC) $(CFLAGS) -c -o $@ $^

test: all
	./type_conv_test
	./hash_table_test
	./search_test
	./stack_test

valgrind: all
	$(VALGRIND_CMD)	./type_conv_test
	$(VALGRIND_CMD) ./hash_table_test
	$(VALGRIND_CMD) ./search_test
	$(VALGRIND_CMD) ./stack_test

clean:
	rm -f $(TARGET) *.o a.out out

# all commands under any rule should start with a TAB character. Otherwise, you will get the "missing separator" error.
