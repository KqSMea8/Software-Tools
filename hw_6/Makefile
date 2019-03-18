# file: GNUMakefile
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: hw_06.exe

# define a target to link the application
#
hw_06.exe: f_00.o f_01.o f_02.o
	gcc -lm f_00.cc f_01.cc f_02.cc -o hw_06.exe

# define targets to compile the source code
#
f_00.o: f_00.cc f_header.h Makefile
	gcc -O2 -c f_00.cc 

f_01.o: f_01.cc f_header.h Makefile
	gcc -O2 -c f_01.cc

f_02.o: f_02.cc f_header.h Makefile
	gcc -O2 -c f_02.cc

# define a target to clean the directory
#
clean:
	rm -f f_00.o f_01.o f_02.o hw_06.exe

#
# end of file
