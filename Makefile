CC=cc
PROGRAM_NAME=posix-gethostname-example

.PHONY: all
all: build

.PHONY: build
build: $(PROGRAM_NAME)

.PHONY: clean
clean:
	rm ./$(PROGRAM_NAME)

.PHONY: run
run: build
	@./$(PROGRAM_NAME)

$(PROGRAM_NAME): $(PROGRAM_NAME).c
	$(CC) -o $@ $^
