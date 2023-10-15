COMP =	g++ -Wall -I include/

all: Test1 Test2


Test1:	sources/Test1.cpp objs/ImageNG.o
			$(COMP) sources/Test1.cpp objs/ImageNG.o -o bin/Test1

objs/ImageNG.o :	sources/ImageNG.cpp  include/ImageNG.h 
			$(COMP) sources/ImageNG.cpp -c -o objs/ImageNG.o 



Test2:	sources/Test2.cpp objs/ImageNG.o objs/Dimension.o
			$(COMP) sources/Test2.cpp objs/ImageNG.o objs/Dimension.o -o bin/Test2

objs/Dimension.o :	sources/Dimension.cpp  include/Dimension.h 
			$(COMP) sources/Dimension.cpp -c -o objs/Dimension.o 





clean: 
	rm -f objs/*.o core 
clobber: clean	
	rm -f bin/Test1 bin/Test2