export SRC_DIR   := examples
export CPPFLAGS  := -Isrc

.PHONY: clean cleanall info

all:
	$(MAKE) -f Makefile.gen

run:
	$(MAKE) -f Makefile.gen run

info:
	$(MAKE) -f Makefile.gen info

clean:
	$(MAKE) -f Makefile.gen clean

cleanall:
	$(MAKE) -f Makefile.gen cleanall
