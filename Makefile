CC:=clang++
CFLAGS:=-lm -O2
SHELL:=/bin/bash

# Assume all directories are problems and all solutions are in C/C++
.PHONY: all
all:
	@for dir in $$(find . -type d -maxdepth 1 ! -iname '.*'); do \
	  cd $(CURDIR)/$$dir && \
	    ($(CC) $(CFLAGS) main.* && \
	    ./a.out < input.txt > output.actual.txt && \
	    diff <(cat output.actual.txt) <(cat output.expected.txt) > /dev/null 2>&1 && \
	    echo -ne '\xE2\x9C\x93 ') || echo -ne '\xE2\x9C\x97 '; echo $$dir; \
	done
