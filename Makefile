CC = gcc
OBJECTS = src/cspot_log.c src/cspot_filter.c cspot.c
LIBS =
CFLAGS = -Wall -O2
BINDIR = $(DESTDIR)/usr/bin
NAME = cspot

cspot: $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<
