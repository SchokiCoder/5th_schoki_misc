CC=cc
CFLAGS=-std=c99 -Wall -Wextra -O3
LIB_NAME=schoki_misc
SO_NAME=lib$(LIB_NAME).so

all: $(SO_NAME) install

SM_log.o:
	$(CC) -c -fPIC $(CFLAGS) src/SM_log.c

SM_string.o:
	$(CC) -c -fPIC $(CFLAGS) src/SM_string.c

$(SO_NAME): SM_log.o SM_string.o
	$(CC) -shared -o $@ $^

install:
	cp $(SO_NAME) /usr/lib
	chmod 0755 /usr/lib/$(SO_NAME)
	mkdir /usr/include/$(LIB_NAME)
	cp src/*.h /usr/include/$(LIB_NAME)
	ldconfig

clean:
	rm -f *.o
	rm -f $(SO_NAME)

uninstall:
	rm -r -f /usr/include/$(LIB_NAME)
	rm -f /usr/lib/$(SO_NAME)
