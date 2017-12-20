GPP = g++ -std=c++11 -Wall -pedantic -g -pg
OBJECTS = recursive_fac.o

FacFinder : $(OBJECTS)
	$(GPP) $(OBJECTS) -o FacFinder
recursive_fac.o : recursive_fac.cpp
	$(GPP) -c recursive_fac.cpp
clean:
	rm -f $(OBJECTS) FacFinder gmon.out
