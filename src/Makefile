#Makefile

CC = gcc
SRC = main.c
OBJS = main.o
TARGET = convert2coe
OUTPUT = ../../bin/

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: $(SRC)
		$(CC) -c $(SRC)

.PHONY: clean
clean:
			rm -rf $(TARGET) $(OBJS)
