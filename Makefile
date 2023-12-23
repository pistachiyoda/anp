# Makefile
CC=g++
CFLAGS=-Wall
TARGET=anp
DESTDIR=/usr/local/bin

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

install:
	cp $(TARGET) $(DESTDIR)/$(TARGET)

clean:
	rm -f $(TARGET)

re: clean all
