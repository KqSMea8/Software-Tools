# file: GNUMakefile
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: mytest.exe

# define a target to link the application
#
mytest.exe: mytest_00.o mytest.o
	g++ -lm mytest_00.cc mytest.cc -o mytest.exe 

# define targets to compile the source code
#



mytest_00.o: mytest_00.cc mytest.h Makefile
	g++ -O2 -c mytest_00.cc -o mytest_00.o 

mytest.o: mytest.cc mytest.h Makefile
	g++ -O2 -c mytest.cc -o mytest.o

# define a target to clean the directory
#
clean:
	rm -f mytest_00.o mytest.o mytest.exe

#
# end of file


