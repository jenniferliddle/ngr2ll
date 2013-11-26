
TARGETS=ngr2ll_test

default: all

test: ngr2ll_test
	ngr2ll_test

all: $(TARGETS)

clean: 
	rm $(TARGETS) *.o

ngr2ll_test: ngr2ll_test.o ngr2ll.o
	$(CC) -o ngr2ll_test ngr2ll_test.o ngr2ll.o -lm

.c.o:
	$(CC) -c $<


