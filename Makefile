PREFIX=/usr
BINDIR=$(PREFIX)/bin

CC=gcc
INSTALL=ginstall

all:	macmask
distclean:	clean

clean:
	rm macmask


install: all
	$(INSTALL) -D macmask $(DESTDIR)$(BINDIR)/macmask

macmask:
	$(CC) macmask.c -o macmask
