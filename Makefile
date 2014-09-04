CPPFLAGS=-I$(JEMALLOC_PREFIX)/include

LDLIBS = -ljemalloc
LDFLAGS = -L$(JEMALLOC_PREFIX)/lib
# -Wl,-rpath=$(JEMALLOC_PREFIX)/lib

app:
