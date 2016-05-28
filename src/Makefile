CC = g++
CFLAGS = -std=c++11 -c -Wall
#CFLAGS= -std=c++11 -O3 -Wall -pedantic -Wextra -Weffc++\
#	 -Wcast-qual -Wcast-align -Wfloat-equal -Wpointer-arith\
#	 -Wunreachable-code -Wchar-subscripts -Wcomment -Wformat\
#	 -Werror-implicit-function-declaration -Wmain -Wmissing-braces\
#	 -Wparentheses -Wsequence-point -Wreturn-type -Wswitch\
#	 -Wuninitialized -Wreorder -Wundef -Wshadow -Wwrite-strings\
#	 -Wsign-compare -Wmissing-declarations -pedantic -Wconversion\
#	 -Wmissing-noreturn -Wall -Wunused -Wsign-conversion -Wunused \
#	 -Wstrict-aliasing -Wstrict-overflow -Wconversion\
#	 -Wdisabled-optimization -Wsuggest-attribute=const -Wsuggest-attribute=noreturn \
#	 -Wlogical-op -Wunsafe-loop-optimizations\
#	 -Weffc++ -Wsuggest-attribute=pure -Wunused-parameter -Wshadow
SOURCES = src/main.cpp src/Module_Deplacement.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXEC = bin/sergej

all: $(SOURCES) $(EXEC) 
	mv src/*.o obj/

$(EXEC): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ 

.cpp.o: 
	$(CC) $(CFLAGS) $< -o $@ 

clean: 
	rm src/*~
	rm obj/*.o 
	rm $(EXEC) 

run: 
	make all 
	/$(EXEC) 

