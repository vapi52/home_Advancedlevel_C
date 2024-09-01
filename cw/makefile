TARGET = report\report.exe
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRCS = src\report.c src\functions.c src\plot.c src\roots.c src\integrals.c 
INCS = -Iinclude
OBJS = $(SRCS:.c=.o)
TXT = _data.txt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	del .\$(TARGET)
	del $(OBJS)
	del $(TXT)
