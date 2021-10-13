TARGET = main
EXENAME = hangary
DEPS = main.o Common.o Algorithm.o

CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
OBJS = $(TARGET).o
LIBS = 

all: $(TARGET)

install: $(TARGET) clean

$(TARGET): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o $(EXENAME) $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o
