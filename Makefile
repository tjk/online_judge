SHELL:=/bin/bash

# Assume all directories are problems and all solutions are in C/C++
.PHONY: all
all:
	@for dir in $$(find . -type d -maxdepth 1 ! -iname '.*'); do \
	  cd $(CURDIR)/$$dir && \
	    (g++ -lm -O2 -pipe -DONLINE_JUDGE main.* 2> /dev/null && \
	    diff <(./a.out < input.txt) <(cat expected.txt) > /dev/null 2>&1 && \
	    echo -ne '\xE2\x9C\x93 ') || echo -ne '\xE2\x9C\x97 '; echo $$dir; \
	done
