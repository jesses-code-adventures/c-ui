# Compiler and flags
CC = gcc
CFLAGS = -g
LDFLAGS = -framework SDL2 -F /Library/Frameworks -I /Library/Frameworks/SDL2.framework/Headers -Wl,-rpath,/Library/Frameworks

# Source files
SRC = $(wildcard main.c state/*.c types/*.c)

# Output binary
OUTPUT = output/out

# Default target
all: clean $(OUTPUT)

# Rule to build the output binary
$(OUTPUT): $(SRC)
	@mkdir -p $(dir $(OUTPUT))
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

# Clean target to remove compiled files
clean:
	rm -f $(OUTPUT)
	rm -rf $(OUTPUT).dSYM
