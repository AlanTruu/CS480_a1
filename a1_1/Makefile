CC = gcc
FLAGS = -wall -g -pthread -Iheaders
FILES = main.c Bots.c


OBJECTS = $(FILES:.c = .o)
EXEC = main

all: $(EXEC)

$(EXEC) : $(OBJECTS)
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)

.c.o
	$(CC) $(FLAGS) -c $<

clean:
	rm -f *.o$(EXEC)