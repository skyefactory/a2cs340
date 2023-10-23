SDIR = src
ODIR = obj

CC = g++
CLFLAGS=-I$(IDIR)

all: create assign1dfo301 clean

_OBJ = main.o node.o stack.o conversions.o expressiontree.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

create:
	mkdir $(ODIR)

assign1dfo301: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	mv assign1dfo301 ../

clean:
	rm -rf $(ODIR)
