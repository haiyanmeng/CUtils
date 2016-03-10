TARGET = type_conv_test hash_table_test

all: $(TARGET) 

type_conv_test: type_conv.c type_conv_test.c
	gcc -g3 -std=c99 -pedantic -Wall -o $@ $^

hash_table_test: hash_table.c hash_table_test.c type_conv.c
	gcc -g3 -Wall -o $@ $^

test: all
	./type_conv_test
	./hash_table_test

clean:
	rm -f $(TARGET) *.o a.out
