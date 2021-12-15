#export SRC_DIR   := examples
export CPPFLAGS  := -Isrc

.PHONY: clean cleanall info


basic:
	$(MAKE) -f Makefile.gen SRC_DIR=examples/en/$@ BUILD_DIR=build/en/$@
	$(MAKE) -f Makefile.gen SRC_DIR=examples/es/$@ BUILD_DIR=build/es/$@

borders:
	$(MAKE) -f Makefile.gen SRC_DIR=examples/en/$@ BUILD_DIR=build/en/$@
	$(MAKE) -f Makefile.gen SRC_DIR=examples/es/$@ BUILD_DIR=build/es/$@

farmacia:
	$(MAKE) -f Makefile.gen SRC_DIR=examples/es/$@ BUILD_DIR=build/es/$@

all: basic borders farmacia

info:
	$(MAKE) -f Makefile.gen info

clean:
	$(MAKE) -f Makefile.gen clean

cleanall:
	$(MAKE) -f Makefile.gen cleanall
