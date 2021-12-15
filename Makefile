#export SRC_DIR   := examples
export CPPFLAGS  := -Isrc

.PHONY: clean cleanall info

all:
	$(MAKE) -f Makefile.gen SRC_DIR=examples/en BUILD_DIR=build/en
	$(MAKE) -f Makefile.gen SRC_DIR=examples/es BUILD_DIR=build/es

run:
	$(MAKE) -f Makefile.gen run

info:
	$(MAKE) -f Makefile.gen info

clean:
	$(MAKE) -f Makefile.gen clean

cleanall:
	$(MAKE) -f Makefile.gen cleanall
