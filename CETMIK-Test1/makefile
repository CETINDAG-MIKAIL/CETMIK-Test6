COMP =	g++ -Wall -I include/

all: Test1


Test1:	sources/Test1.cpp objs/ImageNG.o
			$(COMP) sources/Test1.cpp objs/ImageNG.o -o bin/Test1

objs/ImageNG.o :	sources/ImageNG.cpp include/ImageNG.h
			$(COMP) sources/ImageNG.cpp -c -o objs/ImageNG.o

clean: 
	rm -f objs/*.o core 
clobber: clean	
	rm -f bin/Test1