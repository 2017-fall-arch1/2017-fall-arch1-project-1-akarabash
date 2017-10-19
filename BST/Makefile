all: bsTreeDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#    $@ is the production's target
#    $^ are the production's prerequisites

bsTreeDemo: bsTree.o bsTreeDemo.o
	cc -o $@ $^

bsTree.o: bsTree.c bsTree.h
	cc -c $(CFLAGS) bsTree.c

bsTreeDemo.o: bsTreeDemo.c bsTree.h
	cc -c $(CFLAGS) bsTreeDemo.c

clean:
	rm -f *.0 bsTreeDemo

demo: bsTreeDemo
	
