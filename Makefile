TARGET = type_conv_test

all: $(TARGET) 

type_conv_test: type_conv.c type_conv_test.c
	gcc -g3 -o $@ $^

test: all
	./type_conv_test

clean:
	rm -f $(TARGET) *.o
