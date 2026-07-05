CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/temp_api.c

all: build/kurs1

build/kurs1: $(SRC)
	if not exist build mkdir build
	$(CC) $(CFLAGS) $(SRC) -o build/kurs1

clean:
	if exist build rmdir /s /q build

run: build/kurs1
	build/kurs1
	