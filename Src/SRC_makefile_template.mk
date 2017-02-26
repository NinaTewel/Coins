OWN_INTERFACE_PATH := ../../Interface
CFLAGS             += -I$(OWN_INTERFACE_PATH)

SOURCES       = $(wildcard *.c)
PREREQUISITES = $(SOURCES:.c=.d)
OBJECTS       = $(SOURCES:.c=.o)

all: $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Automatic prerequisites for interface files.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(PREREQUISITES)

