export CC      := gcc
export CFLAGS  := -Wall

SRC    := Src
OBJDIR := $(SRC)/obj

.PHONY: Coins
Coins: makeSources
	$(CC) $(CFLAGS) -o $@ $(wildcard $(OBJDIR)/*.o)

.PHONY: makeSources
makeSources: | $(OBJDIR)
	$(MAKE) $(CFLAGS) -C $(SRC) makeSources

.PHONY: $(OBJDIR)
$(OBJDIR):
	-mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -f Coins
	rm -fr $(OBJDIR)
	$(MAKE) $(CFLAGS) -C $(SRC) clean

