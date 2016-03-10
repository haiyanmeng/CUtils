CC=gcc
CFLAGS=-g3 -Wall -pedantic
VALGRIND_CMD=valgrind --tool=memcheck --leak-check=yes --track-origins=yes

TARGET = type_conv_test hash_table_test

all: $(TARGET) 

type_conv_test: type_conv.o type_conv_test.c
	$(CC) $(CFLAGS) -o $@ $^

hash_table_test: hash_table.o hash_table_test.c type_conv.o
	$(CC) $(CFLAGS) -o $@ $^

type_conv.o: type_conv.c
	$(CC) $(CFLAGS) -c -o $@ $^

hash_table.o: hash_table.c
	$(CC) $(CFLAGS) -c -o $@ $^

test: all
	./type_conv_test
	./hash_table_test

valgrind: all
	$(VALGRIND_CMD)	./type_conv_test
	$(VALGRIND_CMD) ./hash_table_test

clean:
	rm -f $(TARGET) *.o a.out
