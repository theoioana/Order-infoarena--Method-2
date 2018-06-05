CC=gcc

# -c = compilation
# -Wall = throws all warnings
CFLAGS=-c -Wall

all: order
# -c = compilation
# -Wall = throws all warnings
order: main.o build_tree.o query_and_update_tree.o algorithm.o
	$(CC) main.o build_tree.o query_and_update_tree.o algorithm.o -o order

main.o: main.c
	$(CC) $(CFLAGS) main.c

build_tree.o: build_tree.c
	$(CC) $(CFLAGS) build_tree.c

query_and_update_tree.o: query_and_update_tree.c
	$(CC) $(CFLAGS) query_and_update_tree.c

algorithm.o: algorithm.c
	$(CC) $(CFLAGS) algorithm.c


