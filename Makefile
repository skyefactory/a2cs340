SDIR = src
ODIR = obj

CC = g++
CLFLAGS=-I$(IDIR)

all: create assign2dfo301 clean

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

create:
	mkdir $(ODIR)

assign2dfo301: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	mv assign2dfo301 ../

clean:
	rm -rf $(ODIR)
