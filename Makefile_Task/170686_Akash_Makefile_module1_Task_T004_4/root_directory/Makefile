CC = gcc
CFLAGS = -Wall -Wextra -g

PROJECTS = $(wildcard project*)

.PHONY: all clean $(PROJECTS)

all: $(PROJECTS)

$(PROJECTS):
	$(CC) $(CFLAGS) $@/*.c -o $@/$@.out

clean:
	rm -f */*.out

