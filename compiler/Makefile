# Makefile for C Compiler Project

CC = gcc
CFLAGS = -Wall -std=c99

# Object files for compiler
COMPILER_OBJS = main_0.o jiku_2.o kigouhyou_1.o syokika_0.o koubun_3.o code_2.o error_1.o

# Executable names
COMPILER = compiler
VM = vm
TEST_LEXER = test_lexer
TEST_SYMTABLE = test_symtable

# Default target
all: $(COMPILER) $(VM) $(TEST_LEXER) $(TEST_SYMTABLE)

# Build compiler
compiler: $(COMPILER_OBJS)
	$(CC) $(CFLAGS) -o $(COMPILER) $(COMPILER_OBJS)

# Build virtual machine
vm: kasoukikai_1.c
	$(CC) $(CFLAGS) -o $(VM) kasoukikai_1.c

# Build test programs
test_lexer: test_1.c jiku_2.o kigouhyou_1.o syokika_0.o error_1.o
	$(CC) $(CFLAGS) -o $(TEST_LEXER) test_1.c jiku_2.o kigouhyou_1.o syokika_0.o error_1.o

test_symtable: test_2.c jiku_2.o kigouhyou_1.o syokika_0.o error_1.o
	$(CC) $(CFLAGS) -o $(TEST_SYMTABLE) test_2.c jiku_2.o kigouhyou_1.o syokika_0.o error_1.o

# Object file compilation rules
main_0.o: main_0.c global_0.h
	$(CC) $(CFLAGS) -c main_0.c

jiku_2.o: jiku_2.c global_0.h
	$(CC) $(CFLAGS) -c jiku_2.c

kigouhyou_1.o: kigouhyou_1.c global_0.h
	$(CC) $(CFLAGS) -c kigouhyou_1.c

syokika_0.o: syokika_0.c global_0.h
	$(CC) $(CFLAGS) -c syokika_0.c

koubun_3.o: koubun_3.c global_0.h
	$(CC) $(CFLAGS) -c koubun_3.c

code_2.o: code_2.c global_0.h
	$(CC) $(CFLAGS) -c code_2.c

error_1.o: error_1.c global_0.h
	$(CC) $(CFLAGS) -c error_1.c

# Clean up
clean:
	rm -f *.o $(COMPILER) $(VM) $(TEST_LEXER) $(TEST_SYMTABLE)

# Run examples
run_example:
	@echo "Running example: x = 10; y = x + 5; z = y * 2;"
	@echo "x = 10; y = x + 5; z = y * 2;" | ./$(COMPILER) > output.obj
	@echo "Generated object code:"
	@cat output.obj
	@echo "\nExecuting on virtual machine:"
	@./$(VM) < output.obj

.PHONY: all clean run_example compiler vm test_lexer test_symtable
