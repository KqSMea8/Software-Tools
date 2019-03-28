# file: GNUMakefile
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: example.exe

# define a target to link the application
#
example.exe: example_00.o example.o
	g++ -g -lm example_00.cc example.cc -o example.exe

# define targets to compile the source code
#


example_00.o: example_00.cc Example.h Makefile
	g++ -O2 -g -c example_00.cc -o example_00.o

example.o: example.cc Example.h Makefile
	g++ -O2 -g -c example.cc -o example.o

# define a target to clean the directory
#
clean:
	rm -f example_00.o example.o example.exe

#
# end of file
