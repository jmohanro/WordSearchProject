# Makefile for word_search program

CC=gcc

# WARNINGS
CFLAGS=-c -Wall -std=c99 -Wextra -g

# Header files to be used as dependencies
HEADERS=search.h logic.h

# Main project files

OBJECTS=main.o 

# Final Program to Build
EXECUTABLE=word_search

#-----------------------------------------

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)
	
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<
	
clean:
	rm -rf *.o $(EXECUTABLE)
	
	

