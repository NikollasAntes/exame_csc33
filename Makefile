CC = gcc
CFLAGS = -Wall -Wextra

TARGET = exame

.PHONY: all clean

all: $(TARGET)

$(TARGET): exame.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
