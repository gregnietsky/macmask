PREFIX=/usr
BINDIR=$(PREFIX)/bin

CC=gcc
INSTALL=ginstall

all:	macmask
install: all
	$(INSTALL) -D macmask $(DESTDIR)$(BINDIR)

macmask:
	$(CC) macmask.c -o macmask
