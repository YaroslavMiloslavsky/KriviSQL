AUTHOR = YarosMilos
NAME = KriviSQL
TESTING_NAME = $(NAME)_testing
CC = gcc
CCCOMIPLE = $(CC) -c
CCDEBUG = $(CC) -g
CFLAGS = -Wall -Werror -pedantic
HEADERS = -I header
OS := $(shell uname -s)
# MacOS? Nahh..... maybe later
ifeq ($(OS),Linux)
    EXECUTABLE = $(NAME)
	TESTEXEC = $(TESTING_NAME)
else
    EXECUTABLE = $(NAME).exe
	TESTEXEC = $(TESTING_NAME).exe
endif

$(EXECUTABLE) : main.o helper.o command.o
	$(CCDEBUG) $(CFLAGS) command.o helper.o main.o -o $(EXECUTABLE)

main.o : src/main.c header/global.h header/helper.h header/test.h 
	$(CCCOMIPLE) $(CFLAGS) $(HEADERS) src/main.c -o main.o

$(TESTEXEC) : test.o helper.o command.o test_helper.o
	$(CCDEBUG) $(CFLAGS) command.o helper.o test_helper.o test.o -o $(TESTEXEC)

test.o: src/test.c header/test.h header/global.h header/helper.h 
	$(CCCOMIPLE) $(CFLAGS) $(HEADERS) src/test.c -o test.o

test_helper.o : src/test_helper.c header/test_helper.h 
	$(CCCOMIPLE) $(CFLAGS) $(HEADERS) src/test_helper.c -o test_helper.o

helper.o: src/helper.c header/helper.h
	$(CCCOMIPLE) $(CFLAGS) $(HEADERS) src/helper.c -o helper.o

command.o: src/command.c header/command.h
	$(CCCOMIPLE) $(CFLAGS) $(HEADERS) src/command.c -o command.o

clean:
	rm *.o $(EXECUTABLE) $(TESTEXEC)
valgrind : $(EXECUTABLE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)
test: $(TESTEXEC)
	./$(TESTEXEC)
	rm *.o
	rm $(TESTEXEC)