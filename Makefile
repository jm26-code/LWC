
CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = lwc
OBJS = lwc.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f *.o 
