CC=c99
CFLAGS=-D_POSIX_C_SOURCE=200112L
LDFLAGS=
PROGRAM_NAME=posix-gethostname-example

.POSIX:

.PHONY: all
all: build

.PHONY: build
build: $(PROGRAM_NAME)

.PHONY: clean
clean:
	-rm $(PROGRAM_NAME)

.PHONY: run
run: build
	@./$(PROGRAM_NAME)

$(PROGRAM_NAME): $(PROGRAM_NAME).c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
