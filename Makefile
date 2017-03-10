# all: assembler

# %: %.c
# 	gcc $< -o -pedantic –ansi –Wall $@

all: main

CFLAGS = -Wall -pedantic -ansi

main: $(wildcard *.c)
	gcc $(CFLAGS) $^ -o $@ 
	
clean:
	rm *.o *~ *.bak