HOME = /home/ff/cs61c
UNAME = $(shell uname)

# running on hive machines
ifeq ($(UNAME),Linux)
CC = gcc -std=gnu99 -O3
GOTO = $(HOME)/bin/GotoBLAS2_Linux
GOTOLIB = $(GOTO)/libgoto2_nehalemp-r1.13.a
endif

# running on 200 SD machines
ifeq ($(UNAME),Darwin)
CC = gcc -std=gnu99 -O3
GOTO = $(HOME)/bin/GotoBLAS2
GOTOLIB = $(GOTO)/libgoto2_nehalemp-r1.13.a
endif

INCLUDES = -I$(GOTO)
OMP = -fopenmp
LIBS = -lpthread  
# a pretty good flag selection for this machine...
CFLAGS = -msse4 -fopenmp -O3 -pipe -fno-omit-frame-pointer

# your implementation for the extra credit project
bench-extra: benchmark.o extra.o ref.o
	$(CC) -o $@ $(LIBS) $(OMP) benchmark.o extra.o ref.o $(GOTOLIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $<

clean:
	rm -f *~ bench-extra *.o
