
#-------------
# make
# make run
#
#--------------
CC = gcc
CFLAGS = -Wall -Wextra -g -I./include
LDFLAGS = -ldl
TARGET = calculator

all: $(TARGET) func_4_n.so func_4_e.so func_5_i.so func_5_w.so

$(TARGET): src/main2.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

func_4_n.so: src/func_4_n.c include/func4.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

func_4_e.so: src/func_4_e.c include/func4.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

func_5_i.so: src/func_5_i.c include/func5.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

func_5_w.so: src/func_5_w.c include/func5.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

run: all
	LD_LIBRARY_PATH=. ./$(TARGET)

clean:
	rm -f $(TARGET) *.so

.PHONY: all run clean