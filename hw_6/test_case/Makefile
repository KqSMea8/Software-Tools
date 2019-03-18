# file: GNUMakefile
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: example.exe

# define a target to link the application
#
example.exe: example.o example_00.o
	g++ -g -lm example.o example_00.o -o example.exe

# define targets to compile the source code
#
example.o: example.cc example.h Makefile
	g++ -g -c example.cc -o example.o

example_00.o: example_00.cc example.h Makefile
	g++ -g -c example_00.cc -o example_00.o

# define a target to clean the directory
#
clean:
	rm -f example.o example_00.o example.exe

#
# end of file


